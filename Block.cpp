#include"Block.h"

Block::Block() : posX(10.0),posY(0.0)
{
  spr.Load("block.png");
}

Block::~Block()
{
 // delete spr;
}

void Block::Draw()
{
	spr.getSprite()->SetX(posX);
	spr.getSprite()->SetY(posY);

 spr.Draw();
}

//This doesn't work at all fix the fucking thing

/*
//get a position on the map and set a sprite to right pixel position
void Block::setPosition(int x, int y)
{
	//Map::getInstance()->map[x];

}

void Block::getPosition(int &x, int &y)
{
	//calculate the position on the map accordinlly to it's pixel position
	x = spr->getSprite()->GetPosition().x / 20;
	y = spr->getSprite()->GetPosition().y / 20;
}
*/