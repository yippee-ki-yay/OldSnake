#include"Fruit.h"

Fruit::Fruit(): alive(true),posX(0),posY(0)
{
	fruty.Load("fruit.png");

    srand(time(0));

	 posX = (rand()%39) * 20;
		posY = (rand()%28) * 20;

		fruty.getSprite()->SetX(posX);
		fruty.getSprite()->SetY(posY);
    
}

Fruit::~Fruit()
{
}

void Fruit::Draw()
{
 if(alive == true)
 fruty.Draw();
}

void Fruit::Alive(bool state)
{
    alive = state;
}

np::Image Fruit::getImage()
{
    return fruty;
}

void Fruit::getPos(int &x, int &y)
{
	x = posX / 20;
	y = posY / 20;
}


void Fruit::getFruit()
{ 
	if(alive == false)
	{
        posX = (rand()%40) * 20;
		posY = (rand()%30) * 20;

		fruty.getSprite()->SetX(posX);
		fruty.getSprite()->SetY(posY);

        alive = true;
	}
}
