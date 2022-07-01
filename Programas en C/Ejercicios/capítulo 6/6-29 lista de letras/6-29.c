#include <stdio.h>

int main(int argc, char const *argv[])
{
    for (char i = 'Z'; i >= 'A'; i--)
    {
        for (char j = i; j >= 'A'; j--)
        {
            printf("%c",j);
        } 
        puts("");
    }
    return 0;
}