#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
	// Declare a string to store user input
	string input;

	// Prompt the user to enter a string
	cout << "Enter a string: ";
	getline(cin, input);

	// Declare a string to store the current token
	string token = "";

	// Initialize a counter for generating unique identifiers for identifiers
	int count = 0;

	// Loop through each character in the input string
	for (char lexeme : input) {
		if (isalnum(lexeme)) {
			// If the character is alphanumeric, it is part of an identifier or number token
			token += lexeme;
		}
		else if (lexeme == '+' || lexeme == '-' || lexeme == '*' || lexeme == '/' || lexeme == '%' || lexeme == '=' || lexeme == ';') {
			// If the character is an operator or semicolon, handle the current token
			if (!token.empty()) {
				// Check if the token is a number
				bool isNumber = true;
				for (char numbers : token) {
					if (!isdigit(numbers)) {
						isNumber = false;
						break;
					}
				}

				// Output the token based on whether it's an identifier or number
				if (isNumber) {
					cout << "<" << token << ">";
				}
				else {
					cout << "<id," << count++ << ">";
				}
				token = ""; // Reset the token
			}

			// Output the operator or semicolon
			cout << "<" << lexeme << ">";
		}
		else if (!isspace(lexeme)) {
			// If the character is not alphanumeric or a space, it's an invalid token
			cout << "\nInput contains invalid token: " << lexeme << endl;
			return 1; // Exit with an error code
		}
		else if (!token.empty()) {
			// Output Identifier or Number token if any when encountering a space
			bool isNumber = true;
			for (char numbers : token) {
				if (!isdigit(numbers)) {
					isNumber = false;
					break;
				}
			}

			if (isNumber) {
				cout << "<" << token << ">";
			}
			else {
				cout << "<id," << count++ << ">";
			}
			token = ""; // Reset the token
		}
	}

	// Output any remaining Identifier or Number token after the loop
	if (!token.empty()) {
		// Check if the token is a number
		bool isNumber = true;
		for (char numbers : token) {
			if (!isdigit(numbers)) {
				isNumber = false;
				break;
			}
		}

		// Output the remaining token
		if (isNumber) {
			cout << "<" << token << ">";
		}
		else {
			cout << "<id," << count++ << ">";
		}
	}

	return 0; // Exit successfully
}