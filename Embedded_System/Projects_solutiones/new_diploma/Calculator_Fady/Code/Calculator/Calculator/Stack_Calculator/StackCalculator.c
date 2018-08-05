/*
 * StackCalculator.c
 *
 * Created: 8/3/2018 11:26:51 AM
 *  Author: FadyS
 */ 

#include <string.h>
#include <stdlib.h>
#include "StackCalculator.h"

// Stack type
struct Stack
{
	int top;
	unsigned capacity;
	int* array;
};

// Stack Operations
struct Stack* createStack( unsigned capacity )
{
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
	
	if (!stack)
		return NULL;
	
	stack->top = -1;
	stack->capacity = capacity;
	
	stack->array = (int*) malloc(stack->capacity * sizeof(int));
	
	if (!stack->array)
		return NULL;
	
	return stack;
}
int isEmpty(struct Stack* stack)
{
	return stack->top == -1 ;
}
char peek(struct Stack* stack)
{
	return stack->array[stack->top];
}
char pop(struct Stack* stack)
{
	if (!isEmpty(stack))
		return stack->array[stack->top--] ;
	return '$';
}
void push(struct Stack* stack, char op)
{
	stack->array[++stack->top] = op;
}


// A utility function to check if the given character is operand
int isOperand(char ch)
{
	return (ch >= '0' && ch <= '9');
}

// A utility function to return precedence of a given operator
// Higher returned value means higher precedence
int Prec(char ch)
{
	switch (ch)
	{
		case '+':
		case '-':
		return 1;
		
		case '*':
		case '/':
		return 2;
		
		case '^':
		return 3;
	}
	return -1;
}

int infixToPostfix(char* exp)
{
	int i, k;
	
	// Create a stack of capacity equal to expression size
	struct Stack* stack = createStack(strlen(exp));
	if(!stack) // See if stack was created successfully
		return -1 ;
	
	for (i = 0, k = -1; exp[i]; ++i)
	{
		// If the scanned character is an operand, add it to output.
		if (isOperand(exp[i]))
			exp[++k] = exp[i];
		
		// If the scanned character is an ‘(‘, push it to the stack.
		else if (exp[i] == '(')
			push(stack, exp[i]);
		
		// If the scanned character is an ‘)’, pop and output from the stack
		// until an ‘(‘ is encountered.
		else if (exp[i] == ')')
		{
			while (!isEmpty(stack) && peek(stack) != '(')
				exp[++k] = pop(stack);
			if (!isEmpty(stack) && peek(stack) != '(')
				return -1; // invalid expression
			else
				pop(stack);
		}
		else // an operator is encountered
		{
			while (!isEmpty(stack) && Prec(exp[i]) <= Prec(peek(stack)))
				exp[++k] = pop(stack);
			push(stack, exp[i]);
		}
		
	}
	
	// pop all the operators from the stack
	while (!isEmpty(stack))
		exp[++k] = pop(stack );
	
	exp[++k] = '\0';
}

int evaluatePostfix(char* exp)
{
	// Create a stack of capacity equal to expression size
	struct Stack* stack = createStack(strlen(exp));
	int i;
	
	// See if stack was created successfully
	if (!stack) return -1;
	
	// Scan all characters one by one
	for (i = 0; exp[i]; ++i)
	{
		// If the scanned character is an operand (number here),
		// push it to the stack.
		if (isdigit(exp[i]))
		push(stack, exp[i] - '0');
		
		//  If the scanned character is an operator, pop two
		// elements from stack apply the operator
		else
		{
			int val1 = pop(stack);
			int val2 = pop(stack);
			switch (exp[i])
			{
				case '+': push(stack, val2 + val1); break;
				case '-': push(stack, val2 - val1); break;
				case '*': push(stack, val2 * val1); break;
				case '/': push(stack, val2/val1);   break;
			}
		}
	}
	return pop(stack);
}
int evaluateEquation(char* exp){
	infixToPostfix(exp);
	return evaluatePostfix(exp);
}