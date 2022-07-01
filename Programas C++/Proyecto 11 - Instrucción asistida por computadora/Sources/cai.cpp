#include <iostream>
#include "cai.h"
#include <time.h>
#include <random>
using namespace std;

default_random_engine motor(static_cast<unsigned int>(time(0)));
uniform_int_distribution<unsigned int> L(1, 50);
uniform_int_distribution<unsigned int> X(1, 10);
uniform_int_distribution<unsigned int> C(1, 100);
uniform_int_distribution<unsigned int> operacionAleartoria(1, 4);

//Constructor de la clase
cai::cai(Operacion opera = Operacion::SUMA)
:operacion(opera), aciertos(0), fallos(0)
{
}//Fin del constructor

cai::cai()
:operacion(Operacion::SUMA), aciertos(0), fallos(0)
{
}//Fin del constructor


//Destructor de la clase
cai::~cai()
{
}//Fin del destructor

// Función que genera la pregunta según el tipo de operación elegido
void cai::generarPregunta()
{
    
    if (obtenerOperacion() == Operacion::TODAS)
    {
        establecerOperacionAleartoria();
    }
    establecerResultado();
    mostrarPregunta();
} //Fin de la función generarPregunta

//Función que muestra un mensaje que indica si la respuesta del usuario es correcta o no
void cai::mostrarMensaje() const
{
    unsigned contestacion = 0;
    contestacion = ::operacionAleartoria(motor);
    if(obtenerAcierto())
    {
        switch (contestacion)
        {
        case 1:
            cout << "Muy bien." << endl;
            break;
        case 2:
            cout << "Buen trabajo." << endl;
            break;
        case 3:
            cout << "Felicidades." << endl;
            break;
        case 4:
            cout << "Sigue así." << endl;
            break;
        
        default:
            break;
        }
        cout << "-----------------------------------------------------------------------------------" << endl;
    }
    else
    {

        switch (contestacion)
        {
        case 1:
            cout << "Incorrecto. intente de nuevo: ";
            break;
        case 2:
            cout << "No. intenta una vez más: ";
            break;
        case 3:
            cout << "Incorrecto. ¡No te rindas!: ";
            break;
        case 4:
            cout << "No. ¡Sigue intentando!: ";
            break;
        
        default:
            break;
        } //Fin switch
    } // Fin else
}

//Muestra la pregunta que debe responderse
void cai::mostrarPregunta() const
{
    Operacion op;
    if(obtenerOperacion() == Operacion::TODAS)
        op = obtenerOperacionAleartoria();
    else 
        op = obtenerOperacion();
    switch (op)
    {
    case Operacion::SUMA:
        cout << "¿Cúanto es " << obtenerValor1() << " + " << obtenerValor2() << "? ";
        break;
    case Operacion::RESTA:
        cout << "¿Cúanto es " << obtenerValor1() << " - " << obtenerValor2() << "? ";
        break;
    case Operacion::MULTIPLICACION:
        cout << "¿Cúanto es " << obtenerValor1() << " x " << obtenerValor2() << "? ";
        break;
    case Operacion::DIVISION:
        cout << "¿Cúanto es " << obtenerValor1() << " / " << obtenerValor2() << "? ";
        break;
    
    default:
        cerr << "Ha ocurrido un error al intentar mostrar la pregunta." << endl;
        break;
    }
}//Fin de la función mostrarPregunta

//Funcion que establece que tipo de operación se va a generar cuando la elección del usuario fue TODAS.
void cai::establecerOperacionAleartoria()
{
    operacionAleartoria = (Operacion)::operacionAleartoria(motor);
} // Fin de función establecerOperacionAleartoria


// Función que obtiene la operación aleartoria generada
Operacion cai::obtenerOperacionAleartoria() const
{
    return operacionAleartoria;
} //Fin de obtenerOperacionAleartoria

//Función que establece la respuesta del usuario a partir de la entrada por el teclado
void cai::establecerRespuesta()
{
    unsigned entrada;
    cin >> entrada;
    respuesta = entrada;

}//Fin de función establecerRespuesta

//Función que obtiene la respuesta ingresada por el usuario
unsigned cai::obtenerRespuesta() const
{
    return respuesta;
} //Fin de función obtenerRespuesta


//Función que genera los dos numeros aleartorios que serán utilizados para la pregunta
void cai::establecerValores(unsigned val1, unsigned val2)
{
    valor1 = val1;
    valor2 = val2;
} //Fin función establecerValores

//Función que retorna el valor1
unsigned cai::obtenerValor1() const
{
    return valor1;
} //Fin de función obtenerValor1

//Función que retorna el valor2
unsigned cai::obtenerValor2() const
{
    return valor2;
} //Fin de función obtenerValor2


//Función que establece el resultado según la operación a realizar definida por el usuario.
void cai::establecerResultado()
{
    Operacion op;
    if (obtenerOperacion() == Operacion::TODAS)
        op = obtenerOperacionAleartoria();
    else 
        op = obtenerOperacion();
    switch (op)
    {
    case Operacion::SUMA:
        generarSuma();
        break;
    case Operacion::RESTA:
        generarResta();
        break;
    case Operacion::MULTIPLICACION:
        generarMultiplicacion();
        break;
    case Operacion::DIVISION:
        generarDivision();
        break;
    
    default:
        cerr << "Ha ocurrido un error al intentar establecer el resultado para alguna de las posibles operaciones." << endl;
        break;
    }
        
} //Fin de la función establecerResultado

//Función que genera la suma dependiendo de la dificultad
void cai::generarSuma()
{
    switch (obtenerDificultad())
    {
    case Dificultad::NORMAL:
        establecerValores(L(motor), L(motor));
        break;
    case Dificultad::FACIL:
        establecerValores(X(motor), X(motor));
        break;
    case Dificultad::DIFICIL:
        establecerValores(C(motor),C(motor));
        break;
    default:
        cerr << "Error para evaluar la Dificultad al generar la suma." << endl;
        break;
    }
        resultado = obtenerValor1() + obtenerValor2();
    
}// Fin de la funcion generarSuma

//Función que genera la resta dependiendo de la dificultad
void cai::generarResta()
{
    switch (obtenerDificultad())
    {
    case Dificultad::NORMAL:
        if(obtenerValor2() > obtenerValor1() )
            intercambiarValores();
        establecerValores(L(motor), L(motor));
        break;
    case Dificultad::FACIL:
        establecerValores(X(motor), X(motor));
        if(obtenerValor2() > obtenerValor1() )
            intercambiarValores();
        break;
    case Dificultad::DIFICIL:
        establecerValores(C(motor),C(motor));
        break;
    default:
        cerr << "Error para evaluar la Dificultad al generar la resta." << endl;
        break;
    }
        resultado = obtenerValor1() - obtenerValor2();
    
}// Fin de la funcion generarResta

//Función que genera la multiplicación dependiendo de la dificultad
void cai::generarMultiplicacion()
{
    switch (obtenerDificultad())
    {
    case Dificultad::NORMAL:
        establecerValores(X(motor), L(motor));
        break;
    case Dificultad::FACIL:
        establecerValores(X(motor), X(motor));
        break;
    case Dificultad::DIFICIL:
        establecerValores(L(motor),L(motor));
        break;
    default:
        cerr << "Error para evaluar la Dificultad al generar la multiplicación." << endl;
        break;
    }
        resultado = obtenerValor1() * obtenerValor2();
    
}// Fin de la funcion generarMultiplicacion

//Función que genera la division dependiendo de la dificultad
void cai::generarDivision()
{
    switch (obtenerDificultad())
    {
    case Dificultad::NORMAL:
        do
        {
            establecerValores(C(motor), X(motor));
            if (obtenerValor2() > obtenerValor1())
                intercambiarValores();
        } while (!esDivisible());
        break;
    case Dificultad::FACIL:
        do
        {
            establecerValores(X(motor) + X(motor), X(motor));
            if (obtenerValor2() > obtenerValor1())
                intercambiarValores();
        } while (!esDivisible());
        break;
    case Dificultad::DIFICIL:
        do
        {
            establecerValores(C(motor) + C(motor), X(motor) + X(motor));
            if (obtenerValor2() > obtenerValor1())
                intercambiarValores();
        } while (!esDivisible());
        break;
    default:
        cerr << "Error para evaluar la Dificultad al generar la división." << endl;
        break;
    }
        resultado = obtenerValor1() / obtenerValor2();
    
}// Fin de la funcion generarDivision

//Función que evalúa si el valor 1 es divisible entre el valor 2
bool cai::esDivisible() const
{
    if((obtenerValor1() % obtenerValor2() == 0) && (obtenerValor2() != 1))
        return true;
    else 
        return false;
}

// Función que retorna el resultado de la operación
unsigned cai::obtenerResultado() const
{
    return resultado;
} //Fin de la función obtenerResultado

// Función que retorna la operación a realizar suministrada por el usuario
Operacion cai::obtenerOperacion() const
{
    return operacion;
} //Fin de función obtenerOperación

// Función que intercambia los valores de la operación entre si
void cai::intercambiarValores()
{
    unsigned aux = obtenerValor2();
    valor2 = obtenerValor1();
    valor1 = aux;
} //Fin de función intercambiarValores


// Función que muestra el menú de selección de operación
void cai::elegirOperacion() 
{
    cout << "----------------------------------------------------------------------------------" << endl;
    cout << "Eliga el tipo de operación que desea practicar.\n"
            "1. Suma.\n"
            "2. Resta.\n"
            "3. Multiplicación.\n"
            "4. División.\n"
            "0. Todas.\n"
            "Por favor ingrese el número correspondiente (Por ejemplo 3 para multiplicación): ";
    establecerOperacion();
    cout << "----------------------------------------------------------------------------------" << endl;
    mostrarOperacion();
    cout << "----------------------------------------------------------------------------------" << endl;
}

//Función que establece la operación según la entrada del usuario
void cai::establecerOperacion()
{
    unsigned entrada;
    cin >> entrada;
    if (entrada >= 0 && entrada <= 4)
    {
        operacion = (Operacion)entrada;
    }
    else
        establecerOperacion();
} //Fin de función establecerOperación

//Función que muestra en pantalla la operación seleccionada
void cai::mostrarOperacion() const
{
    cout << "Ha escogido ";
    switch (operacion)
    {
    case Operacion::SUMA:
        cout << "suma." << endl;
        break;
    case Operacion::RESTA:
        cout << "resta." << endl;
        break;
    case Operacion::MULTIPLICACION:
        cout << "multiplicación." << endl;
        break;
    case Operacion::DIVISION:
        cout << "división." << endl;
        break;
    case Operacion::TODAS:
        cout << "todas las operaciones." << endl;
        break;
    
    default:
        break;
    }
} //fin de función mostrarOperacion

//Función que evalúa si la respuesta es correcta
void cai::evaluarRespuesta()
{
    if(obtenerRespuesta() == obtenerResultado())
    {
        acierto = true;
        incrementarAciertos();
    }
    else 
    {
        incrementarFallos();
        acierto = false;
    }
}

//Funcion que retorna el valor de acierto
bool cai::obtenerAcierto() const
{
    return acierto;
}

// Función que muestra en pantalla el desempeño del estudiante para la prueba
void cai::mostrarResultados() const
{
    float total = (float)(obtenerAciertos() + obtenerFallos());
    if (( (float)obtenerAciertos() / total ) >= 0.75f )
    {
        cout << "¡Felicidades, estás listo para pasar al siguiente nivel!" << endl;
    }
    else
        cout << "Por favor pida ayuda adicional a su profesor." << endl;
}

// Función que incrementa la cantidad de aciertos en 1
void cai::incrementarAciertos() 
{
    aciertos++;
}

// Función que incrementa la cantidad de fallos en 1
void cai::incrementarFallos() 
{
    fallos++;
}

// Función que retorna los aciertos del usuario
unsigned cai::obtenerAciertos() const
{
    return aciertos;
}

// Función que retorna los fallos del usuario
unsigned cai::obtenerFallos() const
{
    return fallos;
}

// Función que muestra el menú de selección de dificultad
void cai::elegirDificultad() 
{
    cout << "----------------------------------------------------------------------------------" << endl;
    cout << "Eliga la dificultad.\n"
            "1. Fácil.\n"
            "2. Normal.\n"
            "3. Dificil.\n"
            "Ingrese el número correspondiente (Por ejemplo 2 para dificultad normal): ";
    establecerDificultad();
    cout << "----------------------------------------------------------------------------------" << endl;
    mostrarDificultad();
    cout << "----------------------------------------------------------------------------------" << endl;
}

//Función que establece la dificultad según la entrada del usuario
void cai::establecerDificultad()
{
    unsigned entrada;
    cin >> entrada;
    if (entrada >=1 && entrada <= 3)
    {
        dificultad = (Dificultad)entrada;
    }
    else
    {
        cout << "Respuesta inválida. Ingrese una opción válida." << endl;
        establecerDificultad();
    }
} //Fin de función establecerDificultad

void cai::mostrarDificultad() const
{
    cout << "Ha elegido la dificultad ";
    switch (obtenerDificultad())
    {
    case Dificultad::FACIL:
        cout << "fácil." << endl;
        break;
    case Dificultad::NORMAL:
        cout << "normal." << endl;
        break;
    case Dificultad::DIFICIL:
        cout << "dificil." << endl;
        break;
    
    default:
        break;
    }
}

Dificultad cai::obtenerDificultad() const
{
    return dificultad;
}