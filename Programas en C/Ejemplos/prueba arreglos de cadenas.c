#include <stdio.h>
int main(int argc, char const *argv[])
{
    const char cadena[12][20]={
                            "hola",
                            " mundo"
                        };
    printf("%s",cadena[1]);
    return 0;
}
