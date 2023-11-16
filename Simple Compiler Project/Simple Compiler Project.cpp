#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
	string input;
	cout << "Enter a string: ";
	getline(cin, input);

	string token = "";
	int count = 0;
	for (char c : input) {
		if (isalnum(c)) {
			// Identifier or Number token
			token += c;
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '=' || c == ';') {
			// Operator or Semicolon token
			if (!token.empty()) {
				// Check if the token is a number
				bool isNumber = true;
				for (char tc : token) {
					if (!isdigit(tc)) {
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
				token = "";
			}
			cout << "<" << c << ">";
		}
		else if (!isspace(c)) {
			// Invalid token
			cout << "Input contains invalid token: " << c << endl;
			return 1; // Exit with an error code
		}
		else if (!token.empty()) {
			// Output Identifier or Number token if any
			bool isNumber = true;
			for (char tc : token) {
				if (!isdigit(tc)) {
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
			token = "";
		}
	}

	if (!token.empty()) {
		// Output any remaining Identifier or Number token
		// Check if the token is a number
		bool isNumber = true;
		for (char tc : token) {
			if (!isdigit(tc)) {
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
	}

	return 0;
}