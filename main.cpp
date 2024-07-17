// #include "MyArray.h"
// #include "Point.h"
// #include "Triangle.h"
//
// #include <iostream>
// using namespace std;
//
// int main() {
//
//     // Part 1
//     int size;
//     cout << "Enter the size of the array: "; // Prompting the user for array's size
//     cin >> size;
//     int* array = MyArray::createArray(size); // Creating a dynamic array of that size
//     MyArray::initializeArray(array, size); // Initializing the array with values ranging from 0 to size-1
//     MyArray::printArray(array, size); // Printing the array's content
//     MyArray::deleteArray(array); // Deallocating the array from the memory
//     array = nullptr;
//
//     // Part 2
//     cout << endl;
//     Point* point = new Point(1,1,1); // Creating a Point object
//     cout << *point; // Printing the Point object
//     point->translate(5, 'x'); // Moving the Point object by 5 units along the x-axis
//     point->translate(10, 'z'); // Moving the Point object by 10 units along the z-axis
//     cout << *point; // Printing the Point object
//     delete point; // Calling destructor
//     point = nullptr;
//
//     // Part 2
//     cout << endl;
//     Triangle* triangle = new Triangle(Point(0, 0, 0), Point(1, 0, 0), Point(0, 1, 0)); // Creating a Triangle object
//     std::cout << *triangle << std::endl; // Printing the Triangle object
//     triangle->translate(5, 'z'); // Moving the Triangle object by 5 units along the z-axis
//     triangle->translate(12, 'y'); // Moving the Triangle object by 12 units along the y-axis
//     std::cout << *triangle << std::endl; // Printing the Triangle object
//     cout << "Triangle's area: " << triangle->calcArea() << endl; // Calculating and displarying the Triangle object area
//     delete triangle; // Calling destructor
//     triangle = nullptr;
//
//     return 0;
// }
