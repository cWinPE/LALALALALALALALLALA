---
id: version-1.0.0-GooglePay
title: GooglePay
original_id: GooglePay
---
 ## A better way to pay, by Google

Google Pay™ is the fast, simple way to pay on sites, in apps, and in stores using the cards saved to your Google Account. It protects your payment info with multiple layers of security and makes it easy to send money, store tickets, or cash in on rewards – all from one convenient place.


## Connecting Google Pay via Concord Pay Hosted Checkout Page

### To connect, you need: 

 1. Signup in [Concord Pay](https://pay.concord.ua/cabinet/default/signup) and sign a contract with Concord Bank.
 2. Your must adhere to the **[Google Pay APIs Acceptable Use Policy](https://payments.developers.google.com/terms/aup)** and agree to the **[Google Pay Terms of Service](https://payments.developers.google.com/terms/sellertos)**.
### Description

With this connection method, there is no need to carry out any additional integration. The Google Pay button will be displayed on the Concord Pay payment page.

With this connection method, you do not need to perform additional integrations. The Google Pay button will be displayed on Concord Pay payment page. For create Hosted Checkout Page, you can create Invoce from merchant admin panel or use this API: **[Payment on the payment processing page](https://pay.concord.ua/docs/docs/en/dispatcher/#payment-on-the-payment-processing-page)** 

An example of a payment form with the Google Pay method.
![Моя картинка](/docs/img/payment-form-en.png)



## Connection with Google Pay API

### Description

This method is most suitable for customer convenience. It allows you to connect directly, without redirecting to the Concord Pay payment form, and accept payments directly from your site or application.

### How to connect?

* To complete branding requirements 
 - for mobile applications: **[Google Pay Android Brand Guidelines](https://developers.google.com/pay/api/android/guides/brand-guidelines)**, 
 - for websites: **[Google Pay Web Brand Guidelines](https://developers.google.com/pay/api/web/guides/brand-guidelines)**.
* Check compliance integration checklist:
 - for mobile applications: **[Google Pay Android integration checklist](https://developers.google.com/pay/api/android/guides/test-and-deploy/integration-checklist)**.
 - for websites: **[Google Pay Web integration checklist](https://developers.google.com/pay/api/web/guides/test-and-deploy/integration-checklist)**
* Pass the check - send the assembly of the mobile application or a link to the web site with a payment page.

 ### How does it work ? 

![gpayDiagram](/docs/img/gpayDiagram.png)

1. You request the encrypted payment data from your application.
2. Google Pay returns the encrypted data after buyer authentication.
3. You send the encrypted payment data to your server.
4. You send an JSON-request to Concord Pay containing the encrypted data.
5. We send you the payment response
6. You inform the buyer of the outcome

## How to integrate Google Pay?

For integration use **[Google Pay Android developer documentation](https://developers.google.com/pay/api/android/)** or **[Google Pay Web developer documentation](https://developers.google.com/pay/api/web/)**.

## Configuration parameters

1. allowPaymentMethods : CARD
2. tokenizationSpecification = { "type": "PAYMENT_GATEWAY"}
3. allowedCardNetworks = ['MASTERCARD', 'VISA'];
4. allowedCardAuthMethods = ['PAN_ONLY', 'CRYPTOGRAM_3DS'];
5. gateway = concordpay
6. gatewayMerchantId - unique merchant identifier. Issued to each partner when connected to Concord Pay.

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
If the payer confirms the payment, the callback will return the data to the processPayment function, which will need to be sent payment data and encrypted data to the Concord Pay API:

**URL**: https://pay.concord.ua/api/ 
**POST multipart/form-data**

**Request parameters:**

|  **Parameter** | **Description**   |  **Madatory**  |  **Type** |
|---------------|----------------|--------------------|--------------------|
| operation     | Operation type.  Value: **GooglePayPurchase** | Yes            | String |
| merchant_id   | Merchant identifier|  Yes | String |
| amount | Amount. Format: 1.00 |  Yes | Float |
| order_id | Unique operation number on the merchant side. |   Yes | String |
| currency_iso | Currency  **UAH**|   Yes | String |
| description | Description |   Yes | String |
| callback_url | URL for payment result callback data |  Yes | String |
| gpApiVersionMinor | apiVersionMinor form the processPayment(paymentData) |   Yes | Integer |
| gpApiVersion| apiVersion from the processPayment(paymentData)  |  Yes | Integer |
| gpPMDescription| paymentMethodData.description from the processPayment(paymentData) |   Yes | String |
| gpPMType| paymentMethodData.type from the processPayment(paymentData) |   Yes | String |
| gpPMICardNetwork| paymentMethodData.info. cardNetwork from the processPayment(paymentData) |  Yes | String |
| gpPMICardDetails| paymentMethodData.info. cardDetails from the processPayment(paymentData)  |  Yes | String |
| gpTokenType| paymentMethodData. tokenizationData.type from the processPayment(paymentData)  |   Yes | String |
| gpToken| aymentMethodData.tokenizationData.token from the processPayment(paymentData) |   Yes | String |
| signature | HMAC_MD5 signture with merchant **PrivateKey**. Concatenated  parameters **merchant_id,order_id,amount, currency_iso,description** in to string, separated ";" in UTF-8. For example: hmac('md5','merchant_id;order_id;amount;currency_iso;description')|  Yes | String |


**Response parameters:**

| **Parameter** | **Description** |  **Madatory**  |
|---------------|--------------|--------------------|
|    code       | Response code   |   Yes               |
|    status     | Payment status. If status like as "3ds", need to call 3D Secure check | Yes |
| d3AcsUrl | acs url for 3D Secure Check| No |
| d3Md     | Unique message identifier for 3DS host | No |
| d3Pareq  | PaReq message for 3DS host| No |
| transaction_key | Concord Pay transaction key | Yes |


## Check 3DS 
if status like as "3ds", need to call 3D Secure check.

After obtaining of data from Wayforpay system the merchant has to transfer to d3AcsUr  through POST method the parameters d3Pareq и d3Md  in the following form:

```html
<form name="MPIform" action='${d3AcsUrl}' method="POST">
<input type="hidden" name="PaReq" value='${d3Pareq }'>
<input type="hidden" name="MD" value='${d3Md }'>
<input type="hidden" name="TermUrl" value='${TempUrl}'>
</form>
```

**TempUrl** - url transferred by the merchant, to which the issuer will return response after authentication of the client.

## Complete 3DS verification

After passing by the client of authentication and redirecting to TempUrl with a result obtained from the issuer the merchant sends a **Complete3DS** request.

**Request parameters:**

| **Parameter** | **Description** | **Mandatory** |
|----------|----------|-------------|
| operation |  Operation type  **Complete3DS** |  Yes   |
| transaction_key |  Transaction key    |   Yes  |
| merchant_id |  Merchant identifier   |  Yes   |
| d3ds_md |   3ds identifier received after redirect from ACS server|  Yes   |
| d3ds_pares |  Message received after redirect from ACS server   |  Yes   |
| signature |  HMAC_MD5 signture with merchant **PrivateKey**. Concatenated  parameters **merchant_id,transaction_key,d3ds_md,d3ds_pares** in to string, separated ";" in UTF-8. For example: hmac('md5','merchant_id;transaction_key;d3ds_md;d3ds_pares')  |  Yes  |

**Response parameters**

| **Parameter** | **Description** | **Mandatory** |
|----------|----------|-------------|
| status   | Payment status | Yes |
| code     | Response Code | Yes |
| order_id  | Unique order identifier | Yes |
| amount | Amount | Yes |
| fee | Fee | Yes |
| currency | Currency | Yes |
| card_pan | Masked card number | Yes |
| transaction_id | Transaction identifier | Yes |





## Links

* [Demo](https://developers.google.com/pay/api/web/guides/resources/demos)
* [Google Pay Logo](/docs/logo-googlepay.png)
* [API Google Pay](https://developers.google.com/pay/api/)
* [Google Pay Terms and Conditions.](https://payments.developers.google.com/terms/sellertos)