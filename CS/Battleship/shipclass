#include <iostream>
#include <string>
#include "Ship.hpp"

using std::string;
using std::cin;
using std::cout;
using std::endl;

Ship::Ship(string sName, int sLength) // Ship nondefault constructor.
{
	name = sName;
	length = sLength;
	damage = 0;
}

string Ship::getName()
{
	return name;
}

int Ship::getLength()
{
	return length;
}

int Ship::getDamage()
{
	return damage;
}

void Ship::takeHit()
{
	damage += 1;
}

