#include <stdlib.h>
#include <stdio.h>
#include "Autocomplete.h"

int main() {
    Node *lista[26];

    for(int i = 0; i < 26; i++) {
        lista[i] = NULL;
    }

    char palavra[MAX];

    printf("\nDigite uma palavra: ");
    scanf("%s", palavra);
    printf("\nPalavra: %s\n", palavra);
    add(&lista[0], palavra);
    show(lista[0]);

    return EXIT_SUCCESS;
}