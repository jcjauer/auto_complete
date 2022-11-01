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

int buildNode(Node **newNode) {
    Node *aux = (Node *)malloc(sizeof(Node));
    if(aux == NULL) {
        return -1;
    }
    aux->data = (char *)malloc(sizeof(char));
    if(aux->data == NULL) {
        return -1;
    }
    aux->next = NULL;
    aux->under = NULL;
    *aux->data = '\0';
    *newNode = aux;
    return 1;
}

int add(Node **list, char palavra[MAX]) {
    int i = 0;
    Node *newNode;

    printf("\nadd: %d", i); /////////////////
    if(*list == NULL) {
        buildNode(&newNode);
        *newNode->data = palavra[i];
        *list = newNode;
        printf(" Letra: %c\n", *newNode->data); /////////////////
        i++;
    }
    for(i; palavra[i] != '\0' && i < (MAX - 1); i++) {
        printf("\nadd: %d", i); /////////////////
        if(palavra[i] != '\0'){
            buildNode(&newNode);
            *newNode->data = palavra[i];
            Node *aux = NULL;
            for(aux = *list; aux->next != NULL; aux = aux->next);
            aux->next = newNode;
            printf(" Letra: %c\n", *newNode->data); ///////////////////////
        }
        else {

        }
    }
    printf("\nadd: %d", i); ///////////////////////
    if(palavra[i] == '\0') {
        buildNode(&newNode);
        *newNode->data = palavra[i];
        printf(" Letra: nula\n"); ///////////////////////
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
    printf(" \n");
}