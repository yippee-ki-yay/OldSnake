#ifndef _FRUIT_H
#define _FRUIT_H

#include<cmath>
#include<ctime>

#include"Image.h"


class Fruit
{
  public:

  Fruit();
  ~Fruit();

  void Draw();

  void getFruit();

  void getPos(int &x,int &y);

  void Alive(bool state);

  np::Image getImage();

  private:

  np::Image fruty;

  bool alive;

  int posX,posY;
};

#endif
