#include <iostream>
#include "Punto.h"

int main(){
	// Constructor con parametros
        Punto p1(1, 2);
        // Si usas un constructor sin argumentos, no se ponen parentesis
        Punto p2;

        std::cout << "Valores iniciales:\n";
        p1.printPunto();
        p2.printPunto();

        p1.setX(6);
        p1.setY(6);

        p2.setX(7);
        p2.setY(7);

        std::cout << "Valores finales:\n";
        p1.printPunto();
        p2.printPunto();

        p1 = p2;

        std::cout << "Asignacion (p1=p2):\n";
        p1.printPunto();
        p2.printPunto();

        return 0;
}
