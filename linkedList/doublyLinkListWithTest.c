/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

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
    struct ListNode* prev;

} ListNode;


//test functions:
int  test_print_empty_list_should_not_fail_and_print_length_0();
void test_add_one_and_delete_one_then_add_another_one_and_print();
void test_add_three_elements_try_to_find_each();
void test_add_three_verify_len_is_3();
void test_add_3_delete_from_each_spot();
void test_from_end_go_back_and_find_first_node();


ListNode* createNode(int value);
void insert(ListNode** head, ListNode* newNode);
void print(ListNode* head);
int length(ListNode* head);
void delete(ListNode** head, int delIndex);
ListNode* find(ListNode* head, int value);



int main()
{
    test("Length should be 0", test_print_empty_list_should_not_fail_and_print_length_0);

    test_add_one_and_delete_one_then_add_another_one_and_print();

    test_add_three_elements_try_to_find_each();

    test_add_three_verify_len_is_3();

    test_add_3_delete_from_each_spot();

    test_from_end_go_back_and_find_first_node();
    return 0;
}

int test_print_empty_list_should_not_fail_and_print_length_0()
{
    // 1. Print empty list should not fail and print length 0 // success
    // 2. add one and delete one then add another one and print //success
    // 3. add 3 elements and try to find 1st , 2nd and 3rd element//success
    // 4. add 3 and verify list length return 3//success
    // 5. add 3 delete middle //success
    // 6. add 3 delete 1st //success
    // 7. add 3 delete last //success
    // 8. go to end and then back to the begging // success

    ListNode* newNode = NULL;
    ListNode* head = NULL;
    int len = 0;

    len = length(head);

    print(head);
    ASSERT(len == 0);
    return 0;
}

void test_add_one_and_delete_one_then_add_another_one_and_print()
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

void test_add_three_elements_try_to_find_each()
{
    ListNode* newNode = NULL;
    ListNode* head = NULL;
    ListNode* index = NULL;

    newNode = createNode(3);
    insert(&head, newNode);

    newNode = createNode(1);
    insert(&head, newNode);

    newNode = createNode(2);
    insert(&head, newNode);

    print(head);

	if((index = find(head, 4))!= NULL)	
    {	
        printf("value was found, it is : %d\n", index->num);	
    }	
    else if ((index = find(head, 4)) == NULL)	
    {	
        printf("value wasn't found or the list is empty.\n");	
    }	


    if((index = find(head, 3))!= NULL)	
    {	
        printf("value was found, it is : %d\n", index->num);	
    }	
    else if ((index = find(head, 3)) == NULL)	
    {	
        printf("value wasn't found or the list is empty.\n");	
    }
}

void test_add_three_verify_len_is_3()
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

void test_add_3_delete_from_each_spot()
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

void test_from_end_go_back_and_find_first_node()
{
    ListNode* newNode = NULL;
    ListNode* head = NULL;

    newNode = createNode(1);
    insert(&head, newNode);

    newNode = createNode(2);
    insert(&head, newNode);

    newNode = createNode(3);
    insert(&head, newNode);

    newNode = createNode(4);
    insert(&head, newNode);


    print(head);
    while (head->next)
    {
        printf("%d ", head->num);
        head = head->next;
    }
    printf("\n");
    while (head->prev)
    {
        head = head->prev;
        printf("%d ", head->num);
    }

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
    newListNode->prev = NULL;
    return newListNode;
}

/*
This function inserts the node into the list.
input - the adress of the pointer to the list and the new node you want to insert.
output - none
*/
//TODO: make last function and change this one.
void insert(ListNode** head, ListNode* newNode)
{
    ListNode* p = *head;
    ListNode* temp = *head;

    if (!*head)//if head is NULL
    {
        *head = newNode;
    }

    else
    {
        while (p->next)
        {
            p = p->next;
        }
        p->next = newNode;
    }

    p = *head;
    while(p->next)
    {
        p = p->next;
        p->prev = temp;
        temp = temp->next;
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
output - none
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
