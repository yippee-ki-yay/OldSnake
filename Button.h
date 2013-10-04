
#ifndef _BUTTON_H
#define _BUTTON_H

#include<SFML/Graphics.hpp>

#include"Singelton.h"

//hook up to the resoursce manager

namespace np
{

 class Button
{
private:
bool MouseOnButton();
unsigned int Mx,My;  //use to store current mouse position
bool ButtonImageOn;

public:
enum state{ON,OFF};

sf::Image  ImgButtonOn;
sf::Image  ImgButtonOf;
sf::Sprite SprButton;
sf::Font   TextFont;
sf::String StrText;


Button();   //default constructor
Button(int x,int y,std::string imgfile);

void Draw();
bool IsClicked();
void Text();
void Sound();
bool ButtonImage(bool state);

};

}
#endif
