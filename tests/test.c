#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>

#include "../include/struct/lista.h"

//valgrind --leak-check=full ./tu_programa

void testeando_pushs(){
    Lista test = construtor_lista();

    push_int(&test, 6);
    push_bool(&test, true);
    push_char(&test, 'd');
    push_float(&test, 53.23);
    push_string(&test, "Mundo Hola");

    modificar_int(&test, 19, 0);
    modificar_bool(&test, false, 1);
    modificar_char(&test, 'g', 2);
    modificar_float(&test, 90.34, 3);
    modificar_string(&test, "bonito dias XD", 4);

    modificar_string(&test, "ja", 4);

    char * de = consultar_string(&test, 4);
    
    free(de);

    destruir_lista(&test);
}


void test_index()
{
    Lista test = construtor_lista();

    for (int i = 0; i < 10; i++)
    {
        insert_int(&test, i, 0);
    }
    
    _imprimir_lista_all(&test);

    

    insert_int(&test, -1, 100);

    _imprimir_lista_all(&test);

    imprimir_lista(&test);

    int len = get_longitud_lista(&test);
    for (int i = 0; i < len; i++)
    {
        printf("[%d] : %d\n",i,consultar_int(&test,i));
    }

    delete(&test,0);


    delete(&test,1);
  
    
    delete(&test,2);
    
    
    delete(&test,7);
    

    delete(&test,-1);
    insert_int(&test, get_longitud_lista(&test),get_longitud_lista(&test));
    insert_int(&test,909,get_longitud_lista(&test)-1);
    insert_int(&test,1000,-1);

    pop(&test);

    _imprimir_lista_all(&test);

    swap(&test, 2,5);

    _imprimir_lista_all(&test);

    swap(&test, 7,1);

    _imprimir_lista_all(&test);

    Lista test1 = construtor_lista();

    for (int i = 0; i < 10; i++)
    {
        insert_int(&test1, i, 0);
    }
    push_int(&test1, 50);
    _imprimir_lista_all(&test1);

    Lista g = extend(&test, &test1);

    imprimir_lista(&g);

    clear_lista(&test1);
    clear_lista(&test);

    imprimir_lista(&test1);
    imprimir_lista(&test);
    imprimir_lista(&g);

    Lista f = _copiar_lista(&g);
    _imprimir_lista_all(&g);
    _imprimir_lista_all(&f);

    destruir_lista(&f);
    destruir_lista(&test);
    destruir_lista(&test1);
    destruir_lista(&g);
}


void test_array()
{
    Lista q = construtor_lista();

    int len = 10;
    int numero[10] = {1,6,4,7,4,6,3,2,9,3};

    Lista po = extend_array_int(&q, len, numero);

    _imprimir_lista_all(&po);
    destruir_lista(&po);

    char * hh = "holaMondeD";

    po = extend_array_char(&q, strlen(hh), hh);

    _imprimir_lista_all(&po);

    destruir_lista(&po);

    bool boolean[5] = {true, false, true, false, false}; 
    po = extend_array_bool(&q, 5, boolean);

    _imprimir_lista_all(&po);

    destruir_lista(&po);


    float ff[5] = {3.1514, 6.3223, 8.34535, 9.4543, 5.2234}; 
    po = extend_array_float(&q, 5, ff);
    
    _imprimir_lista_all(&po);
    
    destruir_lista(&po);

    
    char *nombre[] = {"andres", "diego", "apolo", "Diablitas Pueblas", NULL};
    po = extend_array_string(&q, 4, nombre);

    _imprimir_lista_all(&po);

    clear_lista(&po);

    destruir_lista(&q);
    destruir_lista(&po);
}

void test_subLista()
{
    Lista test = construtor_lista();

    int len = 10;
    int numero[10] = {1,6,4,7,4,6,3,2,9,3};

    Lista po = extend_array_int(&test, len, numero);

    Lista q = subLista(&po,0,8/2);

    _imprimir_lista_all(&po);
    _imprimir_lista_all(&q);

    destruir_lista(&q);
    destruir_lista(&po);


    destruir_lista(&test);
    
}


void test_reserve()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    Lista numeros = construtor_lista_array_int(10,a);

    Lista numeros_invertidos = reverse_lista(&numeros);

    imprimir_lista(&numeros);
    imprimir_lista(&numeros_invertidos);

    printf("el numero 10 esta : %d\n", index_int(&numeros_invertidos, 10));
    printf("el numero 2 esta : %d\n", index_int(&numeros_invertidos, 2));
    printf("el numero 30 esta : %d\n", index_int(&numeros_invertidos, 30));
    printf("el numero 5 esta : %d\n", index_int(&numeros_invertidos, 5));


    destruir_lista(&numeros_invertidos);
    destruir_lista(&numeros);
}

int main(){
    
    srand(time(NULL));

    test_reserve();

    return 0;
}