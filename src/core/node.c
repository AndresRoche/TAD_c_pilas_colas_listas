#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../include/core/node.h"

Node* _crear_nodo(DataType type, DataValue dato)
{
    Node * newE;
    newE = (Node*) malloc(sizeof(Node));

    newE->next = NULL;
    newE->type = type;

    switch (newE->type)
    {
        case TYPE_INT:
            newE->val.valueInt = dato.valueInt;
        break;
        case TYPE_CHAR:
            newE->val.valueChar = dato.valueChar;
        break;
        case TYPE_BOOL:
            newE->val.valueBool = dato.valueBool;
        break;
        case TYPE_STRING:
            size_t new_size = strlen(dato.valueString) +1;
            newE->val.valueString = (char*)malloc(new_size);
            strcpy(newE->val.valueString, dato.valueString);
            newE->val.valueString[new_size -1] = '\0';
        break;
        case TYPE_FLOAT:
            newE->val.valueFloat = dato.valueFloat;
        break;

    }

    return newE;
}

void _liberar_nodo(Node* nodo)
{
    if (nodo->type == TYPE_STRING)
    {
        free(nodo->val.valueString);
    }
    
    free(nodo);
}

void _imprimir_nodo(const Node* nodo)
{
    printf("╠══════════════════════════════╣\n");
    printf("Direccion De Memoria : %p\n", nodo);
    switch (nodo->type) {
        case TYPE_INT:
            printf("DataType : TYPE_INT\nDataValue : ");
            printf("%d", nodo->val.valueInt);
            break;
        case TYPE_CHAR:
            printf("DataType : TYPE_CHAR\nDataValue : ");
            printf("'%c'", nodo->val.valueChar);
            break;
        case TYPE_BOOL:
            printf("DataType : TYPE_BOOL\nDataValue : ");
            printf("%s", nodo->val.valueBool ? "true" : "false");
            break;
        case TYPE_STRING:
            printf("DataType : TYPE_STRING\nDataValue : ");
            printf("\"%s\"", nodo->val.valueString);
            break;
        case TYPE_FLOAT:
            printf("DataType : TYPE_FLOAT\nDataValue : ");
            printf("%.2f", nodo->val.valueFloat);
            break;
    }
    printf("\n");
    printf("struct Node * Next : ");
    if(nodo->next==NULL){
        printf("NULL\n");
    } else {
        printf("%p\n", nodo->next);
    }
    printf("╠══════════════════════════════╣\n");
}

void _imprimir_nodo_data(const Node* nodo)
{
    switch (nodo->type) {
        case TYPE_INT:
            printf("%d", nodo->val.valueInt);
            break;
        case TYPE_CHAR:
            printf("'%c'", nodo->val.valueChar);
            break;
        case TYPE_BOOL:
            printf("%s", nodo->val.valueBool ? "true" : "false");
            break;
        case TYPE_STRING:
            printf("\"%s\"", nodo->val.valueString);
            break;
        case TYPE_FLOAT:
            printf("%.2f", nodo->val.valueFloat);
            break;
    }
}