#pragma once
#ifndef ITEM_H
#define ITEM_H

#include "Entity.h"
#include "Interactable.h"


class Item : public Entity, public Interactable
{
public:
	Item(Texture& texture, float x, float y);
	~Item();
	virtual void update(RenderWindow& window, float deltatime, View& view) = 0;
	virtual void draw(RenderWindow& window) = 0;
	virtual void interact(shared_ptr<Player>& player) = 0;
};

#endif // !ITEM_H