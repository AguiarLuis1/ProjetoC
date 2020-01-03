//
// Created by Aguia on 30/12/2018.
//

#include "R10.h"

char *charsfrompos(SOPA soup) {
    int linicial, cinicial, nmovimentos, aux;
    printf("Insira a linha inicial[0->%d]:\n",soup.nLines-1);
    scanf("%d", &linicial);
    printf("Insira a coluna inicial[0->%d]:\n",soup.nCols-1);
    scanf("%d", &cinicial);
    LETRA *current= soup.pfirst;
    if (linicial <= soup.nLines && cinicial <= soup.nCols) {//vai avançar para a celula equivalente á linha/col definida
        for (int i = 0; i < linicial; ++i) {
            current = current->s;
        }
        for (int j = 0; j < cinicial; ++j) {
            current = current->e;
        }

        printf("Insira o numero de movimentos que pretente inserir:\n");
        scanf("%d", &nmovimentos);
        char *carateres = malloc(sizeof(char) * nmovimentos + 1);//+1 para o \0
        *(carateres + nmovimentos) = '\0';
        printf("Insira a direcao que pretende seguir(1=s,2=n,3=e,4=o,5=no,6=ne,7=so,8=se\n");
        for (int k = 0; k < nmovimentos; ++k) {
            scanf("%d", &aux);
            if (aux == 1){
                if (current->s != NULL)
                    current = current->s;
                else {
                    printf("Fora da Sopa\n");
                    k--;
                }
            }
            if (aux == 2){
                if (current->n != NULL)
                    current = current->n;
                else {
                    printf("Fora da Sopa\n");
                    k--;
                }
            }
            if (aux == 3){
                if (current->e != NULL)
                    current = current->e;
                else {
                    printf("Fora da Sopa\n");
                    k--;
                }
            }
            if (aux == 4){
                if (current->o != NULL)
                    current = current->o;
                else {
                    printf("Fora da Sopa\n");
                    k--;
                }
            }
            if (aux == 5){
                if (current->no != NULL)
                    current = current->no;
                else {
                    printf("Fora da Sopa\n");
                    k--;
                }
            }
            if (aux == 6){
                if (current->ne != NULL)
                    current = current->ne;
                else {
                    printf("Fora da Sopa\n");
                    k--;
                }
            }
            if (aux == 7){
                if (current->so != NULL)
                    current = current->so;
                else {
                    printf("Fora da Sopa\n");
                    k--;
                }
            }
            if (aux == 8){
                if (current->se != NULL)
                    current = current->se;
                else {
                    printf("Fora da Sopa\n");
                    k--;
                }
            }
            *(carateres+k)=current->letra;//guarda na string carateres a letra
        }
        return carateres;
    } else
        printf("Linha ou Coluna maior que as da Sopa\n");
}