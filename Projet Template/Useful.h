#pragma once
#ifndef USEFUL_H
#define USEFUL_H

#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

Vector2f operator*(const Vector2f& vector, float scalar);

Vector2f normalize(const Vector2f& source);

float dotProduct(const Vector2f& v1, const Vector2f& v2);

float magnitude(const Vector2f& v);

float calculateAngle(const Vector2f& direction);

#endif //USEFUL_H