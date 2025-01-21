#include <stdio.h>
#include <stdlib.h>

// Autores: Roberto y Sebas

void añadirNumero(int * arrNums,int añadido);
int comparar(int *arrNums, int posicionIteracion, int num1, int num2);

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

		if(i == 0){
			continue;
		}

		comparar(arrNums, i, arrNums[i -1], arrNums[i]);
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


int comparar(int *arrNums, int posicionIteracion, int num1, int num2){
	int resultadoComparacion = num1 - num2;

	if (resultadoComparacion > 0){
		int aux = arrNums[posicionIteracion];
		arrNums[posicionIteracion] = num2;

		arrNums[posicionIteracion - 1] = num1;

	}


}