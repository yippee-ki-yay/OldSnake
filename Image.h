#ifndef _IMAGE_H
#define _IMAGE_H

#include<string>

#include<SFML/Graphics.hpp>

#include"ResourceManager.h"

#include"Singelton.h"

namespace np
{
    class Image : public sf::Sprite
     {
         public:

         Image();
         ~Image();

         Image(std::string);

		 void Load(std::string s);

         sf::Sprite* getSprite();


         //image function

         void Draw();

        private:

         sf::Sprite spr;
     };
}

#endif
