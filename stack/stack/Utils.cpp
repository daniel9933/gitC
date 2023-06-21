#include <iostream>
#include "LinkedList.h"
#include "stack.h"

void reverse(int* nums, unsigned int size)
{
	int i = 0;
	Stack* s = new Stack;

	initStack(s);
	for (i = 0; i < size ; i++)
	{
		push(s, nums[i]);
	}

	for (i = 0; i < size; i++)
	{
		nums[i] = pop(s);
	}

	cleanStack(s);
	delete(s);
}

int* reverse10()
{
	int* arr = new int[10];
	int input;

	for (int i = 9; i >= 0; i--)
	{
		std::cout << "Enter a number: ";
		std::cin >> input;
		arr[i] = input;

	}

	return arr;
}