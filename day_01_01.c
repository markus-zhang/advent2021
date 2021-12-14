#include "stdio.h"
#include "string.h"

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        printf("Usage: day_01 textfilename");
        return -1;
    }

    char const* const fileName = argv[1];
    FILE* file = fopen(fileName, "r");
    char line[16];
    int current = 0;
    int previous = 0;
    int count = 0;
    int increaseCount = 0;

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;
        sscanf(line, "%d", &current);
        if (count++ > 0) {
            if (current > previous) {
                increaseCount++;
            }
        }
        previous = current;
    }

    printf("Total number of increases: %d\n", increaseCount);

    fclose(file);
    return 0;
}