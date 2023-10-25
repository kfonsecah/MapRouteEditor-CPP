#pragma once

#include <list>
#include "../include/CImg.h"
#include <string> 

struct Point {
    int x, y;
};

class Route {
private:
    std::string name;
    cimg_library::CImg<unsigned char> color;
    std::list<Point> vertices;

public:
    Route(const std::string& name, const cimg_library::CImg<unsigned char>& color);

    void addVertex(const Point& point);
    void removeVertex(const Point& point);
    const std::list<Point>& getVertices() const;

    void draw(cimg_library::CImg<unsigned char>& image);
};
