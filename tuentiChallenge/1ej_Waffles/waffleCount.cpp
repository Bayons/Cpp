#include<iostream>


/*
Just does n times m. It adjustes n, m and i for a correct
 output and calculation.
The number of holes is stored in a long int because a
 long n and m can override the result.
*/
void countHoles(int i, int n, int m){

	n--;
	m--;
	i++;
	long holes = n * m;

	std::cout << "Case #" << i << ": " << holes << "\n";
}

/*
Stores i times the input in n and m. Then calls to countHoles.
*/
int main(){

	int waffles = 0, i = 0, n = 0, m = 0;
	std::cin >> waffles;
	for (i = 0; i < waffles; i++){
		std::cin >> n >> m;
		countHoles(i, n, m);
	}

	return 0;
}
