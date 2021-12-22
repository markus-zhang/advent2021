/*
    So we want to minimize SUM[(X-Xi)^2].
    Using Calculus, X = AVG(Xi)
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        printf("Usage: day_07_01 textfilename");
        return -1;
    }

    char const* const fileName = argv[1];
    FILE* file = fopen(fileName, "r");
    char firstLine[65536];
    fgets(firstLine, sizeof(firstLine), file);
    fclose(file);

    int count = 0;
    int number[1024];

    char* token = strtok(firstLine, ",");
    int n = atoi(token);
    number[0] = n;
    count++;

    while (token != NULL) {
        token = strtok(NULL, ",");
        if (token != NULL) {
            n = atoi(token);
            number[count] = number;
            count++;
            // printf("%d, ", number);
        }
    }
    // printf("\n");

    return 0;
}