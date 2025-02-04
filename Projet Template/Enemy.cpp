#include "Enemy.h"

Enemy::Enemy(float x, float y, float speed)
    : Entity(x, y), hp(10), position(x, y), velocity(0, 0), speed(speed) {
}