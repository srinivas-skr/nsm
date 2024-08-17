#include<stdio.h>
#include<ctype.h>
#include<string.h>

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
    char plaintext[100];
    char key[30];
    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter key (26 uppercase letters): ");
    fgets(key, sizeof(key), stdin);

    char ciphertext[strlen(plaintext) + 1];   // Encryption
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) 
    {
        ciphertext[i] = encrypt(plaintext[i], key);
    }
    ciphertext[i] = '\0'; // Null terminate 
    printf("Ciphertext: %s\n", ciphertext);

    char decrypted_text[strlen(ciphertext) + 1];  // Decryption
    for (i = 0; ciphertext[i] != '\0'; i++) 
    {
    decrypted_text[i] = decrypt(ciphertext[i], key);
    }
    decrypted_text[i] = '\0'; // Null terminate 
    printf("Decrypted Text: %s\n", decrypted_text);
    return 0;
}

/* OUTPUT 
plaintext - THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG
key -QWERTYUIOPASDFGHJKLZXCVBNM
*/

/* Input for ciphertext to decrypt
    printf("Enter ciphertext to decrypt: ");
    fgets(ciphertext, sizeof(ciphertext), stdin); */
