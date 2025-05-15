#ifndef LISTA
#define LISTA

#include "../core/node.h"

typedef struct Lista
{
    int longitud;
    Node * primera;
    Node * ultimo;
} Lista;

//vamos 

Lista construtor_lista();

void _push(Lista * L, Node * nodo);
void push_int(Lista * L, int data);
void push_float(Lista * L, float data);
void push_char(Lista * L, char data);
void push_string(Lista * L, char* data);
void push_bool(Lista * L, bool data);

void _insert(Lista * L, Node * nodo, int index);
void insert_int(Lista * L, int data, int index);
void insert_float(Lista * L, float data, int index);
void insert_char(Lista * L, char data, int index);
void insert_string(Lista * L, char * data, int index);
void insert_bool(Lista * L, bool data, int index);

void _imprimir_lista_header(Lista *L);
void _imprimir_lista(Node * aux);
void _imprimir_lista_all(Lista * L);
void imprimir_lista(Lista * L);
int get_longitud_lista(Lista * L);



void pop(Lista *L);
void delete(Lista *L, int index);
void _clear_lista(Lista *L);
void clear_lista(Lista *L);
void destruir_lista(Lista *L);
#endif