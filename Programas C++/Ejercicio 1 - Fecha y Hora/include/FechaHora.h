#if !defined(FECHA_HORA_H)
#define FECHA_HORA_H
#include "Fecha.h"
#include "Tiempo.h"

class FechaHora : public Fecha, public Tiempo
{
private:

public:
    FechaHora(int h, int m, int s, int dd, int mm, int aa);
    ~FechaHora();

    void imprimir() const;
    void tictac();
};

#endif // FECHA_HORA_H