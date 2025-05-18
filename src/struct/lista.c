#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../include/struct/lista.h"

Lista _construtor_lista()
{
    Lista L;
    DataValue da;
    da.valueInt = -1;
    Node *new = _crear_nodo(TYPE_INT, da);

    new->next = NULL;

    L.longitud = 0;
    L.primera = new;
    L.ultimo = new;

    return L;
}

Lista construtor_lista()
{
    return _construtor_lista();
}

void _push(Lista *L, Node *nodo)
{
    L->longitud = L->longitud + 1;
    L->ultimo->next = nodo;
    L->ultimo = nodo;
}

void push_int(Lista *L, int num)
{
    DataValue data;
    data.valueInt = num;
    Node *new = _crear_nodo(TYPE_INT, data);

    _push(L, new);
}

void push_float(Lista *L, float data)
{
    DataValue d;
    d.valueFloat = data;
    Node *new = _crear_nodo(TYPE_FLOAT, d);

    _push(L, new);
}

void push_char(Lista *L, char data)
{
    DataValue d;
    d.valueChar = data;
    Node *new = _crear_nodo(TYPE_CHAR, d);

    _push(L, new);
}

void push_string(Lista *L, char *data)
{
    DataValue d;
    d.valueString = data;
    Node *new = _crear_nodo(TYPE_STRING, d);

    _push(L, new);
}

void push_bool(Lista *L, bool data)
{
    DataValue d;
    d.valueBool = data;
    Node *new = _crear_nodo(TYPE_BOOL, d);

    _push(L, new);
}

void _insert(Lista *L, Node *nodo, int index)
{

    if (index < 0)
    {
        printf("ERROR INDICE ES MENOR A 0\n");
        _liberar_nodo(nodo);
        return;
    }

    Node *aux, *aux_next;

    L->longitud = L->longitud + 1;

    if (index + 1 >= L->longitud || (index == 0 && index == L->longitud))
    {
        L->ultimo->next = nodo;
        L->ultimo = nodo;
    }
    else if (index == 0)
    {
        aux = L->primera;
        aux_next = aux->next;
        aux->next = nodo;
        nodo->next = aux_next;

        if (L->longitud == 1)
        {
            L->ultimo = nodo;
        }
    }
    else
    {
        int i = 0;
        aux = L->primera;
        while (aux->next != NULL && i < index)
        {
            aux = aux->next;
            i++;
        }
        aux_next = aux->next;
        aux->next = nodo;
        nodo->next = aux_next;
    }
}

void insert_int(Lista *L, int data, int index)
{
    DataValue d;
    d.valueInt = data;
    Node *new = _crear_nodo(TYPE_INT, d);

    _insert(L, new, index);
}

void insert_float(Lista *L, float data, int index)
{
    DataValue d;
    d.valueFloat = data;
    Node *new = _crear_nodo(TYPE_FLOAT, d);

    _insert(L, new, index);
}

void insert_char(Lista *L, char data, int index)
{
    DataValue d;
    d.valueChar = data;
    Node *new = _crear_nodo(TYPE_CHAR, d);

    _insert(L, new, index);
}

void insert_string(Lista *L, char *data, int index)
{
    DataValue d;
    d.valueString = data;
    Node *new = _crear_nodo(TYPE_STRING, d);

    _insert(L, new, index);
}

void insert_bool(Lista *L, bool data, int index)
{
    DataValue d;
    d.valueBool = data;
    Node *new = _crear_nodo(TYPE_BOOL, d);

    _insert(L, new, index);
}

void _imprimir_lista_header(Lista *L)
{
    printf("╠═════════════════════════════════════════╣\n");
    printf("Longitud : %d \n", L->longitud);
    printf("L->Primera : \n");
    _imprimir_nodo(L->primera);
    printf("L->Ultimo : \n");
    _imprimir_nodo(L->ultimo);
    printf("╠═════════════════════════════════════════╣\n");
}

void _imprimir_lista(Node *aux)
{
    Node *iter = aux;

    printf("[");
    while (iter != NULL)
    {
        printf(" ");
        _imprimir_nodo_data(iter);
        printf(" ");

        iter = iter->next;
    }
    printf("]\n");
}

void _imprimir_lista_all(Lista *L)
{
    Node *aux;
    aux = L->primera;
    printf("Longitud : %d\n", L->longitud);
    printf("Primero : ");
    _imprimir_nodo_data(L->primera);
    printf("\nUltimo : ");
    _imprimir_nodo_data(L->ultimo);
    printf("\n");
    _imprimir_lista(aux);
}

void imprimir_lista(Lista *L)
{
    Node *aux;
    aux = L->primera->next;

    _imprimir_lista(aux);
}

int get_longitud_lista(Lista *L)
{
    return L->longitud;
}

void _clear_lista(Lista *L)
{
    Node *aux1, *aux2;

    if (L->primera->next == NULL)
        return;

    aux1 = L->primera->next;
    while (aux1 != NULL)
    {
        aux2 = aux1->next;
        // free(aux1->val);
        _liberar_nodo(aux1);
        aux1 = aux2;
    }

    L->ultimo = L->primera;
    L->primera->next = NULL;
    L->longitud = 0;
}

void clear_lista(Lista *L)
{
    _clear_lista(L);
}

void destruir_lista(Lista *L)
{

    _clear_lista(L);

    _liberar_nodo(L->primera);
}

void pop(Lista *L)
{
    Node *aux, *liberar;
    int i = 0;
    int len = L->longitud;
    L->longitud = L->longitud - 1;
    if (L->primera != NULL)
    {

        aux = L->primera;

        while (i < len - 1)
        {
            aux = aux->next;
            i++;
        }

        liberar = aux->next;
        aux->next = liberar->next;

        L->ultimo = aux;

        _liberar_nodo(liberar);
    }
}

void delete(Lista *L, int index)
{
    Node *aux, *liberar;
    int i = 0;
    int len = L->longitud;

    if (index < 0)
    {
        printf("ERROR INDICE ES MENOR A 0\n");
        return;
    }

    if (L->primera != NULL)
    {

        aux = L->primera;

        while (i < (index) && aux->next->next != NULL)
        {
            aux = aux->next;
            i++;
        }
        liberar = aux->next;
        aux->next = liberar->next;

        _liberar_nodo(liberar);
        L->longitud = L->longitud - 1;

        if (index >= len - 1)
        {
            L->ultimo = aux;
        }
    }
}

Node *_consultar(Lista *L, int indice)
{
    Node *aux;
    aux = L->primera->next;

    if (indice > L->longitud)
    {
        aux = L->ultimo;
    }
    else
    {
        for (int i = 0; i < indice; i++)
        {
            aux = aux->next;
        }
    }

    return aux;
}

int consultar_int(Lista *L, int indice)
{
    Node *aux = _consultar(L, indice);

    return aux->val.valueInt;
}

float consultar_float(Lista *L, int indice)
{
    Node *aux = _consultar(L, indice);

    return aux->val.valueFloat;
}

char consultar_char(Lista *L, int indice)
{
    Node *aux = _consultar(L, indice);

    return aux->val.valueChar;
}

bool consultar_bool(Lista *L, int indice)
{
    Node *aux = _consultar(L, indice);

    return aux->val.valueBool;
}

char *consultar_string(Lista *L, int indice)
{
    char *palabra_apuntado = _consultar(L, indice)->val.valueString;

    size_t new_size = strlen(palabra_apuntado) + 1;

    char *aux = (char *)malloc(new_size);

    strncpy(aux, palabra_apuntado, new_size);

    aux[new_size - 1] = '\0';

    return aux;
}

void modificar_int(Lista *L, int data, int index)
{
    Node *aux = _consultar(L, index);

    aux->val.valueInt = data;
}

void modificar_float(Lista *L, float data, int index)
{
    Node *aux = _consultar(L, index);

    aux->val.valueFloat = data;
}

void modificar_char(Lista *L, char data, int index)
{
    Node *aux = _consultar(L, index);

    aux->val.valueChar = data;
}

void modificar_string(Lista *L, char *data, int index)
{
    Node *nodo_aux = _consultar(L, index);

    if (nodo_aux == NULL)
    {
        fprintf(stderr, "Error: Índice %d no válido\n", index);
        return;
    }

    // 2. Verificar que data no sea NULL
    if (data == NULL)
    {
        fprintf(stderr, "Error: String a copiar es NULL\n");
        return;
    }

    size_t new_size = strlen(data) + 1;

    char *aux = realloc(nodo_aux->val.valueString, new_size);

    if (aux == NULL)
    {
        fprintf(stderr, "Error: No se pudo reasignar memoria\n");
        return;
    }

    // 5. Actualizar el puntero y copiar el string
    nodo_aux->val.valueString = aux;
    strncpy(nodo_aux->val.valueString, data, new_size);

    // Asegurar terminación nula (strncpy no la añade si data es muy largo)
    nodo_aux->val.valueString[new_size - 1] = '\0';
}

void modificar_bool(Lista *L, bool data, int index)
{
    Node *aux = _consultar(L, index);

    aux->val.valueBool = data;
}

void swap(Lista *L, int A, int B)
{

    if (A >= L->longitud || A < 0 || B >= L->longitud || B < 0)
    {
        printf("ERROR FUERA DE RANGOOO\n");
        return;
    }

    Node *aux1, *aux2, *borra, *cas, *aux3;
    int aux_num;

    // comprobamos que priemro la lista no este vacia
    // y que solo tenga un solo elemento
    //  y que los indices A y B sea inguales

    if (L->longitud > 1 && A != B)
    {
        // A siempre debe ser menor
        if (B < A)
        {
            aux_num = A;
            A = B;
            B = aux_num;
        }

        aux1 = L->primera;
        aux2 = L->primera;

        // recorremos A
        for (int i = 0; i < (A); i++)
            aux1 = aux1->next;
        // y recorremos B
        for (int i = 0; i < (B); i++)
            aux2 = aux2->next;

        cas = aux2->next->next;

        if ((B - A) == 1)
        {
            aux1->next = aux2->next;
            aux2->next->next = aux2;
            aux2->next = cas;
            if (B == L->longitud - 1)
            {
                L->ultimo = aux2;
            }
        }
        else
        {
            aux3 = aux1->next;
            aux2->next->next = aux1->next->next;
            aux1->next = aux2->next;
            aux2->next = aux3;
            aux3->next = cas;
            if (B == L->longitud - 1)
            {
                L->ultimo = aux3;
            }
        }
    }
}

bool _esIgualNodo(Node *n1, Node *n2)
{
    bool bandera = true;

    if (n1->type == n2->type)
    {
        switch (n1->type)
        {
        case TYPE_INT:

            bandera = (n1->val.valueInt == n2->val.valueInt);

            break;
        case TYPE_CHAR:

            bandera = (n1->val.valueChar == n2->val.valueChar);

            break;
        case TYPE_BOOL:
            bandera = (n1->val.valueBool == n2->val.valueBool);
            break;
        case TYPE_STRING:

            bandera = (strcmp(n1->val.valueString, n2->val.valueString) == 0);

            break;
        case TYPE_FLOAT:

            bandera = (n1->val.valueFloat == n2->val.valueFloat);

            break;
        }
    }
    else
    {
        bandera = false;
    }

    return bandera;
}

bool esigual(Lista *L1, Lista *L2)
{

    bool bandera = true;

    if (L1->longitud != L2->longitud)
    {
        bandera = false;
        return bandera;
    }

    Node *aux1, *aux2;
    aux1 = L1->primera->next;
    aux2 = L2->primera->next;
    int len = L1->longitud;

    for (int i = 0; i < len; i++)
    {

        bandera = _esIgualNodo(aux1, aux2);

        if (!bandera)
            break;

        aux1 = aux1->next;
        aux2 = aux2->next;
    }

    return bandera;
}

Lista _copiar_lista(Lista *L1)
{
    Node *aux1;
    Lista L = _construtor_lista();

    aux1 = L1->primera->next;

    while (aux1 != NULL)
    {
        Node *newE = _crear_nodo(aux1->type, aux1->val);

        _push(&L,newE);

        aux1 = aux1->next;
    }

    return L;
}

Lista copiar_lista(Lista *L)
{
    return _copiar_lista(L);
}

Lista extend(Lista *L1, Lista *L2)
{
    Node *aux2;
    Lista L = _copiar_lista(L1);

    aux2 = L2->primera->next;

    while (aux2 != NULL)
    {
        Node *newE = _crear_nodo(aux2->type, aux2->val);

        _push(&L,newE);

        aux2 = aux2->next;
    }

    return L;
}

Lista extend_array_int(Lista *L1, int len, int *vector)
{
    Node *aux1;

    Lista L = _copiar_lista(L1);

    for (int i = 0; i < len; i++)
    {
        DataValue f;
        f.valueInt = vector[i];
        Node *newE = _crear_nodo(TYPE_INT, f);

        _push(&L,newE);
    }

    return L;
}

Lista extend_array_float(Lista *L1, int len, float *vector)
{
    Node *aux1;

    Lista L = _copiar_lista(L1);

    for (int i = 0; i < len; i++)
    {
        DataValue f;
        f.valueFloat = vector[i];
        Node *newE = _crear_nodo(TYPE_FLOAT, f);

        _push(&L,newE);
    }

    return L;
}

Lista extend_array_char(Lista *L1, int len, char *vector)
{
    Node *aux1;

    Lista L = _copiar_lista(L1);

    for (int i = 0; i < len; i++)
    {
        DataValue f;
        f.valueChar = vector[i];
        Node *newE = _crear_nodo(TYPE_CHAR, f);

        _push(&L,newE);
    }

    return L;
}

Lista extend_array_bool(Lista *L1, int len, bool *vector)
{
    Node *aux1;

    Lista L = _copiar_lista(L1);

    for (int i = 0; i < len; i++)
    {
        DataValue f;
        f.valueBool = vector[i];
        Node *newE = _crear_nodo(TYPE_BOOL, f);

        _push(&L,newE);
    }

    return L;
}

Lista extend_array_string(Lista *L1, int len, char **vector)
{
    Node *aux1;

    Lista L = _copiar_lista(L1);

    for (int i = 0; i < len; i++)
    {
        DataValue f;
        f.valueString = vector[i];

        Node *newE = _crear_nodo(TYPE_STRING, f);

        _push(&L,newE);
    }

    return L;
}


Lista subLista(Lista *L, int ini, int fin)
{

    if(fin<ini)
    {
        int aux = ini;
        ini = fin;
        fin = aux;
    }  

    Lista L_new = _construtor_lista();

    if (ini==fin)
        return L_new;
    
    if(ini<0 || fin< 1 || ini>=L->longitud || fin>=L->longitud)
    {
        printf("FUERAA DE RANGOOOO\n");
        return L_new;
    }

    Node * aux;
    aux = L->primera->next;
    int i =0;

    for (; i < ini; i++)
        aux=aux->next;
    
    for (; i <= fin; i++)
    {
        Node *newE = _crear_nodo(aux->type, aux->val);

        _push(&L_new,newE);

        aux=aux->next;
    }
    
    return L_new;

}



Lista construtor_lista_array_int(int len, int * vector)
{
    Lista L = _construtor_lista();

    for (int i = 0; i < len; i++)
    {
        DataValue f;
        f.valueInt = vector[i];
        Node *newE = _crear_nodo(TYPE_INT, f);

        _push(&L,newE);
    }

    return L;
}

Lista construtor_lista_array_float(int len, float * vector)
{
    Lista L = _construtor_lista();

    for (int i = 0; i < len; i++)
    {
        DataValue f;
        f.valueFloat = vector[i];
        Node *newE = _crear_nodo(TYPE_FLOAT, f);

        _push(&L,newE);
    }

    return L;
}

Lista construtor_lista_array_char(int len, char * vector)
{
    Lista L = _construtor_lista();

    for (int i = 0; i < len; i++)
    {
        DataValue f;
        f.valueChar = vector[i];
        Node *newE = _crear_nodo(TYPE_CHAR, f);

        _push(&L,newE);
    }

    return L;
}

Lista construtor_lista_array_bool(int len, bool * vector)
{
    Lista L = _construtor_lista();

    for (int i = 0; i < len; i++)
    {
        DataValue f;
        f.valueBool = vector[i];
        Node *newE = _crear_nodo(TYPE_BOOL, f);

        _push(&L,newE);
    }

    return L;
}

Lista construtor_lista_array_string(int len, char ** vector)
{
    Lista L = _construtor_lista();

    for (int i = 0; i < len; i++)
    {
        DataValue f;
        f.valueString = vector[i];
        Node *newE = _crear_nodo(TYPE_STRING, f);

        _push(&L,newE);
    }

    return L;
}


int _find_nodo_lista(Lista *L, Node * buscar)
{
    Node * aux = L->primera->next;
    int i=0;

    while(aux!=NULL)
    {

        if(_esIgualNodo(aux, buscar))
        {
            return i;
        }
        
        aux=aux->next;
        i++;
    }

    return -1;
}


int index_int(Lista *L, int valor)
{
    DataValue data;
    data.valueInt = valor;

    Node * new_nodo = _crear_nodo(TYPE_INT, data);

    int indice = _find_nodo_lista(L, new_nodo);

    _liberar_nodo(new_nodo);

    return indice;
}


int index_float(Lista *L, float valor)
{
    DataValue data;
    data.valueFloat = valor;

    Node * new_nodo = _crear_nodo(TYPE_FLOAT, data);

    int indice = _find_nodo_lista(L, new_nodo);

    _liberar_nodo(new_nodo);

    return indice;
}

int index_char(Lista *L, char valor)
{
    DataValue data;
    data.valueChar = valor;

    Node * new_nodo = _crear_nodo(TYPE_CHAR, data);

    int indice = _find_nodo_lista(L, new_nodo);

    _liberar_nodo(new_nodo);
    return indice;
}

int index_bool(Lista *L, bool valor)
{
    DataValue data;
    data.valueBool = valor;

    Node * new_nodo = _crear_nodo(TYPE_BOOL, data);

    int indice = _find_nodo_lista(L, new_nodo);

    _liberar_nodo(new_nodo);

    return indice;
}

int index_string(Lista *L, char * valor)
{
    DataValue data;
    data.valueString = valor;

    Node * new_nodo = _crear_nodo(TYPE_STRING, data);

    int indice = _find_nodo_lista(L, new_nodo);

    _liberar_nodo(new_nodo);

    return indice;
}

Node * _invertir(Lista *L, Node * next)
{
    
    Node * new_nodo = _crear_nodo(next->type, next->val);

    if (next->next==NULL)
    {
        return new_nodo;   
    } else
    {

        _push(L,_invertir(L,next->next));
        return  new_nodo;
    }

}

Lista reverse_lista(Lista * L1)
{
    Lista L = _construtor_lista();

    _push(&L,_invertir(&L,L1->primera->next));

    return L;
}

 
