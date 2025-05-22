# Documentación de la Librería de Listas Enlazadas en C

---
Esta librería proporciona una implementación de una lista enlazada genérica en C. **Una característica importante es que, aunque la estructura subyacente podría teóricamente manejar diferentes tipos de datos en nodos individuales, esta implementación está diseñada para trabajar con un solo tipo de dato homogéneo por lista a la vez.**

---
## ¿Como usarlos?

Su include es asi:
`#include "include/struct/lista.h"`

---


## Constructores

Funciones para crear nuevas instancias de `Lista`.

### `Lista construtor_lista()` 


Crea e inicializa una nueva lista vacía.

- **Retorna**: Una nueva instancia de `Lista` con `longitud` 0.

---

### Constructores a partir de Arrays

Estas funciones crean una nueva lista e inicializan sus elementos a partir de un array existente.

#### `Lista construtor_lista_array_int(int len, int * vector)`

Crea una lista a partir de un array de enteros.

- **Parámetros**:
    - `len`: `int` - El número de elementos en el array `vector`.
    - `vector`: `int *` - Puntero al array de enteros.
- **Retorna**: Una nueva `Lista` inicializada con los elementos del `vector`.

#### `Lista construtor_lista_array_float(int len, float * vector)`

Crea una lista a partir de un array de números de punto flotante.

- **Parámetros**:
    - `len`: `int` - El número de elementos en el array `vector`.
    - `vector`: `float *` - Puntero al array de flotantes.
- **Retorna**: Una nueva `Lista` inicializada con los elementos del `vector`.

#### `Lista construtor_lista_array_char(int len, char * vector)`

Crea una lista a partir de un array de caracteres.

- **Parámetros**:
    - `len`: `int` - El número de elementos en el array `vector`.
    - `vector`: `char *` - Puntero al array de caracteres.
- **Retorna**: Una nueva `Lista` inicializada con los elementos del `vector`.

#### `Lista construtor_lista_array_bool(int len, bool * vector)`

Crea una lista a partir de un array de booleanos.

- **Parámetros**:
    - `len`: `int` - El número de elementos en el array `vector`.
    - `vector`: `bool *` - Puntero al array de booleanos.
- **Retorna**: Una nueva `Lista` inicializada con los elementos del `vector`.

#### `Lista construtor_lista_array_string(int len, char ** vector)`

Crea una lista a partir de un array de cadenas de caracteres (strings).

- **Parámetros**:
    - `len`: `int` - El número de elementos en el array `vector`.
    - `vector`: `char **` - Puntero al array de punteros a caracteres (cadenas).
- **Retorna**: Una nueva `Lista` inicializada con los elementos del `vector`.

---

## Operaciones de Inserción (Push)

Funciones para agregar un nuevo elemento al final de la lista.

### `void push_int(Lista * L, int data)`

Agrega un entero al final de la lista.

- **Parámetros**:
    - `L`: `Lista *` - Puntero a la lista a la que se agregará el elemento.
    - `data`: `int` - El valor entero a agregar.

### `void push_float(Lista * L, float data)`

Agrega un número de punto flotante al final de la lista.

- **Parámetros**:
    - `L`: `Lista *` - Puntero a la lista a la que se agregará el elemento.
    - `data`: `float` - El valor flotante a agregar.

### `void push_char(Lista * L, char data)`

Agrega un carácter al final de la lista.

- **Parámetros**:
    - `L`: `Lista *` - Puntero a la lista a la que se agregará el elemento.
    - `data`: `char` - El carácter a agregar.

### `void push_string(Lista * L, char* data)`

Agrega una cadena de caracteres al final de la lista.

- **Parámetros**:
    - `L`: `Lista *` - Puntero a la lista a la que se agregará el elemento.
    - `data`: `char *` - La cadena de caracteres a agregar.

### `void push_bool(Lista * L, bool data)`

Agrega un valor booleano al final de la lista.

- **Parámetros**:
    - `L`: `Lista *` - Puntero a la lista a la que se agregará el elemento.
    - `data`: `bool` - El valor booleano a agregar.

---

## Operaciones de Inserción en Índice Específico (Insert)

Funciones para insertar un elemento en una posición específica de la lista.

### `void insert_int(Lista * L, int data, int index)`

Inserta un entero en la posición `index` de la lista.

- **Parámetros**:
    - `L`: `Lista *` - Puntero a la lista.
    - `data`: `int` - El valor entero a insertar.
    - `index`: `int` - La posición (basada en 0) donde se insertará el elemento.

### `void insert_float(Lista * L, float data, int index)`

Inserta un número de punto flotante en la posición `index` de la lista.

- **Parámetros**:
    - `L`: `Lista *` - Puntero a la lista.
    - `data`: `float` - El valor flotante a insertar.
    - `index`: `int` - La posición (basada en 0) donde se insertará el elemento.

### `void insert_char(Lista * L, char data, int index)`

Inserta un carácter en la posición `index` de la lista.

- **Parámetros**:
    - `L`: `Lista *` - Puntero a la lista.
    - `data`: `char` - El carácter a insertar.
    - `index`: `int` - La posición (basada en 0) donde se insertará el elemento.

### `void insert_string(Lista * L, char * data, int index)`

Inserta una cadena de caracteres en la posición `index` de la lista.

- **Parámetros**:
    - `L`: `Lista *` - Puntero a la lista.
    - `data`: `char *` - La cadena de caracteres a insertar.
    - `index`: `int` - La posición (basada en 0) donde se insertará el elemento.

### `void insert_bool(Lista * L, bool data, int index)`

Inserta un valor booleano en la posición `index` de la lista.

- **Parámetros**:
    - `L`: `Lista *` - Puntero a la lista.
    - `data`: `bool` - El valor booleano a insertar.
    - `index`: `int` - La posición (basada en 0) donde se insertará el elemento.

---

## Operaciones de Visualización

### `void imprimir_lista(Lista * L)`

Imprime los elementos de la lista en la consola.

- **Parámetros**:
    - `L`: `Lista *` - Puntero a la lista que se desea imprimir.

---

## Obtención de Información

### `int get_longitud_lista(Lista * L)`

Obtiene el número de elementos actualmente en la lista.

- **Parámetros**:
    - `L`: `Lista *` - Puntero a la lista.
- **Retorna**: `int` - La longitud de la lista.

---

## Operaciones de Consulta (Acceso por Índice)

Permiten acceder al valor de un elemento en una posición específica, similar a como se accede a los elementos de un array `lista[indice]`.

### `int consultar_int(Lista *L, int indice)`

Consulta el valor entero en la posición `indice` de la lista.

- **Parámetros**:
    - `L`: `Lista *` - Puntero a la lista.
    - `indice`: `int` - El índice del elemento a consultar (basado en 0).
- **Retorna**: `int` - El valor entero en la posición especificada. Si se pasa de su longitud retorna el últimos elemento, y si es un numero menor a 0, retorna el primer elemento.

### `float consultar_float(Lista *L, int indice)`

Consulta el valor de punto flotante en la posición `indice` de la lista.

- **Parámetros**:
    - `L`: `Lista *` - Puntero a la lista.
    - `indice`: `int` - El índice del elemento a consultar (basado en 0).
- **Retorna**: `float` - El valor flotante en la posición especificada. Si se pasa de su longitud retorna el últimos elemento, y si es un numero menor a 0, retorna el primer elemento.

### `char consultar_char(Lista *L, int indice)`

Consulta el carácter en la posición `indice` de la lista.

- **Parámetros**:
    - `L`: `Lista *` - Puntero a la lista.
    - `indice`: `int` - El índice del elemento a consultar (basado en 0).
- **Retorna**: `char` - El carácter en la posición especificada. Si se pasa de su longitud retorna el últimos elemento, y si es un numero menor a 0, retorna el primer elemento.

### `bool consultar_bool(Lista *L, int indice)`

Consulta el valor booleano en la posición `indice` de la lista.

- **Parámetros**:
    - `L`: `Lista *` - Puntero a la lista.
    - `indice`: `int` - El índice del elemento a consultar (basado en 0).
- **Retorna**: `bool` - El valor booleano en la posición especificada. Si se pasa de su longitud retorna el últimos elemento, y si es un numero menor a 0, retorna el primer elemento.

### `char * consultar_string(Lista *L, int indice)`

Consulta la cadena de caracteres en la posición `indice` de la lista.

- **Parámetros**:
    - `L`: `Lista *` - Puntero a la lista.
    - `indice`: `int` - El índice del elemento a consultar (basado en 0).
- **Retorna**: `char *` - Puntero a la cadena de caracteres en la posición especificada. Si se pasa de su longitud retorna el últimos elemento, y si es un numero menor a 0, retorna el primer elemento. El puntero retornado apunta a la memoria dentro de la lista; no debe ser liberado externamente si la lista aún gestiona esa memoria.

---

## Operaciones de Modificación

Funciones para cambiar el valor de un elemento existente en una posición específica.  Si o si cuando se modifica una variable de ve ser del mismo tipo si no da errores.

### `void modificar_int(Lista *L, int data, int index)`

Modifica el valor entero en la posición `index` de la lista.

- **Parámetros**:
    - `L`: `Lista *` - Puntero a la lista.
    - `data`: `int` - El nuevo valor entero.
    - `index`: `int` - La posición (basada en 0) del elemento a modificar.

### `void modificar_float(Lista * L, float data, int index)`

Modifica el valor de punto flotante en la posición `index` de la lista.

- **Parámetros**:
    - `L`: `Lista *` - Puntero a la lista.
    - `data`: `float` - El nuevo valor flotante.
    - `index`: `int` - La posición (basada en 0) del elemento a modificar.

### `void modificar_char(Lista * L, char data, int index)`

Modifica el carácter en la posición `index` de la lista.

- **Parámetros**:
    - `L`: `Lista *` - Puntero a la lista.
    - `data`: `char` - El nuevo carácter.
    - `index`: `int` - La posición (basada en 0) del elemento a modificar.

### `void modificar_string(Lista * L, char * data, int index)`

Modifica la cadena de caracteres en la posición `index` de la lista.

- **Parámetros**:
    - `L`: `Lista *` - Puntero a la lista.
    - `data`: `char *` - La nueva cadena de caracteres.
    - `index`: `int` - La posición (basada en 0) del elemento a modificar. Se debe tener cuidado con la gestión de memoria de la cadena antigua y la nueva.

### `void modificar_bool(Lista * L, bool data, int index)`

Modifica el valor booleano en la posición `index` de la lista.

- **Parámetros**:
    - `L`: `Lista *` - Puntero a la lista.
    - `data`: `bool` - El nuevo valor booleano.
    - `index`: `int` - La posición (basada en 0) del elemento a modificar.

---

## Operaciones de Copia e Intercambio

### `Lista copiar_lista(Lista * L)`

Crea una copia profunda de la lista `L`.

- **Parámetros**:
    - `L`: `Lista *` - Puntero a la lista que se va a copiar.
- **Retorna**: Una nueva `Lista` que es una copia idéntica de `L`.

### `void swap(Lista *L, int A, int B)`

Intercambia los valores de los nodos en las posiciones `A` y `B` de la lista.

- **Parámetros**:
    - `L`: `Lista *` - Puntero a la lista.
    - `A`: `int` - Índice del primer elemento a intercambiar.
    - `B`: `int` - Índice del segundo elemento a intercambiar.

---

## Operaciones de Extensión

Funciones para agregar múltiples elementos al final de una lista existente.

### `Lista extend(Lista * L1, Lista * L2)`

Extiende la lista `L1` agregando todos los elementos de la lista `L2` al final. Los elementos de `L2` son copiados. `L2` no se modifica.

- **Parámetros**:
    - `L1`: `Lista *` - Puntero a la lista que será extendida.
    - `L2`: `Lista *` - Puntero a la lista cuyos elementos serán agregados a `L1`.
- **Retorna**: La lista `L3` con los elementos de `L1` y `L2`. 

---

### Extensión a partir de Arrays

Estas funciones extienden una lista existente con los elementos de un array.

#### `Lista extend_array_int(Lista * L1, int len, int * vector)`

Extiende la lista `L1` agregando los elementos de un array de enteros.

- **Parámetros**:
    - `L1`: `Lista *` - Puntero a la lista que será extendida.
    - `len`: `int` - Número de elementos en `vector`.
    - `vector`: `int *` - Puntero al array de enteros.
- **Retorna**: La lista `L1` Con los elementos de vector.

#### `Lista extend_array_float(Lista * L1, int len, float * vector)`

Extiende la lista `L1` agregando los elementos de un array de flotantes.

- **Parámetros**:
    - `L1`: `Lista *` - Puntero a la lista que será extendida.
    - `len`: `int` - Número de elementos en `vector`.
    - `vector`: `float *` - Puntero al array de flotantes.
- **Retorna**: La lista `L1` Con los elementos de vector.

#### `Lista extend_array_char(Lista * L1, int len, char * vector)`

Extiende la lista `L1` agregando los elementos de un array de caracteres.

- **Parámetros**:
    - `L1`: `Lista *` - Puntero a la lista que será extendida.
    - `len`: `int` - Número de elementos en `vector`.
    - `vector`: `char *` - Puntero al array de caracteres.
- **Retorna**: La lista `L1` Con los elementos de vector.

#### `Lista extend_array_bool(Lista * L1, int len, bool * vector)`

Extiende la lista `L1` agregando los elementos de un array de booleanos.

- **Parámetros**:
    - `L1`: `Lista *` - Puntero a la lista que será extendida.
    - `len`: `int` - Número de elementos en `vector`.
    - `vector`: `bool *` - Puntero al array de booleanos.
- **Retorna**: La lista `L1` Con los elementos de vector.

#### `Lista extend_array_string(Lista * L1, int len, char ** vector)`

Extiende la lista `L1` agregando los elementos de un array de cadenas.

- **Parámetros**:
    - `L1`: `Lista *` - Puntero a la lista que será extendida.
    - `len`: `int` - Número de elementos en `vector`.
    - `vector`: `char **` - Puntero al array de cadenas.
- **Retorna**: La lista `L1` Con los elementos de vector.

---

## Sublistas

### `Lista subLista(Lista *L, int ini, int fin)`

Crea una nueva lista que es una subsección de la lista `L`, desde el índice `ini` (inclusive) hasta el índice `fin` (inclusive).

- **Parámetros**:
    - `L`: `Lista *` - Puntero a la lista original.
    - `ini`: `int` - Índice de inicio de la sublista.
    - `fin`: `int` - Índice de fin de la sublista.
- **Retorna**: Una nueva `Lista` conteniendo los elementos de la subsección especificada. Los elementos son copiados.

---

## Búsqueda de Elementos

Funciones para encontrar el índice de la primera ocurrencia de un valor en la lista.

### `int index_int(Lista *L, int valor)`

Busca un valor entero en la lista.

- **Parámetros**:
    - `L`: `Lista *` - Puntero a la lista.
    - `valor`: `int` - El valor entero a buscar.
- **Retorna**: `int` - El índice de la primera ocurrencia del `valor`. Retorna `-1` si el valor no se encuentra.

### `int index_float(Lista *L, float valor)`

Busca un valor de punto flotante en la lista.

- **Parámetros**:
    - `L`: `Lista *` - Puntero a la lista.
    - `valor`: `float` - El valor flotante a buscar.
- **Retorna**: `int` - El índice de la primera ocurrencia del `valor`. Retorna `-1` si el valor no se encuentra.

### `int index_char(Lista *L, char valor)`

Busca un carácter en la lista.

- **Parámetros**:
    - `L`: `Lista *` - Puntero a la lista.
    - `valor`: `char` - El carácter a buscar.
- **Retorna**: `int` - El índice de la primera ocurrencia del `valor`. Retorna `-1` si el valor no se encuentra.

### `int index_bool(Lista *L, bool valor)`

Busca un valor booleano en la lista.

- **Parámetros**:
    - `L`: `Lista *` - Puntero a la lista.
    - `valor`: `bool` - El valor booleano a buscar.
- **Retorna**: `int` - El índice de la primera ocurrencia del `valor`. Retorna `-1` si el valor no se encuentra.

### `int index_string(Lista *L, char * valor)`

Busca una cadena de caracteres en la lista. La comparación de cadenas se realiza típicamente con `strcmp`.

- **Parámetros**:
    - `L`: `Lista *` - Puntero a la lista.
    - `valor`: `char *` - La cadena a buscar.
- **Retorna**: `int` - El índice de la primera ocurrencia del `valor`. Retorna `-1` si el valor no se encuentra.

---

## Comparación de Listas

### `bool esigual(Lista * L1, Lista * L2)`

Comprueba si dos listas, `L1` y `L2`, son iguales. Dos listas se consideran iguales si tienen la misma longitud y todos sus elementos correspondientes son iguales.

- **Parámetros**:
    - `L1`: `Lista *` - Puntero a la primera lista.
    - `L2`: `Lista *` - Puntero a la segunda lista.
- **Retorna**: `bool` - `true` si las listas son iguales, `false` en caso contrario. La comparación de elementos dependerá del tipo de dato almacenado.

---

## Inversión de Listas

### `Lista reverse_lista(Lista * L1)`

Crea una nueva lista que es la versión invertida de `L1`. La lista original `L1` no se modifica.

- **Parámetros**:
    - `L1`: `Lista *` - Puntero a la lista que se va a invertir.
- **Retorna**: Una nueva `Lista` con los elementos de `L1` en orden inverso.

---

## Operaciones de Eliminación

### `void pop(Lista *L)`

Elimina el último elemento de la lista.

- **Parámetros**:
    - `L`: `Lista *` - Puntero a la lista.

### `void delete(Lista *L, int index)`

Elimina el elemento en la posición `index` de la lista.

- **Parámetros**:
    - `L`: `Lista *` - Puntero a la lista.
    - `index`: `int` - El índice (basado en 0) del elemento a eliminar.

### `void clear_lista(Lista *L)`

Elimina todos los elementos de la lista, dejándola vacía. La estructura `Lista` en sí no se libera, pero su `longitud` se establece en 0 y los punteros `primera` y `ultimo` a `NULL`. Se libera la memoria de los nodos.

- **Parámetros**:
    - `L`: `Lista *` - Puntero a la lista a vaciar.

### `void destruir_lista(Lista *L)`

Elimina todos los elementos de la lista y libera la memoria asociada a los nodos. Es similar a `clear_lista`, pero el nombre sugiere que podría estar pensada para ser llamada cuando la lista ya no se va a utilizar más. El puntero `L` en sí (si fue asignado dinámicamente) debe ser liberado por el llamador después de esta función si es necesario.

- **Parámetros**:
    - `L`: `Lista *` - Puntero a la lista a destruir.






