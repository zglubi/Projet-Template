#pragma once
#ifndef KEY_H
#define KEY_H
#include "Item.h"
#include "Player.h"

class Key : public Item
{
public:
	Key(Texture& texture, float x, float y);
	void update(RenderWindow& window, float deltatime, View& view) override;
	void draw(RenderWindow& window) override;
	void interact(shared_ptr<Player>& player) override;
};


#endif // !KEY_H




