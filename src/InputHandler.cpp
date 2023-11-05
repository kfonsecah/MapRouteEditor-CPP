#include "../include/InputHandler.h"

InputHandler::InputHandler(CImgDisplay& displayRef)
    : display(displayRef) {}

void InputHandler::processInput() {
    if (display.is_key()) {

    }

    if (display.button() && display.mouse_y() >= 0) {

    }
}

bool InputHandler::isLeftMouseClicked() {
    if (display.button() & 1 && display.mouse_y() >= 0) {
        std::cout << "Left mouse button clicked at position (" << display.mouse_x() << ", " << display.mouse_y() << ")" << std::endl;
        return true;
    }
    return false;
}

bool InputHandler::isMouseClicked() {
    return display.button() && display.mouse_y() >= 0;
}

bool InputHandler::isKeyPressed() {
    return display.is_key();
}
