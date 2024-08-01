#include <stdio.h>
#include <string.h>
#include <ctype.h> // Para a função isalpha

#define N 26

char * remove_espacos( char * out, const char * in ){
    const char * p = in;
    int i = 0;

    while( *p )
    {
        if( !isspace(*p) )
            out[i++] = *p;
        p++;
    }
    out[i] = 0;
    return out;
}

void cifraVigenere(char mensagem[], char chave[]) {
    int tam_mensagem = strlen(mensagem);
    int tam_chave = strlen(chave);
    char matriz[N][N];
    char letra;

    //preenche a matriz
    for (int linha = 0; linha < N; linha++) {
        letra = 'a' + linha;
        for (int coluna = 0; coluna < N; coluna++) {
            matriz[linha][coluna] = letra++;
            if (letra > 'z') letra = 'a';  // Translação circular
        }
    }

    for (int i = 0; i < tam_mensagem; i++) {
        if (isalpha(mensagem[i])) { 
            //calcula o indice da linha usando a chave
            //converte a letra da chave em um índice de 0 a 25
            int linha = chave[i % tam_chave] - 'a'; 
            //calcula o índice da coluna da matriz utilizando o caracter da coluna da mensagem
            int coluna = tolower(mensagem[i]) - 'a';
            // Substitui o caractere atual na mensagem pelo caracter cifrado
            mensagem[i] = matriz[linha][coluna];
        }
    }
}

void decifraVigenere(char mensagem[], char chave[]) {
    int tam_mensagem = strlen(mensagem);
    int tam_chave = strlen(chave);
    char matriz[N][N];
    char letra;

    // Preenche a matriz de Vigenère
    for (int linha = 0; linha < N; linha++) {
        letra = 'a' + linha;
        for (int coluna = 0; coluna < N; coluna++) {
            matriz[linha][coluna] = 'a' + (coluna + linha) % N;
        }
    }

    // Decifra a mensagem
    int j = 0; // Índice para percorrer a chave
    for (int i = 0; i < tam_mensagem; i++) {
        if (isalpha(mensagem[i])) {
            int linha = chave[j % tam_chave] - 'a';
            for (int coluna = 0; coluna < N; coluna++) {
                if (matriz[linha][coluna] == mensagem[i]) {
                    mensagem[i] = 'a' + coluna;
                    break;
                }
            }
            j++;
        }
    }
}

int main() {
    char frase[100];
    char chave[100];
    char frase2[100];
    char criptografada[100];

    printf("Mensagem a ser criptografada: ");
    fgets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = '\0';
    
    printf("Chave: ");
    fgets(chave, sizeof(chave), stdin);
    chave[strcspn(chave, "\n")] = '\0';
    
    remove_espacos(frase2, frase);
    
    int tamanho = strlen(frase);
    
    cifraVigenere(frase2, chave);
    int tamanho2 = strlen(frase2);
    
    int num;
    int idx1 = 0, idx2 = 0;
    for (int i = 0; i < tamanho; i++) {
        if (frase[i] == ' ') {
            num = i;
        }
    }
    
    for (int i = tamanho2; i > num; i--) {
        frase2[i] = frase2[i - 1];
    }
    
    frase2[num] = ' ';
    
    printf("Mensagem cifrada : %s\n", frase2);
    
    // Decifração da mensagem cifrada
    decifraVigenere(frase2, chave);
    
    printf("Mensagem decifrada: %s\n", frase2);

    return 0;
}
