//
// Created by Vitor Frango on 06/05/2024.
//
#include <stdio.h>
#include "grelha.h"
#include "retangulo.h"


void Grelha_createCoordenadas(){

    int numeroGrid = 0;
    int m = 1;

    for (int i = 0; i <= 26; i++)
    {
        for (int j = 0; j <= 82; j++)
        {
            grelha[i][j] = ' ';

        }

    }

    for (int k = 2; k <= 81; k++)
    {

        if (numeroGrid == 10)
        {
            numeroGrid = 0;
        }

        grelha[26][k] = numeroGrid + '0';

        numeroGrid++;
    };

    for (int l = 25; l > 0; l--)
    {
        if (l < 10)
        {
            sprintf(&grelha[m][0], " %i", l);
            m++;
            continue;
        };

        sprintf(&grelha[m][0], "%i", l);
        m++;
    }
};

void Grelha_corrigirCoordenadas(struct Retangulo *Retangulo_retangulo){

    //Adiciona 2 ao eixo dos x's para compensar os dois primeiros campos que estão a ser usados com os digitos das coordenadas Y
    Retangulo_retangulo->coordenadaX += 2;
    /*
    Aqui subtrai-se por 26 porque é o número total das coordenadas Y, onde 1 é usada com os digitos das coordenadas X.
    Subtrai-se porque os valores no eixo dos Y começam no 25 e vão descendo. Num array bidimensional o valor equivalente ao 25 é 0,
     logo temos que subtrair para corrigir a coordenada inserida pelo utilizado.
    */
    Retangulo_retangulo->coordenadaY = 26 - Retangulo_retangulo->coordenadaY;
};

void Grelha_printGrelha (){

    /*
Antes de imprimir todos os retângulos novamente, faz-se uma iteração por todos os retângulos para
acertar eventuais coordenadas, aplicando a deformação e a gravidade em retângulos que poderão já não ter outro por baixo.
*/
    for (int i = 0; i < numeroRetangulos; i++)
    {
        Retangulo_apagarRetangulo(Retangulo_retangulos[i]);
        Retangulo_deformarRetangulo(Retangulo_retangulos[i]);
        Retangulo_redesenharRetangulo(Retangulo_retangulos[i]);
    };


    for (int i = 0; i <= 26; i++)
    {
        for (int j = 0; j <= 81; j++)
        {

            printf("%c", grelha[i][j]);
        }
        printf("\n");
    }
};