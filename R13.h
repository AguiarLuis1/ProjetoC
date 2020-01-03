//
// Created by Aguia on 02/01/2019.
//

#ifndef PROJETOAED_LP2_R13_H
#define PROJETOAED_LP2_R13_H

#include "library.h"
/**
 *
 * @param dictionary dicionario
 * @param fn path para o ficheiro
 */
void save_dictionary_bin(DICIONARIO dictionary, char fn[]);
/**
 *
 * @param dictionary dicionario
 * @param fn path para o ficheiro
 */
void read_dictionary_bin(DICIONARIO *dictionary, char fn[]);
/**
 *
 * @param soup tabuleiro
 * @param fn path para o ficheiro
 */
void save_soup_bin(SOPA soup, char fn[]);
/**
 *
 * @param soup tabuleiro
 * @param fn path para o ficheiro
 */
void read_soup_bin(SOPA *soup, char fn[]);
/**
 *
 * @param stackdirection stack das direções
 * @param fn path para o ficheiro
 */
void save_directions_bin(STACKDIRECAO stackdirection, char fn[]);


#endif //PROJETOAED_LP2_R13_H
