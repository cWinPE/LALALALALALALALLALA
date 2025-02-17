---
id: version-1.0.0-dictionary
title: Dictionary
original_id: dictionary
---

## Directory. Payment Statuses

| Value     | Status                                   |
|--------------|------------------------------------------|
| ON-PAYMENT   | Payment is being executed                       |
| NEW          | Payment created, details expected |
| APPROVED     | Payment successful                           |
| DECLINED     | Payment declined                          |
| REFUNDINPROC | In return process                      |
| REFUNDED     | Returned                                |
| EXPIRED      | Payment is past due                         |
| WAITING-AUTH | Awaiting authorization confirmation        |
| 3ds          | Requires verification 3D-Secure               |

## Directory. Answer Codes

| Code  | Decryption                                                                                                                                                  | Расшифровка (ENG)                                                       |
|------|--------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------|
| 1    | OPERATION PERMITTED                                                                                                                                           |                                                                         |
| 50   | Financial Transaction Failed                                                                                                                          | General                                                                 |
| 51   | Customer card expired                                                                                                                                     | Expired card                                                            |
| 52   | PIN attempts exceeded                                                                                                                           | Number of PIN tries exceeded                                            |
| 53   | Failed to route transaction                                                                                                                       | No sharing allowed                                                      |
| 55   | The transaction has invalid attributes or this operation is not allowed.                                                                                      | Invalid transaction                                                     |
| 56   | The requested operation is not supported by the host                                                                                                              | Transaction not supported by institution                                |
| 57   | Client card has the status of 'lost' or 'stolen'                                                                                                         | Lost or stolen card                                                     |
| 58   | Customer card has an invalid status                                                                                                                     | Invalid card status                                                     |
| 59   | Customer card has limited features                                                                                                                | Restricted status                                                       |
| 60   | The vendor with the specified account number was not found                                                                                                                  | Account not found                                                       |
| 61   | Invalid number of information fields for the given vendor                                                                                               | Wrong customer information for payment                                  |
| 62   | Invalid payment information field format                                                                                                                 | Customer information format error                                       |
| 63   | No prepaid code found                                                                                                                                        | Prepaid Code not found                                                  |
| 64   | Track2 client card contains incorrect information                                                                                                          | Bad track information Track2                                            |
| 69   | Invalid message format                                                                                                                                    | Bad message edit                                                        |
| 74   | Unable to authorize                                                                                                                                      | Unable to authorize                                                     |
| 75   | Invalid PAN Card                                                                                                                                           | Invalid credit PAN                                                      |
| 76   | There are not enough funds in the account                                                                                                                                  | Insufficient funds                                                      |
| 78   | Transaction Duplicate                                                                                                                            | Duplicate transaction received                                          |
| 82   | Exceeding the number of uses of a customer card                                                                                                           | Maximum number of times used                                            |
| 85   | Unable to issue balance                                                                                                                                     | Balance not allowed                                                     |
| 95   | Exceeding the limit for the amount                                                                                                                                  | Amount over maximum                                                     |
| 100  | Unable to complete transaction                                                                                                                               | Unable to process                                                       |
| 101  | Unable to authorize - must call the card publisher                                                                                                | Unable to authorize – call issuer                                       |
| 105  | This type of card is not supported.                                                                                                                            | Card not supported                                                      |
| 200  | Invalid customer account                                                                                                                                    | Invalid account                                                         |
| 201  | Incorrect PIN                                                                                                                                             | Incorrect PIN                                                           |
| 205  | Invalid amount                                                                                                                                           | Invalid advance amount                                                  |
| 209  | Invalid Transaction Code                                                                                                                                      | Invalid transaction code                                                |
| 210  | Invalid CAVV value                                                                                                                                      | Bad CAVV                                                                |
| 211  | Invalid CVV2 value                                                                                                                                       | Bad Cvv2                                                                |
| 212  | The original transaction for the slip was not found                                                                                                                 | Original transaction not found for slip                                 |
| 213  | Slip is accepted again                                                                                                                                    | Slip already received                                                   |
| 501  | Transaction completed successfully                                                                                                                                 | Approved                                                                |
| 502  | Partial transaction completed successfully                                                                                                              | Partially approved                                                      |
| 503  | Transaction completed successfully only for the purchase amount (for transaction 118 – Purchase with Cashback)                                                           | Purchase only approved                                                  |
| 510  | There is no account number in the transaction request, there are several accounts of the specified type, and the terminal supports account selection                                           | Should select account number                                            |
| 511  | PVV must be changed (only transaction allowed PIN Change)                                                                                              | Should change PVV                                                       |
| 512  | It is necessary to confirm the results of payment verification in the online payment acceptance system                                                                          | Confirm Payment Precheck                                                |
| 513  | Notification List Request Transaction Successful                                                                                                      | Select Bill                                                             |
| 514  | It is necessary to confirm the results of the pre-check operation                                                                                                      | Customer confirmation requested                                         |
| 515  | Original transaction not found.                                                                                                                           | Original transaction not found                                          |
| 516  | Slip already accepted                                                                                                                                              | Slip already received                                                   |
| 517  | Error in payment details                                                                                                                                  | Personal information input error                                        |
| 520  | Unable to capture Prepaid code                                                                                                                             | Prepaid code not found                                                  |
| 521  | Balance Corr. bills exhausted                                                                                                                                  | Corresponding account exhausted                                         |
| 522  | Acquiring limit exceeded                                                                                                                                 | Acquirer limit exceeded                                                 |
| 524  | Diamic PVV Expired                                                                                                                         | Dynamic PVV Expired                                                     |
| 525  | Weak PIN                                                                                                                                                  | Weak PIN                                                                |
| 540  | Card lost                                                                                                                                               | Lost card                                                               |
| 541  | Card stolen                                                                                                                                               | Stolen card                                                             |
| 549  | Invalid payment type for this vendor                                                                                                                 | Ineligible vendor account                                               |
| 550  | unauthorized use                                                                                                                         | Unauthorized usage                                                      |
| 551  | Card expired                                                                                                                                   | Expired card                                                            |
| 552  | Invalid Card                                                                                                                                               | Invalid card                                                            |
| 553  | Invalid PIN                                                                                                                                            | Invalid PIN                                                             |
| 554  | System error                                                                                                                                         | System error                                                            |
| 555  | Inappropriate transaction                                                                                                                                      | Ineligible transaction                                                  |
| 556  | Inappropriate account                                                                                                                                            | Ineligible account                                                      |
| 557  | Transaction not supported                                                                                                                                | Transaction not supported                                               |
| 558  | Card limited (this card operation is not allowed)                                                                                                     | Restricted Card                                                         |
| 559  | Not enough funds in the account                                                                                                                                | Insufficient funds                                                      |
| 560  | Card usage limit exceeded                                                                                                                  | Uses limit exceeded                                                     |
| 561  | Cash withdrawal limit will be exceeded                                                                                                                     | Withdrawal limit would be exceeded                                      |
| 562  | The limit on the number of incorrect PIN entries has been reached or exceeded                                                                                              | PIN tries limit was reached                                             |
| 563  | Cash withdrawal limit reached                                                                                                                          | Withdrawal limit already reached                                        |
| 564  | Deposit limit reached                                                                                                                                   | Credit amount limit                                                     |
| 565  | No account reporting information available                                                                                                            | No statement information                                                |
| 566  | Reporting is not possible (prohibited)                                                                                                        | Statement not available                                                 |
| 567  | Invalid amount                                                                                                                                           | Invalid amount                                                          |
| 568  | Transaction rejected by external host                                                                                                                        | External decline                                                        |
| 569  | Inconsistent request (this card is not served in this terminal)                                                                                    | No sharing                                                              |
| 571  | Contact publisher                                                                                                                             | Contact card issuer                                                     |
| 572  | Authorizer unavailable                                                                                                                                       | Destination not available                                               |
| 573  | Routing error                                                                                                                                         | Routing error                                                           |
| 574  | Format error                                                                                                                                               | Format error                                                            |
| 575  | The transaction was rejected by the external host on a special condition (the cardholder is suspected of fraud)                                                  | External decline special condition                                      |
| 580  | Invalid CVV                                                                                                                                                 | Bad CVV                                                                 |
| 581  | Invalid CVV2                                                                                                                                                | Bad CVV2                                                                |
| 582  | Invalid transaction (transaction is not allowed with these conditions)                                                                                  | Invalid transaction                                                     |
| 583  | The limit on the number of incorrect PIN entries has ALREADY been reached (i.e., the limit on the number of incorrect PIN entries was reached earlier, after which the correct PIN was entered)| PIN tries limit was exceeded                                            |
| 584  | Invalid check value 3D Secure Cardholder Authentication Verification Value                                                                  | Bad CAVV                                                                |
| 585  | Invalid ARQC cryptogram value                                                                                                                         | Bad ARQC                                                                |
| 800  | Format error                                                                                                                                              | Format error                                                            |
| 801  | No original reverse transaction found                                                                                                               | Original transaction not found                                          |
| 809  | Invalid Period Closing Operation                                                                                                                           | Invalid close transaction                                               |
| 810  | Timeout occurred                                                                                                                                           | Transaction timeout                                                     |
| 811  | System error                                                                                                                                             | System error                                                            |
| 820  | Invalid terminal id                                                                                                                         | Invalid terminal identifier                                             |
| 880  | The last packet was sent - loading completed successfully                                                                                                     | Download has been received in its entirety                              |
| 881  | The previous loading step was successfully completed - there is more data                                                                                          | Download received successfully and there is more data for this download |
| 882  | Terminal loading stopped. It is necessary to call the processing center                                                                                | Download aborted (call for service)                                     |
| 897  | Received invalid cryptogram in transaction                                                                                                                  | Invalid cryptogram                                                      |
| 898  | Invalid MAC Received                                                                                                                                         | Invalid MAC                                                             |
| 899  | Sync error                                                                                                                                         | Sequence error—resync                                                   |
| 900  | PIN attempts exceeded. Card capture required                                                                                                   | Pin Tries Limit Exceeded                                                |
| 901  | Card expired, card capture required                                                                                                                     | Expired Card                                                            |
| 909  | Card capture required                                                                                                                                       | External Decline Special Condition                                      |
| 959  | Administrative transaction not supported                                                                                                                | Administrative transaction not supported                                |
| 2001 | 3DS Verification required                                                                                                                                  | Need 3ds verify                                                         |
| 2002 | 3DS 2.0 Verification required                                                                                                                                  | Need 3ds verify                                                         |

## Directory. System Error Codes

| Code  | Decryption                               | 
|------|-------------------------------------------|
| -1   | System error                         | 
| -2   | Parameter not passed merchant_id           | 
| -3   | Merchant not found                        | 
| -4   | Invalid Signature                      | 
| -5   |Operation limit              | 
| -6   |Invalid card number                      | 
| -7   | Invalid currency                          | 
| -8   | Incorrect  order_id                        | 
| -9   |Operation with such order_id  already exists | 
| -10  | Payment not found                        |
| -11  | Invalid operation type                     | 
| -999 | System error                          |

## Directory. List of additional fields to identify sender and recipient of transfers
Additional fields are passed in the request in the add_params parameter

| Parameter name | Decryption        | 
|---------------|-------------|
| add_params[SenderName] | Sender name. Indicated in Latin letters in uppercase in the format: First name <space> Last name |
| add_params[1ResidentCityInLatin] | The sender's city of residence. Latin letters in uppercase  |
| add_params[1ResidentCountry] | ISO 3166-1 Numeric country code of the sender's residence (for example: 804) |
| add_params[1Address] | Sender's address in Latin letters | 
| add_params[RecipientName] | The name of the recipient in Latin letters in the format: First name <space> Last name | 
| add_params[IdentityNumber] | Identification document number | 



