//
// CS2024 -- Lecture #21, Demo #8
//
// Iterating through the contents of a directory
//
#include <iostream>
#include <filesystem>

int main(int argc,char *argv[]) 
{
	std::string directoryName = "/Users/ron/Documents/CS2024/CS2024-Fall2023/Lectures/Lecture-21/Demos";
	
	// Use a range-based for to iterate through all directory entries
	for (auto dir_entry : std::filesystem::directory_iterator{directoryName})
	{
		std::string nextEntryName = dir_entry.path().filename().string();
		std::cout << "Next Entry: " << nextEntryName << std::endl;
	}
}