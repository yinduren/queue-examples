#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

typedef struct animal_ {
    CIRCLEQ_ENTRY(animal_) link;
    char name[32];
} animal;


CIRCLEQ_HEAD(animal_head_, animal_);
typedef struct animal_head_ animal_head;

int main() {
    /* Create empty circle queue */
    animal_head bird_circle_queue;
    CIRCLEQ_INIT(&bird_circle_queue);

    if (CIRCLEQ_EMPTY(&bird_circle_queue)) {
        printf("There is not any bird in the circle queue\n");
        printf("\n");
    }

    /* 1. Insert an item at circle queue's head*/
    char *duck_name = "duck";
    animal duck;
    memcpy(&duck.name, duck_name, strlen(duck_name) + 1);
    printf("Insert head %s\n", duck.name);
    CIRCLEQ_INSERT_HEAD(&bird_circle_queue, &duck, link);

    /* Show every item in circle queue */
    animal *bird = NULL;
    CIRCLEQ_FOREACH(bird, &bird_circle_queue, link)
        printf("bird name is %s\n", bird->name);
    printf("\n");

    /* 2. Insert an item after another item in the circle queue */
    char *chicken_name = "chicken";
    animal chicken;
    memcpy(&chicken.name, chicken_name, strlen(chicken_name) + 1);
    printf("Insert %s after %s\n", chicken.name, duck.name);
    CIRCLEQ_INSERT_AFTER(&bird_circle_queue, &duck, &chicken, link);

    /* Show every item in circle queue */
    bird = NULL;
    CIRCLEQ_FOREACH(bird, &bird_circle_queue, link)
        printf("bird name is %s\n", bird->name);
    printf("\n");

    /* 3. Insert an item before another item in the circle queue */
    char *goose_name = "goose";
    animal goose;
    memcpy(&goose.name, goose_name, strlen(goose_name) + 1);
    printf("Insert %s before %s\n", goose.name, chicken.name);
    CIRCLEQ_INSERT_BEFORE(&bird_circle_queue, &chicken, &goose, link);

    /* Show every item in circle queue */
    bird = NULL;
    CIRCLEQ_FOREACH(bird, &bird_circle_queue, link)
        printf("bird name is %s\n", bird->name);
    printf("\n");

    /* 4. Insert an item at the head of the circle queue */
    char *hen_name = "hen";
    animal hen;
    memcpy(&hen.name, hen_name, strlen(hen_name) + 1);
    printf("Insert %s at the head of the circle queue\n", hen.name);
    CIRCLEQ_INSERT_HEAD(&bird_circle_queue, &hen, link);

    /* Show every item in circle queue */
    bird = NULL;
    CIRCLEQ_FOREACH(bird, &bird_circle_queue, link)
        printf("bird name is %s\n", bird->name);
    printf("\n");

    /* 5. Insert an item at the tail of the circle queue */
    char *eagle_name = "eagle";
    animal eagle;
    memcpy(&eagle.name, eagle_name, strlen(eagle_name) + 1);
    printf("Insert %s at the tail of the circle queue\n", eagle.name);
    CIRCLEQ_INSERT_TAIL(&bird_circle_queue, &eagle, link);

    /* Show every item in circle queue */
    bird = NULL;
    CIRCLEQ_FOREACH(bird, &bird_circle_queue, link)
        printf("bird name is %s\n", bird->name);
    printf("\n");

    /* 6. The first item in the circle queue */
    bird = NULL;
    bird = CIRCLEQ_FIRST(&bird_circle_queue);
    if (bird != NULL) {
        printf("The first bird in the circle queue is %s\n", bird->name);
    } else {
        printf("The circle queue is empty, no first bird found\n");
    }
    printf("\n");

    /* 7. The last item in the circle queue */
    bird = NULL;
    bird = CIRCLEQ_LAST(&bird_circle_queue);
    if (bird != NULL) {
        printf("The last bird in the circle queue is %s\n", bird->name);
    } else {
        printf("The circle queue is empty, no last bird found\n");
    }
    printf("\n");

    /* 8. The next item of the specified item in the circle queue */
    bird = NULL;
    bird = CIRCLEQ_NEXT(&goose, link);
    if (bird != NULL) {
        printf("The next bird of %s, is %s\n", goose.name, bird->name);
    } else {
        printf("The next bird of %s is NULL\n", goose.name);
    }
    printf("\n");

    /* 9. The pre item of the specified item in the circle queue */
    bird = NULL;
    bird = CIRCLEQ_PREV(&goose, link);
    if (bird != NULL) {
        printf("The prev bird of %s, is %s\n", goose.name, bird->name);
    } else {
        printf("The prev bird of %s is NULL\n", goose.name);
    }
    printf("\n");

    /* 10. Remove an item in the circle queue */
    CIRCLEQ_REMOVE(&bird_circle_queue, &goose, link);
    printf("Remve %s from circle queue\n", goose.name);

    /* Show every item in circle queue */
    bird = NULL;
    CIRCLEQ_FOREACH(bird, &bird_circle_queue, link)
        printf("bird name is %s\n", bird->name);
    printf("\n");

    /* 11. If circle queue is empty */
    if (CIRCLEQ_EMPTY(&bird_circle_queue)) {
        printf("The bird circle queue is empty\n");
    } else {
        printf("The bird circle queue is not empty\n");
    }
    printf("\n");

    /* 12. Show every item in circle queue reverse */
    printf("The birds in circle queue reverse order:\n");
    bird = NULL;
    CIRCLEQ_FOREACH_REVERSE(bird, &bird_circle_queue, link)
        printf("bird name is %s\n", bird->name);
    printf("\n");

    return 0;
}
