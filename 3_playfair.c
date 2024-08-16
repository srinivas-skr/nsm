#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 5

void prepareKey(char *key, char *preparedKey) {
    int used[26] = {0};
    char *ptr = preparedKey;
    for (int i = 0; key[i]; i++) {
        if (key[i] == 'j') key[i] = 'i';
        if (isalpha(key[i]) && !used[key[i] - 'a'])
        {
            used[key[i] - 'a'] = 1;
            *ptr++ = key[i];
        }
    } 
    for (char c = 'a'; c <= 'z'; c++) {
        if (c == 'j') continue;
        if (!used[c - 'a']) *ptr++ = c;
    }
    *ptr = '\0';
}

void generateTable(char *preparedKey, char table[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            table[i][j] = preparedKey[i * SIZE + j];
        }
    }
}


void findPosition(char table[SIZE][SIZE], char c, int *row, int *col) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (table[i][j] == c) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}


void encryptPair(char table[SIZE][SIZE], char a, char b) {
    int rowA, colA, rowB, colB;
    findPosition(table, a, &rowA, &colA);
    findPosition(table, b, &rowB, &colB);
    if (rowA == rowB) {
        printf("%c%c", table[rowA][(colA + 1) % SIZE], table[rowB][(colB + 1) % SIZE]);
    } else if (colA == colB) {
        printf("%c%c", table[(rowA + 1) % SIZE][colA], table[(rowB + 1) % SIZE][colB]);
    } else {
        printf("%c%c", table[rowA][colB], table[rowB][colA]);
    }
}

void encrypt(char *message, char table[SIZE][SIZE]) {
    char cleanMessage[100];
    int j = 0;
    for (int i = 0; message[i]; i++) {
        if (message[i] == 'j') message[i] = 'i';
        if (isalpha(message[i])) cleanMessage[j++] = message[i];
    }
    if (j % 2 != 0) cleanMessage[j++] = 'x';
    for (int i = 0; i < j; i += 2) {
        encryptPair(table, cleanMessage[i], cleanMessage[i + 1]);
    }
    printf("\n");
}

int main() {
    char key[100], preparedKey[26];
    char message[1000];
    char table[SIZE][SIZE];

    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    
    printf("Enter the message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    prepareKey(key, preparedKey);
    generateTable(preparedKey, table);
    
    printf("Encrypted message: ");
    encrypt(message, table);
    return 0;
}
