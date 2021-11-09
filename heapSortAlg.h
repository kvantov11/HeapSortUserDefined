#ifndef HEAPSORTALG_H
#define HEAPSORTALG_H
#include <iostream>

class heapSortAlgClass
{
private:
	//array's variables
	int* arrayPointer; //pointer to array
	int numElements; //number of elements in array

	//heapify's variables
	int childReturnIndex; //index used in heapifyFunction to store index where heapifyFunction return when child and parent are not swapped
	//after child and parent swap, new parent can be bigger than its parent and it has to be also swapped,
	//variable maintains continue of cycle
	bool heapify_cycle; 

	//heapify's function
	
	//arranges elements to max-heap
	void heapifyFunction(); 

	//heapsort's variables
	int lastElementIndex; //index of last element of heap
	int parentIndex; //index of parent
	bool inner_cycle; //true if cycle in heapsortAlg can continue

	//heapsort's functions
	enum numChildEnum //used in switch in heapSortAlg function to determine case
	{
		noChild,
		oneChild,
		twoChildren
	};
	//test if parent has 2 or 1 or none child
	numChildEnum twoChildrenTest()const; 
	//swap the first element with the last element of heap with index lastElementIndex
	int swapLastElement(); 
	//return index of bigger child
	int compareChildren(); 
	//swap child with parent if child id bigger than parent, return true if swap was executed
	bool swapParentAndChild(); 

	//shared variables
	//1. index of child which is compared with parent in heapifyFunction, 
	//2. index of bigger child (bigger value) or index of sole child of parent with index parentIndex
	int childIndex;
	int tmpSwap; //temporarily store value from array before swap


public:
	//constructor: pointer to array, number of elements of array
	heapSortAlgClass(int *arrayPointer,const int& numElements);
	//write all elements to console
	void displayArray() const; 
	//sorting algorithm
	void heapSortAlg(); 
};
#endif 

