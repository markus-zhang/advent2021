#include "stdio.h"
#include "string.h"
#include "math.h"
#include <stdlib.h>
#include <stdbool.h>

typedef struct bingoBoard {
    int board[5][5];
} bingoBoard;

typedef struct bingoNode {
    int number;
    struct bingoNode* next;
} bingoNode;

typedef struct bingoNodeHead {
    int number;
    struct bingoNode* next;
    struct bingoNode* walker;
} bingoNodeHead;

// void updateTree(const char* line, int lineIndex, bingoNode* parentNode);
bool bingoWon(const int[5][5]);
void updateBoard(int number, int board[5][5]);
int getScore(int number, const int board[5][5]);

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        printf("Usage: day_04_01 textfilename");
        return -1;
    }

    char const* const fileName = argv[1];
    FILE* file = fopen(fileName, "r");
    char firstLine[1024];
    char line[16];

    // Grab the first line
    fgets(firstLine, sizeof(firstLine), file);
    firstLine[strcspn(firstLine, "\n")] = 0;

    // Step 1: Build an array of dummy nodes
    
    int bingoLineNumber[5];
    // bingo-row-col
    // int bingo[256][5][5];
    bingoBoard game[256];
    int bingoCount = 0;
    int lineCount = 0;
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;
        if (strlen(line) > 10) {
            // Reset lineCount to 0 and move to next board
            if ((lineCount % 5 == 0) && lineCount > 0) {
                bingoCount++;
                lineCount = 0;
            }
            sscanf(line, "%d %d %d %d %d", 
                &(game[bingoCount].board[lineCount][0]), 
                &(game[bingoCount].board[lineCount][1]), 
                &(game[bingoCount].board[lineCount][2]), 
                &(game[bingoCount].board[lineCount][3]), 
                &(game[bingoCount].board[lineCount][4])
            );
            // printf("%d %d %d %d %d\n", bingo[lineCount][0], bingo[lineCount][1], bingo[lineCount][2], bingo[lineCount][3], bingo[lineCount][4]);
            lineCount++;           
        }
    }

    /*
        Step 2:

        while (still has number in firstLine) {
            grab next number;
            for (i = 0; i < bingoCount; i++) {
                // If there is a match, put zero in the value
                updateBoard(number, bingo[i]);
                // TODO: Complete this algorithm
                // TODO: Need to record the last matched number
                // TODO: Need to record the first won board id
            }
        }
    */
   
    char* token = strtok(firstLine, ",");
    int number = atoi(token);

    for (int i = 0; i < bingoCount; i++) {
        // printf("Updating board %d\n", i);
        updateBoard(number, game[i].board);
        /*
        if (bingoWon(game[i].board)) {
            printf("Board %d won!\n", i);
            for (int row = 0; row < 5; row++) {
                for (int col = 0; col < 5; col++) {
                    printf("%d ", game[i].board[row][col]);
                }
                printf("\n");
            }
            printf("\n");
        }
        */
    }

    while (token != NULL) {
        token = strtok(NULL, ",");
        if (token != NULL) {
            number = atoi(token);
            for (int i = 0; i < bingoCount; i++) {
                // printf("Updating board %d\n", i);
                updateBoard(number, game[i].board);           
                if (bingoWon(game[i].board)) {
                    /*
                    printf("Board %d won!\n", i);
                    for (int row = 0; row < 5; row++) {
                        for (int col = 0; col < 5; col++) {
                            printf("%d ", game[i].board[row][col]);
                        }
                        printf("\n");
                    }
                    printf("\n");
                    printf("Number to multiply: %d\n", number);
                    */
                    printf("Board Score: %d\n", getScore(number, game[i].board));
                    return 0;
                }
            }
        }
    }

    printf("\n");

    return 0;
}

/*
    We simply switch numbers to -1 once there is a match.
    But doing so we need to switch them to 0 when calculating
    the final score.
*/
bool bingoWon(const int board[5][5]) {
    for (int row = 0; row < 5; row++) {
        if (board[row][0] + board[row][1] + board[row][2] + board[row][3] + board[row][4] == -5) {
            return true;
        }
    }
    for (int col = 0; col < 5; col++) {
        if (board[0][col] + board[1][col] + board[2][col] + board[3][col] + board[4][col] == -5) {
            return true;
        }
    }
    return false;
}

/*
    For each number read, we update each board.
    This should be running inside of a loop of all bingoBoards.
*/
void updateBoard(int number, int board[5][5]) {
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {
            if (board[row][col] == number) {
                board[row][col] = -1;
            }
        }
    }
}

int getScore(int number, const int board[5][5]) {
    int boardSum = 0;
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {
            if (board[row][col] > 0) {
                boardSum += board[row][col];
            }
        }
    }
    return number * boardSum;
}