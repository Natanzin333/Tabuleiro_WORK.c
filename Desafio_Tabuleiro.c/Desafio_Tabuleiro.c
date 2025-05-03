#include <stdio.h>

int main() {
    // 1. Criar o tabuleiro com tudo 0 (água)
    int tabuleiro[10][10];
    
    // Inicializar o tabuleiro com 0
    for (int linha = 0; linha < 10; linha++) {         //O primeiro for percorre cada linha da matriz
        for (int coluna = 0; coluna < 10; coluna++) { //O segundo for percorre cada coluna da linha atual
            tabuleiro[linha][coluna] = 0;             //O comando tabuleiro[linha][coluna] = 0; coloca água (0) em cada posição
        }
    }

    printf("TABULEIRO INICIAL:\n\n");
    for (int linha = 0; linha < 10; linha++) {
        for (int coluna = 0; coluna < 10; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }





    // 2. Tamanho fixo dos navios
    int tamanhoNavio = 3;



    // 3. Definir onde o navio horizontal vai começar
    int linhaHorizontal = 2;
    int colunaHorizontal = 3;  
    
    //Linha 2 (ou seja, terceira linha, pois começa em 0)
    //Coluna 3 (ou seja, quarta coluna)
     

    // Verificar se o navio cabe no tabuleiro na horizontal
    if (colunaHorizontal + tamanhoNavio <= 10) {
        // Posicionar o navio horizontal
        for (int i = 0; i < tamanhoNavio; i++) {
            tabuleiro[linhaHorizontal][colunaHorizontal + i] = 3;
        }
    } else {
        printf("Navio horizontal está fora do tabuleiro!\n");
        
    }



    // 4. Definir onde o navio vertical vai começar
    int linhaVertical = 5;
    int colunaVertical = 6;




    // Verificar se o navio cabe no tabuleiro na vertical
    if (linhaVertical + tamanhoNavio <= 10) {
        int podeColocar = 1; // sinal de que está tudo ok

        // Verificar se tem outro navio no caminho
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linhaVertical + i][colunaVertical] == 3) {
                podeColocar = 0;
                break;
            }
        }

        // Se estiver tudo ok, colocar o navio vertical
        if (podeColocar) {
            for (int i = 0; i < tamanhoNavio; i++) {
                tabuleiro[linhaVertical + i][colunaVertical] = 3;
            }
        } else {
            printf("Navio vertical está colidindo com outro navio!\n");
            return 1;
        }
    } else {
        printf("Navio vertical está fora do tabuleiro!\n");
        return 1;
    }

    // 5. Mostrar o tabuleiro
    printf("\nTABULEIRO:\n\n");
    for (int linha = 0; linha < 10; linha++) {
        for (int coluna = 0; coluna < 10; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    printf("===================\n");
    printf("Obrigado por jogar!\n");
    printf("Fim.\n");

    return 0;
}
