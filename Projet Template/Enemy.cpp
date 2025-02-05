#include "Enemy.h"

Enemy::Enemy(Texture& texture, float x, float y, float speed)
    : Entity(texture, x, y), hp(10), position(x, y), velocity(0, 0), speed(speed) {
}