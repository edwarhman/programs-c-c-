#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int random(int, int);
int main(int argc, char const *argv[])
{
    int n, ran_max=100, ran_min=50;
    srand(time(0));
    n=rand();
    n=random(ran_min,ran_max);
    printf(" %d %d",n,RAND_MAX);
    
    for (int i = 0; i < 10; i++)
    {
        n=random(ran_min,ran_max);
        printf(" %d",n);
    }
    
    return 0;
}

int random(int lower,int upper)
{
    int aleartorio=rand();
    return (aleartorio%(upper-lower+1)+lower);
}
