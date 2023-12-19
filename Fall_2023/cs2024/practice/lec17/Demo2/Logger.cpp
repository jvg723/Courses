//
// CS2024 Lecture #17, Demo 2
//
// C Library 
//

#include <stdio.h>  // Used for accessing C-library functions
#include "Logger.h"

// API CALL -- Allocates a "Logger" and returns 
// a generic pointer 

Logger OpenLogger()
{
    // A logger is really just an open C-style file pointer
    FILE *fp = fopen("MyLogFile","w");
    if (fp)
    {
        printf("OpenLogger() opened file\n");
    }
    return (Logger) fp;
}

// API CALL -- Log a message to the file
void LogMessage(Logger logger,char *msg)
{
  fprintf((FILE *)logger,"%s\n",msg);
}

// API CALL -- Close the logger!
void CloseLogger(Logger logger)
{
    printf("CloseLogger() called\n");
    if (logger)
        fclose((FILE *) logger);
}