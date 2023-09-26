#include "GoodReads.hpp"
#include "Functions.hpp"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	GoodReads source;
	read_from_files(source,argv);	

	string command;
	while (cin >> command)
		command_list(command, source);

}
