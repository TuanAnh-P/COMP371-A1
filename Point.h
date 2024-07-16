#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point {
public:
    // Constructors
    Point(); // Default constructor
    Point(int x, int y, int z); // Parameterized constructor

    // Copy constructor
    Point(const Point& other);

    // Assignment operator
    Point& operator=(const Point& other);

    // Destructor
    ~Point(); // Destructor to release any resources

    // Stream insertion operator
    friend std::ostream& operator<<(std::ostream& os, const Point& point);

    int translate(int d, char axis);

    // Getter methods
    int getX() const;
    int getY() const;
    int getZ() const;

private:
    int* x;
    int* y;
    int* z;
};

#endif // POINT_H


