#include <stdio.h>
#include <stdlib.h>

// #include "door_struct.h"

struct node {
    int data;
    struct node *next;
};

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
