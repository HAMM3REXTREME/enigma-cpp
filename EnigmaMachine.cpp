// EnigmaMachine.cpp

#include "EnigmaMachine.h"
#include "Constants.h"
#include "Rotor.h"
#include "Util.h"
#include <cctype>

#include <iostream>
#include <stdexcept>
#include <string>

EnigmaMachine::EnigmaMachine(Plugboard plugboard, std::vector<Rotor> rotorArray, std::vector<int> reflector) :
		plugboard(plugboard), rotors(rotorArray), reflector(reflector) {}

std::string EnigmaMachine::encryptText(const std::string &text) {
	std::string encryptedText;
	for (char c : text) {
		incrementRotors();
		int encryptedNum = char2num(c);
		encryptedNum = plugboard.throughFront(encryptedNum);
		encryptedNum = throughRotorArrayF(encryptedNum);
		encryptedNum = throughReflector(encryptedNum);
		encryptedNum = throughRotorArrayB(encryptedNum);
		encryptedNum = plugboard.throughBack(encryptedNum);
		encryptedText += num2char(encryptedNum);
	}
	return encryptedText;
}

void EnigmaMachine::incrementRotors() {
	rotors[0].spin = addWithOverflow(rotors[0].spin, 1, Letters);
	std::cout << "Spin OFFSET of initial rotor is +" << rotors[0].spin-1 << " now, since you typed.\n";
	for (size_t i = 1; i < rotors.size(); ++i) {
		if (rotors[i - 1].spin == rotors[i - 1].notch) {
			rotors[i].spin = addWithOverflow(rotors[i].spin, 1, Letters);
			std::cout << "Spin OFFSET of rotor " << i+1 << " is +" << rotors[i].spin-1 << " now\n";
		}
	}
}

int EnigmaMachine::throughRotorArrayF(int letterID) const {
	for (const Rotor &rotor : rotors) {
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
	return reflector[refInput]; // Make sure to have a physically possible reflector to avoid bugs.
}
