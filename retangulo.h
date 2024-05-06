//
// Created by Vitor Frango on 06/05/2024.
//

#ifndef EFOLIOB2324_RETANGULO_H
#define EFOLIOB2324_RETANGULO_H

typedef struct Retangulo {
    int coordenadaX;
    int coordenadaY;
    int comprimento;
    int altura;
} Retangulo;

Retangulo *Retangulo_retangulo; // Array de retângulos
Retangulo **Retangulo_retangulos; // Array de retângulos
char vertice; // Variável para guardar o vértice do retângulo
char linhaVertical; // Variável para guardar a linha vertical do retângulo
char linhaHorizontal; // Variável para guardar a linha horizontal do retângulo
int coordenadaX; // Variável para guardar a coordenada X do retângulo
int coordenadaY; // Variável para guardar a coordenada Y do retângulo
int linha; // Variável para guardar a linha do retângulo
int minCoordenadaY; // Variável para guardar a coordenada Y mínima do retângulo
int numeroRetangulos; // Variável para guardar o número de retângulos


int Retangulo_retanguloExiste(int coordenadaX, int coordenadaY);

// Desenha as linhas verticias do retângulo
void Retangulo_desenharLinhasVerticais();
// Desenha as linhas horizontais do retângulo
void Retangulo_desenharLinhasHorizontais();

/*
    Retorna 0 se tiver fora dos limyes da grelha
    Retorna 1 se tiver dentro dos limites da grelha
    verifica se o retângulo está dentro dos limites da grelha
  */

int Retangulo_retanguloDentroLimites();
/*
 * Verifica desde a primeira coordenada de X se existe algum retângulo desenhado, linha a limha .
 * Se existir aumenta em 1 a coordenada X e volta a verificsr
 * Assim que hoiver yma linha livre a coordenada Y é ajustada para essa linha e gusradada
 * */

void Retangulo_aplicarGravidade(struct Retangulo *Retangulo_retangulo); // Aplica a gravidade ao retângulo
void Retangulo_deformarRetangulo(struct Retangulo *Retangulo_retangulo);
void Retangulo_criarRetangulo();
void Retangulo_apagarRetangulo(struct Retangulo *Retangulo_retangulo);
void Retangulo_redefinirRetangulo(struct Retangulo *Retangulo_retangulo);
// retorna 1 se puder mover, 0 se não puder mover
int Retangulo_verSePodeMoverEsquerda(int coordenadaX, int altura, int numeroMovimentos);
// retorna 1 se puder mover, 0 se não puder mover
int Retangulo_verSePodeMoverDireita(int coordenadaX, int comprimento, int altura, int numeroMovimentos);
void Retangulo_moveLeft();
void Retangulo_moveRight();

#endif //EFOLIOB2324_RETANGULO_H
