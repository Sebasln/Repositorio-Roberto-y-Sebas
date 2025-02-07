#include <stdio.h>
#include <stdlib.h>

int encontar_primos(int limite);

int main(){

int m = 0;
int contador = 0;

printf("Introduce un número limite para calcular los primos: ");
scanf("%d", &m);

int * array = (int *)malloc(m * sizeof(int));//Creamos un array con el tamaño maximo que podría tener y después ajustamos su tamaño
if(array == NULL){
	printf("Error al reservar la memoria.\n");
	return 0;
}

	for (int i = 0; i <= m ; ++i){
		if(encontar_primos(i)){//Comprobamos que se cumpla la condicion de que es un primo cada número hasta el introducido
			contador += 1; //Creamos un contador para poder hacer un realloc con el tamaño nuevo
			array = realloc(array, contador * sizeof(int));//Hacemos el realloc de la memoria
			if(array == NULL){
				printf("Error al reservar la memoria.\n");
				return 0;
			}
			array[contador - 1] = i; //Guardamos el numero primo en el array.
		}
	}
	printf("Los primos del número %d son: ", m);
	for (int i = 0; i < contador; i++){//Recorremos el array y usamos el contador para saber el tamaño nuevo del array
		printf("%d", array[i]);
		if(i < contador-2){ //Hacemos que imrpima una coma entre todos los numeros excepto entre el penúltimo y el último número
			printf(", ");
		}else if(i < contador-1){//Hacemos que escriba una "y" entre el penúltimo y el último número
			printf(" y ");
		}
	}
	printf(".\n");
	return 0;
}


int encontar_primos(int limite){//Función para comprobar si es primo
	if(limite < 2){//Comprobamos que no sea menor a 2 ya que no nos interesa el número 0 ni el 1 ya que todos los numeros tendrían estos.
		return 0;//En caso de que sea así devolvemos un 0 (false) para que no se incluya dicho numero
	}
	for(int i = 2;i < limite; i++){//Empezamos en 2 ya que si fuese 1 todos se pueden dividir
		if(limite % i == 0){//Comprobamos si el numero es divisible entre todos los números entre 2 y el limite establecido
			return 0;
		}
	}
	return 1;//En caso de que no se haya podido dividir entre ninguno devolvemos 1 (true) para que almacene el número
}