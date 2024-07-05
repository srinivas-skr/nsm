#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

#define MAX_SIZE 10

int determinant(int a, int b, int c, int d){
    return (a * d - b * c);
}

int moduloInverse(int a, int m){
    int i;
    for(i = 1; i < m; i++){
        if((a * i) % m == 1){
            return i;
        }
    }
}

void encrypt(char message[], int keyMatrix[][MAX_SIZE], int keySize){
    int messageLength = strlen(message);
    int paddedLength = (int) ceil(messageLength/(float)keySize) * keySize;
    int paddedMessage[paddedLength];
    int encrypted[paddedLength];
    int i, j, k, sum;
    
    for(i = 0; i < messageLength; i++){
        paddedMessage[i] = message[i] - 'A';
    }
    
    for(; i < paddedLength; i++){
        paddedMessage[i] = 23; //'X' - 'A' = 23
    }
    
    for(i = 0; i < paddedLength; i += keySize){
        for(j = 0; j < keySize; j++){
            sum = 0;
            for(k = 0; k < keySize; k++){
                sum += keyMatrix[j][k] * paddedMessage[i + k];
            }
            encrypted[i + j] = sum % 26;
        }
    }
    
    printf("Encrypted message: ");
    for(i = 0; i< paddedLength; i++){
        printf("%c", (char) (encrypted[i] + 'A'));
    }
    printf("\n");
}





int main(){
    int keySize, keyMatrix[MAX_SIZE][MAX_SIZE], i, j;
    char message[1000];
    
    printf("Enter the size of the key matrix (max 10): ");
    scanf("%d", &keySize);

    printf("Enter the elements of the key matrix:\n");
    for (i = 0; i < keySize; i++) {
        for (j = 0; j < keySize; j++) {
            scanf("%d", &keyMatrix[i][j]);
        }
    }
    
    if (determinant(keyMatrix[0][0], keyMatrix[0][1], keyMatrix[1][0], keyMatrix[1][1]) == 0) {
        printf("The key matrix is not invertible. Please enter a valid key matrix.\n");
        return 1;
    }

    printf("Enter the message to be encrypted (uppercase letters only): ");
    scanf("%s", message);

    encrypt(message, keyMatrix, keySize);
    return 0;
}



///HILL CIPHER PROGRAM 

Save file  hill.c

gcc -o hill hill.c -lm

./hill///
