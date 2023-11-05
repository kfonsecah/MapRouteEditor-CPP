#ifndef MAPDISPLAY_H
#define MAPDISPLAY_H

#include "CImg.h"

#define cimg_use_jpg

#define MAP_IMAGE_PATH "./resources/Map.jpg"

using namespace cimg_library;

class DoublyLinkedList; 

class MapDisplay {
private:

    CImg<unsigned char> mapImage; 
    CImgDisplay display;        

public:
    MapDisplay();
    void displayMap();
    void drawRoute(const DoublyLinkedList& route);
    void updateDisplay();
};

#endif 
