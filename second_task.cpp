#include <algorithm>

#include "first_task.h"

static CSR_format sum_matrix(CSR_format mat1, CSR_format mat2){
	if ((mat1.m == mat2.m) && (mat1.n == mat2.n)){
		short iter1 = 0;
		short iter2 = 0;
		while ((iter1 < mat1.row.size()) && (iter2 < mat2.row.size())){
			if ((mat1.row[iter1] == mat2.row[iter2]) && (mat1.col[iter1] == mat2.col[iter2])){
				mat1.value[iter1] += mat2.value[iter2];
				iter1++;
				iter2++;
			}
			else if ((mat1.row[iter1] >= mat2.row[iter2]) && (mat1.col[iter1] >= mat2.col[iter2])){
				mat1.row.insert(mat1.row.begin() + iter1, mat2.row[iter2]);
				mat1.col.insert(mat1.col.begin() + iter1, mat2.col[iter2]);
				mat1.value.insert(mat1.value.begin() + iter1, mat2.value[iter2]);
				iter1++;
				iter2++;
			}
			else{
				iter1++;
			}
		}
		return mat1;
	}
	else{
		throw std::runtime_error("Addition is impossible. Different dimensions of matrices."); 
	}
}

static CSR_format matrix_const_multiply(const float number, CSR_format mat){
	for (int i = 0; i < mat.value.size(); i++){
		mat.value[i] *=  number;
	}
	return mat;
}