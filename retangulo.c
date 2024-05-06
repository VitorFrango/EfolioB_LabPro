//
// Created by Vitor Frango on 06/05/2024.
//

#include "retangulo.h"
#include <stdio.h>
#include <stdbool.h>

static Retangulo retangulos[MAX_RETANGULOS];  // Array de retângulos
static int retangulo_conta = 0; // Contador de retângulos


void criar_retangulo(int x, int y, int largura, int altura) {
    if (retangulo_conta >= MAX_RETANGULOS) {
        printf("Erro: número máximo de retângulos atingido\n");
        return;
    }
    // Cria um novo retângulo com as coordenadas e dimensões fornecidas
    retangulos[retangulo_conta++] = (Retangulo) {x, y, largura, altura};
    aplicar_gravidade();
}

void mover_retangulo(int x, int y, int desvio, bool correto) {
    // Move o retângulo especificado para a nova posição
    for (int i = 0; i < retangulo_conta; i++) {
        if (retangulos[i].x <= x && x < retangulos[i].x + retangulos[i].largura &&
           retangulos[i].y - retangulos[i].altura < y && y <= retangulos[i].y) {
            retangulos[i].x += correto ? desvio : -desvio;
            aplicar_gravidade();
            return;
            }
        }
    printf("Erro: nenhum retângulo encontrado nessas coordenadas. \n");
}