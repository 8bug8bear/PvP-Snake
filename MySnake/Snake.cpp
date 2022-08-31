#include "Snake.h"

Snake::Snake(Location location)
{
	direction = Direction::Stop;
	newDirection = Direction::Stop;

	snakeHead = location;

	lastHeadLocation = location;
	lastTailLocation = location;
}

void Snake::SetDirection(Direction localNewDirection)
{
	newDirection = localNewDirection;
}

void Snake::MoveTail()
{
	if (snakeTail.empty())
	{
		return;
	}

	if (snakeTail.size() == 1)
	{
		snakeTail.front() = lastHeadLocation;
	}
	else
	{
		snakeTail.pop_back();
		snakeTail.push_front(lastHeadLocation);
	}
}


void Snake::Move()
{
	lastHeadLocation = snakeHead;

	if (snakeTail.empty())
		lastTailLocation = snakeHead;
	else
		lastTailLocation = snakeTail.back();

	switch (newDirection)
	{
	case Up:
		if (direction != Direction::Down)
			direction = newDirection;
		break;
	case Down:
		if (direction != Direction::Up)
			direction = newDirection;
		break;
	case Left:
		if (direction != Direction::Right)
			direction = newDirection;
		break;
	case Right:
		if (direction != Direction::Left)
			direction = newDirection;
		break;
	}

	switch (direction)
	{
	case Up:
		if (snakeHead.y - 1 < 0)
			snakeHead.y = FieldHeight - 1;
		else
			snakeHead.y--;
		break;
	case Down:
		if (snakeHead.y + 1 > FieldHeight - 1)
			snakeHead.y = 0;
		else
			snakeHead.y++;
		break;
	case Left:
		if (snakeHead.x < 0)
			snakeHead.x = FieldWidth - 1;
		else
			snakeHead.x--;
		break;
	case Right:
		if (snakeHead.x + 1 > FieldWidth - 1)
			snakeHead.x = 0;
		else
			snakeHead.x++;
		break;
	}

	MoveTail();
}

Location Snake::GetHeadLocation()
{
	return snakeHead;
}

std::list<Location> Snake::GetSnakeTail()
{
	return snakeTail;
}

void Snake::AddSegment()
{
	snakeTail.push_back(lastTailLocation);
}
