#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char frase[100];
    printf("Informe a frase: ");
    fgets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = '\0';
    
    int tamanho = strlen(frase);
    char string1[100] = {0};
    char string2[100] = {0};
    char criptografada[100] = {0};
    char descriptografada[100] = {0};
    
    int j = 0, k = 0;
    
    printf("\n");
    printf("Mensagem Original: %s",frase);
    printf("\n");
    
    for (int i = 0; i < tamanho; i++) {
        if (isalpha(frase[i])) {
            if (j % 2 == 0) {
                string1[j/2] = toupper(frase[i]);
            } else {
                string2[k/2] = toupper(frase[i]);
            }
            j++;
            k++;
        }
    }
    
    int idx1 = 0, idx2 = 0;
    for (int i = 0; i < tamanho; i++) {
        if (frase[i] == ' ') {
            criptografada[i] = ' ';
        } else {
            if (idx1 < j/2) {
                criptografada[i] = string1[idx1++];
            } else if (idx2 < k/2) {
                criptografada[i] = string2[idx2++];
            }
        }
    }
    printf("\n");
    printf("String 1: %s", string1);
    printf("\n");
    printf("String 2: %s", string2);
    printf("\n");
    printf("\n");
    printf("Mensagem criptografada: %s\n", criptografada);
    printf("\n");
    
    j = 0, k = 0;
    for (int i = 0; i < tamanho; i++) {
        if (isalpha(frase[i])) {
            if (j % 2 == 0) {
                descriptografada[i] = toupper(string1[j/2]);
            } else {
                descriptografada[i] = toupper(string2[k/2]);
            }
            j++;
            k++;
        }
    }
    
    for (int i = 0; i < tamanho; i++) {
        if (descriptografada[i] == '\0') {
            descriptografada[i] = ' ';
        } else {
            if (idx1 < j/2) {
                descriptografada[i] = string1[idx1++];
            } else if (idx2 < k/2) {
                descriptografada[i] = string2[idx2++];
            }
        }
    }
    
    printf("String 1: %s", string1);
    printf("\n");
    printf("String 2: %s", string2);
    printf("\n");
    printf("\n");
    printf("Mensagem Descriptografada: %s",descriptografada);
    
    return 0;
}
