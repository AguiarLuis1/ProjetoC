//
// Created by Aguia on 25/12/2018.
//

#include "Dicionario.h"
void print_dictionary(DICIONARIO dic){
    printf("Dicionario:\n");
    printf("Numero de Palavras: %d\n",dic.nPalavras);
    PALAVRA *current=dic.pfirst;
    while (current!=NULL){
        printf("%s\n",current->ppalavra);
        current=current->pnext;
    }
}

void remove_word_dictionary(DICIONARIO *dic){
    if(dic->nPalavras!=0) {
        PALAVRA *aux = dic->pfirst;
        dic->pfirst = aux->pnext;
        free(aux);
        dic->nPalavras--;
        printf("A palavra removida segundo o sistema de Queue\n");
    } else  printf("O Dicionario esta vazio\n");

}
void add_word_dictionary(DICIONARIO *dic){
    char palavra[20];
    printf("Insira em CAPS LOCK a palavra que pretende adicionar:");
    scanf("%s",palavra);
    PALAVRA *new=malloc(sizeof(PALAVRA));
    new->ppalavra=malloc(sizeof(char)*strlen(palavra)+1);//+1 para o \0
    strcpy(new->ppalavra,palavra);
    new->pnext=NULL;
    if (dic->nPalavras!=0) {
        PALAVRA *current=dic->pfirst;
        while(1){//loop infinito até encontrar o ultimo elemento, quando o encontra coloca o novo asseguir
            if (current->pnext==NULL){
                current->pnext=new;
                break;
            }
            current=current->pnext;
        }
    }
    else
        dic->pfirst=new;
dic->nPalavras++;
}