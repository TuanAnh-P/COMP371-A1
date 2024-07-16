#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h"
#include <iostream>
#include <cmath>

class Triangle {
public:
    // Constructors
    Triangle(); // Default constructor
    Triangle(const Point& vertex_1, const Point& vertex_2, const Point& vertex_3); // Parameterized constructor

    // Copy constructor
    Triangle(const Triangle& other);

    // Assignment operator
    Triangle& operator=(const Triangle& other);

    // Destructor
    ~Triangle(); // Destructor to release any resources

    // Stream insertion operator
    friend std::ostream& operator<<(std::ostream& os, const Triangle& triangle);

    int translate(int d, char axis);

    double calcArea() const;

private:
    Point* vertex_1;
    Point* vertex_2;
    Point* vertex_3;
};

#endif // TRIANGLE_H
