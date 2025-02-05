#pragma once
#ifndef DOOR_H
#define DOOR_H
#include "Wall.h"


class Door : public Wall
{
public:
	bool isOpen;
	Sprite spriteclose;
	Sprite spriteopen;
	Door(Texture& texture, float x, float y, int nextlvl, bool isOpen, int type);
	~Door();
	Sprite getSprite();
	void open();
};

#endif // WALL_H