#include <stdio.h>

void caesar(char text[], int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z')
            text[i] = 'a' + (text[i] - 'a' + shift) % 26;
        else if (text[i] >= 'A' && text[i] <= 'Z')
            text[i] = 'A' + (text[i] - 'A' + shift) % 26;
    }
}

int main() {
    char text[100];
    int shift;
    
    printf("Enter message: ");
    fgets(text, sizeof(text), stdin);
    printf("Enter shift: ");
    scanf("%d", &shift);

    // Encrypt the message
    caesar(text, shift);
    printf("Encrypted message: %s\n", text);

    // Decrypt the message
    caesar(text, -shift);
    printf("Decrypted message: %s\n", text);
    return 0;
}
