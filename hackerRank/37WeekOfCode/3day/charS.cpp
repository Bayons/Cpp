#include<iostream>
#include<string>
#include<vector>

#define CHARS 26

/*
Conociendo el grupo en el que se encuentra la mediana, devuelve
la cantidad de letras que quedan sobre esta en el mismo grupo
*/
long getFrecSobreMed(long med, std::vector<int> freq){

	int i;
	for (i = 0; i < CHARS; i++){
		med -= freq.at(i);
		if (med <= 0) return (0-med)
	}
	return 0;
}

/*
Devuelve el grupo en el que se encuentra la mediana
*/
int getLetraMed(long med, std::vector<int> freq){

	int i;
	for (i = 0; i < CHARS; i++){
		med -= freq.at(i);
		if (med <= 0) return i;
	}
	return (CHARS - 1);

}

/*
Returns the maximum number of superior characters in all combination
of the same characters
*/
long maximumSuperiorCharacters(std::vector<int> freq) {

	int i, letraMed;
	unsigned long size = 0;
	long max, med;
	
	for (i = 0; i < CHARS; i++) size += freq.at(i);

	med = (size/2)+1;
	letraMed = getLetraMed(med, freq);

	return 0;
}

int main(){

	int t, i, j;
	unsigned long max;
	std::cin >> t;
	std::vector<int> freq(CHARS, 0);

	for (i = 0; i < t; i++){
		for (j = 0; j < CHARS; j++){
			std::cin >> freq.at(j);
		}
		max = maximumSuperiorCharacters(freq);
	}

	return 0;
}
