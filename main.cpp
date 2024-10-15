#include "Board.h"
#include "Triangle.h"
#include "Square.h"
#include "Circle.h"
#include "Line.h"
#include <iostream>
#include <sstream>

int main() {
    Board board;
    std::string command;

    std::cout << "Enter commands:\n";


    while (true) {
        std::cout << "> ";
        std::getline(std::cin, command);
        std::istringstream iss(command);
        std::string cmd;
        iss >> cmd;

        if (cmd == "draw") {
            std::string shapeType, drawType, color;
            iss >> drawType >> color >> shapeType;

            Shape* shape;

            if (shapeType == "triangle") {
                int x, y, height;
                iss >> x >> y >> height;
                shape = new Triangle(x, y, height, color, drawType);
            } else if (shapeType == "square") {
                int x, y, width, height;
                iss >> x >> y >> width >> height;
                shape = new Square(x, y, width, height, color, drawType);
            } else if (shapeType == "circle") {
                int x, y, radius;
                iss >> x >> y >> radius;
                shape = new Circle(x, y, radius, color, drawType);
            } else if (shapeType == "line") {
                int x, y, length;
                double angle;
                iss >> x >> y >> length >> angle;
                shape = new Line(x, y, length, angle, color,drawType);
            } else {
                std::cout << "Unknown shape. Use triangle, square, circle, or line.\n";
                continue;
            }
            board.drawShape(shape);

        } else if (cmd == "print") {
            board.print();
        } else if (cmd == "clear") {
            board.clearAll();
        } else if (cmd == "undo") {
            board.undo();
        } else if (cmd == "shapes") {
            board.displayShapes();
        } else if (cmd == "help") {
           std::cout << "help me";
        } else if (cmd == "list") {
            board.listShapes();
        } else if (cmd == "save") {
            std::string fileName;
            iss >> fileName;
            board.save(fileName);
        } else if (cmd == "load") {
            std::string fileName;
            iss >> fileName;
            board.load(fileName);
        } else if (cmd == "selectC") {
            int x, y;
            if (iss >> x >> y) {
                Shape* selectedShape = board.getShapeByCoordinates(x, y);
                if (selectedShape) {
                    std::cout << "< " << selectedShape->getInfoForConsole() << std::endl;
                } else {
                    std::cout << "< Shape was not found at (" << x << ", " << y << ")." << std::endl;
                }
            }
        } else if (cmd == "selectId") {
                int id;
                if (iss >> id) {
                    Shape* selectedShape = board.getShapeById(id);
                    if (selectedShape) {
                        std::cout << "< " << selectedShape->getInfoForConsole() << std::endl;
                    } else {
                        std::cout << "< Shape with ID " << id << " was not found." << std::endl;
                    }
                }
        } else if (cmd == "exit") {
            break;
        } else {
            std::cout << "Unknown command.\n";
        }
    }

    board.clear();

    return 0;
}
