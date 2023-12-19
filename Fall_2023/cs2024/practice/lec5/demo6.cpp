// 
// CS 2024 -- Lecture #5
// 
// Demo #6 -- Simple Constructor
//
#include <iostream>

#include <string>

using namespace std;

// Define our calculator class
class Calculator
{
    public: 
        Calculator();
        bool calculate(char op, float arg1, float arg2, float &result);

        int getOpCount()
        {
            return opCount;
        }
    private:
        int opCount;
            // Always make sure class defintions have a trailing semicolon
}; 

// Constructor defined outside the class defintion
Calculator::Calculator()
{
    cout << "We're in Calculator::Calculator" << endl;
    opCount = 0;
}

// calculate defined outside the class definition
bool Calculator::calculate(char op, float arg1, float arg2, float &result)
{
    switch(op)
    {
        case '+':
                result = arg1 + arg2;
                opCount = opCount + 1; // Update the counter
        default:
                return false;
    }
    return true;
}

int main()
{
    // Use cout statement so we can see when constrctor is called
    cout << "Checkpoint 1" << endl;

    // Declare an instance of Calculator. The constructor should be called now
    Calculator aCalculator;
    cout << "Checkpoint 2" << endl;

    float result;

    // Now, peform an operation
    if (aCalculator.calculate('+',1,1,result))
        cout << "Result is: " << result << endl;
    else
        cout << "Calculator::calculate() failed" << endl;

    // How many operatrions did we perform?
    cout << "Total number of operations: " << aCalculator.getOpCount() << endl;

    return 0;
}