//
// Created by Vitor Frango on 06/05/2024.
//

#ifndef EFOLIOB2324_RETANGULO_H
#define EFOLIOB2324_RETANGULO_H

#include <stdbool.h>

#define MAX_RETANGULOS 100
#define MAX_LARGURA 80
#define MAX_ALTURA 25

typedef struct Retangulo {
    int x;
    int y;
    int largura;
    int altura;
} Retangulo;

void criar_retangulo(int x , int y, int largura, int altura);
void mover_retangulo(int x, int y, int desvio, bool correto);
void desenhar_grelha(void);
void aplicar_gravidade(void);

#endif //EFOLIOB2324_RETANGULO_H
