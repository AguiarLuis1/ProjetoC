//
// Created by Aguia on 28/12/2018.
//

#include "R9.h"

void checkword(DICIONARIO dictionary, SOPA soup, STACKDIRECAO *stackdirection) {
    PALAVRA *word = dictionary.pfirst;
    stackdirection->npalavras = dictionary.nPalavras;
    stackdirection->pfirst = malloc(sizeof(DIRECAO));
    DIRECAO *direction = stackdirection->pfirst, *previous;

    for (int i = 0; i < dictionary.nPalavras; ++i) {
        direction->palavra = malloc(sizeof(char) * strlen(word->ppalavra) + 1);
        strcpy(direction->palavra, word->ppalavra);
        LETRA *lettercurrent, *pline;
        pline = soup.pfirst;
        lettercurrent = soup.pfirst;
        int *pos = malloc(sizeof(int));
        *pos = 1;//pos 0 esta sempre a ser alterada
        int **mdirections = malloc(100 * sizeof(int *));//alloca 100 espaços para o numero de x que a word aparece
        *(mdirections) = malloc((strlen(word->ppalavra) + 3) * sizeof(int));//alloca memoria para a posição 0
        direction->matrizdirec = mdirections;

        for (int line = 0; line < soup.nLines; ++line) {
            for (int col = 0; col < soup.nCols; ++col) {
                if (lettercurrent->letra ==
                    *(word->ppalavra)) { //Compara todas as letras da sopa de letras com a primeira letra da palavra que procuramos
                    *(*(mdirections) + 0) = line;
                    *(*(mdirections) + 1) = col;
                    find_path((word->ppalavra + 1), lettercurrent,
                              mdirections, 4, col, line,
                              pos);//começa em 4 por causa das 4 primeiras posições estarem reservadar
                }
                lettercurrent = lettercurrent->e;
            }
            pline = pline->s;
            lettercurrent = pline;
        }
        direction->nvezes = *pos-1;//-1 porque a pos 0 está reservada
        word = word->pnext;
        previous = direction;
        if (i == dictionary.nPalavras - 1)//o último tem de apontar para NULL
            direction = NULL;
        else
            direction = malloc(sizeof(DIRECAO));
        previous->pnext = direction;
    }
}

int checkconsistency(char search, LETRA *letra) {

    if (letra != NULL)
        if (letra->letra == search)
            return 1;

    return 0;
}

void find_path(char *word, LETRA *current, int **direction, int size, int col, int line, int *pos) {
    if (*word == '\0') { *(*(direction) + 2) = line;//size -3 porque o find path so trabalha com a palavra sem a 1ª letra e tem 4 espaços reservados
        *(*(direction) + 3) = col;
        *(direction + (*pos)) = malloc((size + 3) * sizeof(int));//alloca memória para as direções
        for (int i = 0; i < size; i++) {
            *(*(direction + *pos) + i) = *(*(direction) + i);
        }
        (*pos)++;
        return;
    }
    //SUL
    if (checkconsistency(*word, current->s)) {
        *(*(direction) + size) = 1;
        find_path((word + 1), current->s, direction, size + 1, col, line + 1, pos);
    }
    //NORTE
    if (checkconsistency(*word, current->n)) {
        *(*(direction) + size) = 2;
        find_path((word + 1), current->n, direction, size + 1, col - 1, line, pos);
    }
    //ESTE
    if (checkconsistency(*word, current->e)) {
        *(*(direction) + size) = 3;
        find_path((word + 1), current->e, direction, size + 1, col + 1, line, pos);
    }
    //OESTE
    if (checkconsistency(*word, current->o)) {
        *(*(direction) + size) = 4;
        find_path((word + 1), current->o, direction, size + 1, col - 1, line, pos);
    }
    //NO
    if (checkconsistency(*word, current->no)) {
        *(*(direction) + size) = 5;
        find_path((word + 1), current->no, direction, size + 1, col - 1, line - 1, pos);
    }
    //NE
    if (checkconsistency(*word, current->ne)) {
        *(*(direction) + size) = 6;
        find_path((word + 1), current->ne, direction, size + 1, col + 1, line - 1, pos);
    }
    //SE
    if (checkconsistency(*word, current->se)) {
        *(*(direction) + size) = 7;
        find_path((word + 1), current->se, direction, size + 1, col + 1, line + 1, pos);
    }
    //SO
    if (checkconsistency(*word, current->so)) {
        *(*(direction) + size) = 8;
        find_path((word + 1), current->so, direction, size + 1, col - 1, line + 1, pos);
    }

}

void print_referencias(STACKDIRECAO stackdirection) {
    printf("Localizacao das Palavras:\n");
    DIRECAO *current = stackdirection.pfirst;
    for (int k = 0; k < stackdirection.npalavras; ++k) {
        printf("\nPalavra:%s\n", current->palavra);
        printf("Numero de vezes encontrada= %d\n", current->nvezes);
        int **mDirections=current->matrizdirec;
        for (int j = 1; j < current->nvezes+1; ++j) {//+1 devido á linha 0 da matriz estar reservada para mudar as posições e copiar p as restantes
            printf("[%d,%d]->[%d,%d] | ", *(*(mDirections + j) + 0), *(*(mDirections + j) + 1),
                   *(*(mDirections + j) + 2),
                   *(*(mDirections + j) + 3));
            for (int i = 4; i < strlen(current->palavra)+3; i++) {//começa em 4 porque as primeiras 4 posições são as posições inicial e final
                switch (*(*(mDirections + j) + i)) {
                    case 1:
                        printf("S");
                        break;

                    case 2:
                        printf("N");
                        break;

                    case 3:
                        printf("E");
                        break;

                    case 4:
                        printf("O");
                        break;

                    case 5:
                        printf("NO");
                        break;

                    case 6:
                        printf("NE");
                        break;

                    case 7:
                        printf("SE");
                        break;

                    case 8:
                        printf("SO");
                        break;
                }
                if (i < strlen(current->palavra)+2) {
                    printf("->");
                }
            }
            printf("\n");
        }
        current=current->pnext;
    }
}

