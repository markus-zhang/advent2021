/*
    So we want to minimize SUM[(X-Xi)].
    Using Calculus, X = AVG(Xi)
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

int calcTotalFuel(const int crab[], int count, int center);
int calcIndividualFuel(int diff);

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        printf("Usage: day_07_01 textfilename");
        return -1;
    }

    char const* const fileName = argv[1];
    FILE* file = fopen(fileName, "r");
    char firstLine[65536];
    int crab[1000];
    fgets(firstLine, sizeof(firstLine), file);
    fclose(file);

    int count = 0;
    int sum = 0;
    int max = 0;
    int min = 0;

    char* token = strtok(firstLine, ",");
    int n = atoi(token);
    crab[0] = n;
    sum += n;
    count++;
    max = n;
    min = n;

    while (token != NULL) {
        token = strtok(NULL, ",");
        if (token != NULL) {
            n = atoi(token);
            crab[count] = n;
            count++;
            sum += n;
            if (min > n) {
                min = n;
            }
            if (max < n) {
                max = n;
            }
        }
    }
    printf("Sum: %d, Count: %d, Min: %d, Max: %d\n", sum, count, min, max);

    int minFuel = INT32_MAX;
    int position = 0;
    for (int i = min; i <= max; i++) {
        int fuel = calcTotalFuel(crab, count, i);
        if (minFuel > fuel) {
            minFuel = fuel;
            position = i;
        }
    }

    printf("Min Fuel spent: %d at position %d\n", minFuel, position);

    return 0;
}

int calcTotalFuel(const int crab[], int count, int center) {
    int sumFuel = 0;
    for (int i = 0; i < count; i++) {
        sumFuel += calcIndividualFuel(abs(crab[i] - center));
    }
    return sumFuel;
}

// For part 2
int calcIndividualFuel(int diff) {
    // Calculate 0+1+...+diff
    return ((diff+1) * diff / 2);
}