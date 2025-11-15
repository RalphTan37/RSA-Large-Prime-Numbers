# RSA-Large-Prime-Numbers
Implementing RSA Using Large Prime Numbers - CSCI 4870/5780 (Applied Cryptography)

## Operating System - Windows 10
### Step 1: Follow this URL
```
https://slproweb.com/products/Win32OpenSSL.html
```

### Step 2: Go to the 'Download Win32/Win64 OpenSSL' Section
### Step 3: Download Win64 OpenSSL v3.6.0 EXE
### Step 4: Run the EXE and Install OpenSSL
### Step 5: Verify Installation
#### Ensure OpenSSL is in Environment Variables, if not:
#### (1) Launch System Properties Application
#### (2) Under Advanced Section, click on 'Environment Variables...' 
#### (3) Click on the 'Path' Variable and then click on 'Edit...'
#### (4) In the popped up 'Edit environment variable' modal, click on 'New'
#### (5) Enter the path for OpenSSL
#### The path is usually,
```
C:\Program Files\OpenSSL-Win64\bin
```
#### (6) Select 'Ok' for all modal windows
#### Open the Command Prompt
#### Enter:
```
openssl version
```
#### You should see as an output:
```
OpenSSL 3.1.0 14 Mar 2023 (Library: OpenSSL 3.1.0 14 Mar 2023)
```

## Compile the Program
```
g++ rsa.cpp -o rsa -lcrypto -lssl
```

## Run the Program
```
.\rsa.exe
```
## Example Expected Output
```
n = BF58737C1EB6BB83D20A3EA5F6B883F9F05101FACB7BBF131E868201B1C429213212F03A4D58B7AB0789CAB8B468A5EB43974653B07C5C132D4BE0C9243C3E10C4EF9A3679404CF07329497A27BB5DA4D66F80DBA8A2F5E2E1A724150EAF1702856F3BD90C619632FD6149349036EB7D119B335B07F518EB9B766AE45F7E48D9
e = 010001
d = 6E9EB4250D9C96CB9EA24D95A50D073F77AF5D75A02DEA49235C9FCC5AF90CCE2424CEBCE5FA64347C272D0B9B40E4AB1E6856400BC7D9733CBCA137A7BB2C25852375AA874082DBF35E0E4F9CE514296E58853927CC95F6E5FE8A4072C207DDA72C17F3B67CD3BB2265C217A73840C5BD32D7472E34D267B54734252A59D001
Encrypted c = 85B06CB1D188D05BE5856B46CE9C7DC3FE26DEA5CED323BAE0CCE938C80B5A1A2B32A8C210264F8ACE23744EEDB84EFA5E27DAC5D88227665F8815F60DA2B7EB2058FECD530C45EC10FE7F3B8AB314628B5F474C684065F542DCB6117FFC24458FCA7A041A0301CD24B40B4EB8484DF43DE07FD1C853C377B7623CEC8F21695A
Decrypted m = 01E240
```
* n is the hex-encoded modulus of the product of p and q, two large primes. It is part of both the public and private keys.
* e is the hex-encoded public exponent (65537 - most common RSA public exponent).
* d is the hex-encoded private exponent, the heart of the private key.
* Encrypted c is the ciphertext that is the same size as the modulus n and will be different every time.
* Decrypted m is the hex-encoded original message recovered. (0 < m < n). For this example, I set my original message as 12345. </br>
m = 01E240 (hexadecimal) = 12345 (decimal)

## Implementation Explanation
The RSA program performs four major tasks: generating RSA keys (n, e, d), defining a message m (as a BIGNUM), encrypting the message (computing c = m^e mod n), and decrypting it (computing m = c^d mod n). The program uses the OpenSSL library to provide support for large integers, prime generation, secure randomness, and efficient modular arithmetic. A BIGNUM context is created to allow OpenSSL to perform big-number operations. OpenSSL then generates two large prime numbers, p and q, which are used to compute the RSA modulus n and keys e and d. The values of n, e, and d are printed in hexadecimal format. A message m is initialized as the plaintext value to be encrypted. The program encrypts m and prints the resulting ciphertext c. Finally, the decryption function processes c and successfully recovers the original message m.