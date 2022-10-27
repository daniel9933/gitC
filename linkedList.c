#include <stdio.h>
#include <stdlib.h>


typedef struct ListNode
{
    int num;
    struct ListNode* next;
} ListNode;


ListNode* createNode(int num);
void insert(ListNode** head, ListNode* newNode);
void print(ListNode* head);
int length(ListNode* head);
void delete(ListNode** head, int delIndex);
ListNode* find(ListNode* head, int value);



int main()
{
    
    ListNode* newNode = NULL;
    ListNode* head = NULL;
    ListNode* index = NULL;

    int len = 0;
    int delIndex = 0;
    int numbers = 0;
    int num = 0;
    int numToFind = 0;

    printf("How many nodes in list? ");
    scanf("%d", &numbers);
    getchar();

    for (int i = 0; i < numbers; i++)
    {
        printf("Enter number: ");
        scanf("%d", &num);
        getchar();

        newNode = createNode(num);
        insert(&head, newNode);
    }

    print(head);

    printf("which node to delete?\n");
    scanf("%d", &delIndex);
    getchar();

    delete(&head, delIndex);
    print(head);

    printf("which num to find?\n");
    scanf("%d", &numToFind);

    if((index = find(head, numToFind))!= NULL)
    {
        printf("value was found, it is : %d\n", index->num);
    }
    else if ((index = find(head, numToFind)) == NULL)
    {
        printf("value wasn't found or the list is empty.\n");
    }

    getchar();
    return 0;
}

/*
This function prints the linked list 
input - the adress of the head node in the list.
output - none
*/
void print(ListNode* head)
{
    ListNode* curr = head;
    printf("the list:\n");

    while (curr)
    {
        printf("%d ", curr->num);
        curr = curr->next;
    }
    printf("\n");
}

/*
This function creates a node 
input - the integer you want in the node.
output - a pointer to a struct with the values.
*/
ListNode* createNode(int num)
{
    ListNode* newListNode = (ListNode*)malloc(sizeof(ListNode));
    newListNode->num = num;
    newListNode->next = NULL;
    return newListNode;
}

/*
This function inserts the node into the list.
input - the adress of the pointer to the list and the new node you want to insert.
output - none
*/
void insert(ListNode** head, ListNode* newNode)
{
    if (!*head)//if head is NULL
    {
        *head = newNode;
    }
    else
    {
        ListNode* p = *head;
        while (p->next)
        {
            p = p->next;
        }
        p->next = newNode;
    }
}

/*
This function calculates the length of the list
input - the adress of the head node in the list.
output - the length of the list.
*/
int length(ListNode* head)
{
    int len = 1;//starts from 1.
    if (head)
    {
        while (head->next)
        {
            len++;
            head = head->next;
        }
    }
    else
    {
        len = 0;// if the list is empty return 0.
    }
    return len;
}

/*
This function deletes a node in the list.
input - the adress of pointer to the list and the index of the node we want to delete.
output - none
*/
void delete(ListNode** head, int delIndex)
{
    ListNode* p = *head;
    ListNode* del = NULL;
    int i = 0;

    if (*head)
    {
        if (i == delIndex - 1)
        {
            *head = p->next;

            free(p);
            p = NULL;
        }

        else if (p->next != NULL)
        {
            while (i < delIndex - 2)
            {
                p = p->next;
                i++;
            }
            del = p->next;
            p->next = del->next;

            free(del);
            del = NULL;
        }
    }
}

/*
This function finds a value in the list and prints it's index.
input - the adress of the head node in the list and the number we want to find.
output - Pointer to the index where the value is stored in the list, if its empty then NULL and if it isn't found NULL.
*/
ListNode* find(ListNode* head, int value)
{
    int index = 0;
    int i = 0;
    int len = 0;
    ListNode* p = head;

    len = length(head);

    if (head)//checks if the list is empty, if it isnt goes in.
    {
        while (p->num != value && index < len)
        {
            index++;
            p = p->next;
            if (p == NULL)
            {
                return p;
            }
        }
    }
    else
    {
        p = NULL;
    }
    
    return p;
}