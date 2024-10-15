#include "Triangle.h"

Triangle::Triangle(int x, int y, int height) : x(x), y(y), height(height) {}


void Triangle::draw(std::vector<std::vector<char> >& grid) const {
    if (height <= 0) return;

    for (int i = 0; i < height; ++i) {
        int leftMost = x - i;
        int rightMost = x + i;
        int posY = y + i;
        if (posY < grid.size()) {
            if (leftMost >= 0 && leftMost < grid[0].size())
                grid[posY][leftMost] = '*';
            if (rightMost >= 0 && rightMost < grid[0].size() && leftMost != rightMost)
                grid[posY][rightMost] = '*';
        }
    }
    for (int j = 0; j < 2 * height - 1; ++j) {
        int baseX = x - height + 1 + j;
        int baseY = y + height - 1;
        if (baseX >= 0 && baseX < grid[0].size() && baseY < grid.size())
            grid[baseY][baseX] = '*';
    }
}


void Triangle::fill(std::vector<std::vector<char>>& grid) const {
    if (height <= 0) return;

    for (int i = 0; i < height; ++i) {
        int leftMost = x - i;
        int rightMost = x + i;
        int posY = y + i;

        if (posY >= 0 && posY < grid.size()) {
            for (int posX = leftMost; posX <= rightMost; ++posX) {
                if (posX >= 0 && posX < grid[0].size()) {
                    grid[posY][posX] = '*';
                }
            }
        }
    }
}


std::string Triangle::getInfoForConsole() const {
    return "ID: " + std::to_string(getId()) + ", Type: Triangle, Coordinates: (" +
           std::to_string(x) + ", " + std::to_string(y) + "), Height: " +
           std::to_string(height);
}


std::string Triangle::getInfoForFile() const {
    return std::to_string(getId()) + " Triangle " +
           std::to_string(x) + " " +
           std::to_string(y) + " " +
           std::to_string(height);
}