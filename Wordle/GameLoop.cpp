#include "GameLoop.h"
#include "FileReader.h"
#include <iostream>
#include <algorithm>
#include "AsciiArt.h"
#include "Container.h"

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

// Adds all the wrong letter, will add duplicates
std::string wrongLetters = "";

bool wordCheck(Container word, Container guess)
{
    int correct = 0;

    //Checks Answere
    for (size_t i = 0; i < 5; i++)
    {
        bool notFound = true;
        bool rightPos = false;

        for (size_t j = 0; j < 5; j++)
        {
            if (guess.At(i) == word.At(j))
            {
                // Found
                notFound = false;

                // Right position
                if (i == j)
                {
                    std::cout << BACKGROUND(BackgroundColor::Green, guess.At(i));
                    rightPos = true;
                    correct++;
                    break;
                }
            }
        }
        // Not found
        if (notFound)
        {
            std::cout << guess.At(i);
            wrongLetters += guess.At(i);
        }

        // Found but wrong position
        else if (!rightPos)
        {
            std::cout << BACKGROUND(BackgroundColor::Yellow, guess.At(i));
            notFound = false;
        }
    }

    // All letter are correct and on the correct position
    if (correct == 5) 
    {
        return true;
    }

    return false;
}

// Game logic loop
void GameLoop::loop() 
{
    AsciiArt art;

    // Gets a random word
	FileReader reader;

    // Container
    Container cWord(reader.Read());

	const int wordLength = 5;

	Container guess("test");
    int guesses = 0;

    //The loop
	while (true) 
	{
        //Loss
        if (guesses >= 6)
        {
            std::cout << std::endl << "No more tries! The word was: ";
            cWord.Print();
            art.smiley(false);
            break; 
        }

		std::cout << std::endl << "Guess a five letter word!" << std::endl << ":";
		
        //Right amount of characthers
        while (true)
        {
            char temp[10];
            std::cin >> temp;
            guess.Set(temp);
            std::cout << std::endl;

            if (guess.Length() == wordLength) { break; }

            std::cout << BACKGROUND(BackgroundColor::Red, "NOT FIVE LETTERS") << std::endl;
        }

        //Makes string uppercase
        guess.Uppercase();

        //Win and prints out the letters with background color
        if (wordCheck(cWord, guess)) 
        {
            std::cout << std::endl << "CORRECT!" << std::endl;
            art.smiley(true);
            break;
        }

        guesses++;

        std::cout << std::endl << std::endl << "Wrong letters: " << wrongLetters;
        std::cout << std::endl << "Guesses left: " << 6 - guesses << std::endl;
	}
}