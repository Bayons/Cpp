#include <iostream>
#include <algorithm>
#include <vector>

bool isContained(std::vector<unsigned int> list, unsigned int height){
	unsigned int i;

	for(i = 0; i < list.size(); i++){
		if(list.at(i) == height)
			return true;
	}
	return false;
}

void printHeights(
		std::vector<std::vector<unsigned int> > city)
{
	unsigned int i, j;
	std::vector<unsigned int> list;

	for(i = 0; i < city.size(); i++){
		for(j = 0; j < city.at(i).size(); j++){
			if(city.at(i).at(j) != 0 &&
				!isContained(list, city.at(i).at(j)))
				list.push_back(city.at(i).at(j));
		}
	}
	
	std::sort(list.begin(), list.end());

	if(list.size() != 0){
		for(i = 0; i < list.size(); i++){
			std::cout << list.at(i);
			if(i != list.size() -1)
				std::cout << " ";
			else
				std::cout << "\n";
		}
	}else
		std::cout << "0\n";
}

int main(void)
{
	unsigned int rows, columns, temp, i, j;
	std::cin >> rows;
	std::cin >> columns;
	std::vector<std::vector<unsigned int> > city(rows);

	for(i = 0; i < rows; i++){
		
		for(j = 0; j < columns; j++){
			std::cin >> temp;
			city.at(i).push_back(temp);
		}
	}

	printHeights(city);

	return 0;
}
