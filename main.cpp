#include "heapSortAlg.h"
#include "arrayFunctions.h"
#include "mainFunctions.h"
#include <iostream>

int main()
{
	//1 means that elements will be displayed in console, 0 means elements will be hidden
	int answer{ dontDisplayArrays() };

	//generate 2 arrays with array size N
	int N{ setArraySize() }; //size of array
	int* Array1{ NULL }; //array sorted by user-defined heapsort
	Array1 = generateArray(N); //generate and randomize elements of array1

	int* Array2{ NULL }; //array sorted by STL sort_heap
	Array2 = new int[N];
	copyArray(Array1, Array2, N); //Array 2 and Array 1 will be equal

	switch (answer)
	{
	case 0: //hide elements
		std::cout << "Array1: ";
		userDefHeapSort(Array1, N, answer); //execute sorting of array1, display duration of sorting by user-defined heapsort

		std::cout << "Array2: ";
		stlHeapSort(Array2, N); //execute sorting of array2, display duration of sorting by STL algorithm make_heap and sort_heap
		break;
	case 1: //write all elements to console
		std::cout << "Array1: ";
		displayArray(Array1, N); //disordered array1
		userDefHeapSort(Array1, N,answer); //execute sorting of array1, display duration of sorting by user-defined heapsort and sorted array

		std::cout << "Array2: "; 
		displayArray(Array2, N); //disordered array2
		stlHeapSort(Array2, N); //execute sorting of array2, display duration of sorting by STL algorithm make_heap and sort_heap
		std::cout << "sorted ";
		displayArray(Array2, N); //display sorted array
		break;
	}


	delete[] Array1;
	Array1 = NULL;
	delete[] Array2;
	Array2 = NULL;

	return 0;
}


