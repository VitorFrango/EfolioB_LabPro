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

void Retangulo_desenharLinhasHorizontais(int coordenadaX, int coordenadaY, int comprimento, int altura)
{
    for (int i = 0; i < comprimento; i++)
        {
            grelha[coordenadaY][coordenadaX+i] = vertice;
            grelha[coordenadaY-altura+1][coordenadaX+i] = vertice;
        }
};

int Retangulo_retanguloDentroLimites(int coordenadaX, int coordenadaY, int comprimento, int altura)
{
    if (coordenadaX + comprimento > 80 || coordenadaY + altura > 25)
    {
        return 0;
    }
    return 1;
};

void Retangulo_aplicarGravidade(struct Retangulo *Retangulo_retangulo){
    int coordenadaFinal;

    for (int i = Retangulo_retangulo->coordenadaX; i < Retangulo_retangulo->comprimento + Retangulo_retangulo->coordenadaX; i++)
    {
        /*
        Se a coordenada não estiver vazia é decrementado a variável minCoordenadaY e volta a chamar a função recursivamente
        para verificar novamente a próxima linha. Assim que tiver uma linha "livre" corrige as coordanas do retangulo colocado
        como parâmetro.
        */
        if (grelha[minCoordenadaY][i] != ' ') {
            minCoordenadaY--;
            Retangulo_aplicarGravidade(Retangulo_retangulo);
            return;
        };
    };


    coordenadaFinal = minCoordenadaY - Retangulo_retangulo->altura+1;
    Retangulo_retangulo->coordenadaY = coordenadaFinal;
    minCoordenadaY = 25;
};

// Função para deformar o retângulo
void Retangulo_deformarRetangulo(struct Retangulo *Retangulo_retangulo){
    int coorndenadaInicial = Retangulo_retangulo->coordenadaY;
    int alturaInicial = Retangulo_retangulo->altura;
    int alturaFinal = Retangulo_retangulo->altura;
    int coordenadaFinal;
    int alturaQueda;
    int razaoAchatamento;

    /*
     * É usada a função gravidade para podermos saber a altura de
     * queda usando a coordenada corrigida por esta função
     * */
    Retangulo_aplicarGravidade(Retangulo_retangulo);

    coordenadaFinal = Retangulo_retangulo->coordenadaY;
    alturaQueda = coorndenadaInicial - coordenadaFinal;

    /*
     *
     * calculado o valor da  razao de 10% por unidade de eixo dos YY da altura de queda
     * usando a coordenada corrigida por esta função
     * */

    razaoAchatamento = round(alturaInicial * (alturaQueda * 0.1));

    printf("Achatamento: %i  Altura Inicial: %i  AlturaQueda: %i Coordenada Final: %i  "
           "Coordenada Inicial: %i", razaoAchatamento, alturaInicial, alturaQueda,
           coordenadaFinal, coorndenadaInicial);

    //Se a razão de achatamento for maior que a altua do retangulo a altuta fuca igual a 1
    if (razaoAchatamento >= Retangulo_retangulo->altura)
    {
        alturaFinal = 1;
        Retangulo_retangulo->altura = alturaFinal;
    } else if (razaoAchatamento < Retangulo_retangulo->altura)
    {
        // removido o valor da razão de achatamento à altura do retângulo
        alturaFinal = Retangulo_retangulo->altura - razaoAchatamento;
        Retangulo_retangulo->altura = alturaFinal;
    }
    Retangulo_aplicarGravidade(Retangulo_retangulo);
};

void Retangulo_redesenharRetangulo(struct Retangulo *Retangulo_retangulo){
    Retangulo_desenharLinhasVerticais(Retangulo_retangulo->coordenadaX, Retangulo_retangulo->coordenadaY, Retangulo_retangulo->comprimento, Retangulo_retangulo->altura);
    Retangulo_desenharLinhasHorizontais(Retangulo_retangulo->coordenadaX, Retangulo_retangulo->coordenadaY, Retangulo_retangulo->comprimento, Retangulo_retangulo->altura);
};

void Retangulo_apagarRetangulo(struct Retangulo *Retangulo_retangulo){


int coordenadaX = Retangulo_retangulo->coordenadaX;
int coordenadaY = Retangulo_retangulo->coordenadaY;
int comprimento = Retangulo_retangulo->comprimento;
int altura = Retangulo_retangulo->altura;

  // vai se às coordenadas do retanngulo pretendido e coloca se '' para simulaer o apagara
    for ( int = 0; i < altura; i++)
};