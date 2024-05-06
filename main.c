#include "retangulo.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {

    int x, y, l, h, p, escolha;

    while (escolha != 0) {
        printf("Escolha uma opção:\n");
        printf("1. Criar retângulo\n");
        printf("2. Mover retângulo\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Introduza as coordenadas x e y, a largura e a altura do retângulo: ");
                scanf("%d %d %d %d", &x, &y, &l, &h);
                criar_retangulo(x, y, l, h);
                break;
            case 2:
                printf("Introduza as coordenadas x e y do retângulo a mover, o desvio e se é correto: ");
                scanf("%d %d %d %d", &x, &y, &p, &escolha);
                mover_retangulo(x, y, p, escolha);
                break;
            case 0:
                printf("Sair!\n");
                break;
            default:
                printf("Opção inválida\n");
        }
    }
}