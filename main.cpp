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
};


int main(){
	return 0;
}
