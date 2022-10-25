#include <stdio.h>
#include <stdlib.h>


typedef struct listNode
{
    int num;
    struct listNode* next;
} listNode;


listNode* createNode(int num);
void insert(listNode** head, listNode* newNode);
void print(listNode* head);
int length(listNode* head);
void delete(listNode** head, int delIndex);
void find(listNode* head, int number);



int main()
{
    
    listNode* newNode = NULL;
    listNode* first = NULL;

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
        insert(&first, newNode);
    }

    print(first);

    printf("which node to delete?\n");
    scanf("%d", &delIndex);
    getchar();

    delete(&first, delIndex);
    print(first);

    printf("which num to find?\n");
    scanf("%d", &numToFind);
    find(first, numToFind);

    getchar();
    return 0;
}

/*
This function prints the linked list 
input - the adress of the first node in the list.
output - none
*/
void print(listNode* head)
{
    listNode* curr = head;
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
listNode* createNode(int num)
{
    listNode* newlistNode = (listNode*)malloc(sizeof(listNode));
    newlistNode->num = num;
    newlistNode->next = NULL;
    return newlistNode;
}

/*
This function inserts the node into the list.
input - the adress of the pointer to the list and the new node you want to insert.
output - none
*/
void insert(listNode** head, listNode* newNode)
{
    if (!*head)//if head is NULL
    {
        *head = newNode;
    }
    else
    {
        listNode* p = *head;
        while (p->next)
        {
            p = p->next;
        }
        p->next = newNode;
    }
}

/*
This function calculates the length of the list
input - the adress of the first node in the list.
output - the length of the list.
*/
int length(listNode* head)
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
void delete(listNode** head, int delIndex)
{
    listNode* p = *head;
    listNode* del = NULL;
    int i = 1;
    if (*head)
    {
        if (i == delIndex)
        {
            *head = p->next;

            free(p);
            p = NULL;
        }

        else if (p->next)
        {
            while (i < delIndex - 1)
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
input - the adress of the first node in the list and the number we want to find.
output - none
*/
void find(listNode* head, int number)
{
    int index = 1;
    int i = 1;
    int len = 0;

    len = length(head);

    if (head)
    {
        for (i = 1; i < len; i++)
        {
            if (head->num == number)
            {
                printf("the number %d is at index : %d\n", number, index);

                return;
            }
            else if (head->next->num == number)
            {
                index++;
                printf("the number %d is at index : %d\n", number, index);

                return;
            }
            else
            {
                head = head->next;
                index++;
            }
        }
        printf("the number %d doesn't exit in the linked list.\n", number);
    }
    else
    {
        printf("list is empty\n");
    }
    return;
}
