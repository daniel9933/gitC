#include "LinkedList.h"
#include "stack.h"
#include <iostream>

void push(Stack* s, unsigned int element)
{
	ListNode* newNode = createNode(element);
	insert(&s->elements, newNode);
	s->count++;
}
int pop(Stack* s)
{
	if (s->count)//if not empty
	{
		s->count--;
		return removeHead(&s->elements);
	}
	else
	{
		return -1;
	}
}

void initStack(Stack* s)
{
	s->count = 0;
	s->elements = NULL;
}

void cleanStack(Stack* s)
{
	del(&s->elements);
	s->count = 0;
}

bool isEmpty(Stack* s)
{
	if (s->count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isFull(Stack* s)
{
	return false;
}