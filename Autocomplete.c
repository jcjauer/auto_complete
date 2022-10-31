#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

#include "Autocomplete.h"

int inicial() {
    return 0;
}

void read() {

    char palavra[10];

    FILE *arquivo;
    arquivo = fopen("ListaDePalavrasPT.txt", "r");

    if(arquivo == NULL) {
        printf("Erro ao tentar abrir o arquivo\n");
    }
    else {     
        while(fscanf(arquivo,"%[^\n]%*c\n", palavra)!=EOF) { 
            //add(list, palavra)
        }
	}


    fclose(arquivo);
}

int add(Node **list, char palavra[MAX]) {

    for(int i = 0; palavra[i] != '\0' && i < (MAX - 1); i++) {

        printf("\nadd: %d", i);

        Node *newNode = (Node *)malloc(sizeof(Node));

        if(newNode == NULL) {
            return -1;
        }

        newNode->next = NULL;
        newNode->under = NULL;

        newNode->data = (char *)malloc(sizeof(char));

        if(newNode->data == NULL) {
            return -1;
        }

        *newNode->data = palavra[i];

        printf(" Letra: %c\n", *newNode->data);

        if(*list == NULL) {
            *list = newNode;
        }
        else {
            Node *aux = NULL;
            for(aux = *list; aux->next != NULL; aux = aux->next);
            aux->next = newNode;
        }
    }

    return 1;
}

void show(Node *list) {
    if(list != NULL) {
        Node *aux = NULL;
        printf("\nSaída: ");
        for(aux = list; aux->next != NULL; aux = aux->next) {
            printf("%c", *aux->data);
        }
        printf("%c", *aux->data);
        printf("\n");
    }

    
}