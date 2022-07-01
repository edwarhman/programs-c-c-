#if !defined(CAI_H)
#define CAI_H

enum class Operacion {TODAS, SUMA, RESTA, MULTIPLICACION, DIVISION};
enum class Dificultad {FACIL = 1, NORMAL, DIFICIL};
class cai
{
private:
    unsigned valor1;
    unsigned valor2;
    unsigned respuesta;
    unsigned resultado;
    unsigned aciertos;
    unsigned fallos;
    Operacion operacion;
    Operacion operacionAleartoria;
    bool acierto;
    Dificultad dificultad;
    

public:
    cai(Operacion opera);
    cai();
    ~cai();
    void generarPregunta(); //
    void mostrarMensaje() const;
    void mostrarPregunta() const; //
    void establecerOperacionAleartoria(); //
    Operacion obtenerOperacionAleartoria() const; //
    void establecerRespuesta(); //
    unsigned obtenerRespuesta() const; //
    void establecerValores(unsigned valor1, unsigned valor2); //
    unsigned obtenerValor1() const; //
    unsigned obtenerValor2() const; // 
    void establecerResultado(); //
    unsigned obtenerResultado() const; //
    Operacion obtenerOperacion() const; //
    void intercambiarValores();
    void elegirOperacion(); //
    void establecerOperacion(); // 
    void mostrarOperacion() const; //
    void evaluarRespuesta(); //
    bool obtenerAcierto() const; //
    bool esDivisible() const; //
    void incrementarAciertos(); //
    unsigned obtenerAciertos() const; //
    void incrementarFallos(); //
    unsigned obtenerFallos() const; //
    void mostrarResultados() const; //
    void elegirDificultad();
    void establecerDificultad();
    void mostrarDificultad() const;
    Dificultad obtenerDificultad() const;
    void generarSuma();
    void generarResta();
    void generarMultiplicacion();
    void generarDivision();

};




#endif // CAI_H
