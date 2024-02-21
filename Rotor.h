// Rotor.h

#ifndef ROTOR_H
#define ROTOR_H

#include "Board.h"

class Rotor {
public:
    Rotor(Plugboard mapBoard, int spinOffset, int notch);
    int throughRotorF(int letterID) const;
    int throughRotorB(int letterID) const;

    Plugboard mapping;
    int spin;
    int notch;
};

int addWithOverflow(int a, int b, int modulus);


#endif // ROTOR_H

