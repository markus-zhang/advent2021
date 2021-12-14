#include "stdio.h"
#include "string.h"
#include "math.h"

void processLine(const char* line, int* countOne);

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

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;
        processLine(line, countOne);
        count++;
    }

    // printf("Total line count: %d\n", count);
    for (int i = 11; i >= 0; i--) {
        // printf("%d ", countOne[i]);
        if (countOne[i] < (count / 2)) {
            gamma += pow(2, 11 - i);
        }
        else {
            epsilon += pow(2, 11 - i);
        }
    }

    printf("gamma = %d, epsilon = %d, consumption = %d\n", gamma, epsilon, gamma * epsilon);

    return 0;
}

void processLine(const char* line, int* countOne) {
    for (int i = 0; i < 12; i++) {
        if (line[i] == '1') {
            countOne[i] += 1;
        }
    }
}