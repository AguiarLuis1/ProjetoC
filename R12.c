//
// Created by Aguia on 02/01/2019.
//

#include "R12.h"

void save_dictionary_txt(DICIONARIO dictionary, char fn[]) {
    FILE *fp;
    fp = fopen(fn, "w");
    if (fp != NULL) {
        fprintf(fp, "Palavras: %d\n", dictionary.nPalavras);
        PALAVRA *temp = dictionary.pfirst;
        for (int i = 0; i < dictionary.nPalavras; ++i) {
            fprintf(fp, "%s\n", temp->ppalavra);
            temp = temp->pnext;
        }
        fclose(fp);
    }
}

void save_soup_txt(SOPA soup, char fn[]) {
    FILE *fp;
    fp = fopen(fn, "w");
    if (fp != NULL) {
        fprintf(fp, "NCols: %d\n", soup.nCols);
        fprintf(fp, "NLines: %d\n", soup.nLines);
        LETRA *current, *pline;
        pline = soup.pfirst;
        current = soup.pfirst;
        for (int line = 0; line < soup.nLines; ++line) {
            for (int col = 0; col < soup.nCols; ++col) {
                fprintf(fp, "%c", current->letra);
                current = current->e;
            }
            fprintf(fp, "\n");
            pline = pline->s;
            current = pline;
        }
        fclose(fp);
    }
}

void save_referencias_txt(STACKDIRECAO stackdirection, char fn[]) {
    FILE *fp;
    fp = fopen(fn, "w");
    if (fp != NULL) {
        fprintf(fp,"Npalavras: %d\n",stackdirection.npalavras);
        DIRECAO *current = stackdirection.pfirst;
        for (int k = 0; k < stackdirection.npalavras; ++k) {
            fprintf(fp,"Palavra: %s\n", current->palavra);
            fprintf(fp,"Nvezes= %d\n", current->nvezes);
            int **mDirections = current->matrizdirec;
            for (int j = 1; j < current->nvezes +1; ++j) {//+1 devido á linha 0 da matriz estar reservada para mudar as posições e copiar p as restantes
                for (int i = 0; i <strlen(current->palavra)+3 ; ++i) {
                    fprintf(fp,"%d ",*(*(mDirections+j)+i));
                }
            }
            fprintf(fp,"\n");
            current = current->pnext;
        }
        fclose(fp);
    }
}
