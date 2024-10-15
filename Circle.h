#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"

class Circle : public Shape {
    int centerX, centerY, radius;
    std::string color;
public:
    Circle(int centerX, int centerY, int radius, std::string color);
    void draw(std::vector<std::vector<char> >& grid) const override;
    void fill(std::vector<std::vector<char>>& grid) const override;
    std::string getInfoForConsole() const override;
    std::string getInfoForFile() const override;
};
#endif // CIRCLE_H