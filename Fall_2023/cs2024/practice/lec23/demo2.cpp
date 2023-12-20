//
// CS2024 Lecture #23, Demo #2
//
// Meals and Multiple Inheritance
//
//  WARNING:  THIS FILE WILL NOT COMPILE
//

#include <iostream>
#include <string>

using namespace std;  //introduces namespace std

// Base meal class
class Meal
{
    public:
        Meal():mainDish(""){}
        Meal(string argMainDish):mainDish(argMainDish){}

        virtual void setMainDish(string argMainDish)
        {
            mainDish = argMainDish;
        }

        virtual void printMenu();

        string getMainDish()
        {
            return mainDish;
        }
    private:
        string mainDish;
};

// Virtual member to print
void Meal::printMenu()
{
    cout << "We will be having" << mainDish << endl;
}

// Derived breakfast class
class Breakfast : public Meal
{
    public:
        Breakfast():Meal(){}
        Breakfast(string argMainDish):Meal(argMainDish){}

        virtual void printMenu();
};

void Breakfast::printMenu()
{
    cout << "For BREAKFAST, ";
    Meal::printMenu();
}

// Derived LUNCH CLASS
class Lunch : public Meal
{
    public:
        Lunch():Meal(){}
        Lunch(string argMainDish):Meal(argMainDish){}

        virtual void printMenu();
};

void Lunch::printMenu()
{
    cout << "For LUNCH, ";
    Meal::printMenu();
}

// Multiply DERIVED Brunch class
class Brunch : public Breakfast, public Lunch
{
    public:
        Brunch():Meal(){}
        Brunch(string argMainDish):Meal(argMainDish){}

        virtual void printMenu();
};

void Brunch::printMenu()
{
    cout << "For BRUNCH, ";
    Meal::printMenu();
}

//
// main() tests out our Brunch class
//
int main(int argc, char * argv[])
{
    Brunch aBrunch("Scambled Eggs");
    aBrunch.printMenu();
    return 0;
}