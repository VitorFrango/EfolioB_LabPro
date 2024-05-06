//
// Created by Vitor Frango on 06/05/2024.
//

#include "retangulo.h"
#include <stdio.h>

extern Retangulo retangulos[MAX_RETANGULOS];  // Array de retângulos
extern int retangulo_conta; // Contador de retângulos

void desenhar_grelha() {
    char world[MAX_ALTURA + 1][MAX_LARGURA + 1];
    // Inicializar mundo com espaços em branco
    for (int i = 0; i <= MAX_ALTURA; i++) {
        for (int j = 0; j <= MAX_LARGURA; j++) {
            world[i][j] = ' ';
        }
    }

    // Desenhar retângulos
    for (int i = 0; i < retangulo_conta; i++) {
        for (int h = 0; h < retangulos[i].altura; h++) {
            for (int w = 0; w < retangulos[i].largura; w++) {
                int drawX = retangulos[i].x + w;
                int drawY = retangulos[i].y - h;
                if (drawX > 0 && drawX <= MAX_LARGURA && drawY > 0 && drawY <= MAX_ALTURA) {
                    world[drawY][drawX] = 'x';
                }
            }
        }
    }

    // Imprimir o mundo
    for (int i = MAX_ALTURA; i > 0; i--) {
        for (int j = 1; j <= MAX_LARGURA; j++) {
            putchar(world[i][j]);
        }
        putchar('\n');
    }
}


void aplicar_gravidade() {
    for (int i = 0; i < retangulo_conta; i++) {
        while (retangulos[i].y > 1) {
            bool canFall = true;
            for (int j = 0; j < retangulo_conta; j++) {
                if (i != j && retangulos[i].x < retangulos[j].x + retangulos[j].largura &&
                    retangulos[i].x + retangulos[i].largura > retangulos[j].x &&
                    retangulos[i].y - 1 == retangulos[j].y + retangulos[j].altura) {
                    canFall = false;
                    break;
                }
            }
            if (canFall)
                retangulos[i].y--;
            else
                break;
        }
    }
}

