# UndergradWork
Various Examples of Projects from Undergraduate Work in Applied Mathematics, Computer Science, and Statistical Methods classes. As you navigate down in each list, the complexity of the assignments tends to increase.

# Directory
## ST
Projects from ST411, Methods of Data Analysis. Coding written in R/RStudio.
## MTH
Projects from MTH420, Models and Methods of Applied Mathematics. Coding written in Python.
## CS
Projects from CS161, written in C++.
The "Battleship" folder was the last assignment to create classes which could be used to make a program which plays a classic game of Battleship. Below is a simple main function which illustrates a few function calls. (Given in the prompt):
int main()
{
   BBoard board;  // creates BBoard object
   Ship ship1("Boaty McBoatface", 2);  // creates Ship object
   board.placeShip(&ship1, 2, 2, 'R');  // adds the Ship object to the Board object
   cout << std::boolalpha << board.allShipsSunk() << endl;  // prints whether all Ships are sunk
   board.attack(2, 2);  // attacks one square the Ship is on
   cout << "damage = " << ship1.getDamage() << endl;  // asks the Ship for its damage
   board.attack(2, 3);  // attacks the other square the Ship is on to sink the Ship
   cout << std::boolalpha << board.allShipsSunk() << endl;  // prints whether all Ships are sunk
   board.attack(2, 3);  // attacks a square that was already attacked
   Ship* shipPtr = board.getShipsArrayElement(2, 3);  // gets the address of the Ship on square (2,3)

   return 0;
}
