#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>


int main(int argc, char const *argv[]) {
  setlocale(LC_ALL, "");
  printf("Hola mundo\n");
  printf("¿cómo estás?\n");
  return 0;
}
