#include <stdio.h>

void encrypt(char plaintext[], char key[]) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            printf("%c", key[plaintext[i] - 'A']);
        } else if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            printf("%c", key[plaintext[i] - 'a']);
        } else {
            printf("%c", plaintext[i]);
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
    char plaintext[] = "THE WUICK BROWN FOX JUMPS OVER THE LAZY DOG";
    char key[] = "QWERTYUIOPASDFGHJKLZXCVBNM";

    printf("Plaintext: %s\n", plaintext);
    printf("Encrypted: ");
    encrypt(plaintext, key);

    char ciphertext[] = "ZIT JXOEA WKGVF YGB PXDHL GCTK ZIT SQMN RGU";
    printf("Ciphertext: %s\n", ciphertext);
    printf("Decrypted: ");
    decrypt(ciphertext, key);
    return 0;
}
