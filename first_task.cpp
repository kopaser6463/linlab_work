#include "first_task.h"

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
}

float CSR_format::trace(){
    float res = 0;
    for (int i = 0; i < value.size(); i++){
        if (row[i] == col[i]){
            res += value[i];
        }
    }
    return res;
}

std::vector<std::vector<float>> CSR_format::csr_to_std(){
	std::vector<std::vector<float>> matrix (n, std::vector<float> (m, 0));
	for (int i = 0; i < value.size(); i++){
		matrix[row[i]][col[i]] = value[i];
	}
	return matrix;
}

float CSR_format::matrix_value(int x, int y){
	for(int i = 0; i < row.size(); i ++){
		if((row[i] == x-1) && (col[i] == y-1)){
			return value[i];
		}
	}
	return 0;
}