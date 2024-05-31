#include <stdio.h>
#include <ctype.h>
#include <string.h>

void transform(char *msg, const char *key, int mode) {
    int key_len = strlen(key);
    
    for(int i =0 ,j =0 ; msg[i];i++){
        if(isalpha(msg[i])){
            char offset = isupper(msg[i]) ?'A':'a';
            msg[i] = ((msg[i]-offset) + (mode? key[j%key_len] - offset : 'A'- key[j%key_len] + offset )) %26 + offset;
            j++;
        }
    }
}

int main() {
    char msg[] = "wearediscoveredsaveyourself";
    char key[256];

    printf("Enter a key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';  // Remove newline character

    printf("Original: %s\n", msg);

    transform(msg, key, 1);  // Encrypt
    printf("Encrypted: %s\n", msg);

    transform(msg, key, 0);  // Decrypt
    printf("Decrypted: %s\n", msg);

    return 0;
}
