// TODO: Make this function faster!
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_STACK_LENGTH 5000

bool isOpenParentheses(char c) {
	return c == '(' || c == '{' || c == '[';
}

bool isMatchParentheses(char c1, char c2) {
	if (c1 == '(' && c2 == ')') return true;
	if (c1 == '{' && c2 == '}') return true;
	if (c1 == '[' && c2 == ']') return true;
	return false;
}

bool isValid(char *s) {
	char *stack = malloc(MAX_STACK_LENGTH * sizeof(char));
	int stack_index = 0;

	int index = 0;
	while (s[index] != '\0') {
		char paren = s[index];
		if (isOpenParentheses(paren)) {
			stack[stack_index] = paren;
			stack_index ++;
		}
		else {
			if (stack_index == 0) {
				free(stack);
				return false;
			}
			stack_index --;
			char stack_paren = stack[stack_index];
			if (!isMatchParentheses(stack_paren, paren)) {
				free(stack);
				return false;
			}
		}
		index ++;
	}
	free(stack);
	if (stack_index != 0)
		return false;
	return true;
}

