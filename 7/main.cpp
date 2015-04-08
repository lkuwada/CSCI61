#include <cctype> // Provides isdigit
#include <cstdlib> // Provides EXIT_SUCCESS
#include <cstring> // Provides strchr
#include <iostream> // Provides cout, cin, peek, ignore
#include <stack> // Provides the stack template class

using namespace std;

double read_and_evaluate(istream& ins);

void evaluate_stack_tops(stack<int>& numbers, stack<string>& operations);



int main( )
{
    int answer;
    cout << "Type a fully parenthesized boolean expression:" << endl;
    answer = read_and_evaluate(cin);
    cout << "That evaluates to " << answer << endl;

    return EXIT_SUCCESS;
}


double read_and_evaluate(istream& ins)
// Library facilities used: cstring, iostream, stack
{
    const char RIGHT_PARENTHESIS = ')';

    stack<int> numbers;
    stack<string> operations;
    int number;
    string symbol;

    // Loop continues while istream is not “bad” (tested by ins) and next character isn’t newline.
    while (ins && ins.peek() != '\n')
    {
        if (isdigit(ins.peek()))
        {
            ins >> number;
            numbers.push(number);
        }
        else if (strchr("&|!<>=", ins.peek( )) != NULL)
        {
            ins >> symbol;
            operations.push(symbol);
        }
        else if (ins.peek() == RIGHT_PARENTHESIS)
        {
            ins.ignore();
            evaluate_stack_tops(numbers, operations);
        }
        else
            ins.ignore( );
    }

    return numbers.top();
}


void evaluate_stack_tops(stack<int>& numbers, stack<string>& operations)
// Library facilities used: stack
{
    int operand1, operand2;

    operand2 = numbers.top( );
    numbers.pop( );

    operand1 = numbers.top( );
    numbers.pop( );


    if (operations.top() == ">")
        numbers.push(operand1 > operand2);
    else if (operations.top() == "<")
        numbers.push(operand1 < operand2);
    else if (operations.top() == "<=")
        numbers.push(operand1 <= operand2);
    else if (operations.top() == ">=")
        numbers.push(operand1 >= operand2);
    else if (operations.top() == "==")
        numbers.push(operand1 == operand2);
    else if (operations.top() == "!=")
        numbers.push(operand1 != operand2);
    else if (operations.top() == "&&")
        numbers.push(operand1 && operand2);
    else if (operations.top() == "||")
        numbers.push(operand1 || operand2);

    operations.pop();

    if (!operations.empty() && operations.top() == "!")
    {
        int opposite = !numbers.top();
        cout << opposite << endl;
        numbers.pop();
        numbers.push(opposite);
        operations.pop();
    }

}
