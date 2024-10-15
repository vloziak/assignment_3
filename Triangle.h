#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include "iostream"

class Triangle : public Shape {
    int x, y, height;

public:
    Triangle(int x, int y, int height);
    std::string getInfoForConsole() const override;
    std::string getInfoForFile() const override;
    void draw(std::vector<std::vector<char> >& grid) const override;
    void fill(std::vector<std::vector<char> >& grid) const override;
};

#endif // TRIANGLE_H
