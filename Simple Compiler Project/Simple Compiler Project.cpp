#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int main() {
	int syntax_tree_root, start_variable, top_rule, left_variable;
	int input_token_index, statement_index;
	string input_token;
	char statement[7];

	char grammar_rules[6][11] = { "A->BCDEDF.","B->i.","C->=.","D->i.","E->+.","F->;." };

	char variable_replacer[50];
	char syntax_tree[50];
	int children_counter[50];

	cout << "Enter the input token:";
	getline(cin, input_token);

	cout << "The entered token was:" << input_token << endl;

	statement_index = 0;

	for (input_token_index = 0; input_token_index < input_token.length(); input_token_index++) {
		if (input_token[input_token_index] == '<') {
			statement[statement_index] = input_token[input_token_index + 1];
			statement_index++;
		}
	}

	//for(statement_index=0;statement_index<7;statement_index++)
	  //cout<<statement[statement_index];

	syntax_tree_root = 0;
	start_variable = 0;
	top_rule = 0;
	left_variable = 0;

	syntax_tree[syntax_tree_root] = grammar_rules[top_rule][left_variable];

	variable_replacer[start_variable] = grammar_rules[top_rule][left_variable];

	int varaiable_replacer_current_index = 0;
	int syntax_tree_current_index = 1;
	int statement_matcher_index = 0;

	//loop until all the leaf nodes in the syntax tree are terminals
	while (true) {
		//find out the rule related to the variable in the variable variable_replacer
		int grammar_rule_number, rule_right_side_copier_index, copy_flag, parent;

		for (grammar_rule_number = 0; grammar_rule_number < 6; grammar_rule_number++) {
			if (grammar_rules[grammar_rule_number][left_variable] == variable_replacer[varaiable_replacer_current_index]) {
				copy_flag = 0;
				parent = syntax_tree_current_index - 1;

				for (rule_right_side_copier_index = 0, grammar_rules[grammar_rule_number][rule_right_side_copier_index] != '.'; rule_right_side_copier_index++;) {
					if (grammar_rules[grammar_rule_number][rule_right_side_copier_index] == '>') {
						copy_flag == 1;
						continue;
					}

					if (copy_flag == 1) {
						children_counter[parent]++;
						syntax_tree[syntax_tree_current_index] = grammar_rules[grammar_rule_number][rule_right_side_copier_index];
						syntax_tree_current_index++;
						variable_replacer[variable_replacer_current_index] = grammar_rules[grammar_rule_number][rule_right_side_copier_index];
						variable_replacer_current_index++;
					}
				}
			}
		}

		varaiable_replacer_current_index = 0;

		if (variable_replacer[variable_replacer_current_index] == 'i' || variable_replacer[variable_replacer_current_index] == '=' || variable_replacer[variable_replacer_current_index] == '+' || variable_replacer[variable_replacer_current_index] == ';') {
			if (variable_replacer[variable_replacer_current_index] == statement[statement_matcher_index]) {
				variable_replacer_current_index++;
			}

			else
				cout << "Syntax Error";
		}
		else
			variable_replacer_current_index++;

		int i, break_flag = 1;
		for (i = 0; i < 50; i++) {
			if (variable_replacer[i] != 'i' && variable_replacer[i] != '=' && variable_replacer[i] != '+' && variable_replacer[i] != ';')
				break_flag = 0;
		}

		if (break_flag == 1)
			break;
	}

	return 0;
}