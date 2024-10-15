#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape {
    int x, y, height;
    std::string color, drawType;

public:
    Triangle(int x, int y, int height, std::string color, std::string drawType);
    std::string getInfoForConsole() const override;
    std::string getInfoForFile() const override;
    void draw(std::vector<std::vector<char> >& grid) const override;
    bool containsPoint(int x, int y) const override;
};

#endif // TRIANGLE_H
