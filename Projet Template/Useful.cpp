#include "Useful.h"

Vector2f operator*(const Vector2f& vector, float scalar) {
    return Vector2f(vector.x * scalar, vector.y * scalar);
}

Vector2f normalize(const Vector2f& source)
{
    float length = sqrt(source.x * source.x + source.y * source.y);
    if (length != 0)
        return Vector2f(source.x / length, source.y / length);
    else
        return source;
}

float dotProduct(const Vector2f& v1, const Vector2f& v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

float magnitude(const Vector2f& v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

float calculateAngle(const Vector2f& direction) {
    Vector2f normalizedDirection = normalize(direction);
    Vector2f reference(1.0f, 0.0f); // Vecteur de référence (axe des x)
    float dot = dotProduct(normalizedDirection, reference);
    float angle = acos(dot); // Angle en radians

    // Déterminer le signe de l'angle en utilisant le produit vectoriel
    float cross = reference.x * normalizedDirection.y - reference.y * normalizedDirection.x;
    if (cross < 0)
    {
        angle = -angle;
    }

    return angle * 180 / 3.14159265;
}