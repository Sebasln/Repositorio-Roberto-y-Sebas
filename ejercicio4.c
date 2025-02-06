#include <stdio.h>
#include <stdlib.h>

int compararString(char * arr, int tam, int ini, int resul, int mitad);
int main(){
	int tam = 0;
	int ini = 0;
	int resul = 0;
	int mitad = 0;

	printf("Introduce el tamaño del array: ");
	scanf("%d", &tam);

	char * string = (char *)malloc(tam +1 * sizeof(char));
	if (string == NULL){
		printf("Error\n");
		return 1;
	}

	printf("Introduce un string: ");
	scanf("%s", string);

	if(sizeof(string) > (sizeof(char) * tam) ){

		printf("Error introduce una cadena con el tamaño correcto.\n");
		return 0;
	}
	
	if (tam % 2 == 0){
		mitad = tam /2 - 1;
	} else {
		mitad = tam / 2 ;
	}

	int resultado = compararString(string, tam - 1, ini, resul, mitad);
	if(resultado == 0){
		printf("si\n");
	}else{
		printf("no\n");
	}
	return 0;
}

int compararString(char * string, int tam,int ini, int resul, int mitad){
	if(mitad % 2 == 1 && ini > tam){
			return resul;
	}else if(mitad % 2 == 0 && ini == tam){
			return resul;
	}
	// if(ini == tam || ini > tam){
	// 	return resul;
	// }

	if(string[ini] == string[tam]){
		tam -= 1;
		ini += 1;
		resul = compararString(string, tam, ini, resul, mitad);
	} else {
		resul = 1;
	}
	return resul;
}