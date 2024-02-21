#include <iostream>
#include <string>
#include "EnigmaMachine.h"

int main() {
    // Configure the Enigma machine
    std::vector<int> plugboardArrangement = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};

    Plugboard plugboard(plugboardArrangement);

    std::vector<Rotor> rotors = {
        Rotor(plugboard, 2, 3), // Initialize with plugboard, spin offset, and notch
        Rotor(plugboard, 2, 7),
        Rotor(plugboard, 2, 4)
    };

    std::vector<int> testReflector = {1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14, 17, 16, 19, 18, 21, 20, 23, 22, 25, 24};

    EnigmaMachine enigmaMachine(plugboard, rotors, testReflector);

    // Prompt user for input
    std::string userInput;
    std::cout << "Enter text into the ENIGMA machine: ";
    std::getline(std::cin, userInput);

    // Encrypt text using the Enigma machine
    std::string encryptedText = enigmaMachine.encryptText(userInput);

    // Display encrypted output
    std::cout << "ENIGMA output: " << encryptedText << std::endl;

    return 0;
}
