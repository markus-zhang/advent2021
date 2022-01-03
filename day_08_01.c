/*
    So we want to minimize SUM[(X-Xi)].
    Using Calculus, X = AVG(Xi)
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

int count1478(const char line[]);
bool compareTwoStrings(const char source[], const char target[]);

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        printf("Usage: day_08_01 textfilename");
        return -1;
    }

    char const* const fileName = argv[1];
    FILE* file = fopen(fileName, "r");
    char line[256];
    int hit = 0;

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;
        printf("%s\n", line);
        hit += count1478(line);
    }
    fclose(file);
    printf("Total hit count: %d\n", hit);
    return 0;
}

int count1478(const char line[]) {
    // febca cfagb ecbafd efdcbg cbegdfa fg bgafec gfae acgdb gfc | cgf facdeb ecgfdb afcbge
    // Ignore the part before |
    int i = 0;
    int count = 0;
    char target[64];
    
    while (1) {
        if (line[i] == '|') {
            memcpy(target, &line[i+2], strlen(line) - i - 2);
            target[strlen(line) - i - 2] = '\0';    // replace '\r' with '\0'
            // printf("%s\n", target);
            char* token = strtok(target, " ");
            /* if (compareTwoStrings(token, "gc") || compareTwoStrings(token, "gcbe") || compareTwoStrings(token, "bgf") || compareTwoStrings(token, "egdcabf")) {
                count++;
            } */
            if (strlen(token) == 2 || strlen(token) == 3 || strlen(token) == 4 || strlen(token) == 7) {
                count++;
            }
            while (token != NULL) {
                token = strtok(NULL, " ");
                if (token == NULL) {
                    break;
                }
                /* if (compareTwoStrings(token, "gc") || compareTwoStrings(token, "gcbe") || compareTwoStrings(token, "bgf") || compareTwoStrings(token, "egdcabf")) {
                    count++;
                }    */
                if (strlen(token) == 2 || strlen(token) == 3 || strlen(token) == 4 || strlen(token) == 7) {
                    count++;
                }
            }
            break;
        }
        else {
            i++;
        }
    }
    return count;
}

bool compareTwoStrings(const char source[], const char target[]) {
    // "fadegcb" equals to "dgebacf"
    // 1) We check if strlen equals
    // 2) Next we check if each character in source is in target
    // assuming there is no duplicated characters in both sets (lazy :D)
    if (strlen(source) != strlen(target)) {
        return false;
    }

    bool charHit = false;
    int sourceLength = strlen(source);
    for (int i = 0; i < sourceLength; i++) {
        for (int j = 0; j < sourceLength; j++) {
            if (source[i] == target[j]) {
                charHit = true;
                break;
            }
        }
        if (!charHit) {
            return false;
        }
        else {
            charHit = false;
        }
    }
}