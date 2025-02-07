#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>//Librería para comprobar si un carácter es mayuscula o minuscula

char cifrado_cesar(char string, int clave);

int main(){

	char cadena[1000];//Creamos una cadena inicial para guardar la cadena inical
	int clave = 0;
	int longitud = 0;

	printf("Introduce una cadena de carácteres la cual queres cifrar: ");
	scanf(" %[^\n]", cadena);

	printf("Introduce la clave: ");
	scanf("%d", &clave);
	if(clave <= 0){
		printf("Error, introduce una clave válida.\n");
		return 0;
	}

	longitud = strlen(cadena);//Creamos la variable longitud la cual será del tamaño de caracteres que tiene la cadena inicial

	char * string=(char *)malloc((longitud + 1) * sizeof(char)); //Creamos una memoria dinamica dependiendo de la longitud que introducimos en la cadena
	//char * string=(char *)malloc(longitud + 1 * sizeof(char));
	if(string == NULL){
		printf("Error, no se pudo reservar la memoria");
	}

	strcpy(string, cadena); //Hacemos que se pasen los caracteres de una cadena a otra

	for(int i = 0; i < longitud; i++){ //Llamamos a la funcion para cifrar para cada uno de los caracteres
		string[i] = cifrado_cesar(string[i], clave);
	}
	printf("%s\n", string);

	free(string);
	return 0;
}

char cifrado_cesar(char string, int clave){
	int string_ascii = 0;//Creamos una variable de apoyo que sea int y que se traduzca el carácter a su número ascii correspondiente
	if(string == ' '){//Comprobamos que no haya un espacio para que no cambie el carácter
		return string;
	}
	string_ascii = string;//Igualamos valores

	while(clave > 26){//Comprobamos que la clave no sea mayor al numero de carácteres existente y en caso de haberlo lo restamos hasta que quede en un numero correcto
		clave -= 26;	 
		}
	if(isupper(string)){//Cromprobamos si es mayuscula o minuscula para asctuar de distinta manera
		
		if(string_ascii + clave > 'Z'){//Comprobamos si la suma supera al abecedario y en caso de hacerlo volvemos al inicio de este
			string_ascii = string_ascii + clave - 26; 
		}else{
			string_ascii = string;
			string_ascii += clave;
		}
	}else {
		if(string_ascii + clave > 'z'){//Lo mismo pero con als minúsculas
			string_ascii = string_ascii + clave - 26;
		}else {
			string_ascii = string;
			string_ascii += clave;
		}
	}

	
	string = string_ascii;//Volvemos a igualar el resultado y asi vuelva a ser uncarácter en vez de un número

	return string;
}