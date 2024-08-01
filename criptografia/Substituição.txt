/*Suelen Medina
Esse codigo foi escrito em C*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* criptografando(char* frase, char* chave){
    int i;
    
    for (i = 0; frase[i] != '\0'; i++) {
        
        if (isalpha(frase[i])) {
            char letra = tolower(frase[i]);
            int posicao = letra - 'a';
            frase[i] = chave[posicao];
        }
    }
    return frase;
}

int main()
{
    char frase[100];
    //char frase[] = "Encontre-me a meia-noite";
    char chave[] = "VHMXUWIBGKJRCSQYOLNZEAFDPT";
    
    printf("Mensagem a ser criptografada:\n");
    fgets(frase, sizeof(frase), stdin);
    printf("\n");
    
    char* frasecripto = criptografando(frase, chave);
    printf("%s\n", frasecripto);
    
    return 0;
}



