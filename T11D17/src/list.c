#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

// #include "door_struct.h"

struct door {
    int id;
    int status;
};

struct node {
    struct door *door;
    struct node *next;
};

struct node *init(struct door *door);
struct node *add_door(struct node *elem, struct door *door);
struct node *find_door(int door_id, struct node *root);
struct node *removd_door(struct node *elem, struct node *root);
void destroy(struct node *root);

int main(void) {
    struct door doors[DOORS_COUNT];
    struct door door_init;

    struct node *iter = root;
    while (iter != NULL) {
        printf("%d ", iter->door->id);
        iter = iter->next;
    }

    return 0;
}

struct node *init(struct door *door) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->door = door;
    newNode->next = NULL;
    return newNode;
}