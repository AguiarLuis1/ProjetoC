//
// Created by Aguia on 28/12/2018.
//

#ifndef PROJETOAED_LP2_R9_H
#define PROJETOAED_LP2_R9_H

#include "library.h"
/**
 *
 * @param dictionary dicionario
 * @param soup tabuleiro
 * @param stackdirection endereço da estrutura que vai guardar as direções)
 */
void checkword(DICIONARIO dictionary, SOPA soup,STACKDIRECAO *stackdirection);
/**
 *
 * @param search  que se pretende verificar
 * @param letra struct LETRA na pos que se pretende verificar
 * @return 1 se para avançar e 0 para tentar a prox direção
 */
int checkconsistency(char search, LETRA *letra);
/**
 *
 * @param word palavra que se está á procura
 * @param current posição atual no tabuleiro
 * @param direction matriz que vai guardas as direções
 * @param size variavel auxiliar que começa em 0
 * @param col para ser possivel guardar a col final
 * @param line para ser possivel guardar a line final
 * @param pos numero de vezes que aparece a palavra +1
 */
void find_path(char *word, LETRA *current, int **direction, int size,int col, int line, int *pos);
/**
 *
 * @param stackdirection stack das direções
 */
void print_referencias(STACKDIRECAO stackdirection);

#endif //PROJETOAED_LP2_R9_H
