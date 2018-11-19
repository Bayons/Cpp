#include <iostream>
#include <algorithm>
#include <vector>

int main(void)
{
	unsigned int nums, i;
	int r1, c1, r2, c2;
	double ratio, x, y;

	std::cin >> nums;

	for(i = 0; i < nums; i++){
		std::cin >> r1 >> c1 >> r2 >> c2 >> ratio;

		x = ((((double)r2 - (double)r1)*ratio)+r1) + 0.5;
		y = ((((double)c2 - (double)c1)*ratio)+c1) + 0.5;
		std::cout << (int)x << " " << (int)y << "\n";
	}
	

	return 0;
}
