#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    char car , pre = '\n';
    while ((car=getchar())!=EOF)
    {
        if (pre == ' ' || pre == '\n')
        {
            putchar(toupper(car));
        }
        else
        {
            putchar(car);
        }
        pre = car;
        
    }
    
    return 0;
}
