#ifndef DataStructure_Autocomplete_h
#define DataStructure_Autocomplete_h

#include <stdlib.h>
#include <stdio.h>

#define MAX  20

typedef struct Node {
    char *data;
    struct Node *under;
    struct Node *next;
}Node;

int inicial();
void read();
int addpalavra(Node **list, char palavra[MAX]);
int addletra(Node **list, char *data);
void show(Node *list);

#endif