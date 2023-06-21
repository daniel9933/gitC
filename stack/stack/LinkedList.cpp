#include "LinkedList.h"
#include <stdio.h>
#include <iostream>


ListNode* createNode(int value)
{
    ListNode* newListNode = new ListNode;
    newListNode->num = value;
    newListNode->next = NULL;
    return newListNode;
}


void insert(ListNode** head, ListNode* newNode)
{
    if (!*head)
    {
        *head = newNode;
    }
    else
    {
        newNode->next = *head;
        *head = newNode;
    }
}


void print(ListNode* head)
{
    ListNode* curr = head;
    std::cout << "the stack:\n";
    while (curr)
    {
        std::cout << curr->num << " ";
        curr = curr->next;
    }
    std::cout << "\n";
}

int removeHead(ListNode** head)
{
    int poped = 0;
    
    if(*head)
    {
        ListNode* curr = *head;
        *head = curr->next;
        poped = curr->num;
        delete curr;
        return poped;
    }
}

void del(ListNode** head)
{
    
    while(*head)
    {
        removeHead(head);
    }
}