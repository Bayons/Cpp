/*

***** SIMPLE LANGUAGE *****
Recoge comandos "set x" o "add x" y opera en relacion a ellos,
eliminando el propio comando si el realizarla implica reducir el
numero.

*/

#include<iostream>
#include<string>

long long int maximumProgramValue(unsigned int n){

	long long x = 0;
	unsigned int i;
	std::string pal = "";
	long a = 0;

	for (i = 0; i < n; i++){
		std::cin >> pal >> a;
		if (pal.compare("set") == 0 && a > x)
			x = (long long) a;
		else if (pal.compare("add") == 0 && a > 0)
			x += (long long) a;
	}

	return x;
}

int main(){
	
	unsigned int n = 0;
	std::cin >> n;

	long long int x = maximumProgramValue(n);
	std::cout << x << "\n";

	return 0;
}
