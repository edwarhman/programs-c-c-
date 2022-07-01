#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main(int argc, char const *argv[]) {
  setlocale(LC_ALL, "spanish");
  printf("Hola mundo.\n");
  printf("¿Cómo estás?\n");
  return 0;
}
