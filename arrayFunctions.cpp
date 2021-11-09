#include "arrayFunctions.h"
#include "heapSortAlg.h"
#include <iostream>
#include <chrono>
#include <algorithm>

void copyArray(const int* fromArray, int* toArray, const int& size) //copy elements from one array to another array
{
	for (int i = 0; i < size; i++)
	{
		toArray[i] = fromArray[i];
	}
}
int* generateArray(const int& size)
{
	int* arrayPointer{ NULL };
	arrayPointer = new int[size];
	for (int i = 0; i < size; i++)
	{
		arrayPointer[i] = i;
	}
	randomizeArray(arrayPointer, size);
	return arrayPointer;
}
void randomizeArray(int* randArray, const int& size)
{
	int tmp{ 0 }; //temporarily stored int
	int randPos{ 0 }; //random index of array
	for (int i = 0; i < size; i++)
	{
		randPos = rand() % size;
		tmp = randArray[i];
		randArray[i] = randArray[randPos];
		randArray[randPos] = tmp;
	}
}
void displayArray(const int* fromArray, const int& size) //writes array to console
{
	std::cout << "elements of array:";
	for (int i = 0; i < size; i++)
	{
		if (0 == (i % 30)) std::cout << '\n'; //place newline after 30 elements
		std::cout << fromArray[i] << ' ';
	}
	std::cout << "\n\n";
}
void userDefHeapSort(int* arrayPointer, const int& size,const int& display)
{
	heapSortAlgClass randArrayClass(arrayPointer, size); //initializing heapsort class
	auto start = std::chrono::high_resolution_clock::now(); //measurement of duration of sorting
	randArrayClass.heapSortAlg(); //execute heapsort
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "user-defined heapsort duration: " << duration.count() << " microseconds\n\n"; //show sorting duration
	if (display == 1) 
	{
		std::cout << "sorted elements of array: ";
		randArrayClass.displayArray();
	}
}
void stlHeapSort(int* arrayPointer, const int& size)
{
	auto start = std::chrono::high_resolution_clock::now();
	std::make_heap(&arrayPointer[0], &arrayPointer[size]);
	std::sort_heap(&arrayPointer[0], &arrayPointer[size]);
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "STL make_heap+sort_heap duration: " << duration.count() << " microseconds\n\n"; //shows duration of sorting
}
