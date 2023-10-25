#include "../include/Route.h"

Route::Route(const std::string& name, const cimg_library::CImg<unsigned char>& color) : name(name), color(color) {}

void Route::addVertex(const Point& point) {
    vertices.push_back(point);
}

void Route::removeVertex(const Point& point) {
    vertices.remove(point);
}

const std::list<Point>& Route::getVertices() const {
    return vertices;
}

void Route::draw(cimg_library::CImg<unsigned char>& image) {
    Point prevPoint = vertices.front();
    for (const Point& point : vertices) {
        if (&point != &vertices.front()) {
            image.draw_line(prevPoint.x, prevPoint.y, point.x, point.y, color);
            prevPoint = point;
        }
    }
}
