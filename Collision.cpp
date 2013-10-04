
#include"Collision.h"



bool np::Collision::BoundingBoxColl(sf::Sprite &object1, sf::Sprite &object2)
{

  leftA = object1.GetPosition().x;
  rightA = object1.GetPosition().x + object1.GetSubRect().GetWidth();
  topA = object1.GetPosition().y;
  bottomA = object1.GetPosition().y + object1.GetSubRect().GetHeight();


  leftB = object2.GetPosition().x;
  rightB = object2.GetPosition().x + object2.GetSubRect().GetWidth();
  topB = object2.GetPosition().y;
  bottomB = object2.GetPosition().y + object2.GetSubRect().GetHeight();

  if(bottomA <= topB)
  return false;

  if(topA >= bottomB)
  return false;

  if(leftA >= rightB)
  return false;

  if(rightA <= leftB)
  return false;

  return true;

}

/*
bool np::Collision::CircuralColl(sf::Sprite &object1, sf::Sprite &object2)
{
    int radious1,radious2;
    int x1,y1,x2,y2;

    //Get the current position of the sprite
    x1 = object1.GetPosition().x;
    x2 = object2.GetPosition().x;
    y1 = object1.GetPosition().y;
    y2 = object2.GetPosition().y;

   //determine the radious of the first object

   if(object1.GetSubRect().GetHeight() > object1.GetSubRect().GetWidth())
   {
       radious1 = object1.GetSubRect().GetHeight();
   }
   else
   radious1 = object1.GetSubRect().GetWidth();

   //determine the radious of the second object

    if(object2.GetSubRect().GetHeight() > object2.GetSubRect().GetWidth())
   {
       radious2 = object2.GetSubRect().GetHeight();
   }
   else
   radious2 = object2.GetSubRect().GetWidth();


    //if the distance forom the two circles is less then the radious
   if(DistanceBetwen2Points(x1,y1,x2,y2)< (radious1 + radious2))
   return true;


return false;
}*/

bool np::Collision::PixelColl(sf::Sprite &object1, sf::Sprite &object2)
{
	return true;
    //will do later :)
}

bool np::Collision::Collided(np::Image object1, np::Image object2)
{
    leftA = object1.getSprite()->GetPosition().x;
  rightA = object1.getSprite()->GetPosition().x + object1.getSprite()->GetSubRect().GetWidth();
  topA = object1.getSprite()->GetPosition().y;
  bottomA = object1.getSprite()->GetPosition().y + object1.getSprite()->GetSubRect().GetHeight();


  leftB = object2.getSprite()->GetPosition().x;
  rightB = object2.getSprite()->GetPosition().x + object2.getSprite()->GetSubRect().GetWidth();
  topB = object2.getSprite()->GetPosition().y;
  bottomB = object2.getSprite()->GetPosition().y + object2.getSprite()->GetSubRect().GetHeight();

  if(bottomA <= topB)
  return false;

  if(topA >= bottomB)
  return false;

  if(leftA >= rightB)
  return false;

  if(rightA <= leftB)
  return false;

  return true;
}

//Private function distance between two points
/*
int np::Collision::DistanceBetwen2Points(int x1, int y1, int x2, int y2)
{
    return sqrt(std::pow(x2-x1,2)+std::pow(y2-y1,2));std::pow
}
*/