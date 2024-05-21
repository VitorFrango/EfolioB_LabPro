#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "retangulo.h"
#include "grelha.h"


void initMenu(){

    Retangulo_retangulos = malloc(10 * sizeof(Retangulo*));
    Grelha_createCoordenadas();

    char opcaoEscolhida;

    do{
    printf("\n-------Menu Principal-------\n");
    printf("a. Criar Retângulo\n");
    printf("b. Mover Retângulo para a Direita\n");
    printf("c. Mover Retângulo para a Esquerda\n");
    printf("d. Mostrar Grelha\n");
    printf("e. Sair\n");
    scanf("%c",&opcaoEscolhida);

    switch(opcaoEscolhida){

    case 'a':
        Retangulo_criarRetangulo();
        fflush(stdin);
        break;
    case 'b':
        Retangulo_moveRight();
        fflush(stdin);
        break;
    case'c':
        Retangulo_moveLeft();
        fflush(stdin);
        break;
    case'd':
        Grelha_printGrelha();
        fflush(stdin);
        break;
    case'e':
        fflush(stdin);
        break;
    default:
        printf("\n !!!-----Por favor escolha uma opção dentro da lista de opções.-----!!!");
        fflush(stdin);
        break;
    }
    }while(opcaoEscolhida != 'e');
};