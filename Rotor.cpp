// Rotor.cpp

#include "Rotor.h"
#include "Constants.h"
#include <iostream>

int addWithOverflow(int a, int b, int modulus) {
    int result = (a + b) % (modulus);
    if (result <= 0) {
        result += modulus;
    }
    return result;
}

Rotor::Rotor(Plugboard mapBoard, int spinOffset, int notch)
    : mapping(mapBoard), spin(spinOffset), notch(notch) {}

int Rotor::throughRotorF(int letterID) const {
    int offsetSignal = addWithOverflow(letterID, spin-1, Letters); // Ensure result is within 1 to 26 range
    int finalSignal = addWithOverflow(mapping.throughFront(offsetSignal), spin-1, Letters);
	//std::cout << "FRONT TO BACK: Originally: " << letterID << " after offset of "<< spin-1 << "is" << offsetSignal << " f(x) to " << finalSignal << "\n";
    return finalSignal; // Ensure result is within 1 to 26 range
}

int Rotor::throughRotorB(int letterID) const {
    int offsetSignal = addWithOverflow(letterID, -(spin-1), Letters); // Ensure result is within 1 to 26 range
    int finalSignal = addWithOverflow(mapping.throughBack(offsetSignal), -(spin-1), Letters);
	//std::cout << "    BACK TO FRONT: Originally: " << letterID << " after offset of -ve " << spin-1 << " is " << offsetSignal << ". Now rotor maps it to " << finalSignal << "\n";
    return finalSignal; // Ensure result is within 1 to 26 range
}

