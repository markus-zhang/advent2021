#include "stdio.h"
#include "string.h"
#include "math.h"
#include <stdlib.h>
#include <stdbool.h>

/*
    We cannot use the linked list approach as in step 1
    because it's going to take forever.
    Instead, know that G256 = G255 + (# of 0s in G255),
    G255 = G254 + (# of 0s in G254), and etc.
    Say G0 has a 2, so G0 = 1 and G1 = 1 as well.
*/

#define GEN_MAX 255

// For a fish of initialValue, how many after N generation?
long countFishes(
    long generation, long prevZeroCount, long prevOneCount,
    long prevTwoCount, long prevThreeCount, long prevFourCount,
    long prevFiveCount, long prevSixCount, long prevSevenCount,
    long prevEightCount
);

int main(int argc, char* argv[]) {
    /* 
        We already know that we have the following:
        1: 212
        2: 23
        3: 25
        4: 21
        5:19
    */

    // Enter 1 in different days to grab the number
    // Final answer: 1757714216975
    // 6206821033*212+ 5617089148*23+ 5217223242*25+ 4726100874*21+ 4368232009*19
    long result = countFishes(0, 0, 0, 0, 0, 0, 1, 0, 0, 0);
    printf("%d generation started with one %d is: %ld\n", GEN_MAX, start, result);

    return 0;
}

long countFishes(
    long generation, long prevZeroCount, long prevOneCount,
    long prevTwoCount, long prevThreeCount, long prevFourCount,
    long prevFiveCount, long prevSixCount, long prevSevenCount,
    long prevEightCount
) {
    long currZeroCount = prevOneCount; 
    long currOneCount = prevTwoCount; 
    long currTwoCount = prevThreeCount; 
    long currThreeCount = prevFourCount; 
    long currFourCount = prevFiveCount; 
    long currFiveCount = prevSixCount; 
    long currSixCount = prevSevenCount + prevZeroCount; 
    long currSevenCount = prevEightCount;
    long currEightCount = prevZeroCount;

    if (generation == GEN_MAX) {
        return (
            currZeroCount + currOneCount + currTwoCount + currThreeCount
            + currFourCount + currFiveCount + currSixCount + currSevenCount
            + currEightCount
        );
    }
    else {
        generation++;
        return countFishes(
            generation, currZeroCount, currOneCount,
            currTwoCount, currThreeCount, currFourCount,
            currFiveCount, currSixCount, currSevenCount,
            currEightCount
        );
    }
}