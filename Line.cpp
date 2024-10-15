#include "Line.h"
#include <cmath>
#include <iostream>
#include <ostream>
Line::Line(int startX, int startY, int length, int angle, std::string color, std::string drawType) :
startX(startX), startY(startY), length(length), angle(angle), color(color), drawType(drawType){}

void Line::draw(std::vector<std::vector<char> >& grid) const {
    double radians = angle * M_PI / 180.0;

    for (int i = 0; i <= length; ++i) {
        int posX = static_cast<int>(startX + i * cos(radians));
        int posY = static_cast<int>(startY + i * sin(radians));

        if (posX >= 0 && posX < grid[0].size() && posY >= 0 && posY < grid.size()) {
            grid[posY][posX] = color[0];
        }
    }
}

bool Line::containsPoint(int pointX, int pointY) const {
    double radians = angle * M_PI / 180.0;
    int endX = static_cast<int>(startX + length * cos(radians));
    int endY = static_cast<int>(startY + length * sin(radians));

    if ((pointX < std::min(startX, endX) || pointX > std::max(startX, endX)) ||
        (pointY < std::min(startY, endY) || pointY > std::max(startY, endY))) {
        return false;
        }

    double numerator = std::abs((endY - startY) * pointX - (endX - startX) * pointY + endX * startY - endY * startX);
    double denominator = std::sqrt(std::pow(endY - startY, 2) + std::pow(endX - startX, 2));
    double distance = numerator / denominator;

    const double threshold = 0.5;

    return distance <= threshold;
}

std::string Line::getInfoForConsole() const {
    return "ID: " + std::to_string(getId()) +
           ", Type: Line" +
           ", Draw Type: " + drawType +
           ", Color: " + color +
           ", Coordinates: (" + std::to_string(startX) + ", " + std::to_string(startY) + ")" +
           ", Length: " + std::to_string(length) +
           ", Angle: " + std::to_string(angle);
}

std::string Line::getInfoForFile() const {
    return std::to_string(getId()) + " Line " +
           drawType + " " +
           color + " " +
           std::to_string(startX) + " " +
           std::to_string(startY) + " " +
           std::to_string(length) + " " +
           std::to_string(angle);
}