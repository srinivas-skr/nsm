#include <stdio.h>
#include <string.h>

void encrypt(char msg[], int keyMatrix[10][10], int size)
{
    int msgLen = strlen(msg);
    int i, j, k;

    for (k = 0; k < msgLen; k += size) {
        int paddedMsg[10] = {0};  // Fixed-size array for the message block
        int encryptedMsg[10] = {0};  // Fixed-size array for the encrypted message

        // Pad with 'X' if the last block is shorter than 'size'
        for (i = 0; i < size; i++) {
            paddedMsg[i] = (k + i < msgLen) ? msg[k + i] - 'A' : 'X' - 'A';
        }

        // Encryption: Multiply the key matrix with the message vector
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {
                encryptedMsg[i] += keyMatrix[i][j] * paddedMsg[j];
            }
            encryptedMsg[i] = encryptedMsg[i] % 26;  // Modulo 26 to stay within 'A' to 'Z'
        }
        
        // Convert back to characters and print the encrypted message
        for (i = 0; i < size; i++) {
            printf("%c", encryptedMsg[i] + 'A');
        }
    }
    printf("\n");
}

int main() {
    int size, i, j;
    printf("Enter the size of the key matrix (max 10): ");
    scanf("%d", &size);

    int keyMatrix[10][10];  // Fixed-size key matrix
    printf("Enter the elements of the key matrix:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            scanf("%d", &keyMatrix[i][j]);
        }
    }
    
    char msg[100];  // Assuming the message won't exceed 100 characters
    printf("Enter the message to be encrypted (uppercase letters only): ");
    scanf("%s", msg);
    encrypt(msg, keyMatrix, size);
    return 0;
}
/* OUTPUT
Enter the size of the key matrix (max 10): 2
Enter the elements of the key matrix:
1 2
3 4
Enter the message to be encrypted (uppercase letters only): HELLO
Encrypted message: PLHZIE 
*/
