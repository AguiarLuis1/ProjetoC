#include "library.h"
#include "Dicionario.h"
#include "Sopa.h"
#include "R5.h"
#include "R6.h"
#include "R8.h"
#include "R9.h"
#include "R10.h"
#include "R12.h"
#include "R13.h"


//Ficheiros a alterar
#define FILEDICIONARIOTXT "C:\\Users\\Aguia\\CLionProjects\\ProjetoAED_LP2\\Dicionario"
#define FILESOPATXT "C:\\Users\\Aguia\\CLionProjects\\ProjetoAED_LP2\\Sopa"
#define FILEDIRECTIONSTXT "C:\\Users\\Aguia\\CLionProjects\\ProjetoAED_LP2\\Directions"
#define FILEBINARY "C:\\Users\\Aguia\\CLionProjects\\ProjetoAED_LP2\\bin.dat"

int main() {
    DICIONARIO dictionary = {0, NULL};
    SOPA soup = {0, 0, NULL};
    STACKDIRECAO direction ={0,NULL};

    /*Import from .txt*/
    read_dicionary_txt(&dictionary, FILEDICIONARIOTXT);
    read_soup_txt(&soup, FILESOPATXT);

    /*Create/Add/Remove dictionary*/
    //manually_insert_dictionary(&dictionary);
    //remove_word_dictionary(&dictionary);
    //add_word_dictionary(&dictionary);

    /*Sort dictionary*/
    merge_sort_dictionary(&dictionary);

    /*Create soup from dictionary*/
    //create_soup_from_dictionary(&soup,dictionary);

    /*Find words in soup*/
    checkword(dictionary,soup,&direction);

    /*Binary Files import/export*/
    //save_dictionary_bin(dictionary,FILEBINARY);
    //read_dictionary_bin(&dictionary,FILEBINARY);
    //save_soup_bin(soup,FILEBINARY);
    //read_soup_bin(&soup,FILEBINARY);
    //save_directions_bin(direction,FILEBINARY);

    /*Export to .txt*/
    save_referencias_txt(direction,FILEDIRECTIONSTXT);
    //save_dictionary_txt(dictionary,FILEDICIONARIOTXT);
    //save_soup_txt(soup,FILESOPATXT);

    /*Prints*/
    //print_dictionary(dictionary);
    //print_sopa(soup);
    print_referencias(direction);

    /*Print chars from pos init and next*/
    char *carateres=charsfrompos(soup);
    printf("%s",carateres);

    return 0;
}
