//
// CS2024 -- Lecture #21, Demo #10
//
// Creating directories
//
#include <iostream>
#include <fstream>
#include <filesystem>

int main(int argc,char *argv[]) 
{
	std::string directoryName = "/Users/ron/Desktop/CS2024/SampleDirectory";
	
	// Create the directories
	if (std::filesystem::create_directories(directoryName)) {
		std::cout << "Directories created!" << std::endl;
		
		// Open a new file in the directory just created
		std::ofstream myFile(directoryName+"/MyFile.txt");
		if (myFile.is_open()) {
			// If file opened successfully, write "Hello World" to the file
			myFile << "Hello world!" << std::endl;
		}
	} else {
		std::cout << "Either directory already exists or error occurred" << std::endl;
	}
}