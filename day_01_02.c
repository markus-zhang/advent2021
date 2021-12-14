#include "stdio.h"
#include "string.h"

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        printf("Usage: day_01_02 textfilename");
        return -1;
    }

    char const* const fileName = argv[1];
    FILE* file = fopen(fileName, "r");
    char line[16];
    int window[3];
    int count = 0;
    int increaseCount = 0;

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;
        if (count >= 3) {
            int current = 0;
            sscanf(line, "%d", &current);
            printf("%d versus %d\n", current, window[count % 3]);
            if (current > window[count % 3]) {
                increaseCount++;
            }
            window[count % 3] = current;
        }
        else {
            sscanf(line, "%d", &window[count % 3]);
        }
        count++;
    }

    printf("Total number of increases: %d\n", increaseCount);

    fclose(file);
    return 0;
}