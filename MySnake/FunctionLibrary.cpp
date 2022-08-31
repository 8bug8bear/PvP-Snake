#include "FunctionLibrary.h"
#include <Windows.h>
#include <iostream>

bool operator==(const Location& a, const Location& b)
{
    return a.x == b.x && a.y == b.y;
}

void OutputMessage(const std::string* message, int symbolOutputTime)
{
	std::cout << "\n \n \t";
	for (int i = 0; i < message->length(); i++)
	{
		Sleep(symbolOutputTime);
		char symbol = message->at(i);
		std::cout << symbol;
		if (symbol == '\n')
			std::cout << '\t';
	}
}

void DrowLine()
{
	const int StringLength = FieldWidth + LeftMargin + RightMargin;
	std::string lineArray;
	for (int i = 0; i < StringLength - 1; i++)
	{
		lineArray += FieldBoundary;
	}
	lineArray += "\n";
	std::cout << lineArray;
}
