#include "R6.h"
void merge_sort_dictionary(DICIONARIO *dictionary){
    mergeSort(&dictionary->pfirst);
}
void mergeSort(PALAVRA **pfirst) {
    PALAVRA *aux = *pfirst;
    PALAVRA *a;
    PALAVRA *b;

    if ((aux == NULL)||(aux->pnext == NULL)) {
        return;
    }

    FrontBackSplit(aux, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *pfirst = Merge(a, b);
}

PALAVRA *Merge(PALAVRA *a, PALAVRA *b) {
    PALAVRA *result = NULL;

    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);


    if (strcmp(a->ppalavra, b->ppalavra) < 0) {
        result = a;
        result->pnext = Merge(a->pnext, b);

    } else {
        result = b;
        result->pnext = Merge(a, b->pnext);
    }

    return (result);
}

void FrontBackSplit(PALAVRA *source, PALAVRA **frontRef, PALAVRA **backRef) {
    PALAVRA *fast;
    PALAVRA *slow;
    if (source == NULL || source->pnext == NULL) {

        *frontRef = source;
        *backRef = NULL;
    } else {
        slow = source;
        fast = source->pnext;

        while (fast != NULL) {
            fast = fast->pnext;
            if (fast != NULL) {
                slow = slow->pnext;
                fast = fast->pnext;
            }
        }

        *frontRef = source;
        *backRef = slow->pnext;
        slow->pnext = NULL;
    }
}