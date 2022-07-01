#include "Votaciones.h"
#include <string>
#include <array>
#include <iostream>
#include <iomanip>
#define ANCHURA 80
using namespace std;

void imprimirFila(char car);
Votaciones::Votaciones(const array<string, QUESTIONS + 1> newTopics)
:total(0)
{
    setQuestions(newTopics);
}

Votaciones::~Votaciones()
{
}

void Votaciones::setQuestions(const array<string, QUESTIONS + 1> newTopics)
{
    for (size_t i = 1; i <= QUESTIONS; i++)
    {
        question[i].setTopic(newTopics[i]);
    }
}

void Votaciones::askQuestions() 
{
    unsigned entrada;
    cin >> entrada;
    setTotal(entrada);
    for (size_t i = 0; i < total; i++)
    {
        cout << "Para cada uno de los siguientes enunciados, por favor"
                " indique, usando números del 1 al 10, que tan de acuerdo está."
                "\nPor ejemplo: 10 para decir que está totalmente de acuerdo y"
                " 0 para decir que está totalmente en desacuerdo."
                << endl;
        for (size_t j = 1; j <= QUESTIONS; j++)
        {
            cout << question[j].getTopic() << endl;
            cin >> entrada;
            question[j].setAnswer(entrada);
        }
    }
    setMedias();
    setMayor();
    setMinor();
}

void Votaciones::showElections() const
{
    showTable();
    cout << endl;
    showMayor();
    showMinor();
    cout << endl;
}

void Votaciones::setTotal(unsigned newTotal) 
{
    if (newTotal > 0)
    {
        total = newTotal;
    }
}

unsigned Votaciones::getTotal() const
{
    return total;
}

void Votaciones::setMedias()
{
    for (size_t i = 1; i <= QUESTIONS; i++)
    {
        question[i].setMedia(total);
    }
}

void Votaciones::setMayor()
{
    for (size_t i = 1; i <= QUESTIONS; i++)
    {
        if (question[i].getMedia() > mayor.getMedia() || i == 1)
        {   
            mayor = question[i];
        }
    }
}

void Votaciones::setMinor()
{
    for (size_t i = 1; i <= QUESTIONS; i++)
    {
        if (question[i].getMedia() < minor.getMedia() || i == 1)
        {
            minor = question[i];
        }
    }
}

void Votaciones::showMayor() const
{
    cout << "El asunto que obtuvo la mayor puntuación fue " << mayor.getTopic()
         << " con " << mayor.getMedia() << " puntos." << endl;
}

void Votaciones::showMinor() const
{
    cout << "El asunto que obtuvo la menor puntuación fue " << minor.getTopic()
         << " con " << minor.getMedia() << " puntos." << endl;
}

void Votaciones::showTable() const
{
    imprimirFila('=');
    cout << "Temas";
    cout  << setw(ANCHURA - string("Temas").length());
    for (size_t i = 1; i <= ANSWERS; i++)
    {
        cout << i << setw(4);
    }
    cout << setw(7) << "media" << endl;
    imprimirFila('-');
    for (size_t j = 1; j <= QUESTIONS; j++)
    {
        cout << question[j].getTopic();
        cout << setw(ANCHURA - question[j].getTopic().length());
        for (size_t i = 1; i <= ANSWERS; i++)
        {
            cout << question[j].getAnswer(i) << setw(4);
        }
        cout << setw(7) << question[j].getMedia() << endl;
    }
    imprimirFila('=');
}

void imprimirFila(char car)
{
    for (size_t i = 1; i <= ((ANSWERS - 1) * 4 + 7) + ANCHURA ; i++)
    {
        cout << car;
    }
    cout << endl;
}