#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rellenarMatriz(int **matriz, int n, int m) { //Creamos una funcion del puntero doble el cual recorra ambos array para rellenar los datos 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matriz[i][j] = (i + 1) * j + 1; 
        }
    }
}

void mostrarMatriz(int **matriz, int n, int m) {//Funcion para mostrar la matriz entera
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%3d ", matriz[i][j]); //El %3d hace que al imprimir el resultado quede alineados todos
        }
        printf("\n");
    }
}

int sumaContorno(int **matriz, int n, int m) {//Una funcion para sumar los bordes 
    int suma = 0;
    
    
    for (int j = 0; j < m; j++) {//Suma la primera y la última fila
        suma += matriz[0][j] + matriz[n - 1][j];
    }
    
    
    for (int i = 1; i < n-1; i++) {//Suma la primera y la última columna (sin repetir las esquinas)
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
    int **matriz = (int **)malloc(n * sizeof(int *));//Creamos la memoria dinamica con un doble puntero
    for (int i = 0; i < n; i++) {
        matriz[i] = (int *)malloc(m * sizeof(int)); //Creamos la segunda memoria dinamica dentro de la primera(pincipal)
    }
    
    rellenarMatriz(matriz, n, m);
    printf("Matriz:\n");
    mostrarMatriz(matriz, n, m);
    
    int suma = sumaContorno(matriz, n, m);
    printf("La suma del contorno es: %d\n", suma);
    
    // Liberar memoria
    for (int i = 0; i < n; i++) {
        free(matriz[i]);//Liberamos la segunda memoria la cual se almacena dentro de la primera
    }
    
    free(matriz);
    return 0;
}
