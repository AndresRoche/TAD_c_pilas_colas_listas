#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/struct/lista.h"


int main(){
    
    srand(time(NULL));

    printf("Hola Mundo\n");

    Lista notas = construtor_lista();

    for (int i = 0; i < 15; i++)
    {
        push_int(&notas, (rand() %21));
    }

    

    _imprimir_lista_all(&notas);
    
    insert_int(&notas, 100, 8);
    _imprimir_lista_all(&notas);
    insert_int(&notas, 100, 0);
    _imprimir_lista_all(&notas);
    insert_int(&notas, 200, 1);

    insert_char(&notas, 'g', 1);

    _imprimir_lista_all(&notas);

    pop(&notas);
    pop(&notas);

    _imprimir_lista_all(&notas);

    _imprimir_lista_header(&notas);

    delete(&notas,0);
    delete(&notas,1);
    delete(&notas,29);
    delete(&notas,3);
    _imprimir_lista_all(&notas);

    _imprimir_lista_header(&notas);

    push_string(&notas, "Diego");

    _imprimir_lista_all(&notas);

    _imprimir_lista_header(&notas);

    destruir_lista(&notas);


    return 0;
}