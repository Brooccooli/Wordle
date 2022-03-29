#include <iostream>
#include <string>
#include <cctype>
#include "Container.h"

/*
Why I choose this container:
	It has a fixed length that I know my program will never go over.
	It can only add string with the length of 5 so i know the game loop will never encouter that on word is too long.
	It has built in uppercase transformer.
	It's easy to set, add, print and get the word length.
*/

// Clears the container
void Container::clearContainer() 
{
	for (size_t i = 0; i < length; i++) // feedack: is there a specific reason you wanted to set each element to an empty string? Often char buffers are either filled
		// or only 1st element of them is set to '\0' - null terminator
	{
		chars[i] = empty;
	}
}

// ------------ Constructors --------------
// ----------------------------------------
Container::Container(char str[]) 
{
	Set(str);
}
Container::Container(std::string str)
{
	Set(str);
}

// ------------ Set methods --------------
// ---------------------------------------
void Container::Set(char str[]) 
{
	clearContainer();
	Add(str);
}
void Container::Set(std::string str)
{
	clearContainer();
	Add(str);
}

// ------------ Add methods --------------
// ---------------------------------------
void Container::Add(char str[]) 
{
	int index = Length();
	for (size_t i = 0; i < 5; i++)
	{
		chars[index + i] = str[i];
	}
}
void Container::Add(std::string str)
{
	int index = Length();
	for (size_t i = 0; i < 5; i++)
	{
		chars[index + i] = str[i];
	}
}
// Only adds of char ins't in the container
void Container::UniqueAdd(char c) 
{
	for (size_t i = 0; i < Length(); i++)
	{
		if (c == chars[i]) { return; }
	}

	chars[Length()] = c;
}

// ------------ Tools --------------
// ---------------------------------
void Container::Print()
{
	for (size_t i = 0; i < Length(); i++)
	{
		std::cout << chars[i];
	}
}

void Container::Uppercase()
{
	for (size_t i = 0; i < Length(); i++)
	{
		chars[i] = std::toupper(chars[i]);
	}
}

char Container::At(int index) 
{
	return chars[index];
}

int Container::Length() 
{
	for (size_t i = 0; i < length; i++)
	{
		if (chars[i] == empty) 
		{
			return i;
		}
	}
}
