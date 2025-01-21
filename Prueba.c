#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Función de comparación para qsort
int comparar(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main(int argc, char *argv[]) {
    int n;                // Número de enteros
    int *arr = NULL;      // Puntero para el array dinámico

    if (argc > 1) {
        // Si hay argumentos en la línea de comandos, se usa el primero como `n`
        n = atoi(argv[1]);
        if (n <= 0) {
            fprintf(stderr, "Error: Debe introducir un número entero positivo como tamaño.\n");
            return 1;
        }

        // Reservar memoria para el array
        arr = (int *)malloc(n * sizeof(int));
        if (arr == NULL) {
            fprintf(stderr, "Error: No se pudo asignar memoria.\n");
            return 1;
        }

        if (argc - 2 >= n) {
            // Leer los valores desde los argumentos de línea de comandos
            for (int i = 0; i < n; i++) {
                arr[i] = atoi(argv[i + 2]);
            }
        } else {
            // Si no hay suficientes números en los argumentos, pedir por consola
            printf("No hay suficientes números en los argumentos. Introduzca %d números:\n", n);
            for (int i = 0; i < n; i++) {
                printf("Número %d: ", i + 1);
                scanf("%d", &arr[i]);
            }
        }

    } else {
        // Si no hay argumentos en la línea de comandos, pedir `n` y los valores por consola
        printf("¿Cuántos números desea introducir? ");
        scanf("%d", &n);

        if (n <= 0) {
            fprintf(stderr, "Error: Debe introducir un número entero positivo como tamaño.\n");
            return 1;
        }

        // Reservar memoria para el array
        arr = (int *)malloc(n * sizeof(int));
        if (arr == NULL) {
            fprintf(stderr, "Error: No se pudo asignar memoria.\n");
            return 1;
        }

        // Leer los valores desde la consola
        printf("Introduzca %d números:\n", n);
        for (int i = 0; i < n; i++) {
            printf("Número %d: ", i + 1);
            scanf("%d", &arr[i]);
        }
    }

    // Ordenar los números usando qsort
    qsort(arr, n, sizeof(int), comparar);

    // Imprimir los números ordenados
    printf("Números ordenados:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Liberar la memoria dinámica
    free(arr);

    return 0;
}
