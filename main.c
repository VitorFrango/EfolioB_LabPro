#include "retangulo.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(){
    char comando[100];
    int x, y, l, h, p;

    while (1) {
        printf("Digite um comando: ");
        fgets (comando, sizeof(comando), stdin);

        // processar comando
        if (sscanf(comando, "criar %d %d %d %d", &x, &y, &l, &h) == 4) {
            criar_retangulo(x, y, l, h);
        } else if (sscanf(comando, "mover %d %d %d %d", &x, &y, &p, &p) == 4) {
            mover_retangulo(x, y, p, p);
        } else if (strcmp(comando, "desenhar\n") == 0) {
            desenhar_grelha();
        } else {
            printf("Comando inválido\n");
        }


    }
