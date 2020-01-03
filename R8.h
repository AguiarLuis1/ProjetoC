//
// Created by Aguia on 26/12/2018.
//

#ifndef PROJETOAED_LP2_R8_H
#define PROJETOAED_LP2_R8_H

#include "library.h"

#define MAX50 50
/**
 *
 * @param soup endereço do tabuleiro
 * @param fn ficheiro de onde lê
 */
void read_soup_txt(SOPA *soup, char fn[]);
/**
 *
 * @param soup endereço do tabuleiro
 * @param dictionary dicionario
 */
void create_soup_from_dictionary(SOPA *soup, DICIONARIO dictionary);

/**
 *
 * @param current pos na lista ligada(tabuleiro) equivalente á col e line
 * @param word palavra que se está a verificar
 * @param col coluna definida aleatoriamente
 * @param line linha definida aleatoriamente
 * @param mAux matriz auxiliar
 */
void write_word(LETRA *current, char *word, int col, int line, int mAux[MAX50][MAX50]);

/** FUNÇÃO AUXILIAR PARA SABER SE PODE AVANÇAR NESTA DIREÇÃO
 *
 * @param word letra que se pretende verificar
 * @param current posição na lista ligada do tabuleiro
 * @param col coluna atual(util para a mAux)
 * @param line linha atual(util para a mAux)
 * @param mAux matriz auxiliar que armazena as posições já ocupadas
 * @return
 */
int checkposition(char word, LETRA *current, int col, int line, int mAux[MAX50][MAX50]);

#endif //PROJETOAED_LP2_R8_H
