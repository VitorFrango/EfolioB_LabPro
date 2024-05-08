//
// Created by Vitor Frango on 08/05/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "retangulo.h"
#include "grelha.h"


void initMenu(){

    // Aloca espaço para 10 retângulos
    Retangulo_retangulos = malloc(10 * sizeof(Retangulo*));
    // Inicializa o contador de retângulos a 0
    Grelha_createCoordenadas();

    char opcaoEscolhida;

    do{
        printf("\n-------Menu Principal-------\n");
        printf("1. Criar Retângulo\n");
        printf("2. Mover Retângulo para a Direita\n");
        printf("3. Mover Retângulo para a Esquerda\n");
        printf("4. Mostrar Grelha\n");
        printf("5. Sair\n");
        scanf("%c",&opcaoEscolhida);

        switch(opcaoEscolhida){

            case '1':
                Retangulo_criarRetangulo();
                fflush(stdin);
                break;
            case '2':
                Retangulo_moveRight();
                fflush(stdin);
                break;
            case'3':
                Retangulo_moveLeft();
                fflush(stdin);
                break;
            case'4':

                Grelha_printGrelha();
                fflush(stdin);
                break;
            case'5':
                fflush(stdin);
                break;
            default:
                printf("\n !!!-----Por favor escolha uma opção dentro da lista de opções.-----!!!");
                fflush(stdin);
                break;
        }
    }while(opcaoEscolhida != '5');
};