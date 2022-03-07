#include <iostream>
#include "AsciiArt.h"

using std::cout;
using std::endl;

// ----------- Text Background Color ----------------
#define BACKGROUND(color, text) "\033[3;42;" << static_cast<int>(color) << "m" << text << "\033[0m"
enum class BackgroundColor : int {
	Red = 41,
	Green = 42,
	Yellow = 43,
	BrightRed = 101,
	BrightGreen = 102,
	BrightYellow = 103
};

void AsciiArt::print(std::string input) 
{
	cout << endl;
	for (size_t i = 0; i < input.length(); i++)
	{
		// New line
		if (input[i] == '=')
		{
			cout << endl;
		}
		// Green box
		else if(input[i] == 'g')
		{
			cout << BACKGROUND(BackgroundColor::Green, " ");
		}
		// Red box
		else if(input[i] == 'r')
		{
			cout << BACKGROUND(BackgroundColor::Red, " ");
		}
		// Empty space
		else 
		{
			cout << " ";
		}
	}
}

void AsciiArt::smiley(bool happy)
{
	//------------ Green smile ------------------
	std::string smile = "";
	smile += "-gggg-=";
	smile += "g-gg-g=";
	smile += "gggggg=";
	smile += "g-gg-g=";
	smile += "g----g=";
	smile += "-gggg-=";

	//------------ Red frown ------------------
	std::string frown = "";
	frown += "-rrrr-=";
	frown += "r-rr-r=";
	frown += "rrrrrr=";
	frown += "r----r=";
	frown += "r-rr-r=";
	frown += "-rrrr-=";

	if (happy) 
	{
		print(smile);
	}
	else 
	{
		print(frown);
	}
}