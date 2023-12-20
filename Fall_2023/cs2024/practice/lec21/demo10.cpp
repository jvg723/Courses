//
// CS2024 -- Lecture #21, Demo #10
//
// Creating directories
//
#include <iostream>
#include <fstream>
#include <filesystem>

int main(int argc, char *argv[])
{
    std::string directorName="/Users/josephgiliberto/Courses/Fall_2023/cs2024/SampleDirectory";

    // Create the directories
    if (std::filesystem::create_directories(directorName))
    {
        std::cout << "Directories created!" << std::endl;

        // Open a new file in the directory just created
        std::ofstream myFile(directorName+"/MyFile.txt");
        if (myFile.is_open())
        {
            myFile << "Hello World!" << std::endl;
        }
    } else{
        std::cout << "Either directory already exists of error occured" << std::endl;
    }
}