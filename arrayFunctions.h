#ifndef ARRAYFUNCTIONS_H
#define ARRAYFUNCTIONS_H
//copy elements from one array to other array
void copyArray(const int* fromArray, int* toArray, const int& size);
//generate and randomize array with element from 0 to size-1
int* generateArray(const int& size); 
//randomize position of elements in array
void randomizeArray(int* randArray, const int& size); 
//write array to console
void displayArray(const int* fromArray, const int& size);
//execute user-defined heapsort and write duration of sorting to console,
//display=0 hide elements
//display=1 write elements to console
void userDefHeapSort(int* arrayPointer, const int& size, const int& display);
// execute STL <algorithm> make_heap and sort_heap and write duration of sorting to console
void stlHeapSort(int* arrayPointer, const int& size);
#endif 

