#include "MisFunciones.h"
#include <ctype.h>
#include <iostream>
using namespace std;


// Evalúa si una cadena de C es o no un dígito.
// Recibe como parámetro una cadena de C.
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
