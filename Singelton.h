#ifndef SINGELTON_H
#define SINGELTON_H

#include<SFML/Graphics.hpp>

class Singleton {
    private:
         static Singleton mInstance;
    public:

    sf::RenderWindow *app;
    sf::Event        *event;

sf::Event change()
{
    return *event;
}

    ~Singleton();  //deconstructor to delete the pointers

      static   Singleton* getInstance()
         {
                   return &mInstance;
              }
 };

#endif
