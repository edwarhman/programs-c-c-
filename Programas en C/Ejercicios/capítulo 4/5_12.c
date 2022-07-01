#include <stdio.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
    float resultado;
    int num_a,num_b;
    resultado=num_a=num_b=0;
    char operador='\n';
    setlocale(LC_CTYPE,"spanish");
    puts("Calculadora que realiza las operaciones algebraicas básicas (suma,resta,multiplicación,división,cálculo del resto).");
    puts("Para realizar el cálculo se debe ingresar una expresion como la siguiente: A + B.");
    puts("Utilizar (+) para sumar.");
    puts("Utilizar (-) para restar.");
    puts("Utilizar (*) para multiplicar.");
    puts("Utilizar (/) para dividir.");
    puts("Utilizar (%) para calcular el resto.");
    for (;;)
    {
    printf("Por favor ingrese la expresion a calcular: ");
    scanf("%d %c %d",&num_a,&operador,&num_b);
    if (operador=='+'||operador=='-'||operador=='*'||operador=='/'||operador=='%') break;
    puts("Expresión inválida.");
    }
    switch (operador)
    {
    case '+':
        resultado=num_a+num_b;
        break;
    case '-':
        resultado=num_a-num_b;
        break;
    case '*':
        resultado=num_a*num_b;
        break;
    case '/':
        resultado=((float)num_a)/(num_b);
        break;
    case '%':
        resultado=num_a%num_b;
        break;
    }
    printf("%d %c %d = %.1f\n",num_a,operador,num_b,resultado);
    return 0;
}