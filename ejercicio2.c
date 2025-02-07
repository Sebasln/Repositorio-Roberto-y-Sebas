#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRE 20
#define MAX_APELLIDO 20
#define MAX_NOTA 10

typedef struct{ //Creamos un struct para que a la hora introducir un studiante siga esa forma
        char Nombre[MAX_NOMBRE];
        char Apellido[MAX_APELLIDO];
        float Nota;
}Estudiante;

int main(){
int numero_estudiantes = 0;
int valor_retorno = 0;
int aux = 0;
char aux2[MAX_APELLIDO];
char aux3[MAX_NOMBRE];

do{
        printf("Ingrese el número de alumnos a introducir: ");
        valor_retorno = scanf("%d", &numero_estudiantes);
        if(numero_estudiantes == 0 && getchar() != '\n'){ //Comprobamos si el dato que introdujo el usuario no es número
                printf("Error el dato introducido no es un número. Introduce de nuevo \n");
                return 0;
        }else if(numero_estudiantes <= 0){ //Comprobamos que es mas alto que 0
                printf("Error introduce un numero más alto.\n");
                return 0;
        }
        

}while (valor_retorno == 0);

Estudiante *Estudiantes = (Estudiante*) malloc(numero_estudiantes * sizeof(Estudiante));

if (Estudiantes == NULL){

        printf("ERROR, no se puede asignar memoria \n");

}

for (int i = 0; i < numero_estudiantes; i++){

        printf("Introduzca el nombre del estudiante: ");
        scanf(" %[^\n]", Estudiantes[i].Nombre);

        printf("Introduzca el apellido del estudiante: ");
        scanf(" %[^\n]", Estudiantes[i].Apellido);

do{
        printf("Introduzca la nota del estudiante: ");
        valor_retorno = scanf("%f",&Estudiantes[i].Nota);

        while (getchar() != '\n'); //Comprobamos si es un número el dato introducido
                if (valor_retorno == 0){
                        printf("Error, el dato introducido no es un número, inténtelo de nuevo. \n");
        }

}while (valor_retorno == 0);

}

for (int i = 0; i < numero_estudiantes; i++){//Imprimimos los estudiantes introducidos para comprobar que esta correcto

        printf("%s %s Nota: %2.f \n", Estudiantes[i].Nombre, Estudiantes[i].Apellido, Estudiantes[i].Nota);

}
printf("\n");

printf("Aqui abajo se muestran los alumnos ingresados por orden (nota y orden alfabético): \n");

printf("Por orden de nota (Mayor a Menor): \n");



for (int i = 0; i < numero_estudiantes; i++){
        for (int j = i + 1; j < numero_estudiantes; j++){
                if(Estudiantes[i].Nota < Estudiantes[j].Nota){
                        aux = Estudiantes[i].Nota;
                        strcpy(aux2, Estudiantes[i].Apellido);
                        strcpy(aux3, Estudiantes[i].Nombre);

                        Estudiantes[i].Nota = Estudiantes[j].Nota;
                        strcpy(Estudiantes[i].Apellido, Estudiantes[j].Apellido);
                        strcpy(Estudiantes[i].Nombre, Estudiantes[j].Nombre);

                        Estudiantes[j].Nota = aux;
                        strcpy(Estudiantes[j].Apellido, aux2);
                        strcpy(Estudiantes[j].Nombre, aux3);

                }
        }
}

for (int i = 0; i < numero_estudiantes; i++){
        printf("Nombre: %s, Apellido: %s, Nota: %2.f \n", Estudiantes[i].Nombre, Estudiantes[i].Apellido, Estudiantes[i].Nota);
}


printf("\n");

printf("Por orden de apellido: \n");

for (int i = 0; i < numero_estudiantes; i++){
        for (int j = i + 1; j < numero_estudiantes; j++){
                if (strcmp(Estudiantes[i].Apellido, Estudiantes[j].Apellido) > 0){
                        aux = Estudiantes[i].Nota;
                        strcpy(aux2, Estudiantes[i].Apellido);
                        strcpy(aux3, Estudiantes[i].Nombre);

                        Estudiantes[i].Nota = Estudiantes[j].Nota;
                        strcpy(Estudiantes[i].Apellido, Estudiantes[j].Apellido);
                        strcpy(Estudiantes[i].Nombre, Estudiantes[j].Nombre);

                        Estudiantes[j].Nota = aux;
                        strcpy(Estudiantes[j].Apellido, aux2);
                        strcpy(Estudiantes[j].Nombre, aux3);

                }
        }
}

for (int i = 0; i < numero_estudiantes; ++i){
        printf("Nombre: %s, Apellido: %s, Nota: %2.f \n", Estudiantes[i].Nombre, Estudiantes[i].Apellido, Estudiantes[i].Nota);
}

        free(Estudiantes);
        return 0;
}
