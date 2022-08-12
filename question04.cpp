#define _CRT_SECURE_NO_WARNINGS


//Question 4 - Filesystem & args  

// Task: Implement the code as described in the main body, make sure to handle cases when the requested file is not found or the "files" directory doesn't exists and you have to create it
// Prefer modern solutions over classic C style solutions and keep in mind that this code should be able to run in other windows, linux and other platforms (hint: '/' and '\' in file paths)


#include <iostream>
#include <iostream>
#include <fstream> 
#include <string>

int main(int argc, char** argv)
{
	//If user passed "create" argument 
	//		Create (or overwrite) a file named *argument2.txt*  with the text "Hello from *argument3*" in a folder named "files" under the current working directory  
	//else if user passed "read" argument 
	//		read a file named* argument2* from a folder named "files" under the current working directory and print it to the console

	//Execution example (assuming working directory c:\code): question04.exe create test1 Nir - should create the file c:\code\files\test1.txt with the content "Hello from Nir"
	//Execution example (assuming working directory c:\code): question04.exe read test1  - should print "Hello from Nir" in the console (assuming the previous command was executed) 
	//If the user passed "create" argument

	for (int i = 0; i < argc; i++) {
		std::cout << "arg[" << i << "] = " << argv[i] << std::endl;
	}
	
	if (std::string(argv[1]) == "create")
	{
		std::string fileName = argv[2];
		fileName += ".txt";
		//std::cout << fileName.c_str() << std::endl;
		std::ofstream out(fileName.c_str());
		//char* name = argv[3];
		out << "Hello From " << argv[3];
		//std::cout << "Hello From " << name << std::endl;
		out.close();

		std::cout << "File saved" << std::endl;
	}
	else if (std::string(argv[1]) == "read") {
		std::string fileName = argv[2];
		fileName += ".txt";
		std::ifstream in(fileName.c_str());
		
		char buff[100];
		in.getline(buff, 100);
		std::cout << buff << std::endl;

		in.close();
	}

	std::cout << "Press enter to exit" << std::endl;
	getchar();
	return 0;
}