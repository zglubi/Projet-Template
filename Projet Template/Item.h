#pragma once
#ifndef ITEM_H
#define ITEM_H

#include "Entity.h"

class Item : public Entity
{
public:
	Item(float x, float y);
	virtual void update(RenderWindow& window, float deltatime, View& view) = 0;
	virtual void draw(RenderWindow& window) = 0;

};

#endif // !ITEM_H