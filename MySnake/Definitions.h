#pragma once
#include <string>

struct Location
{
	int x;
	int y;
};

const Location FirstSnakeHeadLocation{ 8,15 };

const Location SecondSnakeHeadLocation{ 12,15 };

const int FieldHeight = 20; //
                            // there is no accounting of borders
const int FieldWidth = 20;  //

const int LeftMargin = 1;

const int RightMargin = 2;

const int PointsToWin = 10;

const int NnumberFruits = 3; // The number of fruits at the same time on the level

const int SnakeSpeed = 4; // "cells" per second

const char FieldBoundary = '#';

const char FirstSnakeHead = '1';

const char FirstSnakeBody = '0';

const char SecondSnakeHead = '2';

const char SecondSnakeBody = '@';

const char FruitSymbol = 'F';

const std::string WelcomeText = "Welcome to the PvP snake game";
const std::string ControlPromptText = "To control the first snake,\nuse the W A S D keys, \nuse the arrows to\ncontrol the second one";
const std::string RulesOfGameText = "If your snake eats its tail,\nor the tail of the opponent,\nthen you will lose.\nIf the snakes collide heads,\nit will be a draw.\nFruits give points,\nthe first one who gets the\nrequired number of points will win";
const std::string FirstPlayerWinText = "Congratulations to the first player on the victory!";
const std::string SecondPlayerWinText = "Congratulations to the second player on the victory!";
const std::string NoOnePlayerWinText = "Unfortunately, both players lost, we'll be lucky next time.";

