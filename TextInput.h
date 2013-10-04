#ifndef TEXTINPUT_H
#define TEXTINPUT_H

#include<SFML/Graphics.hpp>
#include"Singelton.h"

class TextInput
{

public:

sf::String str;  //for drawing the letters
sf::String temp;


TextInput();
TextInput(float x, float y);
~TextInput();

void draw();

void getText();

void setPosition(float x, float y);

void save();

std::string getInputValue();

bool IsFinished();

private:

sf::Font font;
std::string stdString; //used for hold the current characters
std::string stdTemp;  //temp for checking for any changes
std::string stdSave;  //to save the input string


unsigned int max_char;
bool typing_finished;
};

#endif
