#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

#include "Autocomplete.h"

Node *vetor[26];

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

int addletra(Node **list, char *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));

    if(newNode == NULL) {
        return -1;
    }

    newNode->data = data;
    newNode->next = NULL;
    newNode->under = NULL;

    if(*list == NULL) {
        *list = newNode;
    }
    else {
        Node *aux = NULL;
        for(aux = *list; aux->next != NULL; aux = aux->next);
        aux->next = newNode;
    }
    return 1;
}

int addpalavra(Node **list, char palavra[MAX]) {

    char *data[MAX];

    for(int i = 0; !palavra[i] && i < MAX; i++) {
        data[i] = (char *)malloc(sizeof(char));
        //add(&list, )
    }
}

void show(Node *list){
    //
}