//
// Created by Aguia on 26/12/2018.
//

#include "R8.h"

void read_soup_txt(SOPA *soup, char fn[]) {
    FILE *fp;
    fp = fopen(fn, "r");//r=modo de leitura
    char mAux[100][100];//Matriz auxiliar para armazenar os valor lidos do txt(não armazena memoria)
    if (fp != NULL) {
        fscanf(fp, "%*s%d\n", &(soup->nCols));
        fscanf(fp, "%*s%d\n", &(soup->nLines));
        if (soup->nCols != 0 && soup->nLines != 0) {
            for (int line = 0; line < soup->nLines; ++line) {
                for (int col = 0; col < soup->nCols; ++col) {
                    fscanf(fp, "%c", &mAux[line][col]);
                }
                fscanf(fp, "\n");
            }
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

void create_soup_from_dictionary(SOPA *soup, DICIONARIO dictionary) {
    soup->nLines = 2*dictionary.nPalavras;
    soup->nCols = 2*dictionary.nPalavras;
    LETRA *current = malloc(sizeof(LETRA)), *prevLine, *prevCol;
    soup->pfirst = current;
    prevCol = soup->pfirst;
    prevLine = soup->pfirst;
    srand(time(NULL));
    for (int line = 0; line < soup->nLines; ++line) {
        for (int col = 0; col < soup->nCols; ++col) {
            if (line == 0 && col == 0) {
                current->letra = 'A' + (rand() % 24);
                //current->letra = '0';
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
                current->letra = 'A' + (rand() % 24);
                //current->letra = '0';
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
                current->letra = 'A' + (rand() % 24);
                //current->letra = '0';
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
                current->letra = 'A' + (rand() % 24);
                //current->letra = '0';
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
                current->letra = 'A' + (rand() % 24);
                //current->letra = '0';
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
                current->letra = 'A' + (rand() % 24);
                //current->letra = '0';
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
                current->letra = 'A' + (rand() % 24);
                //current->letra = '0';
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
                current->letra = 'A' + (rand() % 24);
                //current->letra = '0';
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
                current->letra = 'A' + (rand() % 24);
                //current->letra = '0';
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
    int mAux[MAX50][MAX50];
    //colocar a matriz a 0's
    for (int j = 0; j < soup->nLines; ++j) {
        for (int i = 0; i < soup->nCols; ++i) {
            mAux[j][i] = 0;
        }
    }
    PALAVRA *word = dictionary.pfirst;
    for (int i = 0; i < dictionary.nPalavras; ++i) {
        LETRA *letter = soup->pfirst;
        while (1) {
            int line = rand() % (soup->nLines);//random line
            int col = rand() % (soup->nLines);//random col
            if (mAux[line][col] == 0) {
                for (int k = 0; k < line; ++k) {//p chegar á celula equivalente á col/line
                    letter = letter->s;
                }
                for (int j = 0; j < col; ++j) {
                    letter = letter->e;
                }
                mAux[line][col] = 1;
                letter->letra = *word->ppalavra;
                write_word(letter, word->ppalavra + 1, col, line, mAux);
                break;
            }
        }
        word = word->pnext;
    }
}

void write_word(LETRA *current, char *word, int col, int line, int mAux[MAX50][MAX50]) {
    while (*word != '\0') {
        //SO
        if (checkposition(*word, current->so, col - 1, line + 1, mAux)) {
            current = current->so;
            col--;
            line++;
            mAux[line][col] = 1;
            current->letra = *(word);
            word++;
            continue;
        }
        //NO
        if (checkposition(*word, current->no, col - 1, line - 1, mAux)) {
            current = current->no;
            col--;
            line--;
            mAux[line][col] = 1;
            current->letra = *(word);
            word++;
            continue;
        }
        //SE
        if (checkposition(*word, current->se, col + 1, line + 1, mAux)) {
            current = current->se;
            col++;
            line++;
            mAux[line][col] = 1;
            current->letra = *(word);
            word++;
            continue;
        }
        //SUL
        if (checkposition(*word, current->s, col, line + 1, mAux)) {
            current = current->s;
            line++;
            mAux[line][col] = 1;
            current->letra = *(word);
            word++;
            continue;
        }
        //NORTE
        if (checkposition(*word, current->n, col, line - 1, mAux)) {
            current = current->n;
            line--;
            mAux[line][col] = 1;
            current->letra = *(word);
            word++;
            continue;

        }
        //ESTE
        if (checkposition(*word, current->e, col + 1, line, mAux)) {
            current = current->e;
            col++;
            mAux[line][col] = 1;
            current->letra = *(word);
            word++;
            continue;

        }
        //OESTE
        if (checkposition(*word, current->o, col + 1, line, mAux)) {
            current = current->o;
            line++;
            mAux[line][col] = 1;
            current->letra = *(word);
            word++;
            continue;

        }
        //NE
        if (checkposition(*word, current->ne, col + 1, line - 1, mAux)) {
            current = current->ne;
            col++;
            line--;
            mAux[line][col] = 1;
            current->letra = *(word);
            word++;
            continue;
        }
        mAux[line][col]=0;
        return;
    }
}

int checkposition(char word, LETRA *current, int col, int line, int mAux[MAX50][MAX50]) {
    if (current != NULL && col>0 && line >0) {
        if ((mAux[line][col] == 0 && current->letra != word) || (mAux[line][col] == 1 && current->letra == word))
            return 1;
    }
    return 0;
}

