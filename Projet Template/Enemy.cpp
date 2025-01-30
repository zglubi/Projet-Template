#include "Enemy.h"

Enemy::Enemy(float x, float y, float speed)
    : Entity(x, y), position(x, y), velocity(0, 0), speed(speed) {
}