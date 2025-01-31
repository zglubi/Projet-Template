#include "Button.h"

Button::Button(const Texture& texture, const Vector2f& position) {
    buttonSprite.setTexture(texture);
    buttonSprite.setPosition(position);
}

void Button::draw(RenderWindow& window) {
    window.draw(buttonSprite);
}

bool Button::isClicked(const RenderWindow& window, Event event) const {
    if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
        FloatRect bounds = buttonSprite.getGlobalBounds();
        Vector2i mousePos = Mouse::getPosition(window);
        if (bounds.contains(static_cast<Vector2f>(mousePos))) {
            return true;
        }
    }
    return false;
}

void Button::setPosition(const Vector2f& position) {
	buttonSprite.setPosition(position);
}