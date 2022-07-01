#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    char *C1=NULL, *C2=NULL, b[121],*S=NULL;
    char *clave="copia";
    int tam=0;

    puts("Primera cadena:");
    gets(b);
    tam=(strlen(b)+1)*sizeof(char);
    C1=(char*)realloc(C1,tam);
    strcpy(C1,b);
    puts("Segunda cadena:");
    gets(b);
    tam=(strlen(b)+1)*sizeof(char);
    C2=(char*)realloc(C2,tam);
    strcpy(C2,b);

    if (strlen(clave)<strlen(C2))
    {
        int j;
        char* R=NULL;
        R=(char*)realloc(R,(strlen(clave)+1)*sizeof(char));
        for (j = 0; j < strlen(clave); j++)
        {
            *(R+j)=*(C2+j);
        }
        *(R+j)='\0';
        if (strcmp(R,clave)==0)
        {
            int i;
            for (i = 0; i < strlen(C2)-strlen(clave); i++)
            {
                *(C2+i)=*(C2+(i+strlen(clave)));
            }
            *(C2+i)='\0';
            tam=(strlen(C1)+strlen(C2)+1)*sizeof(char);
            C1=(char*)realloc(C1,tam);
            strcat(C1,C2);
            S=R;
        }
    }
    printf("\nPrimera cadena: %s", C1);
    printf("\nSegunda cadena: %s%s",S,C2);
    return 0;
}
