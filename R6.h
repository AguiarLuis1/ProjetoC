#ifndef PROJETOAED_LP2_R6_H
#define PROJETOAED_LP2_R6_H

#include "library.h"

void merge_sort_dictionary(DICIONARIO *dictionary);

void mergeSort(PALAVRA **pfirst);

PALAVRA *Merge(PALAVRA *a, PALAVRA *b);

void FrontBackSplit(PALAVRA *source, PALAVRA **frontRef, PALAVRA **backRef);

#endif //PROJETOAED_LP2_R6_H
