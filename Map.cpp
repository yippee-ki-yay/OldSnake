#include"Map.h"


Map::Map()
{
    for(int i = 0; i < 30*40;++i)
     {
         Block b;
         map.push_back(b);
     }


    for(int i = 0; i < 30;++i)
     {
         for(int j = 0; j < 40;++j)
          {
              map[j].posX = j * 20;
              map[i].posY = i * 20;
          }
     }
}

Map::~Map()
{}

void Map::getPos(const Block &b, int &x, int &y)
{
  x = b.posX / 20;
  y = b.posY / 20;
}

void Map::setPos(Block &b, int x, int y)
{
	b.posX = x *20;
	b.posY = y *20;
}


