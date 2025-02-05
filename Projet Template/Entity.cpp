#include "Entity.h"

Entity::Entity(Texture& texture, float x, float y) : x(x), y(y) 
{
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
}


Sprite& Entity::getSprite() {
	return sprite;
}

bool Entity::isToBeDeleted() const {
	return toBeDeleted;
}

void Entity::setToBeDeleted(bool ToBeDeleted) {
	toBeDeleted = ToBeDeleted;
}