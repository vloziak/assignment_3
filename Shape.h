#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <vector>

class Shape {
public:
    int id;
    static int nextId;
    Shape() : id(nextId++) {}

    virtual void draw(std::vector<std::vector<char> >& grid) const = 0;
    virtual void fill(std::vector<std::vector<char> >& grid) const = 0;
    virtual std::string getInfoForConsole() const = 0;
    virtual std::string getInfoForFile() const = 0;
    int getId() const { return id; }
    void setId(int newId) { id = newId; }

    virtual ~Shape() {}
};


#endif //SHAPE_H
