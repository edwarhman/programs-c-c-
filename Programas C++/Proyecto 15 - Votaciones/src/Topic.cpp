#include "Topic.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

Topic::Topic(/* args */)
:topic(""), media(0)
{
    for (auto &i : answer)
    {
        i = 0;
    }
}

Topic::~Topic()
{
}

void Topic::setTopic(string cadena)
{
    topic = cadena;
}

string Topic::getTopic() const
{
    return topic;
}

void Topic::setAnswer(unsigned in)
{
    if (in <= ANSWERS)
    {
        answer[in]++;
    }
}

unsigned Topic::getAnswer(unsigned indice) const
{
    return answer[indice];
}

void Topic::setMedia(unsigned total) 
{
    int suma = 0;
    for (size_t i = 1; i <= ANSWERS; i++)
    {
        suma += (i * answer[i]);
    }
    media = (double)suma / (double)total;
}

double Topic::getMedia() const
{
    return media;
}