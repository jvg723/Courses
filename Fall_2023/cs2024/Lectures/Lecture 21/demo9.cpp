//
// CS2024 -- Lecture #21, Demo #9
//
// Looking at file status
//
#include <iostream>
#include <filesystem>

int main(int argc,char *argv[]) 
{
	std::string directoryName = "/Users/ron/Documents/CS2024/CS2024-Fall2023/Lectures/Lecture-21/Demos";
	
	// Use a range-based for to iterate through all directory entries
	for (auto dir_entry : std::filesystem::directory_iterator{directoryName})
	{
	    std::filesystem::path nextPath = dir_entry.path();
		std::string nextEntryName = nextPath.filename().string();
		std::cout << "Next Entry: " << nextEntryName ;
		
		// use file_status to determine type of file
		std::filesystem::file_status status = std::filesystem::status(nextPath);
		if (std::filesystem::is_directory(status))
			std::cout << "   -- directory" << std::endl;
	    if (std::filesystem::is_regular_file(status)) 
	    	std::cout << "   -- regular file" << std::endl;
	}
}