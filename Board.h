#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Constants.h"


class Plugboard {
public:
    Plugboard(const std::vector<int>& arrangement);
    int throughFront(int letterNum) const;
    int throughBack(int letterNum) const;

private:
    std::vector<int> forward;
    std::vector<int> backward;
};

#endif

