#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "Shape.h"

class Board {
    std::vector<Shape*> shapes;
    std::vector<Shape*> lastSelectedShapes;

public:
    std::vector<std::vector<char> > grid;
    Board();
    void clearAll();
    void print() const;
    void clear();
    void drawShape(Shape* shape);
    void undo();
    void displayShapes() const;
    void listShapes();
    Shape* getShapeById(int id);
    Shape* getShapeByCoordinates(int x, int y);
    void removeLastSelected();
    Shape* editSelectedShape(std::string param);
    void paintSelectedShape(const std::string& color);
    Shape* move(int x, int y);
    void save(const std::string& filename);
    void load(const std::string& filename);
};
#endif // BOARD_H