#include <iostream>
#include <vector>
#include "triangle.h"
#include "right_triangle.h"
#include "isosceles_triangle.h"
#include "equilateral_triangle.h"
#include "quadrangle.h"
#include "rectangle.h"
#include "square.h"
#include "parallelogram.h"
#include "rhombus.h"
#include "figure_error.h"
#include "main.h"

int main() {
    std::setlocale(0, "rus");
    std::vector<Figure*> figures;


    try {
        figures.push_back(new Triangle(10, 20, 30, 50, 60, 70));
    }
    catch (const FigureError& e) {
        std::cout << "Ошибка создания треугольника. Причина: " << e.what() << "\n";
    }

    try {
        figures.push_back(new RightTriangle(3, 4, 5, 30, 60)); 
    }
    catch (const FigureError& e) {
        std::cout << "Ошибка создания прямоугольного треугольника. Причина: " << e.what() << "\n";
    }

    try {
        figures.push_back(new IsoscelesTriangle(10, 20, 50, 60)); 
    }
    catch (const FigureError& e) {
        std::cout << "Ошибка создания равнобедренного треугольника. Причина: " << e.what() << "\n";
    }

    try {
        figures.push_back(new EquilateralTriangle(30)); 
    }
    catch (const FigureError& e) {
        std::cout << "Ошибка создания равностороннего треугольника. Причина: " << e.what() << "\n";
    }

    try {
        figures.push_back(new Quadrangle(10, 20, 30, 40, 50, 60, 70, 80)); 
    }
    catch (const FigureError& e) {
        std::cout << "Ошибка создания четырёхугольника. Причина: " << e.what() << "\n";
    }

    try {
        figures.push_back(new Rectangle(10, 20));
    }
    catch (const FigureError& e) {
        std::cout << "Ошибка создания прямоугольника. Причина: " << e.what() << "\n";
    }

    try {
        figures.push_back(new Square(20)); 
    }
    catch (const FigureError& e) {
        std::cout << "Ошибка создания квадрата. Причина: " << e.what() << "\n";
    }

    try {
        figures.push_back(new Parallelogram(20, 30, 30, 40)); 
    }
    catch (const FigureError& e) {
        std::cout << "Ошибка создания параллелограмма. Причина: " << e.what() << "\n";
    }

    try {
        figures.push_back(new Rhombus(30, 30, 40)); 
    }
    catch (const FigureError& e) {
        std::cout << "Ошибка создания ромба. Причина: " << e.what() << "\n";
    }

  
    try {
        figures.push_back(new Triangle(1, 1, 1, 60, 60, 70)); 
    }
    catch (const FigureError& e) {
        std::cout << "Ошибка создания треугольника. Причина: " << e.what() << "\n";
    }

    try {
        figures.push_back(new RightTriangle(3, 4, 5, 30, 70)); 
    }
    catch (const FigureError& e) {
        std::cout << "Ошибка создания прямоугольного треугольника. Причина: " << e.what() << "\n";
    }

    try {
        figures.push_back(new Square(40)); 
    }
    catch (const FigureError& e) {
        std::cout << "Ошибка создания квадрата. Причина: " << e.what() << "\n";
    }

    std::cout << "\nСозданные фигуры:\n";
    for (const auto& figure : figures) {
        figure->print_info();
        delete figure;
    }

    return 0;
}