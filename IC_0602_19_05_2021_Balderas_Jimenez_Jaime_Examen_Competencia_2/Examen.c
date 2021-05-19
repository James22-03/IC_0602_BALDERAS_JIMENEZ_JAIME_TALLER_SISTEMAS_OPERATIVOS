#include <stdio.h>
int main(){
char x='x',y='y';
char *p,*puntero,*punteroChar,*punteroCharDos;
p=&x;
puntero=&y;
char arrayChar[5];
punteroChar=&arrayChar[5];
punteroCharDos=&arrayChar[0];
int i=0;
	printf("Ejercicio 1 \n");
	printf("El contenido de p es: %c \n",*p);
	*(p+1);
	printf("El contenido de p es: %c \n",*p);
	*(p+2);
	printf("El contenido de p es: %c \n",*p);
	printf("El contenido de puntero es: %c \n",*puntero);
	printf("Ejercicio 2 \n");
	while (arrayChar[i]!='\0'){
		arrayChar[i]=='a'||arrayChar[i]=='b'||arrayChar[i]=='c'||arrayChar[i]=='d'||arrayChar[i]=='e';
		i++;
	}
	printf("El primer elemento de arrayChar es: %c \n",arrayChar[0]);
	printf("El primer elemento del puntero arrayChar es: %c \n",arrayChar[0]);
	printf("El primer elemento del puntero arrayChar es: %c \n",*punteroChar);
	printf("El primer elemento del puntero arrayChar es: %c \n",*punteroCharDos);
	printf("El quinto elemento del puntero arrayChar es: %c \n",arrayChar[4]);
	printf("El quinto elemento del puntero arrayChar es: %c \n",*(punteroCharDos+4));
	printf ("Valores: ");
	for(i=0;i<5;i++){
		printf ("%c",punteroCharDos[i]);
		i++;
	};
	printf ("Valores: ");
	for(i=0;i<5;i++){
		printf ("%c",punteroCharDos[i]);
		i++;
	};
}
