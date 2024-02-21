#include "Constants.h"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>


// "ABC" --> {-1,1,2,3}
std::vector<int> stringToVector(const std::string& input) {
    std::vector<int> result(Letters + 1, -1); // Initialize with -1
    int position = 1; // Position starts from 1
    // Convert input string to uppercase
    std::string uppercaseInput = input;
    std::transform(uppercaseInput.begin(), uppercaseInput.end(), uppercaseInput.begin(), ::toupper);

    // Check if input string contains all alphabets from A to Z
    for (char c = 'A'; c <= 'Z'; ++c) {
        if (uppercaseInput.find(c) == std::string::npos) {
            // If any alphabet is missing, return an empty vector
            return {};
        }
    }

    // Map each character to its position in the vector
    for (char c : uppercaseInput) {
        result[c - 'A' + 1] = position;
        position++;
    }

    return result;
}

char num2char(int number) {
	if (number < 1 || number > Letters) {
		throw std::out_of_range("letter input must be between 1 and 26");
	}
	char ch = 'A' + number - 1; // Convert the number to the corresponding uppercase English alphabet letter
	return ch;
}

int char2num(char letter) {
	if (std::isalpha(letter)) {
		int letterID = toupper(letter) - 'A' + 1;
		return letterID;
	} else {
		throw std::out_of_range("letter input must be from the alphabet");
	}
}
