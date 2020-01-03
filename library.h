//
// Created by Aguia on 25/12/2018.
//

#ifndef PROJETOAED_LP2_LIBRARY_H
#define PROJETOAED_LP2_LIBRARY_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>


//struct das letras da sopa apontador de norte no sentido dos ponteiros
typedef struct letra {
    char letra;
    struct letra *n;
    struct letra *ne;
    struct letra *e;
    struct letra *se;
    struct letra *s;
    struct letra *so;
    struct letra *o;
    struct letra *no;
} LETRA;

//struct da sopa com apontador para a primeira letra que leva ás outras
typedef struct sopa {
    int nCols;
    int nLines;
    LETRA *pfirst;
} SOPA;

//struct das palavras do dicionario
typedef struct palavra {
   char *ppalavra;
   struct palavra *pnext;
} PALAVRA;

//struct da sopa com apontador para a primeira letra que leva ás outras
typedef struct dicionario {
    int nPalavras;
    PALAVRA *pfirst;
} DICIONARIO;

typedef struct direcao{
    char *palavra;
    int nvezes;
    int **matrizdirec;
    struct direcao *pnext;
}DIRECAO;

typedef struct stackdirecao{
    int npalavras;
    DIRECAO *pfirst;
}STACKDIRECAO;


#endif //PROJETOAED_LP2_LIBRARY_H
