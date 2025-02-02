#include "Entity.h"

Entity::Entity(float x, float y) : x(x), y(y) {}


Sprite& Entity::getSprite() {
	return sprite;
}

bool Entity::isToBeDeleted() const {
	return toBeDeleted;
}

void Entity::setToBeDeleted(bool ToBeDeleted) {
	toBeDeleted = ToBeDeleted;
}