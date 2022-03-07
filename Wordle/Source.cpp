#include <iostream>
#include <string>
#include "GameLoop.h"
#include "AsciiArt.h"

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
}

int main() {
	titleScreen();

	GameLoop game;
	game.loop();

	return 0;
}