#include "Square.h"
#include <ostream>

Square::Square(int x, int y, int width, int height, std::string color, std::string drawType):
x(x), y(y), width(width), height(height), color(color), drawType(drawType) {
}

void Square::draw(std::vector<std::vector<char> >& grid) const {
    if (drawType == "frame") {
        if (width <= 0 || height <= 0) return;

        for (int j = 0; j < width; ++j) {
            if (y >= 0 && y < grid.size()) {
                if (x + j >= 0 && x + j < grid[0].size()) {
                    grid[y][x + j] = color[0];
                }
                if (y + height - 1 < grid.size()) {
                    if (x + j >= 0 && x + j < grid[0].size()) {
                        grid[y + height - 1][x + j] = color[0];
                    }
                }
            }
        }

        for (int i = 1; i < height - 1; ++i) {
            if (y + i >= 0 && y + i < grid.size()) {
                if (x >= 0 && x < grid[0].size()) {
                    grid[y + i][x] = color[0];
                }
                if (x + width - 1 >= 0 && x + width - 1 < grid[0].size()) {
                    grid[y + i][x + width - 1] = color[0];
                }
            }
        }
    } else if (drawType == "fill") {if (width <= 0 || height <= 0) return;

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                int gridX = x + j;
                int gridY = y + i;

                if (gridY >= 0 && gridY < grid.size() && gridX >= 0 && gridX < grid[0].size()) {
                    grid[gridY][gridX] = color[0];
                }
            }
        }
    }

}

bool Square::containsPoint(int pointX, int pointY) const {
    return (pointX >= x && pointX <= (x + width) &&
            pointY >= y && pointY <= (y + height));
}

std::string Square::getInfoForConsole() const {
    return "ID: " + std::to_string(getId()) +
           ", Type: Square" +
           ", Draw Type: " + drawType +
           ", Color: " + color +
           ", Coordinates: (" + std::to_string(x) + ", " + std::to_string(y) + ")" +
           ", Width: " + std::to_string(width) +
           ", Height: " + std::to_string(height);
}

std::string Square::getInfoForFile() const {
    return std::to_string(getId()) + " Square " +
           drawType + " " +
           color + " " +
           std::to_string(x) + " " +
           std::to_string(y) + " " +
           std::to_string(width) + " " +
           std::to_string(height);
}