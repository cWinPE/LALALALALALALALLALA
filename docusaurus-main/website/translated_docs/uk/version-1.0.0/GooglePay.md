---
id: version-1.0.0-GooglePay
title: GooglePay
original_id: GooglePay
---
 ## Зручний спосіб оплати через Google

Google Pay™ – це простий та швидкий спосіб оплати покупок у магазинах та мільйонах онлайн-сервісів. Платити через Google Pay не тільки зручно, але й безпечно: дані банківських карток надійно захищені. Крім того, керувати обліковим записом можна і на сайті сервісу, і в самому додатку.


## Підключення Google Pay через платіжну сторінку Concord Pay

### Для підключення необхідно:

  1. Зареєструватися у системі [Concord Pay](https://pay.concord.ua/cabinet/default/signup) та підписати договір з банком Concord.
  2. Погодитись [з умовами надання послуг Google Pay](https://payments.developers.google.com/terms/sellertos).

### Опис

При такому способі підключення немає необхідності проводити будь-яку додаткову інтеграцію. Кнопка Google Pay з'явиться на сторінці оплати Concord Pay.

Приклад форми оплати з увімкненим методом оплати через Google Pay.
![Моя картинка](/docs/img/payment-form-en.png)

## Пряме підключення через Google Pay API

### Опис

Цей спосіб найзручніший з погляду юзабіліті для клієнта. Він дозволяє підключитися безпосередньо, без переходу на платіжну форму Concord Pay і приймати платежі прямо у себе на сайті або в додатку.

### Як підключиться?

* Виконати вимоги щодо брендування([для мобільних додатків](https://developers.google.com/pay/api/android/guides/brand-guidelines) або для [веб-сайтів](https://developers.google). com/pay/api/web/guides/brand-guidelines)).

* Перевірити відповідність [контрольному списку для інтеграції](https://developers.google.com/pay/api/android/guides/test-and-deploy/integration-checklist).

* Пройти перевірку- відправити збірку мобільного додатку або посилання на сайт зі сторінкою оплати.

### Як це працює?

![gpayDiagram](/docs/img/gpayDiagram.png)

1. Ви ініціюєте запит зі свого сайту або програми на отримання зашифрованих платіжних даних.
2. Google Pay повертає зашифровані платіжні дані після автентифікації покупця.
3. Ви надсилаєте зашифровані дані на сервер.
4. Ваш сервер надсилає інформацію про платеж та зашифровані платіжні дані на сервер Cocnord Pay.
5. Ми у відповідь надсилаємо статус платежу.
6. Ви повідомляєте покупця про статус платежу.

## Як інтегрувати метод Google Pay?

Для інтеграції використовуйте [API Google Pay](https://developers.google.com/pay/api/).

## Парметри для налаштування

1. allowPaymentMethods : CARD
2. tokenizationSpecification = {"type": "PAYMENT_GATEWAY"}
3. allowedCardNetworks = ['MASTERCARD', 'VISA'];
4. allowedCardAuthMethods = ['PAN_ONLY', 'CRYPTOGRAM_3DS'];
5. gateway = concordpay
6. GatewayMerchantId - унікальний ідентифікатор мерчанта. Видається кожному партнеру під час підключення до системи Concord Pay.

```json
{
   "apiVersionMinor":0,
   "apiVersion":2,
   "paymentMethodData":{
      "description":"Mastercard •••• 6812",
      "tokenizationData":{
         "type":"PAYMENT_GATEWAY",
         "token":{"signature":"MEYCIQC+IHxUu9Wwra2Vu6tBa2wJ1VphLGYtNVLLwIhAOkdbNje//eLrXVc+n6LOlc4PqxWOUcqwPCMT3pWtNrmki/CNA1ur","intermediateSigningKey":{"signedKey":"{\"keyValue\":\"MFkwEwYHKoZIzj0CAQYIKoZIzyGFjQuzGSVij0DAQcDQgAEwhRrvGB0kZ1248MEJAPwX0YfrQInhyyRM7nZG3QC9NMvXR9Zd6uVcVzAz+6K/+NEGIWbX8zbk6A\\u003d\\u003d\",\"keyExpiration\":\"1571328568000\"}","signatures":["MEUCIQCR6vhCBHeFPvDJlCIo4/tLd7W8CIGrZDJlCI48IEiyHB8qmlCBHeFPvQIgLZJIe4cZv6pYtYYa56QCI/vvg1GqXTP3bTBjO49r5mI\u003d"]},"protocolVersion":"ECv2","signedMessage":"{\"encryptedMessage\":\"O4wTPip6RruraT6vO9MS+9stjkU/kT5EibKB3O1bbxyybKcGQ5vxBOtNOBKKd/NuqNmN2eEK3UbSKb1M3gv45gT9cCeEvlzO7Wg0N100vUBp9RPDN9TH4tj4w578sWFKfTi6FsSrZB27SGWcU0k85CGUMmd5PaGmQlHFqHc0HrDZmjM1yG82rFB/p31ZyUleN5nihzjOZif/BKXwg3XA2oLXqBSSWcAdfZwXxCEOqvAQE+kpTC7qVO4wTPip6RruraT6vO9M9FtPJXP9bPxzMVk/ozEZSfhSzVTT5EibKB3O1bbxyybKcGQ5vxBOtNOBKKd/NuqNmN2eEK3UbSKb1M3gv45gT9cCeEvlzO7Wg0N100vUBp9RPDN9TH4tj4w578sWFKfTi6FsSrZB27SGWcU0k85CGUMmd5PaGmQlHFqHc0HrDZmjM1yG82rFB/p31ZyUleN5nihzjOZif/BKXJXP9bPxzMVk/ozEZSfhSzVTT5EibKB3O1bbxyybKcGQ5vxBOtNOBKKd/NuqNmN2eEK3UbSKb1M3gv45gT9cCeEvlzO7Wg0N100vwg3XA2oLXqBSSWcAdfZwXxCEOqvAQE+kpTC7qVO4wTPip6RruraT6vO9MS+9stjkU/kT5EibKB3O1bbxyybKcGQ5vxBOtNOBKKd/NuqNmN2eEK3UbSKb1M3gv45gT9cCeEvlzO7Wg0N100vUBp9RPDN9TH4tj4w578sWFKfTi6FsSrZB27SGWcU0k85CGUMmd5PaGmQlHFqHc0HrDZmjM1yG82rFB/p31ZyUleN5nihzjOZif/BKXwg3XA2oLXqBSSWcAdfZwXxCEOqvAQE+kpTC7qVO4wTPip6RruraT6vO9M9FtIf0kcqzYSAN7pl1SUA5jC9rHrqucPoh0/FSspup78SWBt8TnmVKC9O3sQhIZ3SMoGOG4mdjtIrgCwWH2cbrxUH0dHAqOe5ANGOY/mII4nTEp7xaKu41hK/kFE15zVyqgEaKHO9buo94mRBY5yqffF3bKg5mAMPzjDhyHSujqWKAs9C5fBzMEuEr2z7A23kfLqBceH5uS9LJMiZ/yVKCwfpY9u2XyCjKdp7I\\u003d\",\"ephemeralPublicKey\":\"BAMDAtfgcPNuzItrwGLigGj3rtxmyHhZLwx1B4RJZ2oo11jpFf3SA6a3utryCMmlCEcqLfLn6WDH2ArrNBGn+Ew\\u003d\",\"tag\":\"T/qhZ/XY5/3Fe4QBKazwVeiKfm6NqS6EXhRlp8NeWrA\\u003d\"}"}
      },
      "type":"CARD",
      "info":{
         "cardNetwork":"MASTERCARD",
         "cardDetails":"6812"
      }
   }
}
```
У разі підтвердження платником оплати колббек поверне у функцію processPayment дані, які необхідно буде надіслати в API Concord Pay, для проведення оплати.

## Платіжний метод GooglePayPurchase

**URL**: https://pay.concord.ua/api/

**Параметри запиту:**

| **Параметр** | **Опис** | **Обов'язковий** | **Тип** |
|---------------|----------------|--------------------|--------------------|
| Operation | Тип операції. Значення: **GooglePayPurchase** | Так | String |
| merchant_id | Ідентифікатор мерчанта | Так | String |
| amount | Сума платежу у форматі 1.00 | Так | Float |
| order_id | Унікальний номер операції на стороні мерчанта. Якщо операція дублюється – мерчант отримує помилку. | Так | String |
| currency_iso | Валюта платежу **UAH**| Так | String |
| description | Опис платежу | Так | String |
| callback_url | URL, на який прийде інформація про результат виконання платежу | Так | String |
| gpApiVersionMinor | apiVersionMinor з processPayment(paymentData) | Так | Integer |
| gpApiVersion| apiVersion з processPayment(paymentData) | Так | Integer |
| gpPMDescription| paymentMethodData.description з processPayment(paymentData) | Так | String |
| gpPMType| paymentMethodData.type з processPayment(paymentData) | Так | String |
| gpPMICardNetwork| paymentMethodData.info. cardNetwork з processPayment(paymentData) | Так | String |
| gpPMICardDetails| paymentMethodData.info. cardDetails з processPayment(paymentData) | Так | String |
| gpTokenType| paymentMethodData. tokenizationData.type з processPayment(paymentData) | Так | String |
| gpToken | aymentMethodData.tokenizationData.token з processPayment(paymentData) | Так | String |
| signature | З метою підтвердження валідності даних має бути згенерований та переданий у запиті HMAC_MD5 контрольний підпис з використанням **PrivateKey** торговця. Рядок, що підлягає HMAC_MD5, генерується шляхом конкатенації параметрів merchant_id, order_id, amount, currency_iso, description, розділених **“;”** (крапка з комою) у кодуванні UTF-8. **Порядок параметрів при конкатенації важливий!**| Так | String |

**Параметри відповіді:**

| **Параметр** | **Опис** | **Обов'язковий** |
|---------------|--------------|--------------------|
| code | Код відповіді |Так |
| status | Якщо у статусі платежу прийде 3DS – необхідно виконати перевірку 3DS | Так |
| d3AcsUrl | URL ACS-серверу для перевірки 3DS | Ні |
| d3Md | Унікальний ідентифікатор передачі на хост 3DS | Ні |
| d3Pareq | PaReq повідомлення передачі на хост 3DS| Ні |
| transaction_key | Ключ транзакції для підтвердження 3DS |Так |

## Перевірка 3DS
Якщо в полі **status** повернеться значення 3ds, необхідно перевірити 3D Secure.
Після отримання даних від системи Concord Pay необхідно передати на d3AcsUrl методом POST параметри d3Pareq і d3Md у наступній формі:

```html
<form name="MPIform" action='${d3AcsUrl}' method="POST">
<input type="hidden" name="PaReq" value='${d3Pareq }'>
<input type="hidden" name="MD" value='${d3Md }'>
<input type="hidden" name="TermUrl" value='${TempUrl}'>
</form>
```

TempUrl - URL, що переданий мерчантом, на який емітент поверне відповідь після аутентифікації клієнта.

## Підтвердження 3DS верифікації

Після проходження клієнтом аутентифікації та редиректу на TempUrl з результатом, отриманим від емітента, мерчант надсилає запит **Complete3DS**.

**Параметри запиту:**

| **Параметр** | **Опис** | **Обов'язковий** |
|----------|----------|-------------|
| Operation | Тип операції **Complete3DS** | Так |
| transaction_key | Ключ транзакції |Так |
| merchant_id | Ідентифікатор Мерчанта | Так |
| d3ds_md | Ідентифікатор отриманий після редиректу сервера ACS | Так |
| d3ds_pares | Повідомлення, отримане після редиректу з сервера ACS | Так |
| signature | З метою підтвердження валідності даних має бути згенерований та переданий у запиті HMAC_MD5 контрольний підпис з використанням **Private Key** мерчанта. Рядок, що підлягає HMAC_MD5, генерується шляхом конкатенації параметрів merchant_id, transaction_key, d3ds_md, d3ds_pares, розділених **“;”** (крапка з комою) у кодуванні UTF-8. **Порядок параметрів при конкатенації важливий!** | Так |

**Параметри відповіді**

| **Параметр** | **Опис** | **Обов'язковий** |
|----------|----------|-------------|
| status | Статус платежу довідник Статуси платежу | Так |
| code | Код відповіді (Довідник “Коди відповідей”, довідник “Статуси платежу”) | Так |
| order_id | Унікальний номер замовлення у системі мерчанта | Так |
| amount | Сума платежу |Так |
| fee | Комісія | Так |
| currency | Валюта платежу |Так |
| card_pan | Маскований номер картки | Так |
| transaction_id | Ідентифікатор транзакції |Так |



## Корисні посилання

* [Демо](https://developers.google.com/pay/api/web/guides/resources/demos)
* [Логотип Google Pay](/docs/img/logo-googlepay.png)
* [API Google Pay](https://developers.google.com/pay/api/)
* При використанні Google Pay необхідно дотримання [наступних умов від Google.](https://payments.developers.google.com/terms/sellertos)
