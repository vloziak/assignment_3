#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class Square : public Shape {
    int x, y, width, height;
    std::string color, drawType;

public:
    Square(int x, int y, int width, int height, std::string color, std::string drawType);
    void draw(std::vector<std::vector<char> >& grid) const override;
    bool containsPoint(int x, int y) const override;
    std::string getInfoForFile() const override;
    std::string getInfoForConsole() const override;
};

#endif // SQUARE_H
