#include "Triangle.h"

Triangle::Triangle(int x, int y, int height, std::string color, std::string drawType) :
x(x), y(y), height(height), color(color), drawType(drawType) {}


void Triangle::draw(std::vector<std::vector<char> >& grid) const {
    if (drawType == "frame") {
        if (height <= 0) return;

        for (int i = 0; i < height; ++i) {
            int leftMost = x - i;
            int rightMost = x + i;
            int posY = y + i;
            if (posY < grid.size()) {
                if (leftMost >= 0 && leftMost < grid[0].size())
                    grid[posY][leftMost] = color[0];
                if (rightMost >= 0 && rightMost < grid[0].size() && leftMost != rightMost)
                    grid[posY][rightMost] = color[0];
            }
        }
        for (int j = 0; j < 2 * height - 1; ++j) {
            int baseX = x - height + 1 + j;
            int baseY = y + height - 1;
            if (baseX >= 0 && baseX < grid[0].size() && baseY < grid.size())
                grid[baseY][baseX] = color[0];
        }
    } else if (drawType == "fill") {if (height <= 0) return;

        for (int i = 0; i < height; ++i) {
            int leftMost = x - i;
            int rightMost = x + i;
            int posY = y + i;

            if (posY >= 0 && posY < grid.size()) {
                for (int posX = leftMost; posX <= rightMost; ++posX) {
                    if (posX >= 0 && posX < grid[0].size()) {
                        grid[posY][posX] = color[0];
                    }
                }
            }
        }
    }
}

std::string Triangle::getInfoForConsole() const {
    return "ID: " + std::to_string(getId()) +
           ", Type: Triangle" +
           ", Draw Type: " + drawType +
           ", Color: " + color +
           ", Coordinates: (" + std::to_string(x) + ", " + std::to_string(y) + ")" +
           ", Height: " + std::to_string(height);
}

std::string Triangle::getInfoForFile() const {
    return std::to_string(getId()) + " Triangle " +
           drawType + " " +
           color + " " +
           std::to_string(x) + " " +
           std::to_string(y) + " " +
           std::to_string(height);
}