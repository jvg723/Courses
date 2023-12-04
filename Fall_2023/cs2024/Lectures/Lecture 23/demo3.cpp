//
// CS2024 Lecture #23, Demo #3
//
// Brunch hierarchy, take 2
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


// DERIVED Lunch class
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


// MULTIPLY DERIVED Brunch class
class Brunch : public Breakfast, public Lunch
{
public:
	Brunch()
	{
		Lunch::setMainDish("");
		Breakfast::setMainDish("");
	}
	
	Brunch(string argMainDish)
	{
		Lunch::setMainDish(argMainDish);
		Breakfast::setMainDish(argMainDish);  
	}
	
	virtual void printMenu();
	
};

void Brunch::printMenu()
{
	cout << "For BRUNCH, ";
	Lunch *alunch = (Lunch *) this;
	// Need to make a choice here, really doesn't matter
	alunch->Meal::printMenu();
}

int main()
{	
	Brunch aBrunch("Scrambled Eggs");
	aBrunch.printMenu();
	return 0;
}

