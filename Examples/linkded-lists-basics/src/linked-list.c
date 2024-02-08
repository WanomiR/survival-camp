#include <stdio.h>
#include <stdlib.h>

// #include "door_struct.h"

struct node {
    int data;
    struct node *next;
};

struct node *CopyListRecursice(struct node *head);
struct node *CopyListDummy(struct node *head);
struct node *CopyList2(struct node *head);
struct node *CopyList(struct node *head);
struct node *AppendNodePush(struct node **headRef, int num);
struct node *AppendNode(struct node **headRef, int num);
void PushTest(void);
void Push(struct node **headRef, int data);
void LinkTest(void);
void LengthTest(void);
int Length(struct node *head);
struct node *BuildOneTwoThree(void);

int main(void) {
    PushTest();
    return 0;
}

// Recursive variant
struct node *CopyListRecursice(struct node *head) {
    if (head == NULL)
        return NULL;
    else {
        struct node *newList = malloc(sizeof(struct node));
        newList->data = current->data;
        // make the one node
        newList->next = CopyList(current->next);  // recur for the rest
        return (newList);
    }
}
// Dummy node variant
struct node *CopyListDummy(struct node *head) {
    struct node *current = head;  // used to iterate over the original list
    struct node *tail;
    struct node dummy;
    dummy.next = NULL;
    tail = &dummy;
    // kept pointing to the last node in the new list
    // build the new list off this dummy node
    // start the tail pointing at the dummy
    while (current != NULL) {
        Push(&(tail->next), current->data);  // add each node at the tail
        tail = tail->next;                   // advance the tail to the new last node
        current = current->next;
    }
    return (dummy.next);
}

// Variant of CopyList() that uses Push()
struct node *CopyList2(struct node *head) {
    struct node *current = head;  // used to iterate over the original list
    struct node *newList = NULL;  // head of the new list
    struct node *tail = NULL;     // kept pointing to the last node in the new list
    while (current != NULL) {
        if (newList == NULL) {  // special case for the first new node
            Push(&newList, current->data);
            tail = newList;
        } else {
            Push(&(tail->next), current->data);  // add each node at the tail
            tail = tail->next;                   // advance the tail to the new last node
        }
        current = current->next;
    }
    return (newList);
}

struct node *CopyList(struct node *head) {
    struct node *current = head;  // used to iterate over the original list
    struct node *newList = NULL;  // head of the new list
    struct node *tail = NULL;     // kept pointing to the last node in the new list
    while (current != NULL) {
        if (newList == NULL) {  // special case for the first new node
            newList = malloc(sizeof(struct node));
            newList->data = current->data;
            newList->next = NULL;
            tail = newList;
        } else {
            tail->next = malloc(sizeof(struct node));
            tail = tail->next;
            tail->data = current->data;
            tail->next = NULL;
        }
        current = current->next;
    }
    return (newList);
}

struct node *AppendNodePush(struct node **headRef, int num) {
    struct node *current = *headRef;
    // special case for the empty list
    if (current == NULL) {
        Push(headRef, num);
    } else {
        // Locate the last node
        while (current->next != NULL) {
            current = current->next;
        }
        // Build the node after the last node
        Push(&(current->next), num);
    }
    22
}

struct node *AppendNode(struct node **headRef, int num) {
    struct node *current = *headRef;
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = num;
    newNode->next = NULL;
    // special case for length 0
    if (current == NULL) {
        *headRef = newNode;
    } else {
        // Locate the last node
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void PushTest(void) {
    struct node *head = BuildOneTwoThree();

    Push(&head, 1);
    Push(&head, 13);

    // struct node *current = head;
    // while (current != NULL) {
    //     printf("%d\n", current->data);
    //     current = current->next;
    // }

    for (struct node *current = head; current; current = current->next) {
        printf("%d\n", current->data);
    }
}

void Push(struct node **headRef, int data) {
    struct node *newNode = malloc(sizeof(struct node));

    newNode->data = data;
    newNode->next = *headRef;
    *headRef = newNode;
}

void LinkTest(void) {
    struct node *head = BuildOneTwoThree();
    struct node *newNode;

    newNode = malloc(sizeof(struct node));
    newNode->data = 1;
    newNode->next = head;

    head = newNode;
}

void LengthTest() {
    struct node *myList = BuildOneTwoThree();
    int len = Length(myList);
    printf("%d", len);
}

int Length(struct node *head) {
    struct node *current = head;
    int count = 0;

    while (current != NULL) {
        count++;
        current = current->next;
    }
    /*
    When the function exits, current is automatically deallocated since it is just an ordinary local, but the
    nodes in the heap remain.
    */

    return count;
}

struct node *BuildOneTwoThree(void) {
    struct node *head = NULL;
    struct node *second = NULL;
    struct node *third = NULL;

    head = malloc(sizeof(struct node));
    second = malloc(sizeof(struct node));
    third = malloc(sizeof(struct node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    return head;
};
