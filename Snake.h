#ifndef _SNAKE_H
#define _SNAKE_H

#include<vector>
#include<iostream>

#include"Map.h"

#define ARENA_WIDTH  800

#define ARENA_HEIGHT 600


class Snake
{
  public:

  Snake(Map &m);
  ~Snake();

  void Draw();

  void Move();

  void getDirection();

  void Grow();

  bool IsDead();

  void setSpeed(float s);

  bool Died();

  void getHead(int &x, int &y);

  private:

  void littleSnake();

  Map map;

  std::vector<Block>snake_body;

  typedef std::vector<Block>::iterator Iter;

  sf::Clock clock;

  bool dead;

  float deltaTime;

  float speed;

  bool right,left,up,down;


};

#endif
