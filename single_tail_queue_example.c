#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

typedef struct animal_ {
    STAILQ_ENTRY(animal_) link;
    char name[32];
} animal;


STAILQ_HEAD(animal_head_, animal_);
typedef struct animal_head_ animal_head;

int main() {
    /* Create empty single tail queue */
    animal_head bird_stailq;
    STAILQ_INIT(&bird_stailq);

    if (STAILQ_EMPTY(&bird_stailq)) {
        printf("There is not any bird in the single tail queue\n");
        printf("\n");
    }

    /* 1. Insert an item at single tail queue's head*/
    char *duck_name = "duck";
    animal duck;
    memcpy(&duck.name, duck_name, sizeof(duck_name));
    printf("Insert head %s\n", duck.name);
    STAILQ_INSERT_HEAD(&bird_stailq, &duck, link);

    /* Show every item in single tail queue */
    animal *bird = NULL;
    STAILQ_FOREACH(bird, &bird_stailq, link)
        printf("bird name is %s\n", bird->name);
    printf("\n");

    /* 2. Insert an item at single tail queue's tail*/
    char *sparrow_name = "sparrow";
    animal sparrow;
    memcpy(&sparrow.name, sparrow_name, sizeof(sparrow_name));
    printf("Insert tail %s\n", sparrow.name);
    STAILQ_INSERT_TAIL(&bird_stailq, &sparrow, link);

    /* Show every item in single tail queue */
    bird = NULL;
    STAILQ_FOREACH(bird, &bird_stailq, link)
        printf("bird name is %s\n", bird->name);
    printf("\n");

    /* 3. Insert an item after another item in the single tail queue */
    char *chicken_name = "chicken";
    animal chicken;
    memcpy(&chicken.name, chicken_name, sizeof(chicken_name));
    printf("Insert %s after %s\n", chicken.name, duck.name);
    STAILQ_INSERT_AFTER(&bird_stailq, &duck, &chicken, link);

    /* Show every item in single tail queue */
    bird = NULL;
    STAILQ_FOREACH(bird, &bird_stailq, link)
        printf("bird name is %s\n", bird->name);
    printf("\n");

    /* 4. The first item in the single tail queue */
    bird = NULL;
    bird = STAILQ_FIRST(&bird_stailq);
    printf("The first bird in the single tail queue is %s\n", bird->name);
    printf("\n");

    /* 5. The next item of the specified item in the single tail queue */
    bird = NULL;
    bird = STAILQ_NEXT(&chicken, link);
    printf("The next bird of %s, is %s\n", chicken.name, bird->name);
    printf("\n");

    /* 6. Remove the head item in the single tail queue */
    STAILQ_REMOVE_HEAD(&bird_stailq, link);
    printf("Remve the head item in the single tail queue\n");

    /* Show every item in single tail queue */
    bird = NULL;
    STAILQ_FOREACH(bird, &bird_stailq, link)
        printf("bird name is %s\n", bird->name);
    printf("\n");

    /* 7. Remove an item in the single tail queue */
    STAILQ_REMOVE(&bird_stailq, &sparrow, animal_, link);
    printf("Remve %s from single tail queue\n", sparrow.name);

    /* Show every item in single tail queue */
    bird = NULL;
    STAILQ_FOREACH(bird, &bird_stailq, link)
        printf("bird name is %s\n", bird->name);
    printf("\n");

    /* 8. If  single tail queue is empty */
    if (STAILQ_EMPTY(&bird_stailq)) {
        printf("The bird single tail queue is empty\n");
    } else {
        printf("The bird single tail queue is not empty\n");
    }
    printf("\n");

    return 0;
}
