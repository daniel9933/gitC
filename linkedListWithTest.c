#include <stdio.h>
#include <stdlib.h>


typedef struct listNode
{
    int num;
    struct listNode* next;
} listNode;


//test functions:
void Print_empty_list_should_not_fail_and_print_length_0();
void add_one_and_remove_one_then_add_another_one_and_print();
void add_three_elements_try_to_find_each();
void add_three_verify_len_is_3();
void add_3_remove_from_each_spot();


listNode* createNode(int num);
void insert(listNode** head, listNode* newNode);
void print(listNode* head);
int length(listNode* head);
void delete(listNode** head, int delIndex);
void find(listNode* head, int number);



int main()
{
    Print_empty_list_should_not_fail_and_print_length_0();

    add_one_and_remove_one_then_add_another_one_and_print();

    add_three_elements_try_to_find_each();

    add_three_verify_len_is_3();

    add_3_remove_from_each_spot();
    return 0;
}

void Print_empty_list_should_not_fail_and_print_length_0()
{
    // 1. Print empty list should not fail and print length 0 // success
    // 2. add one and remove one then add another one and print //success
    // 3. add 3 elements and try to find 1st , 2nd and 3rd element//success
    // 4. add 3 and verify list length return 3//success
    // 5. add 3 remove middle //success
    // 6. add 3 remove 1st //success
    // 7. add 3 remove last //success

    listNode* newNode = NULL;
    listNode* first = NULL;
    int len = 0;

    len = length(first);

    print(first);
    printf("lenght of the list is: %d\n", len);


}

void add_one_and_remove_one_then_add_another_one_and_print()
{
    listNode* newNode = NULL;
    listNode* first = NULL;

    newNode = createNode(1);//create new node 
    insert(&first, newNode);

    delete(&first, 1);//delete it 

    newNode = createNode(2);//create another node
    insert(&first, newNode);

    print(first);//print the list.
}

void add_three_elements_try_to_find_each()
{
    listNode* newNode = NULL;
    listNode* first = NULL;

    newNode = createNode(3);
    insert(&first, newNode);

    newNode = createNode(1);
    insert(&first, newNode);

    newNode = createNode(2);
    insert(&first, newNode);

    print(first);

    find(first, 1);
    find(first, 2);
    find(first, 3);
}

void add_three_verify_len_is_3()
{
    listNode* newNode = NULL;
    listNode* first = NULL;
    int len = 0;

    newNode = createNode(1);
    insert(&first, newNode);

    newNode = createNode(2);
    insert(&first, newNode);

    newNode = createNode(3);
    insert(&first, newNode);

    len = length(first);

    printf("\nthe lenght of this list is: %d\n", len);

}

void add_3_remove_from_each_spot()
{
    listNode* newNode = NULL;
    listNode* first = NULL;

    newNode = createNode(1);
    insert(&first, newNode);

    newNode = createNode(2);
    insert(&first, newNode);

    newNode = createNode(3);
    insert(&first, newNode);


//from the start.
    print(first);//print the list before the removal.
    delete(&first, 1);//delete from the start.
    print(first);//print the list after the removal.

//from the middle.
    newNode = createNode(4);//add a node back
    insert(&first, newNode);
    print(first);//print the list before the removal.
    delete(&first, 2);//delete from the middle.
    print(first);//print the list after the removal.

//from the end.
    newNode = createNode(5);//add a node back
    insert(&first, newNode);
    print(first);//print the list before the removal.
    delete(&first, 3);//delete from the end.
    print(first); //print the list after the removal.
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