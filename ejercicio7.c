#include <stdio.h>
#include <stdlib.h>

int encontar_primos(int limite);

int main(){

int m = 0;
int contador = 0;

printf("Introduce un número limite para calcular los primos: ");
scanf("%d", &m);

int * array = (int *)malloc(m * sizeof(int));

	for (int i = 0; i <= m ; ++i){
		if(encontar_primos(i)){
			contador += 1;
			array = realloc(array, contador * sizeof(int));
			array[contador - 1] = i;
		}
	}
	printf("Los primos son: ");
	for (int i = 0; i < contador; i++){
		printf("%d", array[i]);
		if(i < contador-2){
			printf(", ");
		}else if(i < contador-1){
			printf(" y ");
		}
	}
	printf(".\n");
	return 0;
}


int encontar_primos(int limite){
	if(limite < 2){
		return 0;
	}
	for(int i = 2;i < limite; i++){
		if(limite % i == 0){
			return 0;
		}
	}
	return 1;
}