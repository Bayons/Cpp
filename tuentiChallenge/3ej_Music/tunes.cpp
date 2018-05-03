#include<iostream>
#include<string>
#include<vector>

std::vector<std::string> notes;

std::string returnEquivalentFlatNote(std::string note){

	int i = 0;
	std::string newNote(note, 0, 1);
	while(notes.at(i).compare(newNote) != 0 && i < notes.size()){
		i++;
	}

	i = (i+11)%notes.size();
	newNote = notes.at(i);

	return newNote;
}

/*Returns natural note only if it exists*/
std::string returnNaturalNote(std::string note){
	
	int i = 0;
	std::string newNote(note, 0, 1);
	while(notes.at(i).compare(newNote) != 0 && i < notes.size()){
		i++;
	}

	i = (i+1)%notes.size();
	newNote = notes.at(i);

	return newNote;
}

bool isInScale(std::vector<std::string> input_notes, int base_note,
	std::vector<bool> scale){

	bool belongs = false;
	int i, j, k;

	for (i = 0; i < input_notes.size(); i++){
		k = base_note;
		for (j = 0; j < scale.size(); j++){

			if (scale.at(j)) k = (k+2)%notes.size();
			else k = (k+1)%notes.size();

			if(input_notes.at(i).compare(notes.at(k)) == 0){
				belongs = true;
				break;
			} 
		}
		if (!belongs) return false;
		belongs = false;
	}

	return true;
}

bool isInList(std::string word, std::vector<std::string> list){

	int i;
	for (i = 0; i < list.size(); i++){
		if (list.at(i).compare(word) == 0)
			return true;
	}
	return false;
}

int main(){

	std::vector<bool> major;
	std::vector<bool> minor;
	std::vector<std::string> input_notes;
	std::string input_word;
	int n, m, i, j;
	bool none;

// Creating notes and scales list
	notes.push_back("A");
	notes.push_back("A#");
	notes.push_back("B");
	notes.push_back("C");
	notes.push_back("C#");
	notes.push_back("D");
	notes.push_back("D#");
	notes.push_back("E");
	notes.push_back("F");
	notes.push_back("F#");
	notes.push_back("G");
	notes.push_back("G#");

	major.push_back(true);
	major.push_back(true);
	major.push_back(false);
	major.push_back(true);
	major.push_back(true);
	major.push_back(true);
	major.push_back(false);

	minor.push_back(true);
	minor.push_back(false);
	minor.push_back(true);
	minor.push_back(true);
	minor.push_back(false);
	minor.push_back(true);
	minor.push_back(true);

	std::cin >> n;
	for (i = 0; i < n; i++){

		std::cin >> m;
		none = true;
		std::cout << "Case #" << (i+1) << ":";
		for (j = 0; j < m; j++){
//input notes
			std::cin >> input_word;
			
//looks for equivalent notes if necessary
			if(input_word.at(input_word.size()-1) == '#'){
				input_word = returnNaturalNote(input_word);
			}
			if(input_word.at(input_word.size()-1) == 'b'){
				input_word = returnEquivalentFlatNote(input_word);
			}

//add words to the input list
			if(!isInList(input_word, input_notes)){
				input_notes.push_back(input_word);
			}
		}
	
//looks in major scales
		for(j = 0; j < notes.size(); j++){
			if(isInScale(input_notes, j, major)){
				std::cout << " M" << notes.at(j);
				none = false;
			}
		}

//looks in minor scales
		for(j = 0; j < notes.size(); j++){
			if(isInScale(input_notes, j, minor)){
				std::cout << " m" << notes.at(j);
				none = false;
			}
		}
		input_notes.clear();
		if (none) std::cout << " None\n";
		else std::cout << "\n";
	}

	return 0;
}
