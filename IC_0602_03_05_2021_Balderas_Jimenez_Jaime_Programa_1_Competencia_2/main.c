#include "scheduler.h"
#include <pthread.h>

void accion1(void *argv){
	printf("Reproduciendo musica\n");
	pthread_exit(NULL);
}
void accion2(void *argv){
	printf("Usando Youtube\n");
	pthread_exit(NULL);
}
void accion3(void *argv){
	printf("Escribiendo texto en Word\n");
	pthread_exit(NULL);
}
void accion4(void *argv){
	printf("Descargando archivo\n");
	pthread_exit(NULL);
}
void accion5(void *argv){
	printf("Subiendo archivo\n");
	pthread_exit(NULL);
}
void accion6(void *argv){
	printf("Compilando programa\n");
	pthread_exit(NULL);
}
void accion7(void *argv){
	printf("Ejecutando programa\n");
	pthread_exit(NULL);
}
void accion8(void *argv){
	printf("Usando terminal\n");
	pthread_exit(NULL);
}

int main(int argc, char const *argv[]){
	pthread_t h1,h2,h3,h4,h5,h6,h7,h8;

	process *p1 = crear_Proceso(1, UN_SEGUNDO, "Proceso_1", accion1, ACTIVO); 		//<--
	process *p2 = crear_Proceso(1, DOS_SEGUNDOS, "Proceso_1", accion2, NO_ACTIVO);
	process *p3 = crear_Proceso(3, TRES_SEGUNDOS, "Proceso_2", accion3, ACTIVO); 	//<--
	process *p4 = crear_Proceso(4, TRES_SEGUNDOS, "Proceso_3", accion4, ACTIVO);   	//<--
	process *p5 = crear_Proceso(3, TRES_SEGUNDOS, "Proceso_4", accion5, ACTIVO);		
	process *p6 = crear_Proceso(4, TRES_SEGUNDOS, "Proceso_5", accion6, NO_ACTIVO);
	process *p7 = crear_Proceso(0, TRES_SEGUNDOS, "Proceso_6", accion7, ACTIVO);	//<--	
	process *p8 = crear_Proceso(2, CUATRO_SEGUNDOS, "Proceso_7", accion8, ACTIVO);		//<--
	process *p9 = crear_Proceso(5, CUATRO_SEGUNDOS, "Proceso_8", accion8, NO_ACTIVO);	//<--*/

	array_procesos *array = crear_ArrayProcesos();

	agregar_Proceso(array, *p1);
	agregar_Proceso(array, *p2);
	agregar_Proceso(array, *p3);
	agregar_Proceso(array, *p4);
	agregar_Proceso(array, *p5);
	agregar_Proceso(array, *p6);
	agregar_Proceso(array, *p7);
	agregar_Proceso(array, *p8);
	agregar_Proceso(array, *p9);

	ejecutar_Procesos(array);
	
	pthread_create(&h1,NULL,(void*)accion1,NULL);pthread_join(h1,NULL);
	pthread_create(&h2,NULL,(void*)accion2,NULL);pthread_join(h2,NULL);
	pthread_create(&h3,NULL,(void*)accion3,NULL);pthread_join(h3,NULL);
	pthread_create(&h6,NULL,(void*)accion6,NULL);pthread_join(h6,NULL);
	pthread_create(&h7,NULL,(void*)accion7,NULL);pthread_join(h7,NULL);
	pthread_create(&h8,NULL,(void*)accion8,NULL);pthread_join(h8,NULL);

	free(array);
	free(p1);
	free(p2);
	free(p3);
	free(p4);
	free(p5);
	free(p6);
	free(p7);
	free(p8);
	free(p9);

	return 0;
}