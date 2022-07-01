#if !defined(ADIVINAELNUMERO_H)
#define ADIVINAELNUMERO_H
#define MAXIMO 1000
#define MINIMO 1
#define INTENTOS_OP 10

class AdivinaElNumero
{
private:
    //Variables

    unsigned int numeroAleartorio;//Numero aleartorio generado por el programa
    unsigned int entradaUsuario;//Entrada ingresada por el usuario
    unsigned int intentos;
    //Funciones privadas

    void MensajeAlGanar() const;
    bool EvaluarEntrada(unsigned int) const;
public:
    //Funciones públicas

    bool CompararNumeros();
    AdivinaElNumero(/* args */);
    ~AdivinaElNumero();
    void LeerEntrada();
    void MostrarMensaje(unsigned int) const;
    void GenerarAleartorio();
};






#endif // ADIVINAELNUMERO_H
