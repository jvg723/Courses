// 
// CS 2024 -- Lecture #5
// 
// Demo #7 -- CoubnterClass
//
// Here's the Counter class. I've put all meber function
// definitions rightn here in the class definitoin, so they are
// all implicity inlined
//

class Counter
{
public:
        // Simple, default constructor, initalize counter to 0
        Counter()
        {
            mCounter = 0;
        }

        // USed if we ever need to reset the counter 
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
        int mCounter; // thjen actual counter variable
};