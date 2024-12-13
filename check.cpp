#include <iostream>
#include <vector>
#include <sstream>
int main(){
	std::vector<std::string> a;
	std::string num;
	std::string numb;
	std::string read;
	std::string line_input;
		
	std::getline(std::cin, num, ' ');
	std::getline(std::cin, numb);
	//std::getline(std::cin, line_input);
	
	//std::stringstream ss(line_input);
	//std::getline(ss, num, ' ');
	//std::getline(ss, numb);
	
	//std::cin >> num;
	//std::cout << "s" << num << "s" << " " << "s" << numb << "s" << "\n";
	std::string buffer = "";
	for (int i = 0; i < std::stoi(num); i++){
		std::getline(std::cin, read);
		read += ' ';
		//std::cout << "s" << read << "s" << "\n";
		buffer = "";
		for (int j = 0; j <= read.length(); j ++){
			if (read[j] != ' '){
				buffer += read[j];	
			}
			else{
				a.push_back(buffer);	
				buffer = "";
			}
		}
	}
	/*
	for(std::string i: a){
		std::cout << "s" << i << "s" << "\n";
	}
	*/
	int numm = std::stoi(num);
	int numbm = a.size()/numm;
	//std::cout << a.size() / numm << "\n";
	std::vector<std::vector<float>> mat(numbm, std::vector<float> (numm));
	//std::cout << 2 % (numm+1) << "\n";
	//std::cout << numm << "\n";
	//std::cout << a.size() << "\n";
	for (int i = 0; i < a.size(); i++){
		//std::cout << "s" << (i)/(numm) << "s" << " " << "s" <<a[i]<< "s" << " " << "s" << (i) % numm << "s" << "\n" ;
		mat[(i)/(numm)][(i) % numm] = (float)std::stoi(a[i]);
	}
	
	for(std::vector<float> i: mat){
		for(float j : i){
			std::cout << j << "\n";
		}
	}
	
	
	return 0;
	
}
