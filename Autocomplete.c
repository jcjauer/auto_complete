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
        else if(*auxlist->next->data == '\0') {
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
            else if(*auxlist->next->data != palavra[i]) {
                if(auxlist->under != NULL) {
                    
                    for(auxlist; auxlist->under != NULL; auxlist = auxlist->under) {
                        if(*auxlist->next->data == palavra[i]) {
                            auxlist = auxlist->next;
                            printf("add: %d Letra: %c\n", i, *auxlist->data); /////////////////
                            break;
                        }
                    }
                }
                if(*auxlist->data != palavra[i] && auxlist->under == NULL) {
                    buildNode(&newNode);
                    auxlist->under = newNode;
                    auxlist = auxlist->under;
                    buildNode(&newNode);
                    *newNode->data = palavra[i];
                    auxlist->next = newNode;
                    auxlist = auxlist->next;
                    printf("add: %d Letra: %c\n", i, *auxlist->data); /////////////////
                }
            }
        }
        else if(*auxlist->next->data != palavra[i]) {
            if(auxlist->under != NULL) {
                
                for(auxlist; auxlist->under != NULL; auxlist = auxlist->under) {
                    if(*auxlist->next->data == palavra[i]) {
                        auxlist = auxlist->next;
                        printf("add: %d Letra: %c\n", i, *auxlist->data); /////////////////
                        break;
                    }
                }
            }
            if(*auxlist->data != palavra[i] && auxlist->under == NULL) {
                buildNode(&newNode);
                auxlist->under = newNode;
                auxlist = auxlist->under;
                buildNode(&newNode);
                *newNode->data = palavra[i];
                auxlist->next = newNode;
                auxlist = auxlist->next;
                printf("add: %d Letra: %c\n", i, *auxlist->data); /////////////////
            }
        }
    }
    buildNode(&newNode);
    auxlist->next = newNode;
    printf("add: %d Letra: nula\n", i); /////////////////
    
    return 1;
}

void show(Node *list, char palavra[MAX], int pos) {
    if(list != NULL) {
        Node *aux = list;
        palavra[pos] = *aux->data;
        printf("show: %d Letra: %c\n", pos, *aux->data);
        pos++;
        for(aux; aux->next != NULL; aux = aux->next) {
            while(aux->under != NULL) {
                show(aux->next, palavra, pos);
                aux = aux->under;
            }
            if(*aux->next->data == '\0') {
                palavra[pos] = *aux->next->data;
                printf("show: %d Letra: nula\n", pos);
                printf("Saída: %s\n", palavra);
            }
            else
            {
                palavra[pos] = *aux->next->data;
                printf("show: %d Letra: %c\n", pos, *aux->next->data);
                pos++;
            }
        }
    }
}

int check(Node **list, char *palavra){

    for(int i = 0; i < 26; i++){
        if(palavra[0] == i){
           add(&list[i], palavra);
           printf("Palavra adicionada na lista %d", i);
            return i;
        }
    }
}