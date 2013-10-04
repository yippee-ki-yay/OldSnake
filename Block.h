#ifndef _BLOCKS_H
#define _BLOCKS_H

#include"Image.h"

class Block
{
    public:

    Block();
    ~Block();

    void Draw();

   // void setPosition(int x, int y);

  //  void getPosition(int &x, int &y);

    np::Image spr;

	float posX,posY;

};

#endif
