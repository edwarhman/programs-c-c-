#include <stdio.h>

int main(int argc, char const *argv[])
{
    int N = 75;
    int* p;
    printf("p = %d\n",p);
    p= &N;
    printf("N = %d\t&N = %p\tp = %p\n",N,&N,p);
    printf("&p = %p\n",&p);
    //p=N;
    *p=999;
    printf("N = %d",N);
    printf("N = %d",*p);

    return 0;
}
