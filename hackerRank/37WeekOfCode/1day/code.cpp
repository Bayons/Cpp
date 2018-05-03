#include<iostream>
#include<vector>
#include<cmath>

void averageOfTopEmployees(std::vector<int> rating){
	int i;
	float sum = 0.0;
	
	/* Erases elements less than 90 */
	for (i = (signed)rating.size()-1; i >= 0; i--){
		if(rating.at(i)<90)
			rating.erase(rating.begin()+i);
	}

	/* Makes the sum of the numbers if size != 0 */
	if (rating.size() != 0){
		for (i = 0; i < (signed)rating.size(); i++)
			sum += (float) rating.at(i);
		sum = std::round(sum * 100 / rating.size())/100;
	}

	/* Prints the result */
	printf("%.2f\n", sum);
}

int main(){

	int n, i, a;
	std::cin >> n;
	std::vector<int> nums (n, 0);

	for (i = 0; i < n; i++){
		std::cin >> a;
		nums.at(i) = a;
	}

	averageOfTopEmployees(nums);

	return 0;
}
