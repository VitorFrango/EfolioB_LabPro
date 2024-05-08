#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "retangulo.h"
#include "grelha.h"

char vertice = '+';
char linhaVertical ='|';
char linhaHorizontal = '-';
char grelha[27][83];  // 25x80
int minCoordenadaY = 25; //Valor máximo do eixo dos yy
int numeroRetangulos = 0; //Contador de retângulos

//Atenção, ver se na minha lógica quando movo o retangulo de baixo se o de cima volta a cair.

void Retangulo_criarRetangulo(){

    int coordenadaX;
    int coordenadaY;
    int comprimento;
    int altura;
    int dentroDosLimites;

    printf("-----Inserir Coordenadas do Retângulo-----\n");

    do
    {
        do
        {
            printf("Inserir Coordenada X:");
            //Verifica se o utilizador insere um número e não letras ou caracteres especiais
            if(scanf("%i", &coordenadaX) != 1){
                printf("\n!!!-----Não pode inserir letras ou caracteres especiais, apenas números-----!!!\n");
                return;
            };
            //Verifica se a coordenada X é maior que 80
            if (coordenadaX > 80)
            {
                printf("\n!!!-----A coordenada X não pode ser maior que 80-----!!!\n");
            }

        } while (coordenadaX > 80);

        do
        {
            printf("Inserir Coordenada Y:");

            //Verifica se o utilizador insere um número e não letras ou caracteres especiais
            if(scanf("%i", &coordenadaY) != 1){
                printf("\n!!!-----Não pode inserir letras ou caracteres especiais, apenas números-----!!!\n");
                return;
            };

            //Verifica se a coordenada Y é maior que 25
            if (coordenadaY > 25)
            {
                printf("\n!!!-----A coordenada Y não pode ser maior que 25-----!!!\n");
            }

        } while (coordenadaY > 25);

        do
        {
            printf("Inserir o comprimento:");

            //Verifica se o utilizador insere um número e não letras ou caracteres especiais
            if(scanf("%i", &comprimento) != 1){
                printf("\n!!!-----Não pode inserir letras ou caracteres especiais, apenas números-----!!!\n");
                return;
            };

            //Verifica se o comprimento é menor que 2 ou maior que 80
            if (comprimento < 2 || comprimento > 80)
            {
                printf("!!!-----O comprimento não pode ser menor que 2 ou maior que 80!-----!!!\n");
            };

        }while (comprimento < 2 || comprimento > 80);

        do
        {
            printf("Inserir a altura:");

            if(scanf("%i", &altura) != 1){
                printf("\n!!!-----Não pode inserir letras ou caracteres especiais, apenas números-----!!!\n");
                return;
            };

            //Verifica se a altura é menor que 2 ou maior que 25
            if (altura <= 1 || altura > 25)
            {
                printf("!!!-----A altura não pode ser menor que 2 ou maior que 25!-----!!!\n");
            };

        } while (altura <= 1 || altura > 25);

        //Verifica se o retângulo está dentro dos limites da grelha
        dentroDosLimites = Retangulo_retanguloDentroDosLimites(coordenadaX, coordenadaY, comprimento, altura);

        if (dentroDosLimites == 0)
        {
            printf("\n!!!-----Retangulo fora dos limites da grelha-----!!!\n");
            printf("A grelha tem 80 de comprimento e 25 de largura. Coloque os dados novamente pff.\n");
        };


    } while (dentroDosLimites == 0);

    Retangulo_retangulo = malloc(sizeof(Retangulo));
    //Alocar memória para o retângulo e verificar se a alocação foi bem sucedida
    if (Retangulo_retangulo == NULL) {
        fprintf(stderr, "Falha ao alocar memoria .\n");
        return;
    }
    //Guarda os valores inseridos pelo utilizador no retângulo
    Retangulo_retangulo->coordenadaX = coordenadaX;
    Retangulo_retangulo->coordenadaY = coordenadaY;

    Retangulo_retangulo->comprimento = comprimento;
    Retangulo_retangulo->altura = altura;
    //Corrige as coordenadas para que o input do utilizador seja refletido corretamente na grelha
    Grelha_corrigirCoordenadas(Retangulo_retangulo);

    //Desenha o retângulo na grelha
    Retangulo_deformarRetangulo(Retangulo_retangulo);
    Retangulo_desenharLinhasVerticais(Retangulo_retangulo->coordenadaX, Retangulo_retangulo->coordenadaY, Retangulo_retangulo->comprimento, Retangulo_retangulo->altura);
    Retangulo_desenharLinhasHorizontais(Retangulo_retangulo->coordenadaX, Retangulo_retangulo->coordenadaY,Retangulo_retangulo->comprimento, Retangulo_retangulo->altura);

    Retangulo_retangulos[numeroRetangulos] = Retangulo_retangulo;

    numeroRetangulos++;
};

//Verifica se o retângulo existe nas coordenadas inseridas pelo utilizador
int Retangulo_retanguloExiste(int coordenadaX, int coordenadaY){
    Retangulo *retanguloAtual;

    for (int i = 0; i < numeroRetangulos; i++)
    {
        retanguloAtual = Retangulo_retangulos[i];
        if (retanguloAtual->coordenadaX == coordenadaX && retanguloAtual->coordenadaY == coordenadaY)
        {
            return 1;
        }

    }

    return 0;
};

//Desenha as linhas verticais do retângulo.
void Retangulo_desenharLinhasVerticais(int coordenadaX, int coordenadaY, int comprimento, int altura){

    //Desenha as linhas verticais e se estiver no inicio ou no fim da linha, desenha o simbolo do vertice
    for (int i = 0; i < altura; i++)
    {
        if (i==0 || i==altura-1)
        {
            grelha[coordenadaY+i][coordenadaX] = vertice;
            grelha[coordenadaY+i][coordenadaX + comprimento-1] = vertice;
            continue;
        }
        grelha[coordenadaY+i][coordenadaX] = linhaVertical;
        grelha[coordenadaY+i][coordenadaX + comprimento-1] = linhaVertical;
    }

};

//Desenha as linhas horizontais do retângulo.
void Retangulo_desenharLinhasHorizontais(int coordenadaX, int coordenadaY, int comprimento, int altura){
    for (int i = 1; i < comprimento-1; i++)
    {
        grelha[coordenadaY][coordenadaX + i] = linhaHorizontal;
        grelha[coordenadaY+altura-1][coordenadaX +i] = linhaHorizontal;
    }
};

// Retorna 0 se tiver fora dos limites da grelha.
int Retangulo_retanguloDentroDosLimites(int coordenadaX, int coordenadaY, int comprimento, int altura){

    if (coordenadaY - altura < 0 || coordenadaX + comprimento > 80)
    {
        return 0;
    }
    return 1;
};

//Verifica, desde a primeira coordenada dos X's, se existe já outro retangulo desenhado, linha a linha.
void Retangulo_aplicarGravidade(struct Retangulo *Retangulo_retangulo){
    int coordenadaFinal;

    for (int i = Retangulo_retangulo->coordenadaX; i < Retangulo_retangulo->comprimento + Retangulo_retangulo->coordenadaX; i++)
    {
        /*
        Se a coordenada não estiver vazia é decrementado a variável minCoordenadaY e volta a chamar a função recursivamente
        para verificar novamente a próxima linha. Assim que tiver uma linha "livre" corrige as coordanas do retangulo colocado
        como parâmetro.
        */
        if (grelha[minCoordenadaY][i] != ' ')
        {
            minCoordenadaY--;
            Retangulo_aplicarGravidade(Retangulo_retangulo);
            return;
        };
    };

    //Corrige a coordenada Y do retângulo para a coordenada final
    coordenadaFinal = minCoordenadaY - Retangulo_retangulo->altura+1;
    Retangulo_retangulo->coordenadaY = coordenadaFinal;
    minCoordenadaY = 25;
};

//Deforma o retângulo, simula a queda do retângulo
void Retangulo_deformarRetangulo(struct Retangulo *Retangulo_retangulo){

    int coordenadaInicial = Retangulo_retangulo->coordenadaY;
    int alturaInicial = Retangulo_retangulo->altura;
    int alturaFinal = Retangulo_retangulo->altura;
    int coordenadaFinal;
    int alturaQueda;
    int razaoAchatamento;

    /*
     É usada a função de aplicar gravidade para podermos saber a altura de queda, usando a a coordenada corrigida por esta função.
     */
    Retangulo_aplicarGravidade(Retangulo_retangulo);

    coordenadaFinal = Retangulo_retangulo->coordenadaY;
    alturaQueda = coordenadaFinal - coordenadaInicial;

    /*
    Calculado o valor da razão de  10% por unidade do eixo dos yy da altura de queda e multiplicado à altura inicial
    para se calcular a percentagem de queda da altura inicial.
    */

    razaoAchatamento = round(alturaInicial * (alturaQueda * 0.1));

    printf("Achatamento: %i  Altura Inicial: %i  AlturaQueda: %i Coordenada Final: %i  Coordenada Inicial: %i", razaoAchatamento, alturaInicial, alturaQueda, coordenadaFinal, coordenadaInicial);

    //Se a razão de achatamento for maior que a altua do retangulo, a altura fica igual a 1.

    if (razaoAchatamento >= Retangulo_retangulo->altura)
    {
        alturaFinal = 1;
        Retangulo_retangulo->altura = alturaFinal;

    }else if (razaoAchatamento < Retangulo_retangulo->altura)
    {
        //Removido o valor da razão de achatamento à altura para simular a "deformação"
        alturaFinal -= razaoAchatamento;
        Retangulo_retangulo->altura = alturaFinal;
    }

    Retangulo_aplicarGravidade(Retangulo_retangulo);

};

//Redesenhar o retângulo na grelha após a deformação
void Retangulo_redesenharRetangulo(struct Retangulo *Retangulo_retangulo){
    Retangulo_desenharLinhasVerticais(Retangulo_retangulo->coordenadaX, Retangulo_retangulo->coordenadaY, Retangulo_retangulo->comprimento,Retangulo_retangulo->altura);
    Retangulo_desenharLinhasHorizontais(Retangulo_retangulo->coordenadaX, Retangulo_retangulo->coordenadaY, Retangulo_retangulo->comprimento, Retangulo_retangulo->altura);
};

//Apagar o retângulo da grelha após a deformação
void Retangulo_apagarRetangulo(struct Retangulo *Retangulo_retangulo){

    int coordenadaX = Retangulo_retangulo->coordenadaX;
    int coordenadaY = Retangulo_retangulo->coordenadaY;
    int comprimento = Retangulo_retangulo->comprimento;
    int altura = Retangulo_retangulo->altura;

    //Vai-se às coordenadas do retangulo pretendido e coloca-se ' ' para simular o "apagar"

    for (int i = 0; i < altura; i++)
    {
        grelha[coordenadaY+i][coordenadaX] = ' ';
        grelha[coordenadaY+i][coordenadaX + comprimento-1] = ' ';
    };

    for (int j = 1; j < comprimento-1; j++)
    {
        grelha[coordenadaY][coordenadaX + j] = ' '; //Linha de cima
        grelha[coordenadaY+altura-1][coordenadaX +j] = ' '; //Linha de baixo
    }

};

//Verifica se o retângulo está dentro dos limites da grelha
int Retangulo_verSePodeMoverEsquerda(int coordenadaX, int altura, int numeroMovimentos){

    //Verifica por coordenada y se já existe um retângulo criado para a posição desejada pelo utilizador
    for (int i = 0; i < altura; i++)
    {
        for (int i = coordenadaX - numeroMovimentos; i < coordenadaX; i++)
        {
            if (grelha[minCoordenadaY][i] != ' ')
            {
                return 0;
            };
        }
        minCoordenadaY--;
    }
    minCoordenadaY = 25;
    return 1;
};

// Verifica se o retângulo está dentro dos limites da grelha
int Retangulo_verSePodeMoverDireita(int coordenadaX, int comprimento, int altura, int numeroMovimentos){

    //Verifica por coordenada y se já existe um retângulo criado para a posição desejada pelo utilizador
    for (int i = 0; i < altura; i++)
    {
        for (int i = coordenadaX + comprimento; i < coordenadaX + comprimento + numeroMovimentos; i++)
        {
            if (grelha[minCoordenadaY][i] != ' ')
            {
                return 0;
            };
        }
        minCoordenadaY--;
    }
    minCoordenadaY = 25;
    return 1;
};

//Função para mover o retângulo para a esquerda
void Retangulo_moveLeft(){

    Retangulo *retangulo;
    int coordenadaX;
    int coordenadaY;
    int retanguloExiste;
    int numeroMovimentos;
    int dentroDosLimites;
    int podeMover;
    int coordenadaXcorrigida;
    int coordenadaYcorrigida;

    do
    {
        printf("Inserir Coordenada X do retângulo:\n");

        //Verifica se o utilizador insere um número e não letras ou caracteres especiais
        if (scanf("%i", &coordenadaX) != 1)
        {
            printf("\n!!!-----Não pode inserir letras ou caracteres especiais, apenas números-----!!!\n");
            return;
        }

        //Adiciona 2 ao eixo dos x's para compensar os dois primeiros campos que estão a ser usados com os digitos das coordenadas Y
        coordenadaXcorrigida = coordenadaX + 2;

        if (coordenadaXcorrigida == 3)
        {
            printf("!!!-----Já não é possível mover este retângulo para a esquerda-----!!!");
            return;
        }

        printf("Inserir Coordenada Y do retângulo:\n");

        if (scanf("%i", &coordenadaY) != 1)
        {
            printf("\n!!!-----Não pode inserir letras ou caracteres especiais, apenas números-----!!!\n");
            return;
        }

        coordenadaYcorrigida = 26 - coordenadaY;

        //Verifica se o retângulo, referente às coordenadas inseridas, existe.
        retanguloExiste = Retangulo_retanguloExiste(coordenadaXcorrigida, coordenadaYcorrigida);

        if (retanguloExiste == 0)
        {
            printf("\n!!!-----Para as coordenadas que inseriu não existe nenhum retângulo-----!!!\n");
            return;
        }

        printf("Inserir número de Movimentos:\n");

        if (scanf("%i", &numeroMovimentos) != 1)
        {
            printf("\n!!!-----Não pode inserir letras ou caracteres especiais, apenas números-----!!!\n");
            return;
        }

        //Retorna o retângulo do array de structs através das coordenadas inseridas
        for (int i = 0; i < numeroRetangulos; i++)
        {
            if (Retangulo_retangulos[i]->coordenadaX == coordenadaXcorrigida && Retangulo_retangulos[i]->coordenadaY == coordenadaYcorrigida)
            {
                retangulo = Retangulo_retangulos[i];
            }
        };

        /*
Verificar se o retângulo já se encontra no inicio do eixo dos x's, se sim, não é possivel mover mais para a esquerda.
Verifica-se que é igual a 3 porque a grelha começa com 2 digitos para as coordenadasY, logo o seu inicio é 3.
*/

        dentroDosLimites = Retangulo_retanguloDentroDosLimites(coordenadaXcorrigida, coordenadaYcorrigida, Retangulo_retangulo->comprimento, Retangulo_retangulo->altura);
        podeMover = Retangulo_verSePodeMoverEsquerda(coordenadaXcorrigida, retangulo->altura, numeroMovimentos);


        if (dentroDosLimites == 0)
        {
            printf("\n!!!-----Movendo o retângulo como pretende, fica fora dos limites da grelha-----!!!\n");
        }else if (podeMover == 0)
        {
            printf("\n!!!-----Movendo o retângulo como pretende, vai ficar sobreposto a outro já existente-----!!!\n");
            return;
        }

    } while (dentroDosLimites == 0 | podeMover == 0 | retanguloExiste == 0);

    //Apagar o retângulo antigo
    Retangulo_apagarRetangulo(retangulo);
    //Subtrair o valor dos movimentos inseridos pelo utilizador à coordenada X de forma a simular o movimento
    retangulo->coordenadaX -= numeroMovimentos;
    Retangulo_deformarRetangulo(retangulo);
    //Redesenhar retângulo novo na grelha
    Retangulo_redesenharRetangulo(retangulo);
};


//Função para mover o retângulo para a direita
void Retangulo_moveRight(){

    Retangulo *retangulo;
    int coordenadaX;
    int coordenadaY;
    int retanguloExiste;
    int numeroMovimentos;
    int dentroDosLimites;
    int podeMover;
    int coordenadaXcorrigida;
    int coordenadaYcorrigida;

    do
    {
        printf("Inserir Coordenada X do retângulo:\n");

        if (scanf("%i", &coordenadaX) != 1)
        {
            printf("\n!!!-----Não pode inserir letras ou caracteres especiais, apenas números-----!!!\n");
            return;
        }

        coordenadaXcorrigida = coordenadaX + 2;

        printf("Inserir Coordenada Y do retângulo:\n");

        if (scanf("%i", &coordenadaY) != 1)
        {
            printf("\n!!!-----Não pode inserir letras ou caracteres especiais, apenas números-----!!!\n");
            return;
        }

        //Corrige a coordenada Y para que o input do utilizador seja refletido corretamente na grelha
        coordenadaYcorrigida = 26 - coordenadaY;

        //Verifica se o retângulo, referente às coordenadas inseridas, existe.
        retanguloExiste = Retangulo_retanguloExiste(coordenadaXcorrigida, coordenadaYcorrigida);

        if (retanguloExiste == 0)
        {
            printf("\n!!!-----Para as coordenadas que inseriu não existe nenhum retângulo-----!!!\n");
            return;
        }

        printf("Inserir número de Movimentos:\n");

        if (scanf("%i", &numeroMovimentos) != 1)
        {
            printf("\n!!!-----Não pode inserir letras ou caracteres especiais, apenas números-----!!!\n");
            return;
        }

        //Retorna o retângulo do array de structs através das coordenadas inseridas
        for (int i = 0; i < numeroRetangulos; i++)
        {
            if (Retangulo_retangulos[i]->coordenadaX == coordenadaXcorrigida && Retangulo_retangulos[i]->coordenadaY == coordenadaYcorrigida)
            {
                retangulo = Retangulo_retangulos[i];
            }
        };

        /*
Verificar se o retângulo já se encontra no inicio do eixo dos x's, se sim, não é possivel mover mais para a direita.
Verifica-se que é igual a 3 porque a grelha começa com 2 digitos para as coordenadasY, logo o seu inicio é 3.
*/
        if (coordenadaXcorrigida == 80)
        {
            printf("!!!-----Já não é possível mover este retângulo para a direita-----!!!");
            return;
        }

        //Verifica se o retângulo está dentro dos limites da grelha
        dentroDosLimites = Retangulo_retanguloDentroDosLimites(coordenadaXcorrigida, coordenadaYcorrigida, Retangulo_retangulo->comprimento, Retangulo_retangulo->altura);
        podeMover = Retangulo_verSePodeMoverDireita(coordenadaXcorrigida, retangulo->comprimento, retangulo->altura, numeroMovimentos);

        if (dentroDosLimites == 0)
        {
            printf("\n!!!-----Movendo o retângulo como pretende, fica fora dos limites da grelha-----!!!\n");
        }else if (podeMover == 0)
        {
            printf("\n!!!-----Movendo o retângulo como pretende, vai ficar sobreposto a outro já existente-----!!!\n");
            return;
        }

    } while (dentroDosLimites == 0 | podeMover == 0 | retanguloExiste == 0);

    //Apagar o retângulo antigo
    Retangulo_apagarRetangulo(retangulo);
    //Subtrair o valor dos movimentos inseridos pelo utilizador à coordenada X de forma a simular o movimento
    retangulo->coordenadaX += numeroMovimentos;
    Retangulo_deformarRetangulo(retangulo);
    //Redesenhar retângulo novo na grelha
    Retangulo_redesenharRetangulo(retangulo);

};