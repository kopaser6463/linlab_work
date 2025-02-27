#include "first_task.h"
#include <sstream>

//Стандартный метод создания класса разряженной матрицы из обычной.
CSR_format::CSR_format(std::vector<std::vector<float>> matrix_std){
		this->n = matrix_std.size();
		this->m = matrix_std[0].size();
		for (unsigned int i = 0; i < n; i++){
			for (unsigned int j = 0; j < m; j++){
				if (matrix_std[i][j] != 0){
					this->row.push_back(i);
					this->col.push_back(j);
					this->value.push_back(matrix_std[i][j]);
				}
			}
		}
};
//Метод класса, возвращаюший след разряженной матрицы.
float CSR_format::trace(){
    float res = 0;
    for (unsigned int i = 0; i < value.size(); i++){
        if (row[i] == col[i]){
            res += value[i];
        }
    }
    return res;
};
//Метод класса возвращающий матрицу в обычном виде.
std::vector<std::vector<float>> CSR_format::csr_to_std(){
	std::vector<std::vector<float>> matrix (n, std::vector<float> (m, 0));
	for (unsigned int i = 0; i < value.size(); i++){
		matrix[row[i]][col[i]] = value[i];
	}
	return matrix;
};
//Метод класса возвращающий значение из матрицы по индексу, из разряженного вида.
float CSR_format::matrix_value(unsigned int row, unsigned int col){
	if ((row<=this->n) && (row > 0) && (col > 0) && (col<=this->m)){  //Если запрошенный элемент вне матрицы вернуть ошибку.
		for(unsigned int i = 0; i < this->row.size(); i ++){
			if(this->row[i] == row-1 && this->col[i] == col-1){
				return this->value[i];
			}
		}
		return 0;
	}
	throw std::runtime_error("Indexing error. The matrix element cannot be returned due to an incorrect index.");
};
//Метод класса осуществляющий вывод значений матрицы в разряженном виде.
void CSR_format::output(){
	std::cout << "value: ";
	for (float i: this->value){
		std::cout << i << " ";
	}
	std::cout << "\n";
	std::cout << "row:   ";
	for (unsigned int i: this->row){
		std::cout << i << " ";
	}
	std::cout << "\n";
	std::cout << "col:   ";
	for (unsigned int i: this->col){
		std::cout << i << " ";
	}
	std::cout << "\n";
	std::cout << "rows: " << this->n << " " << "cols: " << this->m;
	std::cout << "\n";
}
//Метод класса осуществляющий ввод матрицы в рязряженный вид из stdin.
void CSR_format::input(){
	std::cout << "Enter the matrix size and the matrix itself.\n";
	std::vector<std::string> a;
	std::string num;
	std::string numb;
	std::string read;
	std::string line_input;
	std::getline(std::cin, line_input);
	line_input += ' ';
	std::stringstream ss(line_input);
	std::getline(ss, num, ' ');  //Чтение числа столбцов.
	std::getline(ss, numb);      //Чтение числа строк, (не используется)
	std::string buffer = "";
	for (unsigned int i = 0; i < std::stoi(num); i++){
		std::getline(std::cin, read);
		read += ' ';
		buffer = "";
		for (unsigned int j = 0; j <= read.length(); j ++){
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
	
	unsigned int numm = std::stoi(num);
	unsigned int numbm = a.size()/numm;
	
	std::vector<std::vector<float>> array(numm, std::vector<float> (numbm));
	for (unsigned int i = 0; i < a.size(); i++){
		array[(i)/(numbm)][(i) % numbm] = (float)std::stof(a[i]);
	}
	this->n = array.size();
	this->m = array[0].size();
	for (unsigned int i = 0; i < n; i++){
		for (unsigned int j = 0; j < m; j++){
			if (array[i][j] != 0){
				this->row.push_back(i);
				this->col.push_back(j);
				this->value.push_back(array[i][j]);
			}
		}
	}
}