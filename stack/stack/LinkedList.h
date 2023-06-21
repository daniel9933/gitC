#pragma once
#include <iostream>

typedef struct ListNode
{
	int num;
	struct ListNode* next;

} ListNode;


ListNode* createNode(int value);
void insert(ListNode** head, ListNode* newNode);
void print(ListNode* head);
int removeHead(ListNode** head);
void del(ListNode** head);