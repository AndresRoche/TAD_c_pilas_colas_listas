#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../include/struct/lista.h"

Lista construtor_lista()
{
    Lista L;
    DataValue da;
    da.valueInt = -1;
    Node * new = _crear_nodo(TYPE_INT, da);

    new->next=NULL;

    L.longitud=0;
    L.primera=new;
    L.ultimo=new;

    return L;
}

void _push(Lista * L, Node * nodo)
{
    L->longitud = L->longitud+1; 
    L->ultimo->next = nodo;
    L->ultimo = nodo;
}

void push_int(Lista * L, int num)
{
    DataValue data;
    data.valueInt = num;
    Node * new = _crear_nodo(TYPE_INT, data);

    _push(L,new);
}

void push_float(Lista * L, float data)
{
    DataValue d;
    d.valueFloat = data;
    Node * new = _crear_nodo(TYPE_FLOAT, d);

    _push(L,new);
}

void push_char(Lista * L, char data)
{
    DataValue d;
    d.valueChar = data;
    Node * new = _crear_nodo(TYPE_CHAR, d);

    _push(L,new);
}

void push_string(Lista * L, char* data)
{
    DataValue d;
    d.valueString = data;
    Node * new = _crear_nodo(TYPE_STRING, d);

    _push(L,new);
}

void push_bool(Lista * L, bool data)
{
    DataValue d;
    d.valueBool = data;
    Node * new = _crear_nodo(TYPE_BOOL, d);

    _push(L,new);
}



void _insert(Lista * L, Node * nodo, int index)
{

    Node * aux, * aux_next;

    L->longitud = L->longitud+1; 

    if(index>L->longitud || ( index==0 && index==L->longitud))
    {
        L->ultimo->next = nodo;
        L->ultimo = nodo;
    } else if(index==0){
        aux = L->primera;
        aux_next = aux->next;
        aux->next = nodo;
        nodo->next = aux_next;
    } else 
    {
        int i=0;
        aux = L->primera;
        while (aux->next!=NULL && i<index)
        {
            aux= aux->next;
            i++;
        }
        aux_next = aux->next;
        aux->next = nodo;
        nodo->next = aux_next;
    }
}


void insert_int(Lista * L, int data, int index)
{
    DataValue d;
    d.valueInt = data;
    Node * new = _crear_nodo(TYPE_INT, d);

    _insert(L,new, index);
}

void insert_float(Lista * L, float data, int index)
{
    DataValue d;
    d.valueFloat = data;
    Node * new = _crear_nodo(TYPE_FLOAT, d);

    _insert(L,new, index);
}

void insert_char(Lista * L, char data, int index)
{
    DataValue d;
    d.valueChar = data;
    Node * new = _crear_nodo(TYPE_CHAR, d);

    _insert(L,new, index);
}

void insert_string(Lista * L, char * data, int index)
{
    DataValue d;
    d.valueString = data;
    Node * new = _crear_nodo(TYPE_STRING, d);

    _insert(L,new, index);
}

void insert_bool(Lista * L, bool data, int index)
{
    DataValue d;
    d.valueBool = data;
    Node * new = _crear_nodo(TYPE_BOOL, d);

    _insert(L,new, index);
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


void _imprimir_lista(Node * aux)
{
    Node * iter = aux;

    printf("[");
    while (iter!=NULL)
    {
        printf(" ");
        _imprimir_nodo_data(iter);
        printf(" ");

        iter=iter->next;
    }
    printf("]\n");
}

void _imprimir_lista_all(Lista * L)
{
    Node * aux;
    aux = L->primera;
    printf("longitud : %d\n", L->longitud);
    _imprimir_lista(aux);
    
}

void imprimir_lista(Lista * L)
{
    Node * aux;
    aux = L->primera->next;

    _imprimir_lista(aux);

}


int get_longitud_lista(Lista * L)
{
    return L->longitud;
}

void _clear_lista(Lista *L)
{
    Node *aux1, *aux2;

    if(L->primera->next==NULL) return;

    aux1 = L->primera->next;
    while (aux1!=NULL)
    {
        aux2=aux1->next;
        //free(aux1->val);
        _liberar_nodo(aux1);
        aux1=aux2;
    }

    L->ultimo = L->primera;
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
    Node * aux, *liberar;
    int i=0;
    int len = L->longitud;
    L->longitud = L->longitud-1;
    if(L->primera != NULL){

        aux=L->primera;
            
        while(i<len-1){
            aux=aux->next;
            i++;
        }
        
        liberar=aux->next;
        aux->next=liberar->next;

        L->ultimo = aux;

        _liberar_nodo(liberar);

    }
}


void delete(Lista *L, int index)
{
    Node * aux, *liberar;
    int i=0;
    int len = L->longitud;

    if(L->primera!=NULL){

        aux=L->primera;
            
        while(i<(index) && aux->next->next!=NULL){
            aux=aux->next;
            i++;
        }
        liberar=aux->next;
        aux->next=liberar->next;

        _liberar_nodo(liberar);
        L->longitud=L->longitud-1;

        if(index>len){
            L->ultimo=aux;
        }
    }
}