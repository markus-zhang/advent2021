#include "stdio.h"
#include "string.h"
#include "math.h"
#include <stdlib.h>
#include <stdbool.h>

typedef struct coordinate {
    int x;
    int y;
    int visited;
} coordinate;

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        printf("Usage: day_05_01 textfilename");
        return -1;
    }

    char const* const fileName = argv[1];
    FILE* file = fopen(fileName, "r");
    char line[32];
    coordinate map[199999] = {{-1, -1, 0}};
    int mapWalker = 0;

    while (fgets(line, sizeof(line), file)) {
        // Check whether the line is vertical/horizontal
        int x1, y1, x2, y2;
        line[strcspn(line, "\n")] = 0;
        line[strcspn(line, "-")] = ' ';
        line[strcspn(line, ">")] = ' ';
        // printf("Transformed line: %s.\n", line);
        sscanf(line, "%d,%d %d,%d", &x1, &y1, &x2, &y2);
        /*
        if ((x1 == x2) || (y1 == y2)) {
            printf("Line (%d, %d)->(%d, %d) is horizontal/vertical\n", x1, y1, x2, y2);
        } 
        */
        if (x1 == x2) {
            // printf("Line (%d, %d)->(%d, %d) is horizontal/vertical\n", x1, y1, x2, y2);
            // vertical line
            int minY = (y1 <= y2) ? y1 : y2;
            int maxY = (y1 <= y2) ? y2 : y1;
            for (int y = minY; y <= maxY; y++) {
                int index = 0;
                while (1) {
                    if (map[index].x == x1 && map[index].y == y) {
                        map[index].visited++;
                        break;
                    }
                    index++;
                    if (index > mapWalker) {
                        map[mapWalker].x = x1;
                        map[mapWalker].y = y;
                        map[index].visited = 1;
                        mapWalker++;
                        break;
                    }
                }
                
            }
        }
        else if (y1 == y2) {
            int minX = (x1 <= x2) ? x1 : x2;
            int maxX = (x1 <= x2) ? x2 : x1;
            for (int x = minX; x <= maxX; x++) {
                int index = 0;
                while (1) {
                    if (map[index].x == x && map[index].y == y1) {
                        map[index].visited++;
                        break;
                    }
                    index++;
                    if (index > mapWalker) {
                        map[mapWalker].x = x;
                        map[mapWalker].y = y1;
                        map[index].visited = 1;
                        mapWalker++;
                        break;
                    }
                }
                
            }
        }
        /*
            Comment next part if for part 1
        */
        else if (abs(x1 - x2) == abs(y1 - y2)) {
            /* int minX = (x1 <= x2) ? x1 : x2;
            int maxX = (x1 <= x2) ? x2 : x1;
            int minY = (y1 <= y2) ? y1 : y2;
            int maxY = (y1 <= y2) ? y2 : y1;
            int x = minX;
            int y = minY; */
            int x = x1;
            int y = y1;
            while (1) {
                int index = 0;
                while (1) {
                    if (map[index].x == x && map[index].y == y) {
                        map[index].visited++;
                        break;
                    }
                    index++;
                    if (index > mapWalker) {
                        map[mapWalker].x = x;
                        map[mapWalker].y = y;
                        map[index].visited = 1;
                        mapWalker++;
                        break;
                    }
                }
                if (x == x2 && y == y2) {
                    break;
                }
                if (x1 < x2) {
                    x++;
                    if (y1 < y2) {
                        y++;
                    }
                    else {
                        y--;    
                    }
                }
                else {
                    x--;
                    if (y1 < y2) {
                        y++;
                    }
                    else {
                        y--;    
                    }
                }
            }
        }
    }
    printf("A total of %d coordinates have been addressed.\n", mapWalker);
    int result = 0;
    for (int i = 0; i <= mapWalker - 1; i++) {
        if (map[i].visited >= 2) {
            result++;
        }
    }
    printf("A total of %d coordinates have been visited 2+ times.\n", result);
}