#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

// Função para inicializar o tabuleiro com água (0)
void inicializaTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para verificar se o navio cabe no tabuleiro e não sobrepõe outro navio
int podePosicionarNavio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, int orientacao) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha + (orientacao == 1 ? i : 0);     // 1 = vertical
        int c = coluna + (orientacao == 0 ? i : 0);    // 0 = horizontal
        if (l >= TAM_TABULEIRO || c >= TAM_TABULEIRO) return 0; // Fora do tabuleiro
        if (tabuleiro[l][c] != 0) return 0; // Sobreposição
    }
    return 1;
}

// Função para posicionar o navio no tabuleiro
void posicionaNavio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, int orientacao) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha + (orientacao == 1 ? i : 0);
        int c = coluna + (orientacao == 0 ? i : 0);
        tabuleiro[l][c] = 3;
    }
}

// Função para exibir o tabuleiro
void exibeTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    inicializaTabuleiro(tabuleiro);

    // Vetores representando os navios (não usados diretamente, mas ilustram o conceito)
    int navio_horizontal[TAM_NAVIO] = {3, 3, 3};
    int navio_vertical[TAM_NAVIO] = {3, 3, 3};

    // Coordenadas iniciais dos navios (definidas diretamente no código)
    int linha_h = 2, coluna_h = 4; // Navio horizontal
    int linha_v = 5, coluna_v = 7; // Navio vertical

    // Validação e posicionamento do navio horizontal
    if (podePosicionarNavio(tabuleiro, linha_h, coluna_h, 0)) {
        posicionaNavio(tabuleiro, linha_h, coluna_h, 0);
    } else {
        printf("Erro ao posicionar navio horizontal!\n");
        return 1;
    }

    // Validação e posicionamento do navio vertical
    if (podePosicionarNavio(tabuleiro, linha_v, coluna_v, 1)) {
        posicionaNavio(tabuleiro, linha_v, coluna_v, 1);
    } else {
        printf("Erro ao posicionar navio vertical!\n");
        return 1;
    }

    // Exibe o tabuleiro final
    exibeTabuleiro(tabuleiro);

    return 0;
}