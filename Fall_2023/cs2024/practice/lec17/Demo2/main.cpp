//
// CS2024 -- Lecture #17, Demo #2
//
// Custom Deleters
//

#include <iostream>
#include <memory>
#include "Logger.h"

using namespace std;


//
// closeLogger() is a custom delete function for our Logger
//
void closeLogger(Logger logger)
{
    cout << "Custom deleter for logger" << endl;
    CloseLogger(logger);
}

int main(int argc, char *argv[])
{
    // Allocate a new shared pointer for our logger library
    shared_ptr<void> loggerPtr( OpenLogger(), closeLogger );

    // double check the reference count
    cout << "Referecnce count fo rloggerPtr: " << loggerPtr.use_count() << endl;

    // Log something.  To get access to the original pointer used to create
    // the shared pointer, use the get() member function
    LogMessage(loggerPtr.get(),(char *)"Hello World Log Message!");

    // Watch for clean up messages!
}