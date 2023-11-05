#include "../include/MapDisplay.h"
#include "../include/DoubleLinkedList.h"

MapDisplay::MapDisplay()
    : display(1100,820, "Map Display") {
    mapImage.load(MAP_IMAGE_PATH);

    if (mapImage.depth() == 16) {
        mapImage.normalize(0, 255);
    }
    displayMap(); 
}

void MapDisplay::displayMap() {

    display.display(mapImage);

    while (!display.is_closed() && !display.is_keyESC()) {
        display.wait();
        display.display(mapImage);
    }
}


void MapDisplay::drawRoute(const DoublyLinkedList& route) {

}

void MapDisplay::updateDisplay() {
    display.display(mapImage);
}

