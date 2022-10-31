#include <stdlib.h>
#include <stdio.h>
#include "Autocomplete.h"

int main() {
    Node *lista = NULL;
    char palavra[MAX];

    printf("\nDigite uma palavra: ");
    scanf("%s", palavra);
    printf("\nPalavra: %s\n", palavra);
    add(&lista, palavra);
    show(lista);

    return EXIT_SUCCESS;
}