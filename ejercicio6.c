#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char cifrado_cesar(char string, int clave);

int main(){

	char cadena[1000];
	int clave = 0;
	int longitud = 0;

	printf("Introduce una cadena de carácteres la cual queres cifrar: ");
	scanf(" %[^\n]", cadena);

	printf("Introduce la clave: ");
	scanf("%d", &clave);
	if(clave < 0){
		printf("Error, introduce una clave valida (mayor que 0)\n");
		return 0;
	}

	longitud = strlen(cadena);

	char * string=(char *)malloc((longitud + 1) * sizeof(char));
	//char * string=(char *)malloc(longitud + 1 * sizeof(char));
	if(string == NULL){
		printf("Error, no se pudo reservar la memoria");
	}

	strcpy(string, cadena);

	for(int i = 0; i < longitud; i++){
		string[i] = cifrado_cesar(string[i], clave);
	}
	printf("%s\n", string);

	free(string);
	return 0;
}

char cifrado_cesar(char string, int clave){
	int string_ascii = 0;
	if(string == ' '){
		return string;
	}
	string_ascii = string;

	while(clave > 26){
		clave -= 26;	
		}
	if(isupper(string)){
		
		if(string_ascii + clave > 'Z'){
			string_ascii = string_ascii + clave - 26; 
		}else{
			string_ascii = string;
			string_ascii += clave;
		}
	}else {
		if(string_ascii + clave > 'z'){
			string_ascii = string_ascii + clave - 26;
		}else {
			string_ascii = string;
			string_ascii += clave;
		}
	}

	
	string = string_ascii;

	return string;
}