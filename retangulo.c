//
// Created by Vitor Frango on 06/05/2024.
//

#include "retangulo.h"
#include "grelha.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


char vertice = '+'; // Variável para guardar o vértice do retângulo
char linhaVertical = '|'; // Variável para guardar a linha vertical do retângulo
char linhaHorizontal = '-'; // Variável para guardar a linha horizontal do retângulo
char grelha[27][82]; // Array de caracteres para guardar a grelha
int minCoordenadaY = 25 ; // Variável para guardar a coordenada Y mínima do retângulo
int numeroRetangulos = 0; // Variável para guardar o número de retângulos

void Retangulo_CriarRetangulo() {

    int coordenadaX;
    int coordenadaY;
    int comprimento;
    int altura;
    int dentroDosLimites;

    printf(" Inserir as coordenadas do retângulo: ");

    do {
        do {
            printf("Inserir a coordenada X:");

            if (scanf("%i", &coordenadaX) != 1) {
                printf("\n Não pode inserir letras ou caracteres especiais, tente novamente\n");
                return;
            };

            if (coordenadaX > 80) {
                printf("\n A coordenada X não pode ser maior que 80, tente novamente\n");
            }
        } while (coordenadaX > 80);

        do {
            printf("Inserir a coordenada Y:");

            if (scanf("%i", &coordenadaY) != 1) {
                printf("\n Não pode inserir letras ou caracteres especiais, tente novamente\n");
                return;
            };

            if (coordenadaY > 25) {
                printf("\n A coordenada Y não pode ser maior que 25, tente novamente\n");
            }
        } while (coordenadaY > 25);

        do {
            printf("Inserir o comprimento do retângulo:");
            if (scanf("%i", &comprimento) != 1) {
                printf("\n Não pode inserir letras ou caracteres especiais, tente novamente\n");
                return;
            };
            if (comprimento < 2 || comprimento > 80)
                ;
            {
                printf("\n O comprimento do retângulo tem de ser maior que 2 e menor que 80, tente novamente\n");
            };
        } while (comprimento < 2 || comprimento > 80);

        do
        {
            printf("Inserir a altura do retângulo:");
            if (scanf("%i", &altura) != 1) {
                printf("\n Não pode inserir letras ou caracteres especiais, tente novamente\n");
                return;
            };
            if (altura < 2 || altura > 25)
                ;
            {
                printf("\n A altura do retângulo tem de ser maior que 2 e menor que 25, tente novamente\n");
            };

        } while (altura < 2 || altura > 25);

        dentroDosLimites = Retangulo_retanguloDentroLimites(coordenadaX, coordenadaY, comprimento, altura);

        if (dentroDosLimites == 0) {
            printf("\n O retângulo não pode ser desenhado fora dos limites da grelha, tente novamente\n");
            printf("\n A grelha tem 80 de comprimento e 25 de largura\n");
        };

    }while (dentroDosLimites == 0);

        Retangulo_retangulo = malloc(sizeof(Retangulo));
        Retangulo_retangulo->coordenadaX = coordenadaX;
        Retangulo_retangulo->coordenadaY = coordenadaY;
        Retangulo_retangulo->comprimento = comprimento;
        Retangulo_retangulo->altura = altura;
        Greha_corrigirCoordenadas(Retangulo_retangulo);

        Retangulo_deformarRetangulo(Retangulo_retangulo);
        Retangulo_desenharLinhasVerticais(Retangulo_retangulo->coordenadaX, Retangulo_retangulo->coordenadaY, Retangulo_retangulo->comprimento, Retangulo_retangulo->altura);
        Retangulo_desenharLinhasHorizontais(Retangulo_retangulo->coordenadaX, Retangulo_retangulo->coordenadaY, Retangulo_retangulo->comprimento, Retangulo_retangulo->altura);
        Retangulo_retangulos[numeroRetangulos] = Retangulo_retangulo;
        numeroRetangulos++;
    };

    int Retangulo_retanguloExiste(int coordenadaX, int coordenadaY) {
        Retangulo *retanguloAtual;

        for (int i = 0; i < numeroRetangulos; i++)
        {
            retanguloAtual = Retangulo_retangulos[i];
            if (coordenadaX >= retanguloAtual->coordenadaX && coordenadaX <= retanguloAtual->coordenadaX + retanguloAtual->comprimento && coordenadaY >= retanguloAtual->coordenadaY && coordenadaY <= retanguloAtual->coordenadaY + retanguloAtual->altura)
            {
                return 1;
            }
        }
        return 0;

    };

void Retangulo_desenharLinhasVerticais(int coordenadaX, int coordenadaY, int comprimento, int altura)
    {
    for (int i =0; i < altura; i++)
    {
        if(i == 0 || i==altura-1)
        {
            grelha[coordenadaY+i][coordenadaX] = vertice;
            grelha[coordenadaY+i][coordenadaX+comprimento-1] = vertice;
            continue;
        }
            grelha[coordenadaY-i][coordenadaX] = linhaVertical;
            grelha[coordenadaY-i][coordenadaX+comprimento-1] = linhaVertical;
    }

};


