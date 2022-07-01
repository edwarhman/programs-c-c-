#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	//bool fas=true;
	boolean salir;
	char eleccion[20];
	do{
		printf("Esto es un programa.\n");
		scanf("none");	
		printf("¿Desea salir? (Si/no)");
		scanf("%i",salir);
	
	} while (salir==FALSE);
	
	return 0;
}
