//SHIFT CIPHER DECRYPTION (BRUTE FORCE).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void decrypt(char *ciphertext) {
    char temp[10000];

    for(int i =1; i <= 26; i++) {
        strcpy(temp, ciphertext);

        int j = 0;
        while(ciphertext[j] != '\0') {

            char ch = ciphertext[j];

            if(isupper(ch)) {
                ch = (ch - 'A' - i + 26) % 26 + 'A';
            }

            else if(islower(ch)) {
                ch = (ch - 'a' - i + 26) % 26 + 'a';
            }

            ciphertext[j] = ch;

            j++;
        }
        printf("\nPossibility %d:\n %s", i, temp);
    }
}

int main(void) {

    char ciphertext[10000];
    printf("\nEnter your ciphertext below: ");
    scanf(" %[^\n]s", ciphertext);

    printf("Possible decryptions are as follows:\n");
    decrypt(ciphertext);

    return EXIT_SUCCESS;
}