#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "../include/dictionary.h"

int main(int argc, char * argv[]){

	/// Variables and instances
	std::string f, s;
	Dictionary a;
	std::vector<Dictionary> d;

	/// Opening the file
	std::ifstream file;
	file.open(argv[1]);

	/// Storing the data
	if(file.is_open()){	
		while(getline(file, f)){
			a.set_dict(f);
			d.push_back(a);
		}
	}else{
		std::cout << "Erro!\n";
	}

	/// Getting the word
	std::cout << "Type...\n";
	std::cin >> s;
	std::cout << std::endl;

	/// Printing the sugentions
	for(auto i : d){
		i.search_sugestions(s);
	}

}