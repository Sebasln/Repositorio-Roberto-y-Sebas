#include <stdio.h>
#include <stdlib.h>

// Autores: Roberto y Sebas

void añadirNumero(int * arrNums,int añadido);
int comparar(int * arrNums, int cantidad);

int main(){
	int input;

	printf("¿Cuántos números quieres ordenar? ");
	scanf("%d", &input);


	int *arrNums = (int *) malloc(input * sizeof(int)); //Creamos la memoria dinámica la cual alamcenará los numeros a ordenar

	if (arrNums == NULL){
		printf("Error.\n");
		return 1;
	}

	añadirNumero(arrNums, input);
	comparar(arrNums, input);
	printf("Resultado:\n");
	for (int i = 0; i < input; i++){
		printf("Numero %d:%d\n",i + 1,arrNums[i]);
	}	

	free(arrNums);
	return 0;
}

void añadirNumero(int * arrNums,int añadido){
	int numeros = 0;
	if (añadido < 1) {  //Comprobamos que la cantidad a ordenar es mayor que 1 y en caso de no serla terminamos el programa
		printf("Error la cantidad es muy pequeña.\n");
		exit(1);
	}

	printf("Introduce los números:\n");

	for (int i = 0; i < añadido; ++i){  //Bucle para rellenar el array
		printf("Número %d: ", i + 1);
		scanf("%d", &numeros);
		arrNums[i] = numeros;
	}
}


int comparar(int * arrNums, int cantidad){
	int aux = 0;
	for (int i = 0; i < cantidad; i++){
		for(int j = i + 1; j < cantidad; j++){
			if (arrNums[i] > arrNums[j]){   //Creamos una condición en la cual si i(el primer numero) es mayor que j(segundo numero que es un bucle que empieza una posición por encima de i siempre) se intercambien las posición haciendo que el primero sea el mas pequeño y luego con el segundo numero.
				aux = arrNums[i];
				arrNums[i] = arrNums[j];
				arrNums[j] = aux;
			}
		}
	}
}
