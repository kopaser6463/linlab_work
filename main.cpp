#include "first_task.h"
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
				if (buffer.length() != 0){
				a.push_back(buffer);	
				buffer = "";
				}
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
	std::vector<std::vector<float>> array(numbm, std::vector<float> (numm));
	//std::cout << 2 % (numm+1) << "\n";
	//std::cout << numm << "\n";
	//std::cout << a.size() << "\n";
	for (int i = 0; i < a.size(); i++){
		//std::cout << "s" << (i)/(numm) << "s" << " " << "s" <<a[i]<< "s" << " " << "s" << (i) % numm << "s" << "\n" ;
		array[(i)/(numm)][(i) % numm] = (float)std::stoi(a[i]);
	}
	/*
	for(std::vector<float> i: mat){
		for(float j : i){
			std::cout << j << "\n";
		}
	}
	*/
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
	return 0;
}

void test2(){
	std::vector<std::vector<float>> matrix1 = {{1, 1, 0, 0, 1, 0}, {1, 0, 0, 1, 0, 1}};
	std::vector<std::vector<float>> matrix2 = {{0, 1, 0, 1, 1, 0}, {1, 0, 0, 1, 0, 0}};
	CSR_format mat1(matrix1);
	CSR_format mat2(matrix2);
	CSR_format mat = sum_matrix(mat1, mat2);
	for (int i = 0; i < mat.value.size(); i++){
		std::cout << i << " [" << mat.row[i] << "][" << mat.col[i] << "] = " << mat.value[i] << std::endl;
	}
	std::cout << "\n\n\n";
	std::vector<std::vector<float>> matrix2_1 = {{2, 0, 3}, {0, 0, 0}, {0, 7, 0}};
	std::vector<std::vector<float>> matrix2_2 = {{0, 9, 2}, {4, 0, 3}, {0, 0, 0}};
	CSR_format mat2_1(matrix2_1);
	CSR_format mat2_2(matrix2_2);
	CSR_format res = matrix_multiply(mat2_1, mat2_2);
	for (int i = 0; i < res.value.size(); i++){
		std::cout << i << " [" << res.row[i] << "][" << res.col[i] << "] = " << res.value[i] << std::endl;
	}
}

int main(){
    //test();
	test2();
    return 0;
}