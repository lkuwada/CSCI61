#include "calc.h"
#include <cstdlib>
#include <iostream>
#include <stack>

calc::calc()
{
}

double read_and_evaluate(istream& ins)
// Library facilities used: cstring, iostream, stack
{
    const char DECIMAL = '.';
    const char RIGHT_PARENTHESIS = ')';

    stack<double> numbers;
    stack<char> operations;
    double number;
    char symbol;

    // Loop continues while istream is not “bad” (tested by ins) and next character isn’t newline.
    while (ins && ins.peek( ) != '\n')
    {
        if (isdigit(ins.peek( )) || (ins.peek( ) == DECIMAL))
        {
            ins >> number;
            numbers.push(number);
        }
        else if (strchr("+-*/", ins.peek( )) != NULL)
        {
            ins >> symbol;
            operations.push(symbol);
        }
        else if (ins.peek( ) == RIGHT_PARENTHESIS)
        {
            ins.ignore( );
            evaluate_stack_tops(numbers, operations);
        }
        else
            ins.ignore( );
    }

    return numbers.top( );
}

void calc::evaluate_stack_tops(stack<double>& numbers, stack<char>& operations)
// Library facilities used: stack
{
    double operand1, operand2;

    operand2 = numbers.top( );
    numbers.pop( );
    operand1 = numbers.top( );
    numbers.pop( );
    switch (operations.top( ))
    {
        case '+': numbers.push(operand1 + operand2);
                  break;
        case '-': numbers.push(operand1 - operand2);
                  break;
        case '*': numbers.push(operand1 * operand2);
                  break;
        case '/': numbers.push(operand1 / operand2);
                  break;
    }
    operations.pop( );
}
