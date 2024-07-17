#include "Point.h"

// Constructors

// Default constructor initializes x, y, z to 0
Point::Point() : x(new int(0)), y(new int(0)), z(new int(0)) {
}

// Parameterized constructor sets x, y, z to provided values
Point::Point(int xVal, int yVal, int zVal) : x(new int(xVal)), y(new int(yVal)), z(new int(zVal)) {
}

// Copy constructor
Point::Point(const Point& other) : x(new int(*other.x)), y(new int(*other.y)), z(new int(*other.z)) {
}

// Assignment operator
Point& Point::operator=(const Point& other) {
    if (this != &other) { // Self-assignment check
        // Delete old values
        delete x;
        delete y;
        delete z;

        // Allocate new memory and copy the values from the other Point object
        x = new int(*other.x);
        y = new int(*other.y);
        z = new int(*other.z);
    }
    return *this; // Return the current object to allow for chain assignment
}

// Destructor
Point::~Point() {
    // Free the dynamically allocated memory
    delete x;
    delete y;
    delete z;
}

// Method to translate the point along a given axis by a given distance
int Point::translate(int d, char axis) {
    // Validate axis
    if (axis != 'x' && axis != 'y' && axis != 'z') {
        return -1; // Return -1 for invalid axis
    }

    // Perform translation based on axis
    switch (axis) {
        case 'x':
            *x += d; // Translate along x-axis
            break;
        case 'y':
            *y += d; // Translate along y-axis
            break;
        case 'z':
            *z += d; // Translate along z-axis
            break;
        default:
            return -1; // Safe fallback, although this should not happen due to previous check
    }
    return 0; // Return 0 for successful translation
}

// Stream insertion operator for a more readable output of Point object
std::ostream& operator<<(std::ostream& os, const Point& point) {
    // Output the position of the point in the format (x, y, z)
    os << "Position : (" << *(point.x) << ", " << *(point.y) << ", " << *(point.z) << ")" << std::endl;
    return os;
}

// Getter methods

// Get the value of x
int Point::getX() const {
    return *x; // Dereference the pointer to get the value
}

// Get the value of y
int Point::getY() const {
    return *y; // Dereference the pointer to get the value
}

// Get the value of z
int Point::getZ() const {
    return *z; // Dereference the pointer to get the value
}
