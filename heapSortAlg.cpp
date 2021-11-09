#include "heapSortAlg.h"
#include <iostream>

heapSortAlgClass::heapSortAlgClass(int *arrayPointer,const int& numElements)
{
	this->arrayPointer = arrayPointer;
	this->numElements = numElements;
	lastElementIndex = numElements - 1;
	parentIndex = 0;
	childIndex = 0;
	childReturnIndex = 1; // 0 is always parent, therefore it starts from 1
	tmpSwap = 0;
	inner_cycle = true;
	heapify_cycle = true;
}
void heapSortAlgClass::displayArray() const
{
	for (int i = 0; i < numElements; i++)
	{
		if (0 == (i % 30))	std::cout << '\n'; //place newline after 30 elements
		std::cout << arrayPointer[i] << " ";
	}
	std::cout << "\n\n";
}
void heapSortAlgClass::heapifyFunction()
{
	while (childReturnIndex < numElements) //check if index of child is inside of the array
	{
		childIndex = childReturnIndex; //when parent and child were not swapped, heapifyFunction continues with next index of child
		heapify_cycle = true; //value true opens access to cycle for swapping children and parents, it has to be restored each turn

		while (heapify_cycle) 
		{
			if (arrayPointer[childIndex] > arrayPointer[(childIndex - 1) / 2]) //swap values of child and parent if child is bigger
			{
				//swap starts
				tmpSwap = arrayPointer[childIndex];
				arrayPointer[childIndex] = arrayPointer[(childIndex - 1) / 2];
				arrayPointer[(childIndex - 1) / 2] = tmpSwap;
				//swap ends
				childIndex = (childIndex - 1) / 2; //overwrite childIndex to index of its parent
			}
			else 
			{ 
				childReturnIndex++; //return in the beginning of heapifyFunction and continues with next index of child
				heapify_cycle = false; //value false closes cycle
			}
		}
	}
}
int heapSortAlgClass::swapLastElement()
{
	//swap starts
	tmpSwap = arrayPointer[0];
	arrayPointer[0] = arrayPointer[lastElementIndex];
	arrayPointer[lastElementIndex] = tmpSwap;
	//swap ends
	return lastElementIndex - 1; //decrease index of last element of heap because in this index is placed the biggest element of rest of heap
}
heapSortAlgClass::numChildEnum heapSortAlgClass::twoChildrenTest() const
{
	if (((parentIndex + 1) * 2) <= lastElementIndex) //if parent has (index+1)*2 child, it always has 2 children, also index of child has to be inside of array 
	{
		return numChildEnum::twoChildren; //switch will know that parent has 2 children
	}
	else if (((parentIndex + 1) * 2 - 1) <= lastElementIndex) //if parent doesn't have 2 children it can still have 1 child, also index of child has to be inside of array 
	{
		return numChildEnum::oneChild; //switch will know that parent has 1 child
	}
	else
	{
		return numChildEnum::noChild; //if parent doesn't have children, switch will know that
	}
}
int heapSortAlgClass::compareChildren()
{
	if (arrayPointer[(parentIndex + 1) * 2 - 1] > arrayPointer[(parentIndex + 1) * 2]) //compare values of children and return index of bigger child
	{
		return (parentIndex + 1) * 2 - 1;
	}
	else
	{
		return (parentIndex + 1) * 2;
	}
}
bool heapSortAlgClass::swapParentAndChild()
{
	if (arrayPointer[childIndex] > arrayPointer[parentIndex])
	{
		//swap starts
		tmpSwap = arrayPointer[childIndex];
		arrayPointer[childIndex] = arrayPointer[parentIndex];
		arrayPointer[parentIndex] = tmpSwap;
		//swap ends
	
		//after swap, element with childIndex can be bigger than its children,
		//therefore parentIndex is set to childIndex and is executed test of number of children
		parentIndex = childIndex; 
		return true;
	}
	//return false when parent and child were not swapped,
	//it stops inner_cycle and start new turn with swapped the first and last elements of heap
	else return false; 
}
void heapSortAlgClass::heapSortAlg()
{
	heapifyFunction(); //make max-heap from array
	while (lastElementIndex != 0) //if lastElementIndex = 0 there is no element which can be swapped with the first element
	{
		parentIndex = 0; //start every turn from top of the heap (from the first element of heap)
		lastElementIndex = swapLastElement(); //swap the first element with last element of heap
		inner_cycle = true; //open inner_cycle where is tested if parent has 2,1 or 0 children and also tests if child is bigger than parent

		//after swap, element can be smaller than its children, 
		//therefore this cycle has to continue and ends when there is no child/parent to swap
		while (inner_cycle) 
		{
			switch (twoChildrenTest())  //determine case according to number of children
			{
			case twoChildren:
				childIndex = compareChildren(); //if parent has 2 children, returns index of bigger child
				inner_cycle = swapParentAndChild(); //swap bigger child with parent, also return true so inner_cycle will continue with changed parentIndex
				break;
			case oneChild:
				childIndex = (parentIndex + 1) * 2 - 1; //if parent has 1 child it always this index
				inner_cycle = swapParentAndChild(); //swap bigger child with parent, also return true so inner_cycle will continue with changed parentIndex
				break;
			case noChild:
				inner_cycle = false; //nothing to swap, stops inner_cycle
				break;
			}
		}
	}
}