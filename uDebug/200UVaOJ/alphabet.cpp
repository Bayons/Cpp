#include <iostream>
#include <string>
#include <vector>

#define END std::string("#")

/**
 * Returns the index of a value contained in a given vector.
 *
 * @param value
 * 	char whose index is wanted.
 * @param list
 * 	vector of char where the value is contained.
 *
 * @returns int with the index of the value bounded in [0, n), where
 * 	n is the size of the vector.
 */
int getIndex(char value, std::vector<char> list){
	int i;
	for (i = 0; i < (int)list.size(); i++){
		if(value == list.at(i))
			return i;
	}

	return -1;
}

/**
 * Returns true if the incoming vector letters contains the
 * character searched.
 *
 * @param searched
 * 	char which may be contained in the vector.
 * @param letters
 * 	vector of char where the character is going to be
 * 	searched.
 *
 * @returns true if searched is contained in letters.
 */
bool isInTheList(char searched, std::vector<char> letters){
	unsigned int i;

	for(i = 0; i < letters.size(); i++){
		if(letters.at(i) == searched)
			return true;
	}

	return false;
}

/**
 * Generates a vector with all the characters used in all the
 * words. Those characters are not repeated.
 *
 * @param words
 * 	vector of string which will be used to generate the
 * 	list of characters used.
 *
 * @returns vector of char with every character used.
 */
std::vector<char> lettersUsed(std::vector<std::string> words)
{
	std::vector<char> letters;
	unsigned int i, j;

	for(i = 0; i < words.size(); i++){
		for(j = 0; j < words.at(i).size(); j++){
			if(!isInTheList(words.at(i).at(j), letters)){
				letters.push_back(words.at(i).at(j));
			}
		}
	}

	return letters;
}

int getIndexOfRoot(bool **tree, int size){
	int i, j;
	for(j = 0; j < size; j++){
		for (i = 0; i < size; i++){
			if(tree[i][j])
				continue;
			return i;
		}
	}
	return -1;
}

bool isLastNode(bool **tree, int size, int node){
	int i;
	for(i = 0; i < size; i++){
		if(tree[node][i])
			return false;
	}
	return true;
}

bool contains(std::vector<int> parents, int node){
	int i;

	for(i = 0; i < (int)parents.size(); i++){
		if(parents.at(i) == node)
			return true;
	}
	return false;
}

bool isTheOnlyFather(bool **tree, int size, int son, int father,
	std::vector<int> parents){
	int i;

	for(i = 0; i < size; i++){
		//if this father is not the given father
		//and
		//this father is not in the list
		//return false
		if(tree[i][son] && i != father && !contains(parents, i)){
			return false;
		}
	}
	return true;
}

void sortTree(bool **tree, int size, std::vector<char> letters)
{
/*	Rules:
 *	+ Each node must be (1,1) at the end, except
 *	for node n0 which must be (0,1) and node nN, which
 *	must be (1,0)
 *	+ Once a node is read, it's added to the list of
 *	   read elements R
 *
 *	Process:
 *		+ Searches n0 by searching for a (0,1) node.
 *		+ nX = n0
 *		+ Loop:
 *			+ Searches for a son node nX+1 of nX
 *			   whose only father out of R is nX
 *			+ Stores nX in R
 *			+ If(nX+1 didn't appear)
 *				+ Congrats! It is nN
 *				+ End of the sorting
 *			+ nX+1 now is nX
 *		+ R contains the list
 */
	int i;
	int sonNode = -1;
	int fatherNode = getIndexOfRoot(tree, size);
	std::vector<int> r;

	do {
		for(i = 0; i < size; i++){
			if(tree[fatherNode][i] && isTheOnlyFather(tree, size, i,
				fatherNode, r))
				sonNode = i;
		}
		r.push_back(fatherNode);
		fatherNode = sonNode;
	} while(!isLastNode(tree, size, sonNode));
	r.push_back(fatherNode);

	for(i = 0; i < size; i++){
		std::cout << letters.at(r.at(i));
	}
	std::cout << '\n';
}


void fillBoolTree(bool **tree, int size, std::vector<std::string> words,
		std::vector<char> letters)
{
	/*
	 * 1: write down links between nodes
	 * 2: search groups of words with the same initial char
	 *   2.1: char to temp; boolean repeated = false
	 *   2.2: if next char is the same, temp to list L and
	 *         repeated = true
	 *   2.3: when next char is different, repeat from 2.1
	 *   2.4: when list is finished, take chars from L
	 *      2.4.1: takes char C
	 *      2.4.2: looks and inserts every word which begins
	 *              with C in list tempList
	 *      2.4.3: removes the first char of every word
	 *      2.4.4: sends tempList to fillBoolTree
	 */
	unsigned int i, j, indexA, indexB;
	char tempChar = '\0';
	std::vector<char> groups;
	std::vector<std::string> tempList;
	bool repeated = false;

	// Writes down the connections between nodes
	for(i = 1; i < words.size(); i++){
		indexA = getIndex(words.at(i-1).at(0), letters);
		indexB = getIndex(words.at(i).at(0), letters);
		if(indexA != indexB)
			tree[indexA][indexB] = true;
	}

	// Checks for groups of words and writes down the initial characters
	for(i = 0; i < words.size(); i++){
		if(words.at(i).at(0) != tempChar){
			tempChar = words.at(i).at(0);
			repeated = false;
		} else if(words.at(i).at(0) == tempChar && repeated == false){
			groups.push_back(tempChar);
			repeated = true;
		}
	}

	// For every character that sets every group, generates a list and
	//  calls fillBoolTree without the first character
	for(i = 0; i < groups.size(); i++){
		for(j = 0; j < words.size(); j++){
			if(groups.at(i) == words.at(j).at(0) &&
				words.at(j).substr(1) != ""){
				tempList.push_back(words.at(j));
				tempList.at(tempList.size()-1).
					erase(tempList.at(tempList.size()-1).begin());
			}
		}

		fillBoolTree(tree, size, tempList, letters);
		tempList.clear();
	}

}

int main(void)
{
	std::vector<std::string> words;
	std::string temp;
	unsigned int size, i, j;

	while (std::cin >> temp && temp != END)
	{
			words.push_back(temp);
	}

	std::vector<char> letters(lettersUsed(words));
	size = letters.size();

	bool **tree = new bool*[size];
	for(i = 0; i < size; i++) // How to find array size
	{
		tree[i] = new bool[size];
		for(j = 0; j < size; j++)
		{
			tree[i][j] = false;
		}
	}

	fillBoolTree(tree, size, words, letters);

	sortTree(tree, size, letters);

	return 0;
}
