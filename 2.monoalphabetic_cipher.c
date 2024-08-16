#include <stdio.h>
#include <ctype.h>
#include <string.h>

char encrypt(char ch, char *key) 
{
    if (isalpha(ch)) 
    {
        int index = toupper(ch) - 'A';
        return key[index];
    }
    return ch; // Non-alphabetic characters remain unchanged
}

char decrypt(char ch, char *key) 
{
    int i;
    for (i = 0; i < 26; i++) 
    {
        if (key[i] == ch) 
        {
            return 'A' + i;
        }
    }
    return ch; // Non-alphabetic characters remain unchanged
}

int main() 
{
    char text[100];
    char key[30];

    // Input for text
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    // Input for key
    printf("Enter key (26 uppercase letters): ");
    fgets(key, sizeof(key), stdin);

    // Encryption
    char ciphertext[strlen(text) + 1];
    int i;
    for (i = 0; text[i] != '\0'; i++) 
    {
        ciphertext[i] = encrypt(text[i], key);
    }
    ciphertext[i] = '\0'; // Null terminate the ciphertext string
    printf("Ciphertext: %s\n", ciphertext);

    // Input for ciphertext to decrypt
    printf("Enter ciphertext to decrypt: ");
    fgets(ciphertext, sizeof(ciphertext), stdin);

    // Decryption
    char decrypted_text[strlen(ciphertext) + 1];
    for (i = 0; ciphertext[i] != '\0'; i++) 
    {
        decrypted_text[i] = decrypt(ciphertext[i], key);
    }
    decrypted_text[i] = '\0'; // Null terminate the decrypted text string
    printf("Decrypted Text: %s\n", decrypted_text);
    return 0;
}
