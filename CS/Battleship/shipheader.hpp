#ifndef SHIP_H
#define SHIP_H
#include <iostream>

using std::string;

class Ship
{
	private:
		string name;
		int length;
		int damage;
	public:
		Ship(string sName, int sLength);
		Ship();
		string getName();
		int getLength();
		int getDamage();
		void takeHit();
};

#endif
