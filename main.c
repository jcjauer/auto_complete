#include <stdlib.h>
#include <stdio.h>
#include "Autocomplete.h"
/*
int main(){

    int i;
    char palavras[55] = {"Oi. Vamos aprender a programar com a linguagem C?"};

    printf("Digite seu nome: ");
    fgets(palavras, 55, stdin);// file

    i = 0;
    // \0 -> caracter que indica o fim de string
    // enquanto palavras[i] for diferente do fim de string...
    while(palavras[i] != '\0'){
        printf("%d = %d\n", i, palavras[i]);
        i++;
    }
    printf("\n");

    return 0;
}
*/
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