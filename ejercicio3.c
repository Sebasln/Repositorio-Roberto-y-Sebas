#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_SIZE 10

void imprimir_tablero(int ancho, int alto, int x, int y);

int main(int argc, char *argv[]) {
    int ancho = DEFAULT_SIZE, alto = DEFAULT_SIZE;
    if (argc == 2) {
        ancho = alto = atoi(argv[1]);
    } else if (argc == 3) {
        ancho = atoi(argv[1]);
        alto = atoi(argv[2]);
    }
    
    if (ancho < 3 || alto < 3) {
        printf("El tamaño debe ser al menos 3x3.\n");
        return 1;
    }

    int x = ancho / 2, y = alto / 2; // Posición inicial en el centro
    char movimiento;
    
    do {
        imprimir_tablero(ancho, alto, x, y);
        printf("Usa W A S D para mover (#) y Q para salir: ");
        scanf(" %c", &movimiento);
        
        switch (movimiento) {
            case 'w': case 'W': if (y > 1) y--; break;
            case 's': case 'S': if (y < alto - 2) y++; break;
            case 'a': case 'A': if (x > 1) x--; break;
            case 'd': case 'D': if (x < ancho - 2) x++; break;
        }
    } while (movimiento != 'q' && movimiento != 'Q');
    
    return 0;
}

void imprimir_tablero(int ancho, int alto, int x, int y) {
    system("clear"); // Para limpiar la pantalla en sistemas Unix/Linux
    for (int i = 0; i < alto; i++) {
        for (int j = 0; j < ancho; j++) {
            if (i == 0 || i == alto - 1 || j == 0 || j == ancho - 1) {
                printf("*");
            } else if (i == y && j == x) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
