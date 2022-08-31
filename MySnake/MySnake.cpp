#include <iostream>
#include <Windows.h>
#include "Definitions.h"
#include "FunctionLibrary.h"
#include "Snake.h"
#include "Fruit.h"


enum GameStatistics
{
	FirstPlayerWin,
	SecondPlayerWin,
	NoOnePlayerWin
};

void MakeStartMenu()
{
	OutputMessage(&WelcomeText, 100);
	Sleep(4000);
	system("cls");
	OutputMessage(&ControlPromptText, 100);
	Sleep(2000);
	system("cls");
	OutputMessage(&RulesOfGameText, 50);
	Sleep(4000);
	system("cls");
}

void Input(Snake* firstSnake, Snake* secondSnake)
{
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	const short BufferSize = 128;
	INPUT_RECORD irInputBuffer[BufferSize];
	DWORD cNumRead = 0;
	PeekConsoleInput(hStdin, irInputBuffer, BufferSize, &cNumRead);

	for (DWORD i = 0; i < cNumRead; i++)
	{
		if (irInputBuffer[i].EventType == KEY_EVENT)
		{
			KEY_EVENT_RECORD keyEvent = irInputBuffer[i].Event.KeyEvent;
			if (keyEvent.bKeyDown)
			{
				switch (keyEvent.wVirtualKeyCode)
				{
				case 38:
					secondSnake->SetDirection(Direction::Up);
					break;
				case 40:
					secondSnake->SetDirection(Direction::Down);
					break;
				case 37:
					secondSnake->SetDirection(Direction::Left);
					break;
				case 39:
					secondSnake->SetDirection(Direction::Right);
					break;

				case 87:
					firstSnake->SetDirection(Direction::Up);
					break;
				case 83:
					firstSnake->SetDirection(Direction::Down);
					break;
				case 65:
					firstSnake->SetDirection(Direction::Left);
					break;
				case 68:
					firstSnake->SetDirection(Direction::Right);
					break;
				}
			}
		}
	}
}

void LogicMiscalculation(Snake* firstSnake, Snake* secondSnake, Fruit* fruitsArray, int fruitsNumber, bool& bGameOver, int& firstPlayerGlasses, int& secondPlayerGlasses, GameStatistics& gameStatistics)
{
	firstSnake->Move();
	secondSnake->Move();

	Location firstSnakeHeadLocation = firstSnake->GetHeadLocation();
	Location secondSnakeHeadLocation = secondSnake->GetHeadLocation();

	if (firstSnakeHeadLocation == secondSnakeHeadLocation)
	{
		bGameOver = true;
		gameStatistics = GameStatistics::NoOnePlayerWin;
		return;
	}

	bool bFirstSnakeDead = false;
	bool bSecondSnakeDead = false;

	for (Location location : firstSnake->GetSnakeTail())
	{
		if (location == firstSnakeHeadLocation)
		{
			bFirstSnakeDead = true;
		}

		if (location == secondSnakeHeadLocation)
		{	
			bSecondSnakeDead = true;
		}
	}

	for (Location location : secondSnake->GetSnakeTail())
	{
		if (location == firstSnakeHeadLocation)
		{
			bFirstSnakeDead = true;
		}

		if (location == secondSnakeHeadLocation)
		{
			bSecondSnakeDead = true;
		}
	}

	if (bFirstSnakeDead && bSecondSnakeDead)
	{
		gameStatistics = GameStatistics::NoOnePlayerWin;
		bGameOver = true;
		return;
	}

	if (bFirstSnakeDead)
	{
		gameStatistics = GameStatistics::SecondPlayerWin;
		bGameOver = true;
		return;
	}

	if (bSecondSnakeDead)
	{
		gameStatistics = GameStatistics::FirstPlayerWin;
		bGameOver = true;
		return;
	}

	for (int i = 0; i < fruitsNumber; i++)
	{
		bool bFruitEaten = false;

		if(firstSnakeHeadLocation == fruitsArray[i].GetLocation())
		{
			firstSnake->AddSegment();
			firstPlayerGlasses++;
			bFruitEaten = true;
		}

		if (secondSnakeHeadLocation == fruitsArray[i].GetLocation())
		{
			secondSnake->AddSegment();
			secondPlayerGlasses++;
			bFruitEaten = true;
		}

		if (bFruitEaten)
		{
			fruitsArray[i].Relocation();
		}
	}

	if (secondPlayerGlasses == PointsToWin && firstPlayerGlasses == PointsToWin)
	{
		gameStatistics = GameStatistics::NoOnePlayerWin;
		bGameOver = true;
		return;
	}

	if (firstPlayerGlasses == PointsToWin)
	{
		gameStatistics = GameStatistics::FirstPlayerWin;
		bGameOver = true;
		return;
	}

	if (secondPlayerGlasses == PointsToWin)
	{
		gameStatistics = GameStatistics::SecondPlayerWin;
		bGameOver = true;
		return;
	}
}

void Rendering(Snake* firstSnake, Snake* secondSnake, Fruit* fruitsArray, int fruitsNumber, const int& firstPlayerGlasses, const int& secondPlayerGlasses)
{
	system("cls");

	DrowLine();

	std::string screenChars;

	for (int h = 0; h < FieldHeight; h++)
	{
		for (int w = 0; w < FieldWidth + LeftMargin + RightMargin; w++)
		{
			if (w == 0 || w == FieldWidth + RightMargin - 1)
			{
				screenChars += FieldBoundary;
			}
			else
			{
				int state = 0;

				if (firstSnake->GetHeadLocation().y == h && firstSnake->GetHeadLocation().x + LeftMargin == w)
				{
					state = 1;
				}

				if (secondSnake->GetHeadLocation().y == h && secondSnake->GetHeadLocation().x + LeftMargin == w)
				{
					state = 2;
				}

				for (Location location : firstSnake->GetSnakeTail())
				{
					if (location.y == h && location.x + LeftMargin == w)
					{
						state = 3;
					}
				}

				for (Location location : secondSnake->GetSnakeTail())
				{
					if (location.y == h && location.x + LeftMargin == w)
					{
						state = 4;
					}
				}

				for (int i = 0; i < fruitsNumber; i++)
				{
					if (fruitsArray[i].GetLocation().y == h && fruitsArray[i].GetLocation().x + LeftMargin == w)
					{
						state = 5;
					}
				}

				switch (state)
				{
				case 0:
					screenChars += ' ';
					break;
				case 1:
					screenChars += FirstSnakeHead;
					break;
				case 2:
					screenChars += SecondSnakeHead;
					break;
				case 3:
					screenChars += FirstSnakeBody;
					break;
				case 4:
					screenChars += SecondSnakeBody;
					break;
				case 5:
					screenChars += FruitSymbol;
					break;
				default:
					break;
				}
			}
		}
		screenChars += '\n';
	}
	std::cout << screenChars;

	DrowLine();

	std::cout << "\n  1P: " << firstPlayerGlasses << "/" << PointsToWin << " 2P: " << secondPlayerGlasses << "/" << PointsToWin << std::endl;
}

void MakeEndMenu(const GameStatistics& gameStatistics)
{
	system("cls");

	switch (gameStatistics)
	{
	case FirstPlayerWin:
		OutputMessage(&FirstPlayerWinText, 100);
		break;
	case SecondPlayerWin:
		OutputMessage(&SecondPlayerWinText, 100);
		break;
	case NoOnePlayerWin:
		OutputMessage(&NoOnePlayerWinText, 100);
		break;
	}

	std::cout << "\n\n";
}

int main()
{
	MakeStartMenu();

    bool bGameOwer = false;
	int firstPlayerGlasses = 0;
	int secondPlayerGlasses = 0;
	GameStatistics gameStatistics;

	Snake* firstSnake = new Snake(FirstSnakeHeadLocation);
	Snake* secondSnake = new Snake(SecondSnakeHeadLocation);
	Fruit* fruits = new Fruit[NnumberFruits];

	while (!bGameOwer)
	{
		Input(firstSnake, secondSnake);
		LogicMiscalculation(firstSnake, secondSnake, fruits, NnumberFruits, bGameOwer, firstPlayerGlasses, secondPlayerGlasses, gameStatistics);
		Rendering(firstSnake, secondSnake, fruits, NnumberFruits, firstPlayerGlasses, secondPlayerGlasses);
		Sleep(1000 / SnakeSpeed);
	}

	MakeEndMenu(gameStatistics);
	
	delete firstSnake;
	delete secondSnake;
	delete[] fruits;

	return 0;
}

