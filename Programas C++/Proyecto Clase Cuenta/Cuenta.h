//Definición de la clase cuenta
class Cuenta
{
private:
    int saldoCuenta; //Estado de cuenta

public:
    explicit Cuenta(int saldo); //Constructor de la clase
    void establecerSaldo(int saldo); // Cambia el estado de cuenta
    int obtenerSaldo() const; //Accede al estado de cuenta
    void abonar(int monto); //Aumenta el saldo de la cuenta
    void retirar(int monto); //Retira los fondos de la cuenta
    void mostrarSaldo() const; //Muestra en pantalla el estado de cuenta
};