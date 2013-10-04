#include"TextInput.h"

TextInput::TextInput(){}

TextInput::TextInput(float x, float y):max_char(15),typing_finished(false)
{
    //load the font
  //  font.LoadFromFile("kberry.ttf");

   // str.SetFont(font);

    str.SetX(x);
    str.SetY(y);
}

//has a little bug removing the deleted characters
void TextInput::draw()
{
if(stdString != stdTemp && typing_finished == false)
    {
         Singleton::getInstance()->app->Draw(str);

    }
    else
    {
      Singleton::getInstance()->app->Draw(str);
    }


}

void TextInput::setPosition(float x, float y)
{
	str.SetX(x);
	str.SetY(y);
}

void TextInput::getText()
{


if(Singleton::getInstance()->event->Type == sf::Event::TextEntered)
{
    if(typing_finished == false)
    {
    stdString += static_cast<char>(Singleton::getInstance()->event->Text.Unicode);
    str.SetText(stdString);
    stdTemp = stdString;
    }

}


if(Singleton::getInstance()->app->GetInput().IsKeyDown(sf::Key::F1)&& (stdString.length() != 0))
{
  stdString.erase(stdString.length()-1);
}

//if enterd pressed == typing finished
if(Singleton::getInstance()->app->GetInput().IsKeyDown(sf::Key::Return))
{
stdSave = stdString;
typing_finished = true;
}
}

void TextInput::save()
{
   //save to hard disk :)
}

std::string TextInput::getInputValue()
{
    return stdSave;
}

bool TextInput::IsFinished()
{
return typing_finished;
}

TextInput::~TextInput()
{
//WE HAVE NOTHING TO DELETE
//drugi oktobar osto bez posla
}
