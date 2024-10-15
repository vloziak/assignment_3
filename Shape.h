#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <vector>

class Shape {
public:
    int id;
    static int nextId;
    std::string color;
    std::string drawType;
    Shape() : id(nextId++), color(""), drawType("") {}

    virtual void draw(std::vector<std::vector<char> >& grid) const = 0;
    virtual std::string getInfoForConsole() const = 0;
    virtual std::string getInfoForFile() const = 0;
    virtual bool containsPoint (int x, int y) const = 0;
    void setColor(const std::string& newColor) {
        color = newColor;
    }
    int getId() const { return id; }
    void setId(int newId) { id = newId; }

    virtual ~Shape() {}
};


#endif //SHAPE_H
