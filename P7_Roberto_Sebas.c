#include <stdio.h>
#include <stdlib.h>

// Autores: Roberto y Sebas

Num * añadirNumero(int input, int num);

int main(){
	int input;

	printf("¿Cuántos números quieres ordenar? ");
	scanf("%d", &input);



	return 0;
}

int arrNums = (int *)malloc(input * sizeof(int));

if (arrNums == NULL){
	printf("Error.\n");
	return 1;
}

Num * añadirNumero(int input, int num){

}