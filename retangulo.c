#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "retangulo.h"
#include "grelha.h"

char vertice = 'X';
char linhaVertical = 'X';
//char linhaHorizontal = 'X';
char preenchimento = 'O';
char grelha[27][82];
int minCoordenadaY = 25;
int numeroRetangulos = 0;

void Retangulo_criarRetangulo() {
    int coordenadaX;
    int coordenadaY;
    int comprimento;
    int altura;
    int dentroDosLimites;

    printf("-----Inserir Coordenadas do Retângulo-----\n");

    do {
        do {
            printf("Inserir Coordenada X:");

            if (scanf("%i", &coordenadaX) != 1) {
                printf("\n!!!-----Não pode inserir letras ou caracteres especiais, apenas números-----!!!\n");
                return;
            };

            if (coordenadaX > 80) {
                printf("\n!!!-----A coordenada X não pode ser maior que 80-----!!!\n");
            }

        } while (coordenadaX > 80);

        do {
            printf("Inserir Coordenada Y:");

            if (scanf("%i", &coordenadaY) != 1) {
                printf("\n!!!-----Não pode inserir letras ou caracteres especiais, apenas números-----!!!\n");
                return;
            };

            if (coordenadaY > 25) {
                printf("\n!!!-----A coordenada Y não pode ser maior que 25-----!!!\n");
            }

        } while (coordenadaY > 25);

        do {
            printf("Inserir o comprimento:");

            if (scanf("%i", &comprimento) != 1) {
                printf("\n!!!-----Não pode inserir letras ou caracteres especiais, apenas números-----!!!\n");
                return;
            };

            if (comprimento < 2 || comprimento > 80) {
                printf("!!!-----O comprimento não pode ser menor que 2 ou maior que 80!-----!!!\n");
            };

        } while (comprimento < 2 || comprimento > 80);

        do {
            printf("Inserir a altura:");

            if (scanf("%i", &altura) != 1) {
                printf("\n!!!-----Não pode inserir letras ou caracteres especiais, apenas números-----!!!\n");
                return;
            };

            if (altura <= 1 || altura > 25) {
                printf("!!!-----A altura não pode ser menor que 2 ou maior que 25!-----!!!\n");
            };

        } while (altura <= 1 || altura > 25);

        dentroDosLimites = Retangulo_retanguloDentroDosLimites(coordenadaX, coordenadaY, comprimento, altura);

        if (dentroDosLimites == 0) {
            printf("\n!!!-----Retangulo fora dos limites da grelha-----!!!\n");
            printf("A grelha tem 80 de comprimento e 25 de largura. Coloque os dados novamente pff.\n");
        };

    } while (dentroDosLimites == 0);

    Retangulo_retangulo = malloc(sizeof(Retangulo));
    Retangulo_retangulo->coordenadaX = coordenadaX;
    Retangulo_retangulo->coordenadaY = coordenadaY;
    Retangulo_retangulo->comprimento = comprimento;
    Retangulo_retangulo->altura = altura;
    Grelha_corrigirCoordenadas(Retangulo_retangulo);

    Retangulo_deformarRetangulo(Retangulo_retangulo);
    Retangulo_desenharLinhasVerticais(Retangulo_retangulo->coordenadaX, Retangulo_retangulo->coordenadaY, Retangulo_retangulo->comprimento, Retangulo_retangulo->altura);
    Retangulo_desenharLinhasHorizontais(Retangulo_retangulo->coordenadaX, Retangulo_retangulo->coordenadaY, Retangulo_retangulo->comprimento, Retangulo_retangulo->altura);

    Retangulo_retangulos[numeroRetangulos] = Retangulo_retangulo;

    numeroRetangulos++;
}

int Retangulo_retanguloExiste(int coordenadaX, int coordenadaY) {
    Retangulo *retanguloAtual;

    for (int i = 0; i < numeroRetangulos; i++) {
        retanguloAtual = Retangulo_retangulos[i];
        if (retanguloAtual->coordenadaX == coordenadaX && retanguloAtual->coordenadaY == coordenadaY) {
            return 1;
        }
    }

    return 0;
}

void Retangulo_desenharLinhasVerticais(int coordenadaX, int coordenadaY, int comprimento, int altura) {
    for (int i = 0; i < altura; i++) {
        if (i == 0 || i == altura - 1) {
            for (int j = 0; j < comprimento; j++) {
                grelha[coordenadaY + i][coordenadaX + j] = vertice;
            }
        } else {
            grelha[coordenadaY + i][coordenadaX] = linhaVertical;
            for (int j = 1; j < comprimento - 1; j++) {
                grelha[coordenadaY + i][coordenadaX + j] = preenchimento;
            }
            grelha[coordenadaY + i][coordenadaX + comprimento - 1] = linhaVertical;
        }
    }
}

void Retangulo_desenharLinhasHorizontais(int X, int Y, int l, int ) {
    // The horizontal lines are drawn by the vertical lines function.
}

int Retangulo_retanguloDentroDosLimites(int coordenadaX, int coordenadaY, int comprimento, int altura) {
    if (coordenadaX < 0 || coordenadaX + comprimento > 80 || coordenadaY < 0 || coordenadaY + altura > 25) {
        return 0;
    }
    return 1;
}

void Retangulo_aplicarGravidade(struct Retangulo *Retangulo_retangulo) {
    int coordenadaFinal;

    for (int i = Retangulo_retangulo->coordenadaX; i < Retangulo_retangulo->comprimento + Retangulo_retangulo->coordenadaX; i++) {
        if (grelha[minCoordenadaY][i] != ' ') {
            minCoordenadaY--;
            Retangulo_aplicarGravidade(Retangulo_retangulo);
            return;
        };
    };

    coordenadaFinal = minCoordenadaY - Retangulo_retangulo->altura + 1;
    Retangulo_retangulo->coordenadaY = coordenadaFinal;
    minCoordenadaY = 25;
}

void Retangulo_deformarRetangulo(struct Retangulo *Retangulo_retangulo) {
    int coordenadaInicial = Retangulo_retangulo->coordenadaY;
    int alturaInicial = Retangulo_retangulo->altura;
    int alturaFinal = Retangulo_retangulo->altura;
    int coordenadaFinal;
    int alturaQueda;
    int razaoAchatamento;

    Retangulo_aplicarGravidade(Retangulo_retangulo);

    coordenadaFinal = Retangulo_retangulo->coordenadaY;
    alturaQueda = coordenadaFinal - coordenadaInicial;

    razaoAchatamento = round(alturaInicial * (alturaQueda * 0.1));

    printf("Achatamento: %i  Altura Inicial: %i  AlturaQueda: %i Coordenada Final: %i  Coordenada Inicial: %i", razaoAchatamento, alturaInicial, alturaQueda, coordenadaFinal, coordenadaInicial);

    if (razaoAchatamento >= Retangulo_retangulo->altura) {
        alturaFinal = 1;
        Retangulo_retangulo->altura = alturaFinal;

    } else if (razaoAchatamento < Retangulo_retangulo->altura) {
        alturaFinal -= razaoAchatamento;
        Retangulo_retangulo->altura = alturaFinal;
    }

    Retangulo_aplicarGravidade(Retangulo_retangulo);
}

void Retangulo_redesenharRetangulo(struct Retangulo *Retangulo_retangulo) {
    Retangulo_desenharLinhasVerticais(Retangulo_retangulo->coordenadaX, Retangulo_retangulo->coordenadaY, Retangulo_retangulo->comprimento, Retangulo_retangulo->altura);
}

void Retangulo_apagarRetangulo(struct Retangulo *Retangulo_retangulo) {
    int coordenadaX = Retangulo_retangulo->coordenadaX;
    int coordenadaY = Retangulo_retangulo->coordenadaY;
    int comprimento = Retangulo_retangulo->comprimento;
    int altura = Retangulo_retangulo->altura;

    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < comprimento; j++) {
            grelha[coordenadaY + i][coordenadaX + j] = ' ';
        }
    }
}

int Retangulo_verSePodeMoverEsquerda(int coordenadaX, int altura, int numeroMovimentos) {
    for (int i = 0; i < altura; i++) {
        for (int j = coordenadaX - numeroMovimentos; j < coordenadaX; j++) {
            if (grelha[minCoordenadaY][j] != ' ') {
                return 0;
            };
        }
        minCoordenadaY--;
    }
    minCoordenadaY = 25;
    return 1;
}

int Retangulo_verSePodeMoverDireita(int coordenadaX, int comprimento, int altura, int numeroMovimentos) {
    for (int i = 0; i < altura; i++) {
        for (int j = coordenadaX + comprimento; j < coordenadaX + comprimento + numeroMovimentos; j++) {
            if (grelha[minCoordenadaY][j] != ' ') {
                return 0;
            };
        }
        minCoordenadaY--;
    }
    minCoordenadaY = 25;
    return 1;
}

void Retangulo_moveLeft() {
    Retangulo *retangulo;
    int coordenadaX;
    int coordenadaY;
    int retanguloExiste;
    int numeroMovimentos;
    int dentroDosLimites;
    int podeMover;
    int coordenadaXcorrigida;
    int coordenadaYcorrigida;

    do {
        printf("Inserir Coordenada X do retângulo:\n");

        if (scanf("%i", &coordenadaX) != 1) {
            printf("\n!!!-----Não pode inserir letras ou caracteres especiais, apenas números-----!!!\n");
            return;
        }

        coordenadaXcorrigida = coordenadaX + 2;

        if (coordenadaXcorrigida == 3) {
            printf("!!!-----Já não é possível mover este retângulo para a esquerda-----!!!");
            return;
        }

        printf("Inserir Coordenada Y do retângulo:\n");

        if (scanf("%i", &coordenadaY) != 1) {
            printf("\n!!!-----Não pode inserir letras ou caracteres especiais, apenas números-----!!!\n");
            return;
        }

        coordenadaYcorrigida = 26 - coordenadaY;

        retanguloExiste = Retangulo_retanguloExiste(coordenadaXcorrigida, coordenadaYcorrigida);

        if (retanguloExiste == 0) {
            printf("\n!!!-----Para as coordenadas que inseriu não existe nenhum retângulo-----!!!\n");
            return;
        }

        printf("Inserir número de Movimentos:\n");

        if (scanf("%i", &numeroMovimentos) != 1) {
            printf("\n!!!-----Não pode inserir letras ou caracteres especiais, apenas números-----!!!\n");
            return;
        }

        for (int i = 0; i < numeroRetangulos; i++) {
            if (Retangulo_retangulos[i]->coordenadaX == coordenadaXcorrigida && Retangulo_retangulos[i]->coordenadaY == coordenadaYcorrigida) {
                retangulo = Retangulo_retangulos[i];
            }
        };

        dentroDosLimites = Retangulo_retanguloDentroDosLimites(coordenadaXcorrigida, coordenadaYcorrigida, retangulo->comprimento, retangulo->altura);
        podeMover = Retangulo_verSePodeMoverEsquerda(coordenadaXcorrigida, retangulo->altura, numeroMovimentos);

        if (dentroDosLimites == 0) {
            printf("\n!!!-----Movendo o retângulo como pretende, fica fora dos limites da grelha-----!!!\n");
        } else if (podeMover == 0) {
            printf("\n!!!-----Movendo o retângulo como pretende, vai ficar sobreposto a outro já existente-----!!!\n");
            return;
        }

    } while (dentroDosLimites == 0 | podeMover == 0 | retanguloExiste == 0);

    Retangulo_apagarRetangulo(retangulo);
    retangulo->coordenadaX -= numeroMovimentos;
    Retangulo_deformarRetangulo(retangulo);
    Retangulo_redesenharRetangulo(retangulo);
}

void Retangulo_moveRight() {
    Retangulo *retangulo;
    int coordenadaX;
    int coordenadaY;
    int retanguloExiste;
    int numeroMovimentos;
    int dentroDosLimites;
    int podeMover;
    int coordenadaXcorrigida;
    int coordenadaYcorrigida;

    do {
        printf("Inserir Coordenada X do retângulo:\n");

        if (scanf("%i", &coordenadaX) != 1) {
            printf("\n!!!-----Não pode inserir letras ou caracteres especiais, apenas números-----!!!\n");
            return;
        }

        coordenadaXcorrigida = coordenadaX + 2;

        printf("Inserir Coordenada Y do retângulo:\n");

        if (scanf("%i", &coordenadaY) != 1) {
            printf("\n!!!-----Não pode inserir letras ou caracteres especiais, apenas números-----!!!\n");
            return;
        }

        coordenadaYcorrigida = 26 - coordenadaY;

        retanguloExiste = Retangulo_retanguloExiste(coordenadaXcorrigida, coordenadaYcorrigida);

        if (retanguloExiste == 0) {
            printf("\n!!!-----Para as coordenadas que inseriu não existe nenhum retângulo-----!!!\n");
            return;
        }

        printf("Inserir número de Movimentos:\n");

        if (scanf("%i", &numeroMovimentos) != 1) {
            printf("\n!!!-----Não pode inserir letras ou caracteres especiais, apenas números-----!!!\n");
            return;
        }

        for (int i = 0; i < numeroRetangulos; i++) {
            if (Retangulo_retangulos[i]->coordenadaX == coordenadaXcorrigida && Retangulo_retangulos[i]->coordenadaY == coordenadaYcorrigida) {
                retangulo = Retangulo_retangulos[i];
            }
        };

        if (coordenadaXcorrigida == 80) {
            printf("!!!-----Já não é possível mover este retângulo para a direita-----!!!");
            return;
        }

        dentroDosLimites = Retangulo_retanguloDentroDosLimites(coordenadaXcorrigida, coordenadaYcorrigida, retangulo->comprimento, retangulo->altura);
        podeMover = Retangulo_verSePodeMoverDireita(coordenadaXcorrigida, retangulo->comprimento, retangulo->altura, numeroMovimentos);

        if (dentroDosLimites == 0) {
            printf("\n!!!-----Movendo o retângulo como pretende, fica fora dos limites da grelha-----!!!\n");
        } else if (podeMover == 0) {
            printf("\n!!!-----Movendo o retângulo como pretende, vai ficar sobreposto a outro já existente-----!!!\n");
            return;
        }

    } while (dentroDosLimites == 0 | podeMover == 0 | retanguloExiste == 0);

    Retangulo_apagarRetangulo(retangulo);
    retangulo->coordenadaX += numeroMovimentos;
    Retangulo_deformarRetangulo(retangulo);
    Retangulo_redesenharRetangulo(retangulo);
}
