#include "Entity.h"

Entity::Entity(float x, float y) : x(x), y(y) {}


Sprite& Entity::getSprite() {
	return sprite;
}