//
// CS2024 Lecture #17, Demo 2
//
// Sample header file for CLibrary
//

typedef void *Logger;

Logger OpenLogger();
void LogMessage(Logger logger,char *msg);
void CloseLogger(Logger logger);

