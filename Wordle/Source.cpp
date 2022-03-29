#include <iostream>
#include <string>
#include "GameLoop.h"
#include "AsciiArt.h"

//feedback: this file could have a more representative name, like "TitleScreen.cpp" or "AsciiBackground.cpp"

void titleScreen() 
{
	std::string titleAscii = "";
	titleAscii += "rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr=";
	titleAscii += "r--g---------g--gggg--gggg--gggg--g-----gggggg----r=";
	titleAscii += "r--g---------g-g----g-g---g-g---g-g-----g---------r=";
	titleAscii += "r--g---------g-g----g-gggg--g---g-g-----ggg-------r=";
	titleAscii += "r---g---g---g--g----g-g---g-g---g-g-----g---------r=";
	titleAscii += "r----g-g-g-g---g----g-g---g-g---g-g-----g---------r=";
	titleAscii += "r-----g---g-----gggg--g---g-gggg--ggggg-gggggg----r=";
	titleAscii += "rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr=";

	AsciiArt ascii;
	ascii.print(titleAscii);

	std::cout << "Yellow = Letter is in the word but in another position" << std::endl;
	std::cout << "Green = Letter is in the word and in the correct position" << std::endl;
}

int main() {
	titleScreen();

	GameLoop game;
	game.loop();

	return 0;
}