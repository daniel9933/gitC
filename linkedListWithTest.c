#include <stdio.h>
#include <stdlib.h>


#define ASSERT(condition)  {\
        if (!condition){\
            return 1;\
        };\
}
#define test(testName, functionname) {\
    int res = functionname(); \
    if (res != 0) { \
        printf("FAIL: %s",testName);\
        return res;\
    }\
    printf("SUCCESS: %s",testName);\
    printf("\n");\
}

typedef struct ListNode
{
    int num;
    struct ListNode* next;
} ListNode;


//test functions:
int  test_print_empty_list_should_not_fail_and_print_length_0();
void test_add_one_and_delete_one_then_add_another_one_and_print();
void test_add_three_elements_try_to_find_each();
void test_add_three_verify_len_is_3();
void test_add_3_delete_from_each_spot();


ListNode* createNode(int value);
void insert(ListNode** head, ListNode* newNode);
void print(ListNode* head);
int length(ListNode* head);
void delete(ListNode** head, int delIndex);
ListNode* find(ListNode* head, int value);



int main()
{
    test("Length should be 0",test_print_empty_list_should_not_fail_and_print_length_0);

    test_add_one_and_delete_one_then_add_another_one_and_print();

    test_add_three_elements_try_to_find_each();

    test_add_three_verify_len_is_3();

    test_add_3_delete_from_each_spot();
    return 0;
}

int print_empty_list_should_not_fail_and_print_length_0()
{
    // 1. Print empty list should not fail and print length 0 // success
    // 2. add one and delete one then add another one and print //success
    // 3. add 3 elements and try to find 1st , 2nd and 3rd element//success
    // 4. add 3 and verify list length return 3//success
    // 5. add 3 delete middle //success
    // 6. add 3 delete 1st //success
    // 7. add 3 delete last //success

    ListNode* newNode = NULL;
    ListNode* head = NULL;
    int len = 0;

    len = length(head);

    print(head);
    ASSERT(len == 0);
    return 0;
}

void add_one_and_delete_one_then_add_another_one_and_print()
{
    ListNode* newNode = NULL;
    ListNode* head = NULL;

    newNode = createNode(1);//create new node
    insert(&head, newNode);

    delete(&head, 1);//delete it

    newNode = createNode(2);//create another node
    insert(&head, newNode);

    print(head);//print the list.
}

void add_three_elements_try_to_find_each()
{
    ListNode* newNode = NULL;
    ListNode* head = NULL;

    newNode = createNode(3);
    insert(&head, newNode);

    newNode = createNode(1);
    insert(&head, newNode);

    newNode = createNode(2);
    insert(&head, newNode);

    print(head);

    find(head, 1);
    find(head, 2);
    find(head, 3);
}

void add_three_verify_len_is_3()
{
    ListNode* newNode = NULL;
    ListNode* head = NULL;
    int len = 0;

    newNode = createNode(1);
    insert(&head, newNode);

    newNode = createNode(2);
    insert(&head, newNode);

    newNode = createNode(3);
    insert(&head, newNode);

    len = length(head);

    printf("\nthe lenght of this list is: %d\n", len);

}

void add_3_delete_from_each_spot()
{
    ListNode* newNode = NULL;
    ListNode* head = NULL;

    newNode = createNode(1);
    insert(&head, newNode);

    newNode = createNode(2);
    insert(&head, newNode);

    newNode = createNode(3);
    insert(&head, newNode);


//from the start.
    print(head);//print the list before the removal.
    delete(&head, 1);//delete from the start.
    print(head);//print the list after the removal.

//from the middle.
    newNode = createNode(4);//add a node back
    insert(&head, newNode);
    print(head);//print the list before the removal.
    delete(&head, 2);//delete from the middle.
    print(head);//print the list after the removal.

//from the end.
    newNode = createNode(5);//add a node back
    insert(&head, newNode);
    print(head);//print the list before the removal.
    delete(&head, 3);//delete from the end.
    print(head); //print the list after the removal.
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
ListNode* createNode(int value)
{
    ListNode* newListNode = (ListNode*)malloc(sizeof(ListNode));
    newListNode->num = value;
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
//TODO: change the function.
void delete(ListNode** head, int delIndex)
{
    ListNode* p = *head;
    ListNode* del = NULL;
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
input - the adress of the head node in the list and the number we want to find.
output - none
*/
//TODO: shorten the function.
ListNode* find(ListNode* head, int value)
{
    int index = 1;
    int i = 1;
    int len = 0;
    ListNode* p = head;

    len = length(head);

    if (head)
    {
        for (i = 1; i < len; i++)
        {
            if (head->num == value)
            {
                printf("the number %d is at index : %d\n", value, index);

                return;
            }
            else if (head->next->num == value)
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
        printf("the number %d doesn't exit in the linked list.\n", value);
    }
    else
    {
        printf("list is empty\n");
    }
    return ;
}
