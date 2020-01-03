//
// Created by Aguia on 02/01/2019.
//

#ifndef PROJETOAED_LP2_R12_H
#define PROJETOAED_LP2_R12_H

#include "library.h"
/**
 *
 * @param dictionary dicionario
 * @param fn path para o ficheiro
 */
void save_dictionary_txt(DICIONARIO dictionary, char fn[]);
/**
 *
 * @param soup tabuleiro
 * @param fn path para o ficheiro
 */
void save_soup_txt(SOPA soup, char fn[]);
/**
 *
 * @param stackdirection stack das direções
 * @param fn path para o ficheiro
 */
void save_referencias_txt(STACKDIRECAO stackdirection, char fn[]);


#endif //PROJETOAED_LP2_R12_H
