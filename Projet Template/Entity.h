#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "RandomNumber.h"
using namespace sf;
using namespace std;

class Entity
{
public:
	
	Sprite sprite;
	Texture texture;
	bool toBeDeleted = false;

	float x;
	float y;

	Entity(float x, float y);
	virtual void update(RenderWindow& window, float deltatime, View& view) = 0;
	virtual void draw(RenderWindow& window) = 0;

	Sprite& getSprite();
	bool isToBeDeleted() const;
	void setToBeDeleted(bool ToBeDeleted);
};



#endif // !ENTITY_H

