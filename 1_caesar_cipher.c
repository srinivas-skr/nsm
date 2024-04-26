#include <stdio.h>

void caesar(char text[], int shift) {
    // Loop through each character in the text array until the null terminator is reached
    for (int i = 0; text[i] != '\0'; i++) {
        // Encrypt lowercase letters
        if (text[i] >= 'a' && text[i] <= 'z')
            // Apply Caesar cipher to lowercase letters
            text[i] = 'a' + (text[i] - 'a' + shift) % 26;
        // Encrypt uppercase letters
        else if (text[i] >= 'A' && text[i] <= 'Z')
            // Apply Caesar cipher to uppercase letters
            text[i] = 'A' + (text[i] - 'A' + shift) % 26;
    }
}

int main() {
    // Define the message to be encrypted
    char message[] = "hllo how are u";
    // Define the encryption/decryption key
    int key = 3;

    // Print the original message
    printf("Original message: %s\n", message);

    // Encryption: Apply the Caesar cipher with the specified key
    caesar(message, key);
    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decryption: Apply the inverse Caesar cipher (negative key) to decrypt the message
    caesar(message, -key);
    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}
