#include <array>
#include <vector>
#include <iostream>
using namespace std;
void llenarArreglo(vector<unsigned> &a);
void mostrarArreglo(vector<unsigned> &v);
int main(int argc, char const *argv[])
{
    vector<unsigned> miArreglo;
    llenarArreglo(miArreglo);
    mostrarArreglo(miArreglo);

    miArreglo.clear();
    mostrarArreglo(miArreglo);
    miArreglo.push_back(22);
    mostrarArreglo(miArreglo);
    return 0;
}

void llenarArreglo(vector<unsigned> &a)
{
    for (size_t i = 0; i < 10; i++)
    {
        a.push_back(i+1);
    }
}

void mostrarArreglo(vector<unsigned> &v)
{
    for (unsigned &i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}