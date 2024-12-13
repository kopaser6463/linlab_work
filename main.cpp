#include <iostream>
#include <vector>
#include <map>

class CSR_format{
private:
	short n;
	short m;
	std::vector<int>row;
	std::vector<int>col;
	std::vector<float>value;
public:
	CSR_format(std::vector<std::vector<float>> matrix_std){
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
	}

	float trace(){
		float res = 0;
		for (int i = 0; i < value.size(); i++){
			if (row[i] == col[i]){
				res += value[i];
			}
		}
		return res;
	}
	
	short get_n(){
		return this->n;
	}

	short get_m(){
		return this->m;
	}

	std::vector<int> get_row(){
		return this->row;
	}

	std::vector<int> get_col(){
		return this->col;
	}

	std::vector<float> get_value(){
		return this->value;
	}

	std::vector<std::vector<float>> csr_to_std(){
		std::vector<std::vector<float>> matrix (n, std::vector<float> (m, 0));
		for (int i = 0; i < value.size(); i++){
			matrix[row[i]][col[i]] = value[i];
		}
		return matrix;
	}

	std::vector<float> matrix_const_multiply(const float number){
		for (int i = 0; i < value.size(); i++){
			value[i] *=  number;
		}
	}

	std::vector<float> matrix_summ(){

		

	}


};

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
	for (float i: mat.get_value()){
		std::cout << i << " ";
	}
	std::cout << "\n";
	std::cout << "row: ";
	for (float i: mat.get_row()){
		std::cout << i << " ";
	}
	std::cout << "\n";
	std::cout << "col: ";
	for (float i: mat.get_col()){
		std::cout << i << " ";
	}
	std::cout << "\n";
	return 0;
}

int main(){
	test();
	return 0;
}
