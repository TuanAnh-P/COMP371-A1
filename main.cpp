#include "MyArray.h"
#include <iostream>

#include "MyArray.h";
#include "Point.h"
#include "Triangle.h"
using namespace std;

int main() {

    // Part 1
    // int size;
    // cout << "Enter the size of the array: ";
    // cin >> size;
    // int* array = MyArray::createArray(size);
    // MyArray::initializeArray(array, size);
    // MyArray::printArray(array, size);
    // MyArray::deleteArray(array);
    // array = nullptr;

    // Part 2
    // Point* point = new Point(1,1,1);
    // cout << *point;
    // point->translate(5, 'x');
    // point->translate(10, 'z');
    // cout << *point;
    // delete point;
    // point = nullptr;
    // return 0;

    // Part 2
    Triangle* triangle = new Triangle(Point(0, 0, 0), Point(1, 0, 0), Point(0, 1, 0));
    std::cout << *triangle << std::endl;
    triangle->translate(5, 'z');
    std::cout << *triangle << std::endl;
    cout << "Triangle's area: " << triangle->calcArea() << endl;
    delete triangle;
    triangle = nullptr;
    return 0;
}
