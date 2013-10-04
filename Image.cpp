#include"Image.h"

np::Image::Image()
{

}


np::Image::~Image()
{
    //delete spr;
}

void np::Image::Load(std::string s)
{
   np::ResourceManager::getInstance()->addImage(s);

    spr.SetImage(np::ResourceManager::getInstance()->getImage(s));
}

np::Image::Image(std::string name)
{
    np::ResourceManager::getInstance()->addImage(name);


    spr.SetImage(np::ResourceManager::getInstance()->getImage(name));
}

void np::Image::Draw()
{
    Singleton::getInstance()->app->Draw(spr);
}

sf::Sprite* np::Image::getSprite()
{
    return &spr;
}
