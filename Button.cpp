
#include"Button.h"

np::Button::Button(){};  //default constructor

np::Button::Button(int x, int y,std::string imgfile):ButtonImageOn(true)
{
ImgButtonOn.LoadFromFile(imgfile);
//ImgButtonOf.LoadFromFile("sbutton2.png");


SprButton.SetImage(ImgButtonOn);
SprButton.SetX(static_cast<float>(x));   //yup,type conversion
SprButton.SetY(static_cast<float>(y));
}

bool np::Button::IsClicked()
{
    if( Singleton::getInstance()->app->GetInput().IsMouseButtonDown(sf::Mouse::Left)
&& MouseOnButton()==true )
    {
       SprButton.SetImage(ImgButtonOf);
       return true;
    }
    else if(Singleton::getInstance()->app->GetInput().IsMouseButtonDown(sf::Mouse::Left)== false)
    {
        SprButton.SetImage(ImgButtonOn);
        return false;
    }

return false;
}


//private function determites if the mouse is in the button RECT

bool np::Button::MouseOnButton()
{
Mx = Singleton::getInstance()->app->GetInput().GetMouseX();
My = Singleton::getInstance()->app->GetInput().GetMouseY();

float leftA,rightA,topA,bottomA;

leftA = SprButton.GetPosition().x;
  rightA = SprButton.GetPosition().x + SprButton.GetSubRect().GetWidth();
  topA = SprButton.GetPosition().y;
  bottomA = SprButton.GetPosition().y + SprButton.GetSubRect().GetHeight();

  if(Mx > leftA && Mx < rightA && My > topA && My < bottomA)
  return true;


  return false;
}

void np::Button::Draw()
{
    if(ButtonImageOn == true)
    {
        Singleton::getInstance()->app->Draw(SprButton);
    }
    Singleton::getInstance()->app->Draw(StrText);
}

void np::Button::Text()
{
StrText.SetText("Button");
StrText.SetX( SprButton.GetCenter().x);
StrText.SetY(SprButton.GetCenter().y);


}

void np::Button::Sound()
{

}


bool np::Button::ButtonImage(bool state)
{
   ButtonImageOn = state;
   if(state == true)
   return true;
   else
   return false;
}
