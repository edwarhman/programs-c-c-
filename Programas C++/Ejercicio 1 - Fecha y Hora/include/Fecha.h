#if !defined(FECHA_H)
#define FECHA_H

class Fecha
{
private:
    int dia;
    int mes;
    int anio;
public:
    Fecha();
    Fecha(int, int, int);
    ~Fecha();
    // Funciones establecer
   
    void establecerFecha(int d, int m, int a);
    void establecerFecha();
    void establecerDia(int entrada);
    void establecerMes(int entrada);
    void establecerAnio(int entrada);
    // Funciones obtener

    int obtenerDia() const;
    int obtenerMes() const;
    int obtenerAnio() const;

    // Funciones imprimir
    void imprimir() const;

    // Otras funciones
    bool esBisiesto() const;
    void siguienteDia();
    private: bool evaluarDia(int d) const;
    private: bool evaluarFebrero(int d) const;
};

#endif // FECHA_H
