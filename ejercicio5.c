#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rellenarMatriz(int **matriz, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matriz[i][j] = (i + 1) * j + 1; // Números aleatorios entre 0 y 99
        }
    }
}

void mostrarMatriz(int **matriz, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matriz[i][j]); // Imprime el número con un ancho de 3 caracteres
        }
        printf("\n");
    }
}

int sumaContorno(int **matriz, int n, int m) {
    int suma = 0;
    
    // Sumar primera y última fila
    for (int j = 0; j < m; j++) {
        suma += matriz[0][j] + matriz[n - 1][j];
    }
    
    // Sumar primera y última columna (sin repetir esquinas)
    for (int i = 1; i < n-1; i++) {
        suma += matriz[i][0] + matriz[i][m-1];
    }
    
    return suma;
}

int main() {
    int n, m;
    
    printf("Ingrese el número de filas (n): ");
    scanf("%d", &n);
    printf("Ingrese el número de columnas (m): ");
    scanf("%d", &m);
    
    // Reserva de memoria dinámica
    int **matriz = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matriz[i] = (int *)malloc(m * sizeof(int));
    }
    
    rellenarMatriz(matriz, n, m);
    printf("Matriz:\n");
    mostrarMatriz(matriz, n, m);
    
    int suma = sumaContorno(matriz, n, m);
    printf("La suma del contorno es: %d\n", suma);
    
    // Liberar memoria
    for (int i = 0; i < n; i++) {
        free(matriz[i]);
    }
    
    free(matriz);
    return 0;
}
