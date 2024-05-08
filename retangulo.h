//
// Created by Vitor Frango on 06/05/2024.
//

#ifndef RETANGULO_H
#define RETANGULO_H

typedef struct Retangulo
{
    int coordenadaX;
    int coordenadaY;
    int comprimento;
    int altura;
} Retangulo;

Retangulo *Retangulo_retangulo;
Retangulo **Retangulo_retangulos;
char vertice;
char linhaVertical;
char linhaHorizontal;
int coordenadaX;
int coordenadaY;
int linha;
int minCoordenadaY;
int numeroRetangulos;


int Retangulo_retanguloExiste(int coordenadaX, int coordenadaY);

//Desenha as linhas verticais do retângulo.
void Retangulo_desenharLinhasVerticais();
//Desenha as linhas horizontais do retângulo.
void Retangulo_desenharLinhasHorizontais();
/*ero
  Retorna 0 se tiver fora dos limites da grelha.
  Retorna 1 se tiver dentro dos limites da grelha.
  Verifica se está dentro dos valores máximos da grelha.
*/
int Retangulo_retanguloDentroDosLimites();
/*Verifica, desde a primeira coordenada dos X's, se existe já outro retangulo desenhado, linha a linha.
Se existir, aumenta em 1 a coordenada X e volta a verificar. Assim que houver uma linha livre, a coordenada Y é ajustada e guardada.
*/
void Retangulo_aplicarGravidade(struct Retangulo *Retangulo_retangulo);
void Retangulo_deformarRetangulo(struct Retangulo *Retangulo_retangulo);
void Retangulo_criarRetangulo();
void Retangulo_apagarRetangulo(struct Retangulo *Retangulo_retangulo);
void Retangulo_redesenharRetangulo(struct Retangulo *Retangulo_retangulo);
//Retorna 1 se puder mover, retorna 0 se não for possivel mover
int Retangulo_verSePodeMoverEsquerda(int coordenadaX, int altura, int numeroMovimentos);
//Retorna 1 se puder mover, retorna 0 se não for possivel mover
int Retangulo_verSePodeMoverDireita(int coordenadaX, int comprimento, int altura, int numeroMovimentos);
void Retangulo_moveLeft();
void Retangulo_moveRight();


#endif //EFOLIOB2324_RETANGULO_H
