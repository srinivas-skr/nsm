#include <stdio.h>

void encrypt(char text[], char key[]) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            printf("%c", key[text[i] - 'A']);
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            printf("%c", key[text[i] - 'a']);
        } else {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}

void decrypt(char ciphertext[], char key[]) {
    int i, j;
    for (i = 0; ciphertext[i] != '\0'; i++) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            for (j = 0; key[j] != '\0'; j++) {
                if (ciphertext[i] == key[j]) {
                    printf("%c", 'A' + j);
                    break;
                }
            }
        } else if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            for (j = 0; key[j] != '\0'; j++) {
                if (ciphertext[i] == key[j] + 'a' - 'A') {
                    printf("%c", 'a' + j);
                    break;
                }
            }
        } else {
            printf("%c", ciphertext[i]);
        }
    }
    printf("\n");
}

int main() {
    char text[] = "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG";
    char key[] = "QWERTYUIOPASDFGHJKLZXCVBNM";

    printf("Text: %s\n", text);
    printf("Encrypted: ");
    encrypt(text, key);

    char ciphertext[] = "ZIT JXOEA WKGVF YGB PXDHL GCTK ZIT SQMN RGU";
    printf("Ciphertext: %s\n", ciphertext);
    printf("Decrypted: ");
    decrypt(ciphertext, key);
    return 0;
}
