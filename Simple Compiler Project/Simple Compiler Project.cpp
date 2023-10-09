#include <iostream>
#include <ctype.h>
#include <string>
using namespace std;

int main()
{
	string statement{};
	cout << "Enter a statement to analyze:\n";
	getline(cin, statement);

	int count{ 0 };

	for (int i = 0; i < statement.length(); i++)
	{
		char ch = statement[i];
		char char_next = statement[i + 1];
		if (isdigit(ch)) {
			if (isdigit(ch) && isdigit(char_next)) {
				cout << "<" << ch << char_next << ">";
				statement[i + 1] = ' ';
				continue;
			}
			else {
				cout << "<" << ch << ">";
				continue;
			}
		}
		else if (ch == '+')
		{
			cout << "<+>";
			continue;
		}
		else if (ch == '-') {
			cout << "<->";
			continue;
		}
		else if (ch == '*') {
			cout << "<*>";
			continue;
		}
		else if (ch == '/') {
			cout << "</>";
			continue;
		}
		else if (ch == '%') {
			cout << "<%>";
			continue;
		}
		else if (ch == '=') {
			cout << "<=>";
			continue;
		}
		else if (ch == ';') {
			cout << "<;>";
			break;
		}
		else if (ch == ' ') {
			continue;
		}
		else
		{
			cout << "<id," << count << ">";
			count++;
			continue;
		}
	}
	return 0;
}