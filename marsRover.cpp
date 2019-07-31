#include <iostream>
#include <string.h>

class MarsRover {

	private:
		int x;
		int y;
		char ort;
		

	public:
		
		static int maxX;
		static int maxY;

		MarsRover();
		MarsRover(int, int, char);
		void displayPosition() const;
		bool isValidMove();
		void notValidMove();
		void leftRotation();
		void righRotation();
		void movePosition();
};

MarsRover::MarsRover() : x(0), y(0), ort('N') {}

MarsRover::MarsRover(int x, int y, char ort) : x(x), y(y), ort(ort) {}

void MarsRover::displayPosition() const {
	std::cout << x << " " << y << " " << ort << "\n";
}

void MarsRover::leftRotation() {

	switch(ort) {
		case 'N': ort = 'W';
				break;
		case 'E': ort = 'N';
				break;
		case 'S': ort = 'E';
				break;
		case 'W': ort = 'S';
				break;
	}
}

void MarsRover::righRotation() {

	switch(ort) {
		case 'N': ort = 'E';
				break;
		case 'E': ort = 'S';
				break;
		case 'S': ort = 'W';
				break;
		case 'W': ort = 'N';
				break;
	}
}

bool MarsRover::isValidMove() {

	if ( x > maxX || y > maxY || x < 0 || y < 0 )
		return false;
	return true;
}

void MarsRover::notValidMove() {
	std::cout << "\nYou cannot be proceeded with desired moves.\n";
	std::cout << "As it is out of boundary of Rover...SORRY\n";
	return;
}

void MarsRover::movePosition() {

	switch(ort) {
		case 'N': y++;
				  break;
	
		case 'E': x++;
				  break;

		case 'S': y--;
				  break;

		case 'W': x--;
				  break;
	}
}

int MarsRover::maxX;
int MarsRover::maxY;

int main() {

	char ans;
	int maxX, maxY;
	std::cin >> maxX >> maxY;

	MarsRover::maxX = maxX;
	MarsRover::maxY = maxY;

	do {

		int x,y;
		char ot;
		std::cin >> x >> y >> ot;

		MarsRover rover(x,y,ot);

		std::string movement;
		std::cin >> movement;

		for(int i=0; i<movement.size(); i++) {

			if ( movement[i] == 'L' )
				rover.leftRotation();

			else if ( movement[i] == 'R' )
				rover.righRotation();

			else {
				rover.movePosition();
				if ( !rover.isValidMove() ) {
					rover.notValidMove();
					break;
				}
			}
		}

		if ( rover.isValidMove() ) 
			rover.displayPosition();
		

		std::cout << "\nDo you want to continue(Y/N) : ";
		std::cin >> ans; 

	}while(ans == 'Y' || ans == 'y');

	return 0;
}
