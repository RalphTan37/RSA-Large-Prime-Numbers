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