#ifndef NODE
#define NODE

#include "typedata.h"

typedef struct Node
{
    DataValue val;
    DataType type;
    struct Node * next;
} Node;

Node* _crear_nodo(DataType tipo, DataValue dato);
void _liberar_nodo(Node* nodo);
void _imprimir_nodo(const Node* nodo);
void _imprimir_nodo_data(const Node* nodo);

#endif