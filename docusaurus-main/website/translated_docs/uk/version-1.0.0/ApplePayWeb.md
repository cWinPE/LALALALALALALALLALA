---
id: version-1.0.0-ApplePayWeb
title: ApplePayWeb
original_id: ApplePayWeb
---
## Операція купівлі через Apple Pay

Для інтеграції кнопки Apple Pay на платіжну сторінку інтернет магазину необхідно реалізувати метод ApplePaySession.canMakePaymentsWithActiveCard. Метод визначає, чи підтримує цей пристрій оплату за допомогою Apple Pay.

Якщо так - необхідно відобразити кнопку "Купити за допомогою Apple Pay".

Далі необхідно створити об'єкт **ApplePaySession**, з параметрами покупки:

``` js
  countryCode: 'UA',
  currencyCode: 'UAH',
  supportedNetworks: ['visa', 'masterCard'],
  merchantCapabilities: ['supports3DS'],
  total: { label: 'Your Merchant Name', amount: '10.00' },

```
Опис полів можна подивитися в документації Apple Pay on Web.

На подію **onvalidatemerchant** необхідно повісити обробник, в якому буде викликатися API "api / apple / validate". Опис методу буде нижче.

На подію **onpaymentauthorized** необхідно повісити обробник, який буде викликати API "api / apple / payment".


Після підтвердження платежу в **onpaymentauthorized** необхідно викликати метод
**ApplePaySession.completePayment**.


Документацію по ApplePaySession можна знайти на оф.сайті Apple (https://developer.apple.com/documentation/apple_pay_on_the_web/apple_pay_js_api).

## Валідація мерчанта Apple Pay (api / apple / validate).
 
 **Production url:** https://pay.concord.ua/api/apple/validate
 
 POST-параметри:
 | Параметр             | Опис                                                                                                                                                                       | Значення |
 |----------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------|
 | operation            | Тип операції                                                                                                                                                                      | Purchase |
 | apple_validation_url | Цей параметр приходить в подію onvalidatemerchant, event.validationURL <br> session.onvalidatemerchant = (event) => { <br> console.log(event.validationURL);  <br>    }           |          |                                                                                                                                                                      |          |
 | merchant_id          | ID мерчанта                                                                                                                                                 |          |
 | amount               | Сума операції. Приклад: 500.00                                                                                                                                                     |          |
 | signature            | З метою підтвердження валідності даних повинен бути згенерований і переданий у запиті HMAC_MD5 контрольний підпис з використанням SecretKey мерчанта.                          |          |
 |                      | Рядок, що підлягає HMAC_MD5, генерується шляхом конкатенації параметрів merchant_id, order_id, amount, currency_iso, description розділених ";" (крапка з комою) в кодуванні UTF-8. |          |
 |                      |Порядок параметрів при конкатенації важливий!                                                                                                                                        |          |
 | order_id             | Унікальний номер операції на стороні мерчанта. Якщо операція дублюється - мерчант отримує помилку.                                                                              |          |
 | currency_iso         | Валюта платежу.                                                                                                                                                                   | UAH      |
 | description          | Призначення платежу. Виводиться на платіжній сторінці, при введенні платіжних реквізитів. Відображається в виписці за рахунком і реєстрах                                                   |          |
 | add_params           | Масив з додатковими параметрами. Розширені можливості пошуку потім повертаються мерчанту в callback виклику                                                                     |          |
 | callback_url         | URL, на який прийде інформація про результат виконання платежу                                                                                                                  |          |
 

У відповідь приходять такі параметри:

| Параметр            | Опис                                                                       |
|---------------------|--------------------------------------------------------------------------------|
| apple_validate_data | Дані, які необхідно передати в метод session.completeMerchantValidation |
| order_key           | Ідентифікатор замовлення в платіжній системі                                      |
| code                | Код відповіді (0 - успіх)                                                     |
| message             | Розшифровка коду відповіді                                                        |


## Підтвердження платежу Apple Pay (api/apple/payment)

**Production url:**   https://pay.concord.ua/api/apple/payment

POST-параметри:

| Параметр               | Опис                                                                                               |
|------------------------|---------------------------------------------------------------------------------------------------------|
| order_key              | Ідентифікатор замовлення в платіжній системі                                                               |
| apple_pay_payment_data | Дані закодовані в base64, отримані в новій події onpaymentauthorized в параметрі event.payment. <br> Приклад: <br>session.onpaymentauthorized = (event) => { <br>       console.log(event.payment); <br>  }  |

У відповідь приходить:

| transactionStatus | Cтатус операції         | Approved - Успішно / Declined - Відмова  |
|-------------------|--------------------------|--------------------|
| reason            | Текстова причина відмови |                    |
| reasonCode        | Код помилки при відмові    |                    |

Після виклику цього методу приходить callback в backend мерчанта.