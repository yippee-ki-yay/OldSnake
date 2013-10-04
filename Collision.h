
#ifndef _COLLISION_H
#define _COLLISION_H

#include<SFML/Graphics.hpp>
#include<cmath>

#include"Image.h"

namespace np
{


class Collision
 {
   private:

   //int DistanceBetwen2Points(int x1, int y1,int x2, int y2);

   float leftA,rightA,topA,bottomA;

   float leftB,rightB,topB,bottomB;

  public:

  bool BoundingBoxColl(sf::Sprite &object1, sf::Sprite &object2);

  //bool CircuralColl(sf::Sprite &object1, sf::Sprite &object2);

  bool PixelColl(sf::Sprite &object1, sf::Sprite &object2);

  bool SetRect(sf::Sprite &object);

  bool Collided(np::Image object1, np::Image object2);

 };

}

#endif
