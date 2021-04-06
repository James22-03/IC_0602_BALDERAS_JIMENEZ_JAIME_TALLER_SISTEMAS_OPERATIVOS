#include <stdio.h>
#include <conio.h>
typedef struct proceso{
	int dato;
	char nombre[20];
	char estado[20];
	int espacio;
	struct proceso* siguiente;
}proceso;

proceso* primero = NULL;
proceso* ultimo = NULL;

void insertar();
void buscar();
void liberar();
void mostrar();

int main(){
	int opcionMenu = 0;
	do{
        printf("\n ELABORADO POR: BALDERAS JIMENEZ JAIME ");
		printf("\n|-------------------------------------|");
		printf("\n|   PLANIFICADOR DE PROCESOS (FIFO)   |");
		printf("\n|------------------|------------------|");
		printf("\n| 1. Insertar      | 3. Liberar       |");
		printf("\n| 2. Buscar        | 4. Mostrar       |");
		printf("\n|                  | 5. Salir         |");
		printf("\n|------------------|------------------|");
		printf("\n\n Escoja una opcion: ");
		scanf("%d", &opcionMenu);
		switch(opcionMenu){
			case 1:
				printf("\n\n..INGRESANDO PROCESO..\n\n");
				insertar();
				break;
			case 2:
				printf("\n\n..BUSCANDO PROCESO..\n\n");
				buscar();
				break;
			case 3:
				printf("\n\n..LIBERANDO PROCESO..\n\n");
				eliminar();
				break;
			case 4:
				printf("\n\n..MOSTRANDO PROCESOS..\n\n");
				mostrar();
				break;
			case 5:
				printf("\n\n..FIN DEL PROGRAMA..GRACIAS..");
				break;
			default:
				printf("\nOPCION NO VALIDA\n");
		}
	}while(opcionMenu != 5);
	return 0;
}

void insertar(){
	proceso* nuevo = (proceso*) malloc(sizeof(proceso));
	printf(" Ingrese el identificador del proceso: ");
	scanf("%d", &nuevo->dato);
	printf(" Ingrese el nombre del proceso: ");
	scanf("%s", &nuevo->nombre);
	printf(" Ingrese el estado del proceso: ");
	scanf("%s", &nuevo->estado);
	printf(" Ingrese el espacio que ocupa el proceso: ");
	scanf("%d", &nuevo->espacio);
	if(primero == NULL){
		primero = nuevo;
		primero->siguiente = NULL;
		ultimo = nuevo;
	}else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = NULL;
		ultimo = nuevo;
	}
	printf("\n Proceso ingresado con exito\n\n");
}

void buscar(){
	proceso* actual = (proceso*) malloc(sizeof(proceso));
	actual = primero;
	int procesoBuscado = 0, encontrado = 0;
	printf(" Ingrese el identificador del proceso a buscar: ");
	scanf("%d", &procesoBuscado);
	if(primero != NULL){
		while(actual != NULL && encontrado != 1){
			if(actual->dato == procesoBuscado){
				printf("\n El proceso con el ID: ( %d ) encontrado\n\n", procesoBuscado);
				encontrado = 1;
			}
			actual = actual->siguiente;
		}
		if(encontrado==0){
			printf("\n Proceso no encontrado\n\n");
		}
	}else{
		printf("\n Lista de procesos vacia\n\n");
	}
}

void eliminar(){
	proceso* actual = (proceso*) malloc(sizeof(proceso));
	actual = primero;
	proceso* anterior = (proceso*) malloc(sizeof(proceso));
	anterior = NULL;
	int procesoBuscado = 0, encontrado = 0;
	printf(" Ingrese el identificador del proceso a eliminar: ");
	scanf("%d", &procesoBuscado);
	if(primero != NULL){
		while(actual != NULL && encontrado != 1){
			if(actual->dato == procesoBuscado){
				if(actual == primero){
					primero = primero->siguiente;
					printf("\nProceso liberado con exito\n\n");
					encontrado = 1;
				}else{
			    printf("\nError: El proceso no se encuentra al comienzo de la cola\n");
			}
			}
			anterior = actual;
			actual = actual->siguiente;
		}
		if(encontrado==0){
			printf("\nLiberacion fallida\n");
		}else{
			free(anterior);
		}
	}else{
		printf("\nLista de procesos vacia\n\n");
	}
}

void mostrar(){
	proceso* actual = (proceso*) malloc(sizeof(proceso));
	actual = primero;
	if(primero != NULL){
	    printf("ID -- NOMBRE -- ESTADO -- ESPACIO");
		while(actual != NULL){
			printf("\n%d--%s--%s--%d", actual->dato, actual->nombre,actual->estado,actual->espacio);
			actual = actual->siguiente;
		}
	}else{
		printf("\nLista de procesos vacia\n");
	}
}
