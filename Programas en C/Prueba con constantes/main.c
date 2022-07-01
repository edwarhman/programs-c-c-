#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>

#define NUEVALINEA "mantequilla"
#define VALOR 54
#define PI 3.141592
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "");
	printf("Hola %s",NUEVALINEA);
	printf("¿cómo estás?");
	return 0;
}
