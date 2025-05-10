#include <stdio.h>
#include <stdlib.h>

//Definindo constantes
#define TAMANHO_TABULEIRO 10
#define AFETADO_CONE 5
#define AFETADO_CRUZ 1
#define AFETADO_OCTAEDRO 7
#define AGUA 0

// Função para calcular o valor absoluto de um número inteiro
int valorAbsoluto(int x) {
    if (x < 0) {
        return -x;  // Se x for negativo, retorna o valor positivo (inverte o sinal)
    } else {
        return x;   // Se x for positivo ou zero, retorna x como está
    }
}


// Função para aplicar a habilidade do cone
void aplicarCone(int tabuleiro[][TAMANHO_TABULEIRO], int origemLinha, int origemColuna, int altura) {
    for (int i = 0; i < altura; i++) {
        for (int j = origemColuna - i; j <= origemColuna + i; j++) {
            if (origemLinha + i < TAMANHO_TABULEIRO && j >= 0 && j < TAMANHO_TABULEIRO) {
                tabuleiro[origemLinha + i][j] = AFETADO_CONE;
            }
        }
    }
}
// Função para aplicar a habilidade da cruz
void aplicarCruz(int tabuleiro[][TAMANHO_TABULEIRO], int origemLinha, int origemColuna, int alcance) {
    for (int j = origemColuna - alcance; j <= origemColuna + alcance; j++) {
        if (origemLinha >= 0 && origemLinha < TAMANHO_TABULEIRO && j >= 0 && j < TAMANHO_TABULEIRO) {
            tabuleiro[origemLinha][j] = AFETADO_CRUZ;
        }
    }

    for (int i = origemLinha - alcance; i <= origemLinha + alcance; i++) {
        if (i >= 0 && i < TAMANHO_TABULEIRO && origemColuna >= 0 && origemColuna < TAMANHO_TABULEIRO) {
            tabuleiro[i][origemColuna] = AFETADO_CRUZ;
        }
    }
}
// Função para aplicar a habilidade do octaedro
void aplicarOctaedro(int tabuleiro[][TAMANHO_TABULEIRO], int origemLinha, int origemColuna, int raio) {
    for (int i = -raio; i <= raio; i++) {
        for (int j = -raio; j <= raio; j++) {
            if (valorAbsoluto(i) + valorAbsoluto(j) <= raio) {
                int linha = origemLinha + i;
                int coluna = origemColuna + j;
                if (linha >= 0 && linha < TAMANHO_TABULEIRO && coluna >= 0 && coluna < TAMANHO_TABULEIRO) {
                    tabuleiro[linha][coluna] = AFETADO_OCTAEDRO;
                }
            }
        }
    }
}
// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int main() {

    // Inicializando o tabuleiro com zeros
    int tabuleiro[10][10];

    for (int linha = 0; linha < 10; linha++) {
        for (int coluna = 0; coluna < 10; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }

    printf("TABULEIRO INICIAL:\n\n");
    for (int linha = 0; linha < 10; linha++) {
        for (int coluna = 0; coluna < 10; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    // Colocando navios no tabuleiro
    // Navio horizontal
    for (int linha = 0; linha < 10; linha++) {
        for (int coluna = 0; coluna < 10; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }

    int tamanhoNavio = 3;

    int linhaHorizontal = 2;
    int colunaHorizontal = 3;
    if (colunaHorizontal + tamanhoNavio <= 10) {
        for (int i = 0; i < tamanhoNavio; i++) {
            tabuleiro[linhaHorizontal][colunaHorizontal + i] = 3;
        }
    }

    // Navio vertical
    int linhaVertical = 5;
    int colunaVertical = 6;
    if (linhaVertical + tamanhoNavio <= 10) {
        int podeColocar = 1;
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linhaVertical + i][colunaVertical] == 3) {
                podeColocar = 0;
                break;
            }
        }
        if (podeColocar) {
            for (int i = 0; i < tamanhoNavio; i++) {
                tabuleiro[linhaVertical + i][colunaVertical] = 3;
            }
        }
    }

    // Navio diagonal
    int linhaDiag1 = 0;
    int colunaDiag1 = 0;
    if (linhaDiag1 + tamanhoNavio <= 10 && colunaDiag1 + tamanhoNavio <= 10) {
        int podeColocar = 1;
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linhaDiag1 + i][colunaDiag1 + i] == 3) {
                podeColocar = 0;
                break;
            }
        }
        if (podeColocar) {
            for (int i = 0; i < tamanhoNavio; i++) {
                tabuleiro[linhaDiag1 + i][colunaDiag1 + i] = 3;
            }
        }
    }


    // Navio diagonal 2
    int linhaDiag2 = 3;
    int colunaDiag2 = 6;
    if (linhaDiag2 + tamanhoNavio <= 10 && colunaDiag2 - tamanhoNavio + 1 >= 0) {
        int podeColocar = 1;
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linhaDiag2 + i][colunaDiag2 - i] == 3) {
                podeColocar = 0;
                break;
            }
        }
        if (podeColocar) {
            for (int i = 0; i < tamanhoNavio; i++) {
                tabuleiro[linhaDiag2 + i][colunaDiag2 - i] = 3;
            }
        }
    }

    //Exibir o tabuleiro com os navios
    printf("\nTABULEIRO COM NAVIOS:\n\n");
    exibirTabuleiro(tabuleiro);


    //Exibir o tabuleiro com as habilidades
    int tabHabilidades[10][10] = {0};
    
    aplicarCone(tabHabilidades, 0, 4, 3);
    aplicarCruz(tabHabilidades, 6, 2, 2);
    aplicarOctaedro(tabHabilidades, 7, 7, 2);

    printf("TABULEIRO COM AS 3 HABILIDADES JUNTAS (sem navios):\n\n");
    exibirTabuleiro(tabHabilidades);

    
    printf("===================\n");
    printf("Obrigado por jogar!\n");
    printf("Fim.\n");

    return 0;
}
