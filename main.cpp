#include <iostream>
#include <string>
#include "EnigmaMachine.h"
#include "Util.h"




int main() {
    // Configure the Enigma machine
    //std::vector<int> plugboardArrangement = {-1, 2, 1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};

    Plugboard plugboard(stringToVector("MDTSWILRUYQNKFEJCAZBPGXOHV"));

    Plugboard rotor1(stringToVector("DMTWSILRUYQNKFEJCAZBPGXOHV"));
	Plugboard rotor2(stringToVector("HQZGPJTMOBLNCIFDYAWVEUSRKX"));
	Plugboard rotor3(stringToVector("UQNTLSZFMREHDPXKIBVYGJCWOA"));

	std::vector<Rotor> rotors = {
        Rotor(rotor1, 5, 6), // Initialize with plugboard, spin offset, and notch
        Rotor(rotor2, 0, 6), // 1 is no offset.
        Rotor(rotor3, 5, 0) // 0 means no notch
    };

    // Make sure your reflector is physically accurate
    std::vector<int> testReflector = {-1, 26, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14, 17, 16, 19, 18, 21, 20, 23, 22, 25, 24, 1};

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
