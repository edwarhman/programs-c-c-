#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    void *p;
    int i;
    long m = 0;
    for (i = 0;; i++)
    {
        p=malloc(1000);
        if(p==NULL) break;
        m+=1000;
    }
    printf("\nTotal de memoria asignada: %d",m);
    return 0;
}
