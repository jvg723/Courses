//
// CS2024  Lecture #23, Demo #4
//
// Virtual Base Classes and Multiple Inheritance
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

// Virutal member to print menu
void Meal::printMenu()
{
	cout << "we will be having " << mainDish << endl;
}


// DERIVED Breakfast class
// NOW WITH A VIRTUAL BASE CLASS!!
class Breakfast : virtual public Meal
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


// DERIVED Lunch class
// NOW WITH A VIRTUAL BASE CLASS!!
class Lunch : virtual public Meal
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


// MULTIPLY DERIVED Brunch class
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

int main()
{	
	Brunch aBrunch("Scrambled Eggs");
	aBrunch.printMenu();
	return 0;
}

