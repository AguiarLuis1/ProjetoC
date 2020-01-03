//
// Created by Aguia on 26/12/2018.
//

#include "Sopa.h"

void print_sopa(SOPA soup){
    printf("Sopa De Letras:\n");
    LETRA *current,*pline;
    pline=soup.pfirst;
    current=soup.pfirst;
    for (int line = 0; line < soup.nLines ; ++line) {
        for (int col = 0; col < soup.nCols ; ++col) {
        printf("%c",current->letra);
            current=current->e;
        }
        printf("\n");
        pline=pline->s;
        current=pline;
    }
}
