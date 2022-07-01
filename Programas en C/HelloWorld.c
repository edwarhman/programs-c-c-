#include <stdio.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
    setlocale(LC_CTYPE,"spanish");
    puts("número máximo o mínimo.");
    puts("Hello World.");
    return 0;
}
