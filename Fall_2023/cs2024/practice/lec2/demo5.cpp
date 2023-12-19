// 
// CS 2024 -- Lecture #2
// 
// Demo #5 -- Various

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
        int howManyTimes;
        string name;

        cout << "What is your name? ";
        getline(cin,name);

        cout << "How many times should I print it? ";
        cin >> howManyTimes;

        // Use a for loop   
        cout << "Using a for loop..." << endl;
        for (int i=0; i<howManyTimes; i++)
        {
            cout << name << endl;
        }

        // Use a while loop
        int j = 0;

        cout << "Using a while loop" << endl;
        while (j < howManyTimes)
        {
            cout << name << endl;
            j++;
        }

        // Use a do...while loop
        int k = 0; // Original style init syntax

        cout << "Using a do...while loop" << endl;
        do
        {
            cout << name << endl;
            k++;
        } while (k < howManyTimes);

    return 0;

}