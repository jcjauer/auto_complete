#include <stdlib.h>
#include <stdio.h>
#include "Autocomplete.h"

int main() {
    Node *lista[26];

    for(int i = 0; i < 26; i++) {
        lista[i] = NULL;
    }

    char entrada[MAX];
    char saida[MAX];

    printf("\nDigite uma entrada: ");
    scanf("%s", entrada);
    printf("Entrada: %s\n", entrada);
    add(&lista[0], entrada);
    show(lista[0], saida, 0);

    printf("\nDigite uma entrada: ");
    scanf("%s", entrada);
    printf("Entrada: %s\n", entrada);
    add(&lista[0], entrada);
    show(lista[0], saida, 0);

    printf("\nDigite uma entrada: ");
    scanf("%s", entrada);
    printf("Entrada: %s\n", entrada);
    add(&lista[0], entrada);
    show(lista[0], saida, 0);

    printf("\nProcurar uma entrada: ");
    scanf("%s", entrada);
    printf("Entrada: %s\n", entrada);
    found(lista[0], entrada);
    printf("\n");

    return EXIT_SUCCESS;
}