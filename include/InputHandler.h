#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "CImg.h"
#include <iostream>
#include <string>

using namespace cimg_library;

class InputHandler {
private:
    CImgDisplay& display;

public:

    bool isLeftMouseClicked();

    explicit InputHandler(CImgDisplay& displayRef);


    void processInput();


    bool isMouseClicked();
    bool isKeyPressed();

};

#endif 
