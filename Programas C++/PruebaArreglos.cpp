//Headers 
#include <iostream>
#include <iomanip>
#include <locale.h>
#include <array>
#include <vector>
#include <cstddef>

using namespace std;

//Definicion de constantes
#define TAM_ARRAY 11 //Rango de los arreglos utilizados en el programa

/* Declaraciones de variables globales */
array <int, TAM_ARRAY> a;/* declaracion de arreglo utilizando la plantilla del archivo <array> */
array <int, TAM_ARRAY> b = {5, 4, 9, 7, 14, 22, 1, 24, 32, 74, 10};
vector <int> v1 = {1, 2, 3, 4};
vector <int> v2 = {5, 6, 7, 8, 9, 10};
//Prototipos de funciones
void establecerArray(array<int,TAM_ARRAY> &a); //Funcion que solicita al usuario los datos del arreglo y los almacena en el
void mostrarArray(array<int,TAM_ARRAY> a); //Función que muestra los elementos del array suministrado como parametro
void mostrarVector(vector<int> v);//Muestra el vector suministrado en pantalla
void comparaVectores(vector<int> v1, vector<int> v2);//Compara si dos vectores son iguales o no. Muestra el resultado de la comparación en pantalla

//Funcion Main
int main()
{
    setlocale(LC_ALL,"");
    // Prueba arrays
    a[2] = 150;
    b[2] = 250;
    //a[11] = 352
    establecerArray(a);
    mostrarArray(a);
    mostrarArray(b);
    a = b;
    if (a == b)
    {
        cout << "a y b son iguales." << endl;
    }
    else 
        cout << "a y b son distintos." << endl;
    mostrarArray(a);

    //Prueba vectores
    mostrarVector(v1);
    mostrarVector(v2);
    comparaVectores(v1, v2);
    v1[0] = 2;
    v2 = v1;
    comparaVectores(v1,v2);
    mostrarVector(v2);
    v2.pop_back();
    mostrarVector(v2);
    return 0;
} //Fin funcion main

//Función que muestra los elementos del array suministrado como parametro
void mostrarArray(array<int,TAM_ARRAY> a)
{
    for (auto &elemento : a)
    {
        cout << elemento <<" ";
    }
    cout << endl;
}//Fin funcion mostrarArray

//Funcion que solicita al usuario los datos del arreglo y los almacena en el
void establecerArray(array<int,TAM_ARRAY> &a)
{
    cout << "Por favor ingrese los " << a.size() << " elementos del array: ";
    for (auto &elemento : a)
    {
        cin >> elemento;
    }
}//Fin funcion establecerArray

void mostrarVector(vector<int> v)
{
    for (auto &i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}//Fin funcion mostrarVector

void comparaVectores(vector<int> v1, vector<int> v2)
{
    if (v1 == v2)
    {
        cout << "Ambos vectores son iguales." << endl;
    }
    else
    {
        
        cout << "Los vectores son distintos." << endl;
    }
    
}