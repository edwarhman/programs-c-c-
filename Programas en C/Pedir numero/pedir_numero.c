#include <stdio.h>
#include <wchar.h>
#include <locale.h>
int entrada =0;

int main(int argc, char const *argv[]) {
  setlocale(LC_ALL,"spanish");
  printf("Ingrese un número: "); 
  scanf("%d",&entrada);
  printf("\nSu numero es: %d\n",entrada);
  return 0;
}
