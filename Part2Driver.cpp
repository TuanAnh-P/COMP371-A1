#include "Point.h"
#include "Triangle.h"

#include <iostream>
using namespace std;

// Function to print the menu options
void printMenu() {
    cout << "Menu Options:" << endl;
    cout << "-------------------------------" << endl;
    cout << "1. Create Triangle" << endl;
    cout << "2. Translate Triangle" << endl;
    cout << "3. Display Triangle Coordinates" << endl;
    cout << "4. Calculate Triangle Area" << endl;
    cout << "5. Quit" << endl;
    cout << "-------------------------------" << endl;
    cout << "Enter your choice: ";
}

int main() {
    Triangle* triangle = nullptr; // Pointer to a Triangle object
    int choice; // Variable to store the user's menu choice
    bool running = true; // Boolean to control the main loop

    while (running) {
        printMenu(); // Display the menu options
        cin >> choice; // Read the user's choice

        switch (choice) {
            case 1: {
                // Case 1: Create a new Triangle object
                double x1, y1, z1, x2, y2, z2, x3, y3, z3;
                cout << "Enter coordinates for Point 1 (x y z): ";
                cin >> x1 >> y1 >> z1;
                cout << "Enter coordinates for Point 2 (x y z): ";
                cin >> x2 >> y2 >> z2;
                cout << "Enter coordinates for Point 3 (x y z): ";
                cin >> x3 >> y3 >> z3;
                triangle = new Triangle(Point(x1, y1, z1), Point(x2, y2, z2), Point(x3, y3, z3));
                cout << "Triangle created: " << endl << *triangle << endl;
                break;
            }
            case 2: {
                // Case 2: Translate the existing Triangle object
                if (triangle) {
                    double value;
                    char axis;
                    cout << "Enter distance: ";
                    cin >> value;
                    cout << "Enter axis (x/y/z): ";
                    cin >> axis;
                    triangle->translate(value, axis);
                    cout << "Triangle translated: " << endl << *triangle << endl;
                } else {
                    cout << "No triangle created yet. Please create a triangle first." << endl << endl;
                }
                break;
            }
            case 3: {
                // Case 3: Display the current coordinates of the Triangle object
                if (triangle) {
                    cout << "Triangle coordinates: " << endl << *triangle << endl;
                } else {
                    cout << "No triangle created yet. Please create a triangle first." << endl << endl;
                }
                break;
            }
            case 4: {
                // Case 4: Calculate and display the area of the Triangle object
                if (triangle) {
                    cout << "Triangle's area: " << triangle->calcArea() << endl << endl;
                } else {
                    cout << "No triangle created yet. Please create a triangle first." << endl << endl;
                }
                break;
            }
            case 5: {
                // Case 5: Quit the program
                running = false;
                if (triangle) {
                    delete triangle; // Delete the Triangle object to free memory
                    triangle = nullptr;
                }
                cout << "Exiting program." << endl;
                break;
            }
            default:
                // Default case: Invalid menu choice
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
