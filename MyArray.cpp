// MyArray.cpp
// Created by Tuan Anh Pham on 2024-07-10.
//

#include "MyArray.h"
#include <iostream> // Include the iostream library for input and output
using namespace std; // Use the standard namespace to avoid prefixing std::

// Definition of the MyArray class's member function to create a dynamic array
int *MyArray::createArray(int size) {
    cout << "Creating an array with size " << size << endl; // Inform the user about the array size being created
    int* array = new int[size]; // Dynamically allocate memory for an array of integers of the given size
    return array; // Return the pointer to the newly created array
}

// Definition of the MyArray class's member function to initialize the array with values
void MyArray::initializeArray(int* array, int size) {
    cout << "Initializing array values ranging from 0 to size-1" << endl; // Inform the user about the initialization process
    for (int i = 0; i < size; i++) { // Loop through each index of the array
        array[i] = i; // Assign the index value to the corresponding array element
    }
}

// Definition of the MyArray class's member function to print the array elements
void MyArray::printArray(int *array, int size) {
    cout << "Printing the array values" << endl; // Inform the user that the array values are being printed
    for (int i = 0; i < size; i++) { // Loop through each index of the array
        cout << "The value at index " << i << " is " << array[i] << endl; // Print the value at the current index
    }
}

// Definition of the MyArray class's member function to delete the array
void MyArray::deleteArray(int *array) {
    cout << "Deallocating the array from the memory" << endl; // Inform the user that the array is being deallocated
    delete[] array; // Deallocate the memory previously allocated for the array
}

