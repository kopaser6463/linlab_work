#include "first_task.cpp"
#include "second_task.cpp"
#include "third_task.cpp"

int test(){
	std::vector<std::string> a;
	std::string num;
	std::string numb;
	std::string read;
	std::string line_input;
		
	std::getline(std::cin, num, ' ');
	std::getline(std::cin, numb);
	
	std::string buffer = "";
	for (int i = 0; i < std::stoi(num); i++){
		std::getline(std::cin, read);
		read += ' ';
		buffer = "";
		for (int j = 0; j <= read.length(); j ++){
			if (read[j] != ' '){
				buffer += read[j];	
			}
			else{
				if (buffer.length() != 0){
				a.push_back(buffer);	
				buffer = "";
				}
			}
		}
	}
	
	int numm = std::stoi(num);
	int numbm = a.size()/numm;
	
	std::vector<std::vector<float>> array(numbm, std::vector<float> (numm));
	for (int i = 0; i < a.size(); i++){
		array[(i)/(numm)][(i) % numm] = (float)std::stoi(a[i]);
	}
	
	CSR_format mat(array);
	std::cout << "value: ";
	for (float i: mat.value){
		std::cout << i << " ";
	}
	std::cout << "\n";
	std::cout << "row: ";
	for (float i: mat.row){
		std::cout << i << " ";
	}
	std::cout << "\n";
	std::cout << "col: ";
	for (float i: mat.col){
		std::cout << i << " ";
	}
	std::cout << "\n";

	matrix_const_multiply(2, mat);
	
	std::cout << "value: ";
	for (float i: mat.value){
		std::cout << i << " ";
	}
	std::cout << "\n";
	std::cout << "row: ";
	for (float i: mat.row){
		std::cout << i << " ";
	}
	std::cout << "\n";
	std::cout << "col: ";
	for (float i: mat.col){
		std::cout << i << " ";
	}
	std::cout << "\n";
	std::cout << mat.matrix_value(1,1); // Не 0 based система
	std::cout << "\n";
	return 0;
}

int main(){
    test();
    return 0;
}