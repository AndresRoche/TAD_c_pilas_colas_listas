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

Lista _construtor_lista();
Lista construtor_lista();

Lista construtor_lista_array_int(int len, int * vector);
Lista construtor_lista_array_float(int len, float * vector);
Lista construtor_lista_array_char(int len, char * vector);
Lista construtor_lista_array_bool(int len, bool * vector);
Lista construtor_lista_array_string(int len, char ** vector);

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

Node * _consultar(Lista *L, int indice);
int consultar_int(Lista *L, int indice);
float consultar_float(Lista *L, int indice);
char consultar_char(Lista *L, int indice);
bool consultar_bool(Lista *L, int indice);
char * consultar_string(Lista *L, int indice);


void modificar_int(Lista *L,int data ,int index);
void modificar_float(Lista * L, float data, int index);
void modificar_char(Lista * L, char data, int index);
void modificar_string(Lista * L, char * data, int index);
void modificar_bool(Lista * L, bool data, int index);

Lista _copiar_lista(Lista * L1);
Lista copiar_lista(Lista * L);

void swap(Lista *L,int A,int B);


Lista extend(Lista * L1, Lista * L2);
Lista extend_array_int(Lista * L1, int len, int * vector);
Lista extend_array_float(Lista * L1, int len, float * vector);
Lista extend_array_char(Lista * L1, int len, char * vector);
Lista extend_array_bool(Lista * L1, int len, bool * vector);
Lista extend_array_string(Lista * L1, int len, char ** vector);

Lista subLista(Lista *L, int ini, int fin);


int _find_nodo_lista(Lista *L, Node * buscar);
int index_int(Lista *L, int valor);
int index_float(Lista *L, float valor);
int index_char(Lista *L, char valor);
int index_bool(Lista *L, bool valor);
int index_string(Lista *L, char * valor);

bool _esIgualNodo(Node * n1, Node * n2);
bool esigual(Lista * L1, Lista * L2);

Node * _invertir(Lista *L, Node * next); 
Lista reverse_lista(Lista * L1);

void pop(Lista *L);
void delete(Lista *L, int index);
void _clear_lista(Lista *L);
void clear_lista(Lista *L);
void destruir_lista(Lista *L);

#endif