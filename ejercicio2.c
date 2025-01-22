#include <stdio.h>
#include <stdlib.h>

//TO DO: Migrar la función del qsort a este código e invertirla. De ahí seguir xd
#define MAX_NOMBRE 40
#define MAX_APELLIDO 40
// Autores: Roberto y Sebas

typedef struct{
	char nombre[MAX_NOMBRE];
	char apellido[MAX_APELLIDO];
	float nota;
} Estudiante;

void añadirEstudiante(Estudiante * Estudiantes, int cantidad);
void imprimirEstudiantes(int * agarrPosicion, float * arrNota, Estudiante * Estudiantes, int cantidad);
int comparar(const void * a, const void * b);
void notas(int * arrPosicion, float* arrNota, Estudiante * Estudiantes, int cantidad);

int main(){
	int numEstudiantes;

	printf("¿Cuántos estudiantes quieres introducir? ");
	scanf("%d", &numEstudiantes);

	float arrNotas[numEstudiantes];
	int arrPosicionNotas[numEstudiantes];

	Estudiante * Estudiantes = (Estudiante *) malloc(numEstudiantes * sizeof(Estudiante));
	añadirEstudiante(Estudiantes, numEstudiantes);
	// qsort(, numEstudiantes, sizeof(Estudiante), comparar);

	notas(arrPosicionNotas, arrNotas, Estudiantes, numEstudiantes);

	imprimirEstudiantes(arrPosicionNotas, arrNotas, Estudiantes, numEstudiantes);

	free(Estudiantes);
	return 0;
}

void añadirEstudiante(Estudiante * Estudiantes, int cantidad){
	for (int i = 0; i < cantidad; i++){
		printf("Nombre:\n");
		scanf(" %[^\n]", Estudiantes[i].nombre);

		printf("Apellido:\n");
		scanf(" %[^\n]", Estudiantes[i].apellido);

		printf("Nota:\n");
		scanf("%f", &Estudiantes[i].nota);
	}

}

void imprimirEstudiantes(int * arrPosicion, float * arrNota, Estudiante * Estudiantes, int cantidad){
	printf("Estos son los estudiantes ordenados por nota: \n");
	for(int i = 0; i < cantidad; i++){
		printf("Nombre: %s \n Apellido: %s\n Nota: %f\n", Estudiantes[arrPosicion[i]].nombre, Estudiantes[arrPosicion[i]].apellido, Estudiantes[arrPosicion[i]].nota);

	}

	// printf("Estos son los estudiantes ordenados por nota: \n");

	for(int i = 0; i < cantidad; i++){
		// arrNotas, 


	}
}

int comparar(const void * a, const void * b){
	return (*(int*)a) - (*(int*)b);
}

// void notas(int *arrPosicion, float * arrNota, Estudiante * Estudiantes, int cantidad){
// 	int aux;

// 	for(int i = 0; i < cantidad; i++){
// 		arrNota[i] = Estudiantes[i].nota;
// 		arrPosicion[i] = cantidad - i;
// 	}
// 	qsort(arrNota, cantidad, sizeof(float), comparar);


// 	// arrNota[]

// 	printf("Notas de mayor a menor:\n");
// 	for(int i = 0; i < cantidad; i++){
// 		printf("Nota %d: %.2f\n", i +1,  arrNota[i]);
// 	}
// }