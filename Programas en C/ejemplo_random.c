#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main(int argc, char const *argv[]) {
  setlocale(LC_CTYPE,"spanish");
  printf("Hola mundo. ¿cómo estás?\n");
  randomize();
  int lista[10];
  for (int i = 0; i < 10; i++) {
    lista[i]=random(50)+1;
  }

  return 0;
}
