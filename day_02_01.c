#include "stdio.h"
#include "string.h"

int extractNumber(const char* line);

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        printf("Usage: day_02_01 textfilename");
        return -1;
    }

    char const* const fileName = argv[1];
    FILE* file = fopen(fileName, "r");
    char line[16];
    char direction[8];
    int number;
    int horizontal = 0;
    int depth = 0;

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;
        sscanf(line, "%s %d", direction, &number);
        // printf("'%s' and '%d'", direction, number);
        char c = direction[0];
        
        switch(c) {
            case 'f':
                // forward
                horizontal += number;
                break;
            case 'd':
                // down
                depth += number;
                break;
            case 'u':
                // up
                depth -= number;
                break;
            default:
                break;
        }
    }

    printf("%d by %d: %d\n", horizontal, depth, horizontal * depth);
}

int extractNumber(const char* line) {
    int number = 0;
    char c = line[0];
    return number;
}