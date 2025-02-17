---
id: version-1.0.0-GooglePay
title: GooglePay
original_id: GooglePay
---
 ## Удобный способ оплаты через Google

Google Pay™ – это простой и быстрый способ оплаты покупок в магазинах и миллионах онлайн-сервисов. Платить через Google Pay не только удобно, но и безопасно: данные банковских карт надежно защищены. Кроме того, управлять аккаунтом можно и на сайте сервиса, и в самом приложении.


## Подключение Google Pay через платежную страницу Concord Pay 

### Для подключения необходимо: 

 1. Зарегистрироватся в системе [Concord Pay](https://pay.concord.ua/cabinet/default/signup) и подписать договор с банком Concord.
 2. Согласиться [с условиями предоставления услуг Google Pay](https://payments.developers.google.com/terms/sellertos).

### Описание

При таком сопсобе подключения нет необходимости проводить какую либо дополнительную интеграцию. Кнопка Google Pay будет отображатся на странице оплаты Concord Pay.

Пример формы оплаты с включенным методом оплаты через Google Pay.
![Моя картинка](/docs/img/payment-form.png)

## Прямое подключение через Google Pay Api

### Описание

Этот способ наиболее удобный с точки зрения юзабилити для клиента. Он позволяет подключиться напрямую, без перехода на платежную форму Concord Pay и принимать платежи прямо у с себя на сайте или в приложении.

### Как подключится ?

* Выполнить требования по брендированию([для мобильных приложений](https://developers.google.com/pay/api/android/guides/brand-guidelines) или для [веб-сайтов](https://developers.google.com/pay/api/web/guides/brand-guidelines)). 

* Проверьте соответствие [контрольному списку для интеграции](https://developers.google.com/pay/api/android/guides/test-and-deploy/integration-checklist).

 * Пройти проверку- отправить сборку мобильного приложения или ссылку на сайт со страницей оплаты.

 ### Как это работаает ? 

![gpayDiagram](/docs/img/gpayDiagram.png)

1. Вы инициируете запрос со своего сайта или приложения на получение зашифрованных платежных данных.
2. Google Pay возвращает зашифрованные платежные данные после аутентификации покупателя.
3. Вы отправляте зашифраванные данные на свой сервер.
4. Ваш сервер отправляет информацию о платеже и заашифрованные платежные данные на сервер Cocnord Pay.
5. Мы в ответ отправляем статус платежа.
6. Вы уведомляете покупателя о статусе платежа.

## Как интегрировть метод Google Pay ?

Для интеграции используйте [API Google Pay](https://developers.google.com/pay/api/).

## Парметры для настройки

1. allowPaymentMethods : CARD
2. tokenizationSpecification = { "type": "PAYMENT_GATEWAY"}
3. allowedCardNetworks = ['MASTERCARD', 'VISA'];
4. allowedCardAuthMethods = ['PAN_ONLY', 'CRYPTOGRAM_3DS'];
5. gateway = concordpay
6. gatewayMerchantId - уникальный идентификатор мерчанта. Выдается каждому партнеру при подключении к системе Concord Pay.

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
В случае подтверждения плательщиком оплаты коллбек вернет в функцию processPayment данные, которые необходимо будет отправить в API Concord Pay, для проведения оплаты.

## Платежный метод GooglePayPurchase

**URL**: https://pay.concord.ua/api/ 

**Параметры запроса:**

|  **Параметр** | **Описание**   |  **Обязательный**  |  **Тип** |
|---------------|----------------|--------------------|--------------------|
| operation     | Тип операции.  Значение: **GooglePayPurchase** | Да            | String |
| merchant_id   | Идентификатор мерчанта|  Да | String |
| amount | Сумма платежа в формате 1.00 |  Да | Float |
| order_id | Уникальный номер операции на стороне торговца. Если операция дублируется - торговец получает ошибку. |   Да | String |
| currency_iso | Валюта платежа **UAH**|   Да | String |
| description | Описание платежа |   Да | String |
| callback_url | URL на который придет информация о результате выполнения платежа |  Да | String |
| gpApiVersionMinor | apiVersionMinor из processPayment(paymentData) |   Да | Integer |
| gpApiVersion| apiVersion из processPayment(paymentData)  |  Да | Integer |
| gpPMDescription| paymentMethodData.description из processPayment(paymentData) |   Да | String |
| gpPMType| paymentMethodData.type из processPayment(paymentData) |   Да | String |
| gpPMICardNetwork| paymentMethodData.info. cardNetwork из processPayment(paymentData) |  Да | String |
| gpPMICardDetails| paymentMethodData.info. cardDetails из processPayment(paymentData)  |  Да | String |
| gpTokenType| paymentMethodData. tokenizationData.type из processPayment(paymentData)  |   Да | String |
| gpToken| aymentMethodData.tokenizationData.token из processPayment(paymentData) |   Да | String |
| signature | В целях подтверждения валидности данных должна быть сгенерирована и передана в запросе HMAC_MD5 контрольная подпись с использованием **PrivateKey** торговца. Строка, подлежащая HMAC_MD5, генерируется путем конкатенации параметров **merchant_id,order_id,amount, currency_iso,description** разделенных **“;”**   (точка с запятой) в кодировке UTF-8. **Порядок параметров при конкатенации важен!**|   Да | String |


**Параметры ответа:**

| **Парааметр** | **Описание** |  **Обязательный**  |
|---------------|--------------|--------------------|
|    code       | Код ответа   |   Да               |
|    status     |  Если в статусе платежа прийдет 3DS - необходимо выполнить проверку 3DS | Да |
| d3AcsUrl | acs url для проверки 3DS| Нет |
| d3Md     | Уникальный идентификатор для передачи на хост 3DS | Нет |
| d3Pareq  | PaReq сообщение для передачи на хост 3DS| Нет |
| transaction_key | Ключ транзакции для подтверждения 3DS | Да |


## Проверка 3DS 
Если в поле **status** вернется значение 3ds необходимо выполнить проверку 3D Secure.
После получения данных от системы Concord Pay, их необходимо передать на d3AcsUr методом POST параметры d3Pareq и d3Md в следующей форме:

```html
<form name="MPIform" action='${d3AcsUrl}' method="POST">
<input type="hidden" name="PaReq" value='${d3Pareq }'>
<input type="hidden" name="MD" value='${d3Md }'>
<input type="hidden" name="TermUrl" value='${TempUrl}'>
</form>
```

TempUrl - url переданный мерчантом, на который эмитент вернет ответ после аутентификации клиента.

## Подтверждение 3DS верификации

После  прохождения клиентом аутентификации и редиректа на TempUrl с результатом, полученным от эмитента, мерчант направляет запрос **Complete3DS**.

**Параметры запроса:**

| **Параметр** | **Описание** | **Обязтельный** |
|----------|----------|-------------|
| operation |  Тип операции  **Complete3DS** |  Да   |
| transaction_key |  Ключ транзакции    |   Да  |
| merchant_id |  Идентификатор мерчанта   |  Да   |
| d3ds_md |   Идентификатор полученный после редиректа с сервера ACS  |  Да   |
| d3ds_pares |  Сообщение полученное после редиректа с сервера ACS   |  Да   |
| signature |   В целях подтверждения валидности данных должна быть сгенерирована и передана в запросе HMAC_MD5 контрольная подпись с использованием **Private Key** торговца. Строка, подлежащая HMAC_MD5, генерируется путем конкатенации параметров **merchant_id,transaction_key,d3ds_md,d3ds_pares** разделенных **“;”** (точка с запятой) в кодировке UTF-8. **Порядок параметров при конкатенации важен!**  |   Да  |

**Параметры ответа**

| **Параметр** | **Описание** | **Обязтельный** |
|----------|----------|-------------|
| status   | Статус платежа справочник “Статусы платежа” | Да |
| code     | Код ответа. Справочник “Коды ответов” справочник “Статусы платежа” | Да |
| order_id  | Уникальный номер заказа в системе торговца | Да |
| amount | Сумма платежа | Да |
| fee | Комиссия | Да |
| currency | Валюта платежа | Да |
| card_pan | Маскированный номер карты | Да |
| transaction_id | Идентификатор транзакции | Да |





## Полезные ссылки

* [Демо](https://developers.google.com/pay/api/web/guides/resources/demos)
* [Логотип Google Pay](/docs/img/logo-googlepay.png)
* [API Google Pay](https://developers.google.com/pay/api/)
* При использовании Google Pay необходимо соблюдение [следующих условий от компании Google.](https://payments.developers.google.com/terms/sellertos)