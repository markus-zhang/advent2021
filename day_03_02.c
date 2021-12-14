#include "stdio.h"
#include "string.h"
#include "math.h"
#include <stdlib.h>

typedef struct node {
    int count;
    struct node* zero;
    struct node* one;
} node;

void processLine(const char* line, int* countOne);
void updateTree(const char* line, int lineIndex, node* parentNode);
int getLifeSupportRating(const node* root);

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        printf("Usage: day_02_01 textfilename");
        return -1;
    }

    char const* const fileName = argv[1];
    FILE* file = fopen(fileName, "r");
    char line[16];
    // countOne records the number of 1s
    int countOne[12] = {0};
    int count = 0;
    int gamma = 0;
    int epsilon = 0;

    node* root = (node*)malloc(sizeof(node));
    root->count = 0;
    root->one = NULL;
    root->zero = NULL;

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;
        updateTree(line, 0, root);
        count++;
    }

    // printf("root zero: %d, root one: %d\n", root->zero->count, root->one->count);
    getLifeSupportRating(root);

    return 0;
}

void processLine(const char* line, int* countOne) {
    for (int i = 0; i < 12; i++) {
        if (line[i] == '1') {
            countOne[i] += 1;
        }
    }
}

void updateTree(const char* line, int lineIndex, node* parentNode) {
    if (line[lineIndex] == '\0') {
        return;
    }
    if (parentNode->zero == NULL) {
        node* zeroChild = (node*)malloc(sizeof(node));
        zeroChild->count = 0;
        zeroChild->one = NULL;
        zeroChild->zero = NULL;
        parentNode->zero = zeroChild;
    }

    if (parentNode->one == NULL) {
        node* oneChild = (node*)malloc(sizeof(node));
        oneChild->count = 0;
        oneChild->one = NULL;
        oneChild->zero = NULL;
        parentNode->one = oneChild;
    }

    if (line[lineIndex] == '0') {
        parentNode->zero->count++;
        lineIndex++;
        updateTree(line, lineIndex, parentNode->zero);
    }
    else {
        parentNode->one->count++;
        lineIndex++;
        updateTree(line, lineIndex, parentNode->one);
    }
}

int getLifeSupportRating(const node* root) {
    int oxygenRating = 0;
    int scrubberRating = 0;
    int count = 0;

    node* walker = root;

    for (int i = 0; i < 12; i++) {
        if (walker->one->count >= walker->zero->count) {
            // oxygen rating
            oxygenRating += pow(2, 12 - i);
            walker = walker->one;
            printf("1");
        }
        else {
            walker = walker->zero;
            printf("0");
        }
    }
    walker = root;
    printf("\n");

    for (int i = 0; i < 12; i++) {
        if (walker->one->count < walker->zero->count) {
            // oxygen rating
            scrubberRating += pow(2, 12 - i);
            walker = walker->one;
            printf("1");
            getchar();
        }
        else {
            walker = walker->zero;
            printf("0");
            getchar();
        }
    }

    printf("Result: %d", oxygenRating * scrubberRating);

    return oxygenRating * scrubberRating;
}