#ifndef DataStructure_Autocomplete_h
#define DataStructure_Autocomplete_h

#include <stdlib.h>
#include <stdio.h>

#define MAX  100

typedef struct Node {
    char *data;
    struct Node *under;
    struct Node *next;
}Node;

int inicial();
void read();
int add(Node **list, char palavra[MAX]);
void show(Node *list, char palavra[MAX], int pos);
int buildNode(Node **newNode);
int check(Node **list, char *palavra);

#endif