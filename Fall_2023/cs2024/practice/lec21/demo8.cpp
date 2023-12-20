//
// CS2024 -- Lecture #21, Demo #8
//
// Iterating through the contents of a directory
//
#include <iostream>
#include <filesystem>

int main(int argc, char *argv[])
{
    std::string directorName="/Users/josephgiliberto/Courses/Fall_2023/cs2024";

    // Use a range-based for to iterate through all directory entries
    for (auto dir_entry : std::filesystem::directory_iterator{directorName})
    {
        std::string nextEntryName = dir_entry.path().filename().string();
        std::cout << "Next Entry: " << nextEntryName << std::endl;
    }
}