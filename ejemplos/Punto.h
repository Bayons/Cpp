#ifndef NAME
#define NAME
#include <iostream>

class Punto{
	public:
		Punto(int newX, int newY);
		Punto();
		int getX();
		int getY();
		void setX(int newX);
		void setY(int newY);
		void printPunto();
	private:
		int x, y;
};

Punto::Punto(int newX, int newY){
	x = newX;
	y = newY;
}

Punto::Punto(){
	x = 0;
	y = 0;
}

int Punto::getX(){
	return x;
}

int Punto::getY(){
	return y;
}

void Punto::setX(int newX){
	x = newX;
}

void Punto::setY(int newY){
	y = newY;
}

void Punto::printPunto(){
	std::cout << "(" << x << "," << y << ")" << "\n";
}
#endif
