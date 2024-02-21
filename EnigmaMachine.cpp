// EnigmaMachine.cpp

#include "EnigmaMachine.h"
#include "Constants.h"
#include <cctype>

#include <stdexcept> // for std::out_of_range
#include <string>    // for std::string
#include <iostream>

char num2rune(int number) {
    if (number < 0 || number > Letters) {
        throw std::out_of_range("letter input must be between 0 and 25");
    }

    char ch = 'A' + number ;//- 1; // Convert the number to the corresponding uppercase English alphabet letter
    return ch;
}

int num2rune(char letter) {
    if (std::isalpha(letter)) {
        int letterID = toupper(letter) - 'A';
		return letterID;
} else {
	throw std::out_of_range("letter input must from the alphabet");
}
}





EnigmaMachine::EnigmaMachine(Plugboard plugboard, std::vector<Rotor> rotorArray, std::vector<int> reflector)
    : plugboard(plugboard), rotors(rotorArray), reflector(reflector) {}

 std::string EnigmaMachine::encryptText(const std::string& text) {
    std::string encryptedText;
    for (char c : text) {
            //incrementRotors();
			int encryptedNum = num2rune(c);
			encryptedNum = plugboard.throughFront(encryptedNum);
            encryptedNum = throughRotorArrayF(encryptedNum);
            encryptedNum = throughReflector(encryptedNum);
            encryptedNum = throughRotorArrayB(encryptedNum);
            encryptedNum = plugboard.throughBack(encryptedNum);
            encryptedText += num2rune(encryptedNum);
    }
    return encryptedText;
}

void EnigmaMachine::incrementRotors() {
    rotors[0].spin = (rotors[0].spin + 1) % Letters;
    for (size_t i = 1; i < rotors.size(); ++i) {
        if (rotors[i - 1].spin == rotors[i - 1].notch) {
            rotors[i].spin = (rotors[i].spin + 1) % Letters;
        }
    }
}

int EnigmaMachine::throughRotorArrayF(int letterID) const {
    for (const Rotor& rotor : rotors) {
        letterID = rotor.throughRotorF(letterID);
    }
    return letterID;
}

int EnigmaMachine::throughRotorArrayB(int letterID) const {
    for (size_t i = rotors.size(); i > 0; --i) {
        letterID = rotors[i - 1].throughRotorB(letterID);
    }
    return letterID;
}

int EnigmaMachine::throughReflector(int refInput) const {
    if (reflector[refInput] == refInput){
		std::cout << "Warning: Potentially invalid reflector since out == in.\n";
	}
    return reflector[refInput];
}

