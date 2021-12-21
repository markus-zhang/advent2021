#include "stdio.h"
#include "string.h"
#include "math.h"
#include <stdlib.h>
#include <stdbool.h>

/*
    If we have two fish 1,
    we would have exactly twice the number of fishes
    comparing to having one fish 1 from the beginning.

    So we just need to get a statistics of how many 0, 1,
    2, .... in the list and do multiplication.
*/

typedef struct fishNode {
    struct fishNode* next;
    int value;
} fishNode;

// For a fish of initialValue, how many after N generation?
int countFishes(fishNode* head, fishNode* tail, int generation, int prevCount);

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        printf("Usage: day_06_01 textfilename");
        return -1;
    }

    char const* const fileName = argv[1];
    FILE* file = fopen(fileName, "r");
    char firstLine[1024];
    char line[16];

    // Grab the first line
    fgets(firstLine, sizeof(firstLine), file);
    firstLine[strcspn(firstLine, "\n")] = 0;

    char* token = strtok(firstLine, ",");
    int number = atoi(token);

    // Hack...
    int one = 0;
    int two = 0;
    int three = 0;
    int four = 0;
    int five = 0;
    int six = 0;
    one++;  // We know first number is 1

    /*
    while (token != NULL) {
        token = strtok(NULL, ",");
        if (token != NULL) {
            number = atoi(token);
            // I bet I'm the only guy who write this LOL
            // Treating C programs as scripts and then manually calculate the result
            switch (number) {
            case 1:
                one++;
                break;
            case 2:
                two++;
                break;
            case 3:
                three++;
                break;
            case 4:
                four++;
                break;
            case 5:
                five++;
                break;
            case 6:
                six++;
                break;
            default:
                break;
            }
        }
    }
    printf("One: %d\n", one);
    printf("Two: %d\n", two);
    printf("Three: %d\n", three);
    printf("Four: %d\n", four);
    printf("Five: %d\n", five);
    printf("Six: %d\n", six);

    return 0;
    */

    // Test for a 1-day fish
    fishNode* fn = (fishNode*)malloc(sizeof(fishNode));
    fn->value = 5;
    fn->next = NULL;
    fishNode* head = fn;
    fishNode* tail = fn;
    int fishCount = countFishes(head, tail, 0, 1);
    printf("Fish count: %d\n", fishCount);

    // Free linked list
    fishNode* walkerBehind = head;
    fishNode* walkerFront = head;
    while (walkerFront != NULL) {
        walkerFront = walkerFront->next;
        free(walkerBehind);
        walkerBehind = walkerFront;
    }

}

int countFishes(fishNode* head, fishNode* tail, int generation, int prevCount) {
    fishNode* walker = head;
    fishNode* originalTail = tail;
    int count = prevCount;
    while (1) {
        /*
            Change values and spawn new nodes after tail if necessary.
            Don't forget to update tail.
        */
        if (walker->value == 0) {
            fishNode* node = (fishNode*)malloc(sizeof(fishNode));
            node->next = NULL;
            node->value = 8;

            walker->value = 6;

            /* if (walker == head) {
                // Only the old nodes has 6 as max value
                walker->value = 6;                
            }
            else {
                walker->value = 8;
            } */
            tail->next = node;
            tail = node;
            // printf("New node added\n");
            count++;
        }
        else {
            walker->value--;
        }
        if (walker == originalTail) {
            break;
        }
        else {
            walker = walker->next;
        }
    }
    // All element looped through means the end of a generation   
    generation++;
    if (generation == 80) {
        return count;
    }
    else {
        return countFishes(head, tail, generation, count);
    }
} 