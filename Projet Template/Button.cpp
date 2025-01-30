#include "Button.h"

Button::Button(const string& text, const Vector2f& position, const Vector2f& size) {
    buttonShape.setPosition(position);
    buttonShape.setSize(size);
    buttonShape.setFillColor(Color::Blue);

    if (!font.loadFromFile("arial.ttf")) {
        throw std::runtime_error("Failed to load font");
    }

    buttonText.setFont(font);
    buttonText.setString(text);
    buttonText.setCharacterSize(24);
    buttonText.setFillColor(Color::White);
    buttonText.setPosition(
        position.x + (size.x - buttonText.getGlobalBounds().width) / 2,
        position.y + (size.y - buttonText.getGlobalBounds().height) / 2
    );
}

void Button::draw(RenderWindow& window) {
    window.draw(buttonShape);
    window.draw(buttonText);
}

bool Button::isClicked(const RenderWindow& window, Event event) const {
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
        Vector2i mousePos = Mouse::getPosition(window);
        return buttonShape.getGlobalBounds().contains(static_cast<Vector2f>(mousePos));
    }
    return false;
}
