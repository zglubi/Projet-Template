#pragma once
#ifndef MEDIPACK_H
#define MEDIPACK_H
#include "Item.h"
#include "Player.h"

class Medipack : public Item
{
public:
	Medipack(float x, float y);
	void update(RenderWindow& window, float deltatime, View& view) override;
	void draw(RenderWindow& window) override;
	void interact(shared_ptr<Player>& player) override;
};


#endif // !MEDIPACK_H




