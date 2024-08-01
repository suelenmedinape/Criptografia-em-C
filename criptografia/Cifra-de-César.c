#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* cifra(char* frase, int desloc){
    desloc = desloc % 26;

    for (int i = 0; i < strlen(frase); i++) {
        if (isalpha(frase[i])) {
            char base = islower(frase[i]) ? 'a' : 'A';
            frase[i] = base + (frase[i] - base + desloc) % 26;
        }
    }
    return frase;
}

int main(){
    char frase[100];
    int desloc;

    printf("Mensagem a ser criptografada:\n");
    fgets(frase, sizeof(frase), stdin);

    size_t len = strlen(frase);
    if (len > 0 && frase[len-1] == '\n') {
        frase[len-1] = '\0';
    }

    printf("Informe o deslocamento: ");
    scanf("%d", &desloc);

    char* retcifra = cifra(frase, desloc);
    printf("%s\n", retcifra);

    return 0;
}
