#include"Fade.h"


np::Fade::Fade(fadetype f)
{
bg = new np::Image("fade.png");
bg->getSprite()->SetColor(sf::Color(255,255,255,0));
if(f == FADEIN)
alpha = 0;
else if (f == FADEOUT)
alpha = 255;
}

np::Fade::~Fade()
{
    delete bg;
}


void np::Fade::FadeIn(float time)
{
 time = time/10;
if(alpha < 255)
{
  bg->getSprite()->SetColor(sf::Color(255,255,255,static_cast<int>(alpha)));
alpha += time;
}
}


void np::Fade::FadeOut(float time = 1)
{
 time = time / 10;
if(alpha >0)
{
  bg->getSprite()->SetColor(sf::Color(255,255,255,static_cast<int>(alpha)));
  alpha -= time;
}

}

void np::Fade::Draw()
{
    bg->Draw();
}
