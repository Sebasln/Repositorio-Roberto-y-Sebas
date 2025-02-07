#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compararString(char * arr, int tam, int ini, int resul, int mitad);
int main(){
	int tam = 0;
	int ini = 0;
	int resul = 0;
	int mitad = 0;

	printf("Introduce el tamaño del array: ");
	scanf("%d", &tam);
	if(tam <= 0){
		printf("Erro el tamaño introducido no es correcto.\n");
		return 0;
	}

	char * string = (char *)malloc((tam + 1) * sizeof(char));//Declaramos un string del tmaño introducido +1 para el /0
	if (string == NULL){
		printf("Error\n");
		return 1;
	}

	printf("Introduce un string: ");
	scanf("%s", string);

	if(strlen(string) > (sizeof(char) * tam ) ){//Comprobamos que la cadena introdicida sea del tamaño que se indicó

		printf("Error introduce una cadena con el tamaño correcto.\n");
		return 0;
	}
	
	if (tam % 2 == 0){ //Declaramos la mitad y en caso de ser par le restamos uno ya qeu empieza contando en 0
		mitad = tam / 2 - 1 ;
	} else {
		mitad = tam / 2;
	}

	int resultado = compararString(string, tam - 1, ini, resul, mitad);
	if(resultado == 0){
		printf("si\n");
	}else{
		printf("no\n");
	}
	return 0;
}

int compararString(char * string, int tam,int ini, int resul, int mitad){//Hacemos un comparaddor de forma recursiva
	if(mitad % 2 == 1 && ini > tam){ //Comrpbamos que en caso de ser impar que el principio no supere al final ya que significaria que comparó todos
			return resul;
	}else if(mitad % 2 == 0 && ini == tam){//Comrpbamos que en caso de ser par que el principio es igual al final ya que significaria que comparó todos
			return resul;
	}


	if(string[ini] == string[tam]){//Comparamos el principio con el final y en caso de ser iguales pasaría al siguiente
		tam -= 1;
		ini += 1;
		resul = compararString(string, tam, ini, resul, mitad);
	} else {
		resul = 1;
	}
	return resul;
}