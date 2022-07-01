#if !defined(VOTACIONES_H)
#define VOTACIONES_H
#include "Topic.h"
#include <array>
#define QUESTIONS 5

class Votaciones
{
private:
    // Miembros

    std::array<Topic, QUESTIONS +1> question;
    unsigned total;
    Topic mayor;
    Topic minor; 

    //Funciones miembro

    void setMedias();
    void setMayor();
    void setMinor();
    void showMayor() const;
    void showMinor() const;
    void showTable() const;
public:
    // Funciones miembro 

    Votaciones(const std::array<std::string, QUESTIONS + 1> newTopics);
    ~Votaciones();
    void setQuestions(const std::array<std::string, QUESTIONS + 1> newTopics);
    void askQuestions();
    void showElections() const;
    void setTotal(unsigned newTotal);
    unsigned getTotal() const;
    
};

#endif // VOTACIONES_H
