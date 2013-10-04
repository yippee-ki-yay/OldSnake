#ifndef _MAP_H
#define _MAP_H

#include<vector>
#include<iostream>
#include"Block.h"


class Map
{
    public:

    Map();
	~Map();

	void getPos(const Block &b,int &x,int &y);

	void setPos(Block &b,int x,int y);

    std::vector<Block>map;

};

#endif
