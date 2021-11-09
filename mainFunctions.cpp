#include "mainFunctions.h"
#include <iostream>
#include <string>

int setArraySize() 
{
	std::cout << "Enter size of Array: ";
	int inputArraySize{ 0 };
	std::cin >> inputArraySize;
	return inputArraySize;
}
int dontDisplayArrays()
{
	std::string answer{' '};
	std::cout << "Write elements of arrays to console?\n"
		<< "Consider to hide elements of array if size of array is large number. Enter NO to hide elements of arrays.\n"
		<< "Anything else will result in displaying elements\n";
	std::cin >> answer;
	if (answer == "NO")
	{
		std::cout << "so you chose NO\n";
		return 0;
	}
	else
	{
		std::cout << "elements will be displayed\n";
		return 1;
	}
}