#include "Circle.h"
#include <iostream>
#include <math.h>

Circle::Circle(int centerX, int centerY, int radius, std::string color, std::string drawType) :
centerX(centerX), centerY(centerY), radius(radius), color(color), drawType(drawType) {}


void Circle::draw(std::vector<std::vector<char> >& grid) const {
    if (drawType == "frame") {
        for (int x = 0; x <= 2 * radius; x++) {
            for (int y = 0; y <= 2 * radius; y++) {
                double distance = sqrt((x - radius) * (x - radius) + (y - radius) * (y - radius));

                if (distance > radius - 0.65 && distance < radius + 0.2) {
                    int gridX = centerX - radius + x;
                    int gridY = centerY - radius + y;

                    if (gridX >= 0 && gridX < grid[0].size() && gridY >= 0 && gridY < grid.size()) {
                        grid[gridY][gridX] = color[0];
                    }
                }
            }
        }
    }else if (drawType == "fill") {
        for (int x = 0; x <= 2 * radius; x++) {
            for (int y = 0; y <= 2 * radius; y++) {
                double distance = sqrt((x - radius) * (x - radius) + (y - radius) * (y - radius));

                if (distance <= radius) {
                    int gridX = centerX - radius + x;
                    int gridY = centerY - radius + y;

                    if (gridX >= 0 && gridX < grid[0].size() && gridY >= 0 && gridY < grid.size()) {
                        grid[gridY][gridX] = color[0];
                    }
                }
            }
        }
    }
}

bool Circle::containsPoint(int x, int y) const {
    int dx = x - centerX;
    int dy = y - centerY;
    return (dx * dx + dy * dy <= radius * radius);
}

std::string Circle::getInfoForConsole() const {
    return "ID: " + std::to_string(getId()) +
           ", Type: Circle" +
           ", Draw Type: " + drawType +
           ", Color: " + color +
           ", Coordinates: (" + std::to_string(centerX) + ", " + std::to_string(centerY) + ")" +
           ", Radius: " + std::to_string(radius);
}

std::string Circle::getInfoForFile() const {
    return std::to_string(getId()) + " Circle " +
           drawType + " " +
           color + " " +
           std::to_string(centerX) + " " +
           std::to_string(centerY) + " " +
           std::to_string(radius);
}