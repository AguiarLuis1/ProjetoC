//
// Created by Aguia on 25/12/2018.
//

#include "R5.h"
void read_dicionary_txt(DICIONARIO *dic, char fn[]){
    FILE *fp;
    fp=fopen(fn,"r");
    if(fp!=NULL){
        fscanf(fp,"%*s%d\n",&(dic->nPalavras));//o %*s ignora a string Palavras:
        if (dic->nPalavras!=0){
            PALAVRA *current=malloc(sizeof(PALAVRA)),*previous;
            dic->pfirst=current;
            for (int i = 0; i <dic->nPalavras ; ++i) {
                char palavra[50];
                fscanf(fp,"%s",palavra);
                current->ppalavra=malloc(sizeof(char)*strlen(palavra)+1);//+1 para o \0
                strcpy(current->ppalavra,palavra);
                previous=current;
                if (i == dic->nPalavras - 1)//o último tem de apontar para NULL
                    current = NULL;
                else
                    current = malloc(sizeof(PALAVRA));
                previous->pnext = current;
            }
        }
    }
    fclose(fp);
}

void manually_insert_dictionary(DICIONARIO *dic){
    printf("Com quantas palavras pretende criar o dicionario?");
    scanf("%d",&(dic->nPalavras));//inteiros precisam de i comercial(endereço)
    printf("Insira em CAPS LOCK a palavra que pretende adicionar\n");
    if (dic->nPalavras!=0){
        PALAVRA *current=malloc(sizeof(PALAVRA)),*previous;
        dic->pfirst=current;
        for (int i = 0; i <dic->nPalavras ; ++i) {
            char palavra[50];
            printf("[%d]->",i+1);
            scanf("%s",palavra);
            current->ppalavra=malloc(sizeof(char)*strlen(palavra)+1);//+1 para o \0
            strcpy(current->ppalavra,palavra);
            previous=current;
            if (i == dic->nPalavras - 1)
                current = NULL;
            else
                current = malloc(sizeof(PALAVRA));
            previous->pnext = current;
        }
    }
}

