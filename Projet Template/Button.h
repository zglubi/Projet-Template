#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Button {
public:
    Button(const string& text, const Vector2f& position, const Vector2f& size);

    void draw(RenderWindow& window);
    bool isClicked(const RenderWindow& window, Event event) const;

private:
    RectangleShape buttonShape;
    Text buttonText;
    Font font;
};

#endif