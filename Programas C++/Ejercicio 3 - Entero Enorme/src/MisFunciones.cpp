#include "MisFunciones.h"
#include <ctype.h>
#include <iostream>
using namespace std;


// Eval�a si una cadena de C es o no un d�gito.
// Recibe como par�metro una cadena de C.
bool esDigito(char *cadena)
{
    for (;*cadena ; cadena++)
    {
        if (!isdigit(*cadena))
        {
            return false;
        }
    }
    return true; 
}
