#ifndef LINE_H
#define LINE_H

#include "Shape.h"

class Line : public Shape {
    int startX, startY, length, angle;
    std::string color, drawType;

public:
    Line(int startX, int startY, int length, int angle, std::string color, std::string drawType);
    void draw(std::vector<std::vector<char> >& grid) const override;
    bool containsPoint(int x, int y) const override;
    std::string getInfoForConsole() const override;
    std::string getInfoForFile() const override;
};

#endif // LINE_H
