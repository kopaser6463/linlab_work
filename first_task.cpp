#include "first_task.h"
#include <sstream>
CSR_format::CSR_format(std::vector<std::vector<float>> matrix_std){
		this->n = matrix_std.size();
		this->m = matrix_std[0].size();
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (matrix_std[i][j] != 0){
					this->row.push_back(i);
					this->col.push_back(j);
					this->value.push_back(matrix_std[i][j]);
				}
			}
		}
};

float CSR_format::trace(){
    float res = 0;
    for (int i = 0; i < value.size(); i++){
        if (row[i] == col[i]){
            res += value[i];
        }
    }
    return res;
};

std::vector<std::vector<float>> CSR_format::csr_to_std(){
	std::vector<std::vector<float>> matrix (n, std::vector<float> (m, 0));
	for (int i = 0; i < value.size(); i++){
		matrix[row[i]][col[i]] = value[i];
	}
	return matrix;
};

float CSR_format::matrix_value(int col, int row){
	for(int i = 0; i < this->row.size(); i ++){
		if(this->row[i] == row-1 && this->col[i] == col-1){
			return this->value[i];
		}
	}
	return 0;
};

void CSR_format::output(){
	std::cout << "value: ";
	for (float i: this->value){
		std::cout << i << " ";
	}
	std::cout << "\n";
	std::cout << "row:   ";
	for (float i: this->row){
		std::cout << i << " ";
	}
	std::cout << "\n";
	std::cout << "col:   ";
	for (float i: this->col){
		std::cout << i << " ";
	}
	std::cout << "\n";
	std::cout << "rows: " << this->n << " " << "cols: " << this->m;
	std::cout << "\n";
}

void CSR_format::input(){
	std::vector<std::string> a;
	std::string num;
	std::string numb;
	std::string read;
	std::string line_input;
	
	std::getline(std::cin, line_input);
	line_input += ' ';
	std::stringstream ss(line_input);
	std::getline(ss, num, ' ');
	std::getline(ss, numb);
	
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
	
	std::vector<std::vector<float>> array(numm, std::vector<float> (numbm));
	for (int i = 0; i < a.size(); i++){
		array[(i) % numm][(i)/(numm)] = (float)std::stof(a[i]);
	}
	this->n = array.size();
	this->m = array[0].size();
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (array[i][j] != 0){
				this->row.push_back(i);
				this->col.push_back(j);
				this->value.push_back(array[i][j]);
			}
		}
	}
}