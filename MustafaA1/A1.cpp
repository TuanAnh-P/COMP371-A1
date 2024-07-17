#include <iostream>
using namespace std;
#include <cmath>

// ********** PART 1 ***********
int* createArray(int size){
    int *array = new int[size];
    return array;
}

void initializeArray(int *array, int size){
    for(int i=0; i<size; i++){
        cout << "Enter the value to be stored in array[" << i << "]:" << endl;
        cin >> array[i];
    }
}

void printArray(const int *array, int size){
    cout << "The values stored in the array: ";
    for(int i=0; i<size; i++){
        cout << array[i] << " ";
    }
}

void deleteArray(int *array){
    delete[] array;
}



// ********** PART 2 ***********

// CLASS POINT
class Point{
private:
    double x,y,z;

public:
    // Default Constructor
    Point(){
        x = 0;
        y = 0;
        z = 0;
    }
    // Parameterized Constructor
    Point(double x, double y, double z){
        this->x = x;
        this->y = y;
        this->z = z;
    }
    // Destructor
    ~Point() {
        cout << "Point Destructor Called." << endl;
    }

    // Getters
    double getX(){return x;}
    double getY(){return y;}
    double getZ(){return z;}


    // Function
    int translate(int d, char axis){
        if(axis == 'x'){
            x += d;
            return 0;
        }
        else if(axis == 'y'){
            y += d;
            return 0;
        }
        else if(axis == 'z'){
            z += d;
            return 0;
        }
        else
            return -1;
    }
    void displayPoint(){
        cout << "(" << x << "," << y << "," << z << ")" << endl;
    }
};


// CLASS TRIANGLE
class Triangle{
private:
    Point *vertex_1;
    Point *vertex_2;
    Point *vertex_3;

public:
    // Constructor
    Triangle(){
        vertex_1 = nullptr;
        vertex_2 = nullptr;
        vertex_3 = nullptr;
    }
    // Parameterized Constructor
    Triangle(Point &vertex_1, Point &vertex_2, Point &vertex_3){
        this->vertex_1 = &vertex_1;
        this->vertex_2 = &vertex_2;
        this->vertex_3 = &vertex_3;
    }
    // Destructor
    ~Triangle() {
        cout << "Triangle Destructor Called.";
    }

    // Translate Function
    int translate(int d, char axis){
        if(axis == 'x'){
            // Translate X direction
            vertex_1->translate(d, 'x');
            vertex_2->translate(d, 'x');
            vertex_3->translate(d, 'x');
            return 0;
        }
        else if(axis == 'y'){
            // Translate Y direction
            vertex_1->translate(d, 'y');
            vertex_2->translate(d, 'y');
            vertex_3->translate(d, 'y');
            return 0;
        }
        else if(axis == 'z'){
            // Translate Z direction
            vertex_1->translate(d, 'z');
            vertex_2->translate(d, 'z');
            vertex_3->translate(d, 'z');
            return 0;
        }
        else
            return -1;
    }
    void displayVertices(){
        cout << "[DISPLAY]" << endl;
        cout << "The coordinates of vertex 1 is: ";
        vertex_1->displayPoint();
        cout << "The coordinates of vertex 2 is: ";
        vertex_2->displayPoint();
        cout << "The coordinates of vertex 3 is: ";
        vertex_3->displayPoint();
    }
    // Area Function
    double calcArea(){
        // Vector AB
        double ABx = vertex_2->getX() - vertex_1->getX();
        double ABy = vertex_2->getY() - vertex_1->getY();
        double ABz = vertex_2->getZ() - vertex_1->getZ();

        // Vector AC
        double ACx = vertex_3->getX() - vertex_1->getX();
        double ACy = vertex_3->getY() - vertex_1->getY();
        double ACz = vertex_3->getZ() - vertex_1->getZ();

        // Vector Cross product AB x AC
        double crossX = ABy * ACz - ABz * ACy;
        double crossY = ABz * ACx - ABx * ACz;
        double crossZ = ABx * ACy - ABy * ACx;

        // Magnitude of vector
        double crossMagnitude = sqrt(crossX * crossX + crossY * crossY + crossZ * crossZ);

        double area = 0.5 * crossMagnitude;
        return area;
    }
};

// ********** MAIN ***********
int main() {
    // PART 1
    cout << endl << "***************** PART1 *****************" << endl;
    int size = 0;
    cout << "Enter the size of the array to be initialized:";
    cin >> size;

    int* array = createArray(size);
    initializeArray(array, size);
    printArray(array, size);
    deleteArray(array);

    // PART 2
    cout << endl << "***************** PART2 *****************" << endl;

    int choice;
    Triangle *triangle = nullptr;
    Point *p1 = nullptr;
    Point *p2 = nullptr;
    Point *p3 = nullptr;

    do {
        // Display menu
        cout << "[Menu]:" << endl;
        cout << "1. Create Triangle" << endl;
        cout << "2. Translate Triangle" << endl;
        cout << "3. Display Vertices" << endl;
        cout << "4. Display Area" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                double x, y, z;
                cout << "Enter x, y, z coordinates for point 1: ";
                cin >> x >> y >> z;
                p1 = new Point(x, y, z);

                cout << "Enter x, y, z coordinates for point 2: ";
                cin >> x >> y >> z;
                p2 = new Point(x, y, z);

                cout << "Enter x, y, z coordinates for point 3: ";
                cin >> x >> y >> z;
                p3 = new Point(x, y, z);

                triangle = new Triangle(*p1, *p2, *p3);
                break;

            case 2:
                if (triangle) {
                    int d;
                    char axis;
                    cout << "Enter translation distance: ";
                    cin >> d;
                    if (cin.fail()) {
                        cout << "Must input an integer for distance translation" << endl;
                        return -2;
                    }
                    cout << "Enter axis (x, y, z): ";
                    cin >> axis;
                    triangle->translate(d, axis);
                } else {
                    cout << "Create a triangle first." << endl;
                }
                break;

            case 3:
                if (triangle) {
                    triangle->displayVertices();
                } else {
                    cout << "Create a triangle first." << endl;
                }
                break;

            case 4:
                if (triangle) {
                    cout << "The area of the triangle is: " << triangle->calcArea() << " units^2" << endl;
                } else {
                    cout << "Create a triangle first." << endl;
                }
                break;

            case 5:
                cout << "Program Terminated." << endl;
                break;

            default:
                cout << "Invalid choice. Try again." << endl;
        }
        cout << endl;
    } while (choice != 5);

    // Memory cleanup
    delete triangle;
    delete p1;
    delete p2;
    delete p3;
    triangle = nullptr;
    p1 = nullptr;
    p2 = nullptr;
    p3 = nullptr;

    return 0;
}