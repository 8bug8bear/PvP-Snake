#include "Fruit.h"
#include "FunctionLibrary.h"


Fruit::Fruit()
{
	Relocation();
}

Location Fruit::GetLocation()
{
	return location;
}

void Fruit::Relocation()
{
	int x = rand() % FieldWidth;
	int y = rand() % FieldWidth;
	
	Location newLocation{ x,y };
	
	if (newLocation == FirstSnakeHeadLocation || newLocation == SecondSnakeHeadLocation)
	{
		newLocation.x++;
		newLocation.y++;
	}

	location = newLocation;
}
