#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Entity
{
public:
	
	Sprite sprite;
	Texture texture;

	float x;
	float y;

	Entity(float x, float y);
	virtual void update(RenderWindow& window, float deltatime, View& view) = 0;
	virtual void draw(RenderWindow& window) = 0;

	Sprite& getSprite();

};



#endif // !ENTITY_H

