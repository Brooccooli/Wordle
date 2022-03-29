#include "FileReader.h"
#include <fstream>
#include <iostream>
#include <string>

using std::ifstream;

#include <cstdlib>
#include <ctime>

#include <random>

int randNum(int range) 
{
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<> distr(0, range); // define the range

	return distr(gen);
}

std::string FileReader::Read() {
	ifstream indata; // indata is like cin
	std::string words;

	indata.open("words.txt");
	if (!indata)
	{
		std::cerr << "ERROR: file couldn't be opened" << std::endl;
		exit(1);
	}

	indata >> words;

	// Ramdomize word
	int random = randNum(8598); // feedback: it's ok to trust the specification of the assignemnt, that text file contains exactly 8598 lines but
								// for more reliable solution I'd count how many lines was there in fact, from the reading code below and then take
								// a random line from that range(its ok to read whole file into RAM in this case, but make sure you release it after)

	int i = 0;
	while (!indata.eof()) { // keep reading until end-of-file
		// Breaks if index = random position
		if (random == i) 
		{
			break;
		}
		indata >> words; // sets EOF flag if no value found
		i++;
	}
	indata.close();

	return words;
}