//
// Created by Vitor Frango on 06/05/2024.
//

#ifndef EFOLIOB2324_GRELHA_H
#define EFOLIOB2324_GRELHA_H

#include "retangulo.h"

/*
 A grelha é criada com 25 elementos no eixo dos yy para contemplar a impressão dos valores das coordenadas do eixo dos xx.
 A grelha é criada com 80 elementos no eixo dos xx para contemplar a impressão dos valores das coordenadas do eixo dos yy.
 */
char grelha[27][83];  // 25x80

/*
 Esta função guarda nos indexes certos os valores das coordenadas nos eixos dos xx e yy.
 */
void Grelha_createCoordenadas();
/*
Corrige a coordenadas, de forma a que o input do user seja refletido na grelha corretamente.
É necessário porque, por exemplo, a coordenada 25 do eixo dos yy, é na realidade a coordenada 0 (programáticamente),
visualmente, para que corresponda ao que o utilizador insere, é subtraído o valor inserido, por 26.
*/
void Grelha_corrigirCoordenadas(struct Retangulo *Retangulo_retangulo);
//Função para imprimir o array bidimencional "grelha"
void Grelha_printGrelha ();

#endif//EFOLIOB2324_GRELHA_H
