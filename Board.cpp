#include "Board.h"
#include "Triangle.h"
#include "Square.h"
#include "Circle.h"
#include "Line.h"
#include "Shape.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

Board::Board() : grid(30, std::vector<char>(100, ' ')) {}

void Board::print() const {
    for (const auto& row : grid) {
        for (char c : row) {
            std::cout << c;
        }
        std::cout << "\n";
    }
}

void Board::clearAll() {
    grid.assign(30, std::vector<char>(100, ' '));
    shapes.clear();
    Shape::nextId = 1;
}

void Board::clear() {
    grid.assign(30, std::vector<char>(100, ' '));
}

void Board::drawShape(Shape* shape) {
    shapes.push_back(shape);
    shape->draw(grid);
}

void Board::undo() {
    if (!shapes.empty()) {
        delete shapes.back();
        shapes.pop_back();
        clear();

        for (Shape* shape : shapes) {
            Shape::nextId = shapes.back()->id + 1;
            shape->draw(grid);
        }


    }
    else {
        std::cout << "No shapes to undo.\n";
    }
}
void Board::displayShapes() const {
    std::cout << "List of all available shapes:\n";
    std::cout << "> triangle x y height\n";
    std::cout << "> square x y width height\n";
    std::cout << "> circle x y radius\n";
    std::cout << "> line x y length angle\n";
}

void Board::listShapes() {
    if (shapes.empty()) {
        std::cout << "No shapes available.\n";
        return;
    }

    std::cout << "Shapes on the board:\n";
    for (const Shape* shape : shapes) {
        std::cout << shape->getInfoForConsole() << '\n';
    }
}

void Board::save(const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Error opening file for saving: " << filename << std::endl;
        return;
    }

    for (const Shape* shape : shapes) {
        outFile << shape->getInfoForFile() << std::endl;
    }

    outFile.close();
    std::cout << "Blackboard is saved to the file." << std::endl;
}

void Board::load(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Failed to open the file: " << filename << std::endl;
        return;
    }

    clear();
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int id, x, y, length, width, height, radius, angle;
        std::string type, color, drawType;

        if (iss >> id >> type >> drawType >> color) {
            if (type == "Line") {
                if (iss >> x >> y >> length >> angle) {
                    Shape* newLine = new Line(x, y, length, angle, color, drawType);
                    drawShape(newLine);
                }
            } else if (type == "Circle") {
                if (iss >> x >> y >> radius) {
                    Shape* newCircle = new Circle(x, y, radius, color, drawType);
                    drawShape(newCircle);
                }
            } else if (type == "Square") {
                if (iss >> x >> y >> width >> height) {
                    Shape* newSquare = new Square(x, y, width, height, color, drawType);
                    drawShape(newSquare);
                }
            } else if (type == "Triangle") {
                if (iss >> x >> y >> height) {
                    Shape* newTriangle = new Triangle(x, y, height, color, drawType);
                    drawShape(newTriangle);
                }
            } else {
                std::cout << "Unknown shape type: " << type << std::endl;
            }
        } else {
            std::cout << "Invalid line format: " << line << std::endl;
        }
    }

    std::cout << "Blackboard loaded from the file." << std::endl;
}