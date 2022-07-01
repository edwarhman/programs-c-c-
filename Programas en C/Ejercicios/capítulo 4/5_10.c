#include <locale.h>
#include <stdio.h>
#define IVA 0.1f
#define INCREMENTO 1.5f
#define LIMITE_RETENCIONES 50000

int main(int argc, char const *argv[])
{
    int horas_s,tasa;
    float salario_neto,salario_bruto;
    setlocale(LC_CTYPE,"spanish");
    puts("Programa que calcula el salario neto de un trabajador a partir de una tasa dada y las horas semanales trabajadas.");
    printf("Por favor ingrese la tasa a la que se pagan las horas trabajadas: ");
    scanf("%d",&tasa);
    printf("Ahora ingrese las horas trabajadas: ");
    scanf("%d",&horas_s);
    if (horas_s<38) salario_bruto=horas_s*4*tasa;
        else salario_bruto=horas_s*4*tasa*INCREMENTO;
    if (salario_bruto<LIMITE_RETENCIONES) salario_neto=salario_bruto;
        else salario_neto=salario_bruto-(salario_bruto*IVA);
    printf("El salario neto es %.2f.",salario_neto);
    return 0;
}
