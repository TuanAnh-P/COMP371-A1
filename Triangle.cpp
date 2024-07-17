#include "Triangle.h"

// Constructors

// Default constructor initializes the 3 vertices to (0, 0, 0)
Triangle::Triangle() : vertex_1(new Point(0, 0, 0)), vertex_2(new Point(0, 0, 0)), vertex_3(new Point(0, 0, 0)) {
}

// Parameterized constructor sets the 3 vertices to provided values
Triangle::Triangle(const Point& vertex1, const Point& vertex2, const Point& vertex3)
        : vertex_1(new Point(vertex1)), vertex_2(new Point(vertex2)), vertex_3(new Point(vertex3)) {
}

// Copy constructor
Triangle::Triangle(const Triangle& other)
        : vertex_1(new Point(*other.vertex_1)), vertex_2(new Point(*other.vertex_2)), vertex_3(new Point(*other.vertex_3)) {
}

// Assignment operator
Triangle& Triangle::operator=(const Triangle& other) {
    if (this != &other) { // Self-assignment check
        // Delete old vertices
        delete vertex_1;
        delete vertex_2;
        delete vertex_3;

        // Allocate new memory and copy the vertices from the other Triangle object
        vertex_1 = new Point(*other.vertex_1);
        vertex_2 = new Point(*other.vertex_2);
        vertex_3 = new Point(*other.vertex_3);
    }
    return *this; // Return the current object to allow for chain assignment
}

// Destructor
Triangle::~Triangle() {
    // Delete vertices and set pointers to nullptr to avoid dangling pointers
    delete vertex_1;
    delete vertex_2;
    delete vertex_3;
    vertex_1 = nullptr;
    vertex_2 = nullptr;
    vertex_3 = nullptr;
}

// Translation function to translate all vertices of the triangle
int Triangle::translate(int d, char axis) {
    // Translate all vertices
    int result1 = vertex_1->translate(d, axis);
    int result2 = vertex_2->translate(d, axis);
    int result3 = vertex_3->translate(d, axis);
    // Return the first non-zero error code, if any
    if (result1 != 0) return result1;
    if (result2 != 0) return result2;
    if (result3 != 0) return result3;
    return 0; // Return 0 for successful translation
}

// Calculate the area of the triangle using the cross product of two sides
double Triangle::calcArea() const {
    // Vector AB
    double ABx = vertex_2->getX() - vertex_1->getX();
    double ABy = vertex_2->getY() - vertex_1->getY();
    double ABz = vertex_2->getZ() - vertex_1->getZ();

    // Vector AC
    double ACx = vertex_3->getX() - vertex_1->getX();
    double ACy = vertex_3->getY() - vertex_1->getY();
    double ACz = vertex_3->getZ() - vertex_1->getZ();

    // Cross product AB x AC
    double crossX = ABy * ACz - ABz * ACy;
    double crossY = ABz * ACx - ABx * ACz;
    double crossZ = ABx * ACy - ABy * ACx;

    // Magnitude of the cross product
    double crossMagnitude = std::sqrt(crossX * crossX + crossY * crossY + crossZ * crossZ);

    // Area is half the magnitude of the cross product
    return 0.5 * crossMagnitude;
}

// Stream insertion operator for a more readable output of Triangle object
std::ostream& operator<<(std::ostream& os, const Triangle& triangle) {
    // Output the positions of the triangle's vertices
    os << "Triangle 1st vertex: " << *triangle.vertex_1;
    os << "Triangle 2nd vertex: " << *triangle.vertex_2;
    os << "Triangle 3rd vertex: " << *triangle.vertex_3;
    return os;
}
