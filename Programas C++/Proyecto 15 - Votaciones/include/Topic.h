#if !defined(TOPIC_H)
#define TOPIC_H
#include <string>
#include <array>
#define ANSWERS 10

class Topic
{
private:
    std::string topic;
    std::array<int, ANSWERS + 1> answer;
    double media;
public:
    Topic(/* args */);
    ~Topic();
    void setTopic( std::string cadena);
    std::string getTopic() const;
    void setAnswer(unsigned in);
    unsigned getAnswer(unsigned indice) const;
    void setMedia(unsigned total);
    double getMedia() const;
};

#endif // TOPIC_H
