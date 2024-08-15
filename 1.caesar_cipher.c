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
    char message[100];
    int shift;

    // Input message and shift from the user
    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter shift: ");
    scanf("%d", &shift);

    // Encrypt the message
    caesar(message, shift);
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    caesar(message, -shift);
    printf("Decrypted message: %s\n", message);
    return 0;
}
