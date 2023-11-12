#include "../include/InputHandler.h"

InputHandler::InputHandler() : mouseClicked(false), clickClock() {}

void InputHandler::handleInput(const sf::Event& event, sf::RenderWindow& window) {
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        if (clickClock.getElapsedTime() >= clickThreshold) {
            mouseClicked = true;
            mousePosition = sf::Mouse::getPosition(window);
            clickClock.restart();
        }
    }
}

bool InputHandler::isMouseClicked() {
    if (mouseClicked) {
        mouseClicked = false;
        return true;
    }
    return false;
}

sf::Vector2i InputHandler::getMousePosition() const {
    return mousePosition;
}




