#include <stdio.h>
#include <locale.h>
int main(int argc, char const *argv[])
{
    char alfabeto[]="abcdefghijklmnñopqrstuvwxyz";
    char* p=alfabeto;
    setlocale(LC_CTYPE,"spanish");
    while(*p) printf("%c ",*p++);
    
    return 0;
}
