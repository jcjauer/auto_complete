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
    Node *auxlist = NULL;
    if(*list == NULL) {
        buildNode(&newNode);
        *newNode->data = palavra[i];
        *list = newNode;
    }
    auxlist = *list;
    printf("add: %d Letra: %c\n", i, *auxlist->data); ///////////////// 
    i++;
    for(i; palavra[i] != '\0' && i < (MAX - 1); i++) {
        if(auxlist->next == NULL) {
            buildNode(&newNode);
            *newNode->data = palavra[i];
            auxlist->next = newNode;
            auxlist = auxlist->next;  
            printf("add: %d Letra: %c\n", i, *auxlist->data); /////////////////
        }
        else if(*auxlist->next->data == palavra[i]) {
            auxlist = auxlist->next;
            printf("add: %d Letra: %c\n", i, *auxlist->data); /////////////////
        } 
        else {
            auxlist = auxlist->next;
            if(auxlist->next == NULL) {
                buildNode(&newNode);
                *newNode->data = palavra[i];
                auxlist->next = newNode;
                auxlist = auxlist->next; 
                printf("add: %d Letra: %c\n", i, *auxlist->data); /////////////////
            }
            else if(*auxlist->next->data == palavra[i]) {
                auxlist = auxlist->next;
                printf("add: %d Letra: %c\n", i, *auxlist->data); /////////////////
            }
        }
    }
    buildNode(&newNode);
    *newNode->data = palavra[i];
    auxlist->next = newNode;
    printf("add: %d Letra: nula\n", i); /////////////////
    
    return 1;
}

void show(Node *list) {
    if(list != NULL) {
        char palavra[MAX];
        int i = 0;
        Node *aux = list;
        palavra[i] = *aux->data;
        printf("show: %d Letra: %c\n", i, *aux->data);
        i++;
        for(aux; aux->next != NULL; aux = aux->next) {
            if(*aux->next->data == '\0') {
                palavra[i] = *aux->next->data;
                printf("show: %d Letra: nula\n", i);
                printf("Saída: %s\n", palavra);
            }
            else
            {
                palavra[i] = *aux->next->data;
                printf("show: %d Letra: %c\n", i, *aux->next->data);
                i++;
            }
        }
    }
    printf("\n");
}