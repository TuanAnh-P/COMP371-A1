//
// Created by Tuan Anh Pham on 2024-07-10.
//

#ifndef MYARRAY_H
#define MYARRAY_H



class MyArray {
public:
    static int* createArray(int size);
    static void initializeArray(int* array, int size);
    static void printArray(int* array, int size);
    static void deleteArray(int* array);
};



#endif //MYARRAY_H
