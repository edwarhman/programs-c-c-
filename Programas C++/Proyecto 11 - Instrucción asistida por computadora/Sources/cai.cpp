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

// Funci�n que genera la pregunta seg�n el tipo de operaci�n elegido
void cai::generarPregunta()
{
    
    if (obtenerOperacion() == Operacion::TODAS)
    {
        establecerOperacionAleartoria();
    }
    establecerResultado();
    mostrarPregunta();
} //Fin de la funci�n generarPregunta

//Funci�n que muestra un mensaje que indica si la respuesta del usuario es correcta o no
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
            cout << "Sigue as�." << endl;
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
            cout << "No. intenta una vez m�s: ";
            break;
        case 3:
            cout << "Incorrecto. �No te rindas!: ";
            break;
        case 4:
            cout << "No. �Sigue intentando!: ";
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
        cout << "�C�anto es " << obtenerValor1() << " + " << obtenerValor2() << "? ";
        break;
    case Operacion::RESTA:
        cout << "�C�anto es " << obtenerValor1() << " - " << obtenerValor2() << "? ";
        break;
    case Operacion::MULTIPLICACION:
        cout << "�C�anto es " << obtenerValor1() << " x " << obtenerValor2() << "? ";
        break;
    case Operacion::DIVISION:
        cout << "�C�anto es " << obtenerValor1() << " / " << obtenerValor2() << "? ";
        break;
    
    default:
        cerr << "Ha ocurrido un error al intentar mostrar la pregunta." << endl;
        break;
    }
}//Fin de la funci�n mostrarPregunta

//Funcion que establece que tipo de operaci�n se va a generar cuando la elecci�n del usuario fue TODAS.
void cai::establecerOperacionAleartoria()
{
    operacionAleartoria = (Operacion)::operacionAleartoria(motor);
} // Fin de funci�n establecerOperacionAleartoria


// Funci�n que obtiene la operaci�n aleartoria generada
Operacion cai::obtenerOperacionAleartoria() const
{
    return operacionAleartoria;
} //Fin de obtenerOperacionAleartoria

//Funci�n que establece la respuesta del usuario a partir de la entrada por el teclado
void cai::establecerRespuesta()
{
    unsigned entrada;
    cin >> entrada;
    respuesta = entrada;

}//Fin de funci�n establecerRespuesta

//Funci�n que obtiene la respuesta ingresada por el usuario
unsigned cai::obtenerRespuesta() const
{
    return respuesta;
} //Fin de funci�n obtenerRespuesta


//Funci�n que genera los dos numeros aleartorios que ser�n utilizados para la pregunta
void cai::establecerValores(unsigned val1, unsigned val2)
{
    valor1 = val1;
    valor2 = val2;
} //Fin funci�n establecerValores

//Funci�n que retorna el valor1
unsigned cai::obtenerValor1() const
{
    return valor1;
} //Fin de funci�n obtenerValor1

//Funci�n que retorna el valor2
unsigned cai::obtenerValor2() const
{
    return valor2;
} //Fin de funci�n obtenerValor2


//Funci�n que establece el resultado seg�n la operaci�n a realizar definida por el usuario.
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
        
} //Fin de la funci�n establecerResultado

//Funci�n que genera la suma dependiendo de la dificultad
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

//Funci�n que genera la resta dependiendo de la dificultad
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

//Funci�n que genera la multiplicaci�n dependiendo de la dificultad
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
        cerr << "Error para evaluar la Dificultad al generar la multiplicaci�n." << endl;
        break;
    }
        resultado = obtenerValor1() * obtenerValor2();
    
}// Fin de la funcion generarMultiplicacion

//Funci�n que genera la division dependiendo de la dificultad
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
        cerr << "Error para evaluar la Dificultad al generar la divisi�n." << endl;
        break;
    }
        resultado = obtenerValor1() / obtenerValor2();
    
}// Fin de la funcion generarDivision

//Funci�n que eval�a si el valor 1 es divisible entre el valor 2
bool cai::esDivisible() const
{
    if((obtenerValor1() % obtenerValor2() == 0) && (obtenerValor2() != 1))
        return true;
    else 
        return false;
}

// Funci�n que retorna el resultado de la operaci�n
unsigned cai::obtenerResultado() const
{
    return resultado;
} //Fin de la funci�n obtenerResultado

// Funci�n que retorna la operaci�n a realizar suministrada por el usuario
Operacion cai::obtenerOperacion() const
{
    return operacion;
} //Fin de funci�n obtenerOperaci�n

// Funci�n que intercambia los valores de la operaci�n entre si
void cai::intercambiarValores()
{
    unsigned aux = obtenerValor2();
    valor2 = obtenerValor1();
    valor1 = aux;
} //Fin de funci�n intercambiarValores


// Funci�n que muestra el men� de selecci�n de operaci�n
void cai::elegirOperacion() 
{
    cout << "----------------------------------------------------------------------------------" << endl;
    cout << "Eliga el tipo de operaci�n que desea practicar.\n"
            "1. Suma.\n"
            "2. Resta.\n"
            "3. Multiplicaci�n.\n"
            "4. Divisi�n.\n"
            "0. Todas.\n"
            "Por favor ingrese el n�mero correspondiente (Por ejemplo 3 para multiplicaci�n): ";
    establecerOperacion();
    cout << "----------------------------------------------------------------------------------" << endl;
    mostrarOperacion();
    cout << "----------------------------------------------------------------------------------" << endl;
}

//Funci�n que establece la operaci�n seg�n la entrada del usuario
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
} //Fin de funci�n establecerOperaci�n

//Funci�n que muestra en pantalla la operaci�n seleccionada
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
        cout << "multiplicaci�n." << endl;
        break;
    case Operacion::DIVISION:
        cout << "divisi�n." << endl;
        break;
    case Operacion::TODAS:
        cout << "todas las operaciones." << endl;
        break;
    
    default:
        break;
    }
} //fin de funci�n mostrarOperacion

//Funci�n que eval�a si la respuesta es correcta
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

// Funci�n que muestra en pantalla el desempe�o del estudiante para la prueba
void cai::mostrarResultados() const
{
    float total = (float)(obtenerAciertos() + obtenerFallos());
    if (( (float)obtenerAciertos() / total ) >= 0.75f )
    {
        cout << "�Felicidades, est�s listo para pasar al siguiente nivel!" << endl;
    }
    else
        cout << "Por favor pida ayuda adicional a su profesor." << endl;
}

// Funci�n que incrementa la cantidad de aciertos en 1
void cai::incrementarAciertos() 
{
    aciertos++;
}

// Funci�n que incrementa la cantidad de fallos en 1
void cai::incrementarFallos() 
{
    fallos++;
}

// Funci�n que retorna los aciertos del usuario
unsigned cai::obtenerAciertos() const
{
    return aciertos;
}

// Funci�n que retorna los fallos del usuario
unsigned cai::obtenerFallos() const
{
    return fallos;
}

// Funci�n que muestra el men� de selecci�n de dificultad
void cai::elegirDificultad() 
{
    cout << "----------------------------------------------------------------------------------" << endl;
    cout << "Eliga la dificultad.\n"
            "1. F�cil.\n"
            "2. Normal.\n"
            "3. Dificil.\n"
            "Ingrese el n�mero correspondiente (Por ejemplo 2 para dificultad normal): ";
    establecerDificultad();
    cout << "----------------------------------------------------------------------------------" << endl;
    mostrarDificultad();
    cout << "----------------------------------------------------------------------------------" << endl;
}

//Funci�n que establece la dificultad seg�n la entrada del usuario
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
        cout << "Respuesta inv�lida. Ingrese una opci�n v�lida." << endl;
        establecerDificultad();
    }
} //Fin de funci�n establecerDificultad

void cai::mostrarDificultad() const
{
    cout << "Ha elegido la dificultad ";
    switch (obtenerDificultad())
    {
    case Dificultad::FACIL:
        cout << "f�cil." << endl;
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