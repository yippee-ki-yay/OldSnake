#include"Snake.h"

Snake::Snake(Map &m) : dead(false), speed(10.0f)
{
  map = m;

  Snake::littleSnake();

  deltaTime = Singleton::getInstance()->app->GetFrameTime();

  right = true;
  up = false;
  down = false;
  left = false;

}

Snake::~Snake()
{

}

void Snake::Draw()
{
  for(unsigned int i = 0; i < snake_body.size();++i)
   {
       snake_body[i].Draw();
   }


}

void Snake::Move()
{
	
	int posX,posY;

	for(int i = snake_body.size()-1;i > 0;i--)
	{
		map.getPos(snake_body[i - 1],posX,posY);
		map.setPos(snake_body[i],posX,posY);
	}

	map.getPos(snake_body[0],posX,posY);

	if(down == true && (posY < 26))
	posY++;
	if(up == true && (posY > 1))
    posY--;
	if(left == true && (posX > 1))
	posX--;
	if(right == true && (posX < 39))
    posX++;

	map.setPos(snake_body[0],posX,posY);

	sf::Sleep(0.1f);
	
}

void Snake::getDirection()
{

  if((Singleton::getInstance()->event->Type == sf::Event::KeyPressed) && (Singleton::getInstance()->event->Key.Code == sf::Key::Right))
   {
	   if(left == false)
       right = true;

       down = false;
	   up = false;

   }
   else if((Singleton::getInstance()->event->Type == sf::Event::KeyPressed) && (Singleton::getInstance()->event->Key.Code == sf::Key::Left))
   {
	   if(right == false)
       left = true;

	   up = false;
	   down = false;
	   
       
   }

   else if((Singleton::getInstance()->event->Type == sf::Event::KeyPressed) && (Singleton::getInstance()->event->Key.Code == sf::Key::Up))
   {
	   if(down == false)
       up = true;

	   right = false;
	   left = false;
	
   }
   else if((Singleton::getInstance()->event->Type == sf::Event::KeyPressed) && (Singleton::getInstance()->event->Key.Code == sf::Key::Down))
   {
	   if(up == false)
       down = true;

       left = false;
       right = false;

   }
}

void Snake::Grow()
{
	Block b;
	snake_body.push_back(b);

	int tmpX,tmpY;

	map.getPos(snake_body[snake_body.size()-2],tmpX,tmpY);

	if(right == true)
	map.setPos(snake_body[snake_body.size()-1],tmpX-1,tmpY);

	if(left == true)
	map.setPos(snake_body[snake_body.size()-1],tmpX+1,tmpY);

	if(down == true)
	map.setPos(snake_body[snake_body.size()-1],tmpX,tmpY+1);

	if(up == true)
	map.setPos(snake_body[snake_body.size()-1],tmpX,tmpY-1);
}

bool Snake::Died()
{
int headX,headY;
int x,y;

Snake::getHead(headX,headY);

//did it bite it's tail
 for(int i = 1; i < snake_body.size();++i)
 {
	 map.getPos(snake_body[i],x,y);
	 if((headX == x) && (headY == y))
		 return true;
 }

 //did it hit the wall
 if((headX > 39) && (headX < 1) && (headY > 26) && (headY < 1))
	 return true;

    return false;
}

bool Snake::IsDead()
{
    return dead;
}

void Snake::setSpeed(float s)
{
    speed = s;
}


void Snake::getHead(int &x, int &y)
{
	map.getPos(snake_body[0],x,y);
}



//private

void Snake::littleSnake()
{
    for(int i = 0; i < 3;++i)
     {
         Block b;
         snake_body.push_back(b);
     }

	map.setPos(snake_body[0],5,3);
	map.setPos(snake_body[1],4,3);
	map.setPos(snake_body[2],3,3);

}


