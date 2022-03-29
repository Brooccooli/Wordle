#pragma once
#include <string>

/*
Why I choose this container:
	It has a fixed length that I know my program will never go over.
	It can only add string with the length of 5 so i know the game loop will never encouter that on word is too long.
	It has built in uppercase transformer.
	It's easy to set, add, print and get the word length.
*/

class Container 
{
private:
	const int length = 80;
	const char empty = *"";
	char chars[80]; // feedback: not sure I understand why this has size 80 while you have words of size 5 in the file.
	void clearContainer();

public:
	Container(char str[]);
	Container(std::string str); // feedback: this argument as well as args in Set() and Add() could be string refs to avoid copying.

	void Uppercase();

	void Set(char str[]);
	void Set(std::string str);

	void Print();

	void Add(char str[]);
	void Add(std::string str);

	void UniqueAdd(char c);

	char At(int index);
	int Length();
};