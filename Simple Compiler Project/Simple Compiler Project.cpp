#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    string token = "";

    for (char c : input) {
        if (isalnum(c)) {
            // Identifier or Number token
            token += c;
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '=' || c == ';') {
            // Operator or Semicolon token
            if (!token.empty()) {
                cout << "<" << token <<">";
                token = "";
            }
            cout << "<" << c << ">";
        }
        else if (!isspace(c)) {
            // Invalid token
            continue;
        }
        else if (!token.empty()) {
            // Output Identifier or Number token if any
            cout << "<" << token << ">";
            token = "";
        }
    }

    if (!token.empty()) {
        // Output any remaining Identifier or Number token
        cout << "<" << token << ">";
    }

    return 0;
}