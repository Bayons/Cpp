#include <iostream>

int magia(int n){
	if (n%2!=0){
		n=3*n+1;
	}else{
		n/=2;
	}
	return n;
}

int ciclo(int n){
	int cont = 0;

	while(n!=1){
		cont++;
		n=magia(n);
	}
	cont++;
	return cont;
}

int main(void){
	int x, y, cont, max, a;

	while(std::cin >> x){
		std::cin >> y;
		max = 0;

		std::cout << x << " " << y << " ";
		if (y < x){
			a = y;
			y = x;
			x = a;
		}

		for (cont = x; cont <= y; cont++){
			if ((a=ciclo(cont))>max)
				max = a;
		}
		std::cout << max << "\n";
	}
	std::cout << "\n";

	return 0;
}
