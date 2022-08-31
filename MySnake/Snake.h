#pragma once
#include "Definitions.h"
#include <list>

enum Direction
{
	Stop,
	Up,
	Down,
	Left,
	Right
};

class Snake
{
protected:
	Direction direction;

	Direction newDirection;

	std::list<Location> snakeTail;

	Location snakeHead;

	Location lastHeadLocation;

	Location lastTailLocation;

	void MoveTail();

public:
	Snake(Location location);

	void SetDirection(Direction newDirection);

	void Move();

	Location GetHeadLocation();

	std::list<Location> GetSnakeTail();

	void AddSegment();
};

