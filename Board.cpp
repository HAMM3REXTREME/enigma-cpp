// BiMap.cpp

#include "Board.h"
#include <vector>
#include "Constants.h"


Plugboard::Plugboard(const std::vector<int>& arrangement) {
    // Initialize forward and backward mappings
    forward.resize(Letters+1);
    backward.resize(Letters+1);

    int prevMappedLetter = 0; // Track the previously mapped letter

    for (int i = 1; i < (Letters+1); ++i) {
        if (arrangement[i] != 0) {
            forward[i] = arrangement[i];
            prevMappedLetter = forward[i];
        } else {
            forward[i] = prevMappedLetter; // Map to the previous mapped letter
        }
        backward[forward[i]] = i;
    }
}


int Plugboard::throughFront(int letterNum) const {
/*     if (letterNum <= 0 || letterNum > Letters) {
        return letterNum; // Return the same letter if out of range
    } */
    return forward[letterNum];
}

int Plugboard::throughBack(int letterNum) const {
/*     if (letterNum <= 0 || letterNum > Letters) {
        return letterNum; // Return the same letter if out of range
    } */
    return backward[letterNum];
}



