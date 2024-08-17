# Cryptography and Network Security Programs
## Execution

All Programs Run Successfully only on UBUNTU

## Overview

This repository contains C programs implementing various cryptographic algorithms and network security protocols. The programs are designed to demonstrate encryption and decryption techniques for secure communication.

## Course Content

### 1. Caesar Cipher

**Program Name:** `caesar_cipher.c`

**Description:** Implements the Caesar Cipher algorithm for encryption and decryption. This program shifts each letter in the plaintext by a fixed number of places down or up the alphabet. It provides functionality to encrypt and decrypt a sample message 'hello how are u' to ensure confidentiality.

### 2. Monoalphabetic Cipher

**Program Name:** `monoalphabetic_cipher.c`

**Description:** Implements the Monoalphabetic Cipher, a substitution cipher where each letter in the plaintext is replaced with a letter in the ciphertext using a fixed key. The program encrypts the plaintext 'THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG' with the key 'QWERTYUIOPASDFGHJKLZXCVBNM' and decrypts the ciphertext 'QWE R TUIK BRGOS FXJVN TWHUZ SDG' using the same key.

### 3. Playfair Cipher

**Program Name:** `playfair_cipher.c`

**Description:** Implements the Playfair Cipher algorithm. This encryption method operates on digraphs (pairs of letters) and uses a 5x5 matrix to encrypt and decrypt messages. Users provide a key and a message, and the program performs the encryption and decryption processes accordingly.

### 4. Hill Cipher

**Program Name:** `hill_cipher.c`

**Description:** Implements the Hill Cipher algorithm, which uses linear algebra to encrypt and decrypt messages. Users input a matrix key and a message, and the program applies matrix multiplication to perform encryption and decryption.

### 5. Polyalphabetic Cipher

**Program Name:** `polyalphabetic_cipher.c`

**Description:** Implements the Polyalphabetic Cipher algorithm, which uses multiple substitution alphabets to encrypt and decrypt messages. This program employs the key 'deceptive' and the plaintext 'wearediscoveredsaveyourself' to demonstrate its encryption and decryption capabilities.

### 6. RSA Algorithm

**Program Name:** `rsa_cipher.c`

**Description:** Implements the RSA algorithm for asymmetric encryption and decryption. This program allows User A to encrypt a message, which can then be decrypted by User B. RSA is widely used for secure data transmission.

### 7. Diffie-Hellman Key Exchange

**Program Name:** `diffie_hellman_key_exchange.c`

**Description:** Implements the Diffie-Hellman Key Exchange algorithm, a method for securely exchanging cryptographic keys over a public channel. This program sets up a secure channel between a client and server by establishing a shared secret key.

### 8. AES Algorithm

**Program Name:** `aes_cipher.c`

**Description:** Implements the Advanced Encryption Standard (AES) algorithm for encrypting and decrypting messages. The program encrypts the message “welcome to ISE” and then decrypts it, demonstrating AES's capability to provide robust encryption.

## Getting Started

To get started with these programs, follow these steps:

1. **Clone the repository:**
   ```bash
   git clone https://github.com/yourusername/cryptography-network-security.git

Contributing
Contributions are welcome! If you have suggestions or improvements, please fork the repository and submit a pull request.

License
This project is licensed under the MIT License - see the LICENSE file for details.
