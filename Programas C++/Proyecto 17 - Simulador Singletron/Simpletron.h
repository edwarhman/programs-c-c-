#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
#define CAPACIDAD_MAX 10000
#define TAB 28
#define DIGITOS 5
#define MEMORIA 100
void alto(int acumulador, int contadorInstrucciones, int registroInstruccion, int codigoOperacion, int operando, const int * memoria);
enum class Operaciones {LEE = 10, ESCRIBE,
                        CARGA = 20, ALMACENTA,
                        SUMA = 30, RESTA, DIVIDE, MULTIPLICA,
                        BIFURCA = 40, BIFURCANEG, BIFURCACERO, ALTO
};

// Operaciones de entrada

// Lee una palabra desde el teclado y la introduce en una ubicaci�n espec�fica de memoria.
void lee(int ubicacion, int * const memoria, long * centinela = nullptr)
{
    long entrada = 0;
    std:: cout << "? ";
    std::cin >> entrada;
    if (entrada >= 0 && entrada < CAPACIDAD_MAX)
    {
        memoria[ubicacion] = entrada;
    }
    else if (entrada == -99999)
    {
        *centinela = entrada;
    }
    
    else
    {
        throw std::invalid_argument("*** instruccion inv�lida. Por favor intente de nuevo ***");
        lee(ubicacion, memoria, centinela);
    }
    
}

// Escribe una palabra de una ubicaci�n espec�fica de memoria y imprime en pantalla
void escribe(int ubicacion, int * const memoria)
{
    std::cout << memoria[ubicacion] << std::endl;
}

// Operaciones de carga/almacenamiento

// Carga una palabra de una ubicaci�n especifica de memoria y la coloca en el acumulador
void carga(int ubicacion, int * const memoria, int * const acumulador)
{
    *acumulador = memoria[ubicacion];
    std::cout << memoria[ubicacion] << " se cargo en el acumulador.\n";
}

// Almacena una palabra del acumulador dentro de una ubicaci�n espec�fica de memoria.
void almacena(int ubicacion, int acumulador, int * const memoria)
{
    memoria[ubicacion] = acumulador;
    std::cout << "El valor en el acumulador (" << acumulador << ") se almacen� en la ubicaci�n " << ubicacion << " de la memoria.\n";
}

// Operaciones aritm�ticas

// Suma una palabra de una ubicaci�n espec�fica de memoria a la palabra en el acumulador.
// deja el resultado en el acumulador.
void suma(int ubicacion, int * acumulador, int * const memoria)
{
    *acumulador += memoria[ubicacion];
    if (*acumulador >= CAPACIDAD_MAX)
    {
        throw std::invalid_argument("*** Desvoldamiento al sumar ***\n*** La ejecuci�n de Simpletron se termino en forma anormal ***");

    }
    else
    {
        std::cout << "Se sum� " << memoria[ubicacion] << " al acumulador\n";
    }
    
}

// resta una palabra de una ubicaci�n espec�fica de memoria a la palabra en el acumulador.
// deja el resultado en el acumulador.
void resta(int ubicacion, int * const acumulador, int * const memoria)
{
    *acumulador -= memoria[ubicacion];
    if (*acumulador <= -CAPACIDAD_MAX)
    {
        throw std::invalid_argument("*** Desvoldamiento al restar ***\n*** La ejecuci�n de Simpletron se termino en forma anormal ***");
        
    }
    else
    {
        std::cout << "Se rest� " << memoria[ubicacion] << " al acumulador\n";
    }
    
}

// Multiplica una palabra de una ubicaci�n espec�fica de memoria a la palabra en el acumulador.
// deja el resultado en el acumulador.
void multiplica(int ubicacion, int * const acumulador, int * const memoria)
{
    *acumulador *= memoria[ubicacion];
    if (*acumulador >= CAPACIDAD_MAX || *acumulador <= -CAPACIDAD_MAX)
    {
        throw std::invalid_argument("*** Desvoldamiento al multiplicar  ***\n*** La ejecuci�n de Simpletron se termino en forma anormal ***");
        
    }
    else
    {
        std::cout << "Se multiplic� " << memoria[ubicacion] << " al acumulador\n";
    }
}

// Divide una palabra de una ubicaci�n espec�fica de memoria a la palabra en el acumulador.
// deja el resultado en el acumulador.
void divide(int ubicacion, int * const acumulador, int * const memoria)
{
    
    if (memoria[ubicacion] == 0)
    {
        throw std::invalid_argument("*** Intento de dividir entre cero. ***\n*** La ejecuci�n de Simpletron se termino en forma anormal ***");
        
    }
    else
    {
        *acumulador += memoria[ubicacion];
        std::cout << "Se dividi� " << memoria[ubicacion] << " al acumulador\n";
    }
    
}

// Operaciones de transferencia de control

// Bifurca hacia una ubicaci�n espec�fica de memoria
void bifurca(int operando, int * const contador)
{
    *contador = operando;
    std::cout << "Se bifurc� a la posici�n " << operando << " de la memoria.\n";
}

// Operaciones de transferencia de control

// Bifurca hacia una ubicaci�n espec�fica de memoria si el acumulador es cero
void bifurcaCero(int operando, int * const contador, int acumulador)
{
    if (acumulador == 0)
    {
        *contador = operando;
        std::cout << "Se bifurc� a la posici�n " << operando << " de la memoria.\n";
    }
    else
    {
        std::cout << "No se llev� a cabo la operaci�n.\n";
    }
    
}

// Bifurca hacia una ubicaci�n espec�fica de memoria si el acumulador es menor a 0
void bifurcaNeg(int operando, int * const contador, int acumulador)
{
    if (acumulador < 0)
    {
        *contador = operando;
        std::cout << "Se bifurc� a la posici�n " << operando << " de la memoria.\n";
    }
    else
    {
        std::cout << "No se llev� a cabo la operaci�n.\n";
    }
    
}

// El programa completo su tarea
void alto(int acumulador, int contadorInstrucciones, int registroInstruccion, int codigoOperacion, int operando, const int * memoria)
{
    std::cout << std::endl;
    std::cout << "*** Termin� la ejecuci�n de Simpletron. ***" << std::endl;
    std::cout << std::endl;
    std::cout << "REGISTROS:" << std::endl;
    std::cout << "acumulador" << std::setw(TAB - std::string("acumulador").length()) << ' ' << std::setw(DIGITOS) << std::showpos << std::setfill('0') << std::internal << acumulador << std::noshowpos;
    std::cout << std::setfill('\0');
    std::cout << "\ncontadorInstrucciones" << std::setw(TAB - std::string("contadorInstrucciones").length() + 3) << ' ' << std::setw(2) << std::setfill('0') << contadorInstrucciones ;
    std::cout << std::setfill('\0');
    std::cout << "\nregistroDeInstruccion" << std::setw(TAB - std::string("registroDeInstruccion").length()) << ' ' << std::setw(DIGITOS) << std::showpos << std::setfill('0') << std::internal << registroInstruccion << std::noshowpos;
    std::cout << std::setfill('\0');
    std::cout << "\ncodigoDeOperacion" << std::setw(TAB - std::string("codigoDeOperacion").length() + 3) << ' ' << std::setw(2) << std::setfill('0') <<  codigoOperacion;
    std::cout << std::setfill('\0');
    std::cout << "\noperando" << std::setw(TAB - std::string("operando").length() + 3) << ' ' << std::setw(2) << std::setfill('0') << operando << std::endl;
    std::cout << std::setfill('\0');
    std::cout << std::endl;
    std::cout << "MEMORIA" << std::endl;
    std::cout << std::setw(2) << "   ";
    for (size_t i = 0; i < 10; i++)
    {
        std::cout << std::showpos << std::setw(DIGITOS) << i << ' ' << std::noshowpos;
    }
    std::cout << std::endl;
    
    for (size_t i = 0; i < 10; i++)
    {
        std::cout << std::setw(2) << i << ' ';
        for (size_t j = 0; j < 10; j++)
        {
            std::cout << std::showpos << std::setw(DIGITOS) << std::setfill('0') << std::internal << memoria[i*10 + j]  << ' ';
        }
        std::cout << std::setfill('\0') << std::endl;
    }
    std::cout << std::endl;

}

void obtenerCodigoyOperando(int *codigo, int * operando, int registro)
{
    *codigo = registro / 100;
    *operando = registro % 100;
}

void realizarInstruccion(int codigo, int operando, int * memoria, int * acumulador, int * contador, int registro)
{
    switch ((Operaciones)codigo)
    {
    case Operaciones::LEE :
        lee(operando, memoria);
        break;
    case Operaciones::ESCRIBE:
        escribe(operando, memoria);
        break;
    case Operaciones::CARGA:
        carga(operando, memoria, acumulador);
        break;
    case Operaciones::ALMACENTA:
        almacena(operando, *acumulador, memoria);
        break;
    case Operaciones::SUMA:
        suma(operando, acumulador, memoria);
        break;
    case Operaciones::RESTA:
        resta(operando, acumulador, memoria);
        break;
    case Operaciones::DIVIDE:
        divide(operando, acumulador, memoria);
        break;
    case Operaciones::MULTIPLICA:
        multiplica(operando, acumulador, memoria);
        break;
    case Operaciones::BIFURCA:
        bifurca(operando, contador);
        break;
    case Operaciones::BIFURCANEG:
        bifurcaNeg(operando, contador, *acumulador);
        break;
    case Operaciones::BIFURCACERO:
        bifurcaCero(operando, contador, *acumulador);
        break;
    case Operaciones::ALTO:
        alto(*acumulador, *contador, registro, codigo, operando, memoria);
        break;
    default:
        break;
    }
}