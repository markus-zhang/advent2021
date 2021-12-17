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
int countFishes(fishNode* head, fishNode* tail, int generation, int count) {
    fishNode* walker = head;
    int count = count;
    while (1) {
        /*
            Change values and spawn new nodes after tail if necessary.
            Don't forget to use a pointer to memorize the last spawned node,
            because that pointer would be the tail for next recursion
        */
        if (walker->value == 0) {
            if (walker == head) {
                // Only the head node has 6 as max value
                
            }
        }
        if (walker == tail) {
            break;
        }
        walker++;
    }
    
    
    generation++;
    if (generation == 80) {
        return count;
    }
    else {
        countFishes(head, newTail, generation, count);
    }
} 

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
}
