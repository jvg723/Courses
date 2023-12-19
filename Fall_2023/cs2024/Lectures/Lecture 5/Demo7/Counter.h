//
// CS2024 -- Lecture #5
//
// Demo #7 -- CounterClass
//

//
// Here's the Counter class.   I've put all member function
// definitions right here in the class definition, so they are
// all implicitly inlined.
//

class Counter
{
public:
	// Simple, default constructor, initializes counter to 0
	Counter()
	{
		mCounter = 0;
	}
	
	// Used if we ever need to reset the counter
	void resetCounter()
	{
		mCounter = 0;
	}
	
	// get the value of the counter
	int getCounter()
	{
		return mCounter;
	}
	
	// increment the counter by one
	void increment()
	{
		mCounter++;
	}
	
	// decrement the counter by one
	void decrement()
	{
		mCounter--;
	}
	
private:
	int mCounter;  // the actual counter variable
};
