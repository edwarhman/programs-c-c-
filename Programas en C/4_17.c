#include "stdio.h"
#include "locale.h"

int arroba;
int main() {
  setlocale(LC_CTYPE,"spanish");

  int mes;
  //Encabezado
  printf("Programa que indica la cantidad de días de un mes dado.\n");
  printf("\nPor favor introduzca el número del mes deseado (1-12): ");
  scanf("%d",&mes);
  switch (mes) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:{
      printf("\nEl mes tiene 31 días.\n");
      break;
  }
    case 2:{
      printf("\nEl mes tiene 28 días.\n");
      break;
    }
    case 4: case 6: case 9: case 11:{
      printf("\nEl mes tiene 30 días.\n");
      break;
    }
    default: printf("\n Lo sentimos, entrada inválida.\n");
  }
  return 0;
}
