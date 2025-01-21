#include <stdio.h>
#include <stdlib.h>

// Autores: Roberto y Sebas

void añadirNumero(int * arrNums,int añadido);
int comparar(const void * a, const void * b);

int main(){
	int input;

	printf("¿Cuántos números quieres ordenar? ");
	scanf("%d", &input);


	int *arrNums = (int *) malloc(input * sizeof(int));

	if (arrNums == NULL){
		printf("Error.\n");
		return 1;
	}

	añadirNumero(arrNums, input);

	printf("Resultado:\n");
	for (int i = 0; i < input; i++){
		printf("Numero %d:%d\n",i + 1,arrNums[i]);
	}	

	free(arrNums);
	return 0;
}

void añadirNumero(int * arrNums,int añadido){
	int numeros = 0;
	if (añadido < 1) {
		printf("Invalid quantity.\n");
		return;
	}

	printf("Introduce los números:\n");

	for (int i = 0; i < añadido; ++i){
		printf("Número %d: ", i + 1);
		scanf("%d", &numeros);
		arrNums[i] = numeros;
	}
}


int comparar(const void * a, const void * b){
	return (*(int*)a - *(int*)b);
}