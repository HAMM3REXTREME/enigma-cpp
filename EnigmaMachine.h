// EnigmaMachine.h

#ifndef ENIGMAMACHINE_H
#define ENIGMAMACHINE_H

#include "Board.h"
#include "Rotor.h"
#include <vector>
#include <map>
#include <string>

class EnigmaMachine {
public:
    EnigmaMachine(Plugboard plugboard, std::vector<Rotor> rotorArray, std::vector<int> reflector);
    std::string encryptText(const std::string& text); // Text encryption function

private:
    Plugboard plugboard;
    std::vector<Rotor> rotors;
    std::vector<int> reflector;

    void incrementRotors(); // Increment rotor position
    int throughRotorArrayF(int letterID) const;
    int throughRotorArrayB(int letterID) const;
    int throughReflector(int rotorOut) const;
};

#endif // ENIGMAMACHINE_H

