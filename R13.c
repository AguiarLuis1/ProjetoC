//
// Created by Aguia on 02/01/2019.
//

#include "R13.h"

void save_dictionary_bin(DICIONARIO dictionary, char fn[]) {
    size_t namelen;
    FILE *fp = fopen(fn, "wb");
    if (fp != NULL) {
        fwrite(&dictionary, sizeof(DICIONARIO), 1, fp);
        PALAVRA *temp = dictionary.pfirst;
        for (int i = 0; i < dictionary.nPalavras; ++i) {
            namelen = (strlen(temp->ppalavra) + 1);
            fwrite(&namelen, sizeof(int), 1, fp);
            fwrite(temp->ppalavra, sizeof(char), namelen, fp);
            temp = temp->pnext;
        }
        fclose(fp);
    }
}

void read_dictionary_bin(DICIONARIO *dictionary, char fn[]) {
    int namelen;
    FILE *fp = fopen(fn, "rb");
    if (fp != NULL) {
        fread(dictionary, sizeof(DICIONARIO), 1, fp);
        PALAVRA *current = malloc(sizeof(PALAVRA)), *previous;
        dictionary->pfirst = current;
        for (int i = 0; i < dictionary->nPalavras; ++i) {
            fread(&namelen, sizeof(int), 1, fp);
            current->ppalavra = malloc(sizeof(char) * (namelen));
            fread(current->ppalavra, sizeof(char), namelen, fp);
            previous = current;
            if (i == dictionary->nPalavras - 1)
                current = NULL;
            else
                current = malloc(sizeof(PALAVRA));
            previous->pnext = current;
        }
        fclose(fp);
    }
}

void save_soup_bin(SOPA soup, char fn[]) {
    FILE *fp = fopen(fn, "wb");
    if (fp != NULL) {
        fwrite(&soup.nLines, sizeof(int), 1, fp);
        fwrite(&soup.nCols, sizeof(int), 1, fp);
        LETRA *current, *pline;
        pline = soup.pfirst;
        current = soup.pfirst;
        for (int line = 0; line < soup.nLines; ++line) {
            for (int col = 0; col < soup.nCols; ++col) {
                fwrite(&current->letra, sizeof(char), 1, fp);
                current = current->e;
            }
            pline = pline->s;
            current = pline;
        }
        fclose(fp);
    }
}
void read_soup_bin(SOPA *soup, char fn[]) {
    FILE *fp = fopen(fn, "rb");
    if (fp != NULL) {
        fread(&soup->nLines, sizeof(int), 1, fp);
        fread(&soup->nCols, sizeof(int), 1, fp);
        char mAux[soup->nLines][soup->nCols];
        for (int i = 0; i < soup->nLines; ++i) {
            for (int j = 0; j < soup->nCols; ++j) {
                fread(&mAux[i][j], sizeof(char), 1, fp);
            }
        }
        fclose(fp);
        LETRA *current = malloc(sizeof(LETRA)), *prevLine, *prevCol;
        soup->pfirst = current;
        prevCol = soup->pfirst;
        prevLine = soup->pfirst;
        for (int line = 0; line < soup->nLines; ++line) {
            for (int col = 0; col < soup->nCols; ++col) {
                if (line == 0 && col == 0) {
                    current->letra = mAux[line][col];
                    current->n = NULL;
                    current->ne = NULL;
                    current->e = malloc(sizeof(LETRA));
                    current->se = malloc(sizeof(LETRA));
                    current->s = malloc(sizeof(LETRA));
                    current->so = NULL;
                    current->o = NULL;
                    current->no = NULL;
                }
                if (line == 0 && col != 0 && col != soup->nCols - 1) {
                    current->letra = mAux[line][col];
                    current->n = NULL;
                    current->ne = NULL;
                    current->e = malloc(sizeof(LETRA));
                    current->se = malloc(sizeof(LETRA));
                    current->s = prevCol->se;
                    current->so = prevCol->s;
                    current->o = prevCol;
                    current->no = NULL;
                }
                if (line == 0 && col == soup->nCols - 1) {
                    current->letra = mAux[line][col];
                    current->n = NULL;
                    current->ne = NULL;
                    current->e = NULL;
                    current->se = NULL;
                    current->s = prevCol->se;
                    current->so = prevCol->s;
                    current->o = prevCol;
                    current->no = NULL;
                }
                if (line != 0 && col == 0 && line != soup->nLines - 1) {
                    current->letra = mAux[line][col];
                    current->n = prevLine;
                    current->ne = prevLine->e;
                    current->e = prevLine->se;
                    current->se = malloc(sizeof(LETRA));
                    current->s = malloc(sizeof(LETRA));
                    current->so = NULL;
                    current->o = NULL;
                    current->no = NULL;
                }
                if (line != 0 && col != 0 && col != soup->nCols - 1) {
                    current->letra = mAux[line][col];
                    current->n = prevCol->ne;
                    current->ne = prevCol->ne->e;//debug
                    current->e = prevCol->ne->se;//debug
                    current->se = malloc(sizeof(LETRA));
                    current->s = prevCol->se;
                    current->so = prevCol->s;
                    current->o = prevCol;
                    current->no = prevCol->n;
                }
                if (line != 0 && col != 0 && col == soup->nCols - 1) {
                    current->letra = mAux[line][col];
                    current->n = prevCol->ne;
                    current->ne = NULL;
                    current->e = NULL;
                    current->se = NULL;
                    current->s = prevCol->se;
                    current->so = prevCol->s;
                    current->o = prevCol;
                    current->no = prevCol->n;
                }
                if (line == soup->nLines - 1 && col == 0) {
                    current->letra = mAux[line][col];
                    current->n = prevLine;
                    current->ne = prevLine->e;
                    current->e = prevLine->se;
                    current->se = NULL;
                    current->s = NULL;
                    current->so = NULL;
                    current->o = NULL;
                    current->no = NULL;
                }
                if (line == soup->nLines - 1 && col != 0 && col != soup->nCols - 1) {
                    current->letra = mAux[line][col];
                    current->n = prevCol->ne;
                    current->ne = prevCol->ne->e;
                    current->e = prevCol->ne->se;
                    current->se = NULL;
                    current->s = NULL;
                    current->so = NULL;
                    current->o = prevCol;
                    current->no = prevCol->n;
                }
                if (line == soup->nLines - 1 && col != 0 && col == soup->nCols - 1) {
                    current->letra = mAux[line][col];
                    current->n = prevCol->ne;
                    current->ne = NULL;
                    current->e = NULL;
                    current->se = NULL;
                    current->s = NULL;
                    current->so = NULL;
                    current->o = prevCol;
                    current->no = prevCol->n;
                }


                prevCol = current;
                current = current->e;
            }
            if (line >= 1) {
                prevLine = prevLine->s;
            }
            current = prevLine->s;

        }
    }
}
void save_directions_bin(STACKDIRECAO stackdirection, char fn[]){
    FILE *fp=fopen(fn,"w");
    if(fp!=NULL){
        fwrite(&stackdirection.npalavras, sizeof(int),1,fp);
        DIRECAO *current=stackdirection.pfirst;
        for (int i = 0; i <stackdirection.npalavras ; ++i) {
            fwrite(&current->palavra, sizeof(char),strlen(current->palavra)+1,fp);
            fwrite(&current->nvezes,sizeof(int),1,fp);
            for (int j = 0; j <current->nvezes ; ++j) {
                for (int k = 0; k <strlen(current->palavra)+3 ; ++k) {
                    fwrite((*current->matrizdirec+j)+k,sizeof(int),1,fp);
                }
            }
            current=current->pnext;
        }
        fclose(fp);
    }
}
