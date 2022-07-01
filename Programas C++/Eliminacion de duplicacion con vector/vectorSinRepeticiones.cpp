#include <vector>
#include <iostream>
using namespace std;
bool evaluarEnVector(vector<int> v,const int test);
void agregarElemento(vector<int> &v);
void mostrarVector(vector<int> v);
int main()
{
    vector<int> v1;
    cout << v1.size() << endl;
    agregarElemento(v1);
    mostrarVector(v1);
    return 0;
}

void agregarElemento(vector<int> &v)
{
    int entrada = 0;
    do
    {
        cout << "Ingrese el valor que desea añadir al vector"
             << endl << " (si desea salir escriba -1): ";
        cin >> entrada;
        if (entrada>=0 && !evaluarEnVector(v, entrada))
        {
            v.push_back(entrada);
        }
        
    } while (entrada >= 0);
    
}

bool evaluarEnVector(vector<int> v,const int test)
{
    bool seRepite = false;
    if (v.size() > 0)
        for (auto &i : v)
        {
            if (test == i)
                seRepite = true;
        }
    return seRepite;
}

void mostrarVector(vector<int> v)
{
    cout << "Elementos del vector: ";
    for (auto &i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}