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

static CSR_format matrix_multiply(CSR_format mat1, CSR_format mat2){
	if (mat1.m == mat2.n){
		auto A = mat1.csr_to_std();
		auto B = mat2.csr_to_std();
		std::vector<std::vector<float>> v_res(mat1.n, std::vector<float> (mat2.m, 0));
		for(int i = 0; i < mat1.n; i++){
			for(int j = 0; j < mat2.m; j++){
				for(int k = 0; k < mat1.m; k++){
					v_res[i][j] += A[i][k] * B[k][j];
				}
			}
		}
		CSR_format res(v_res);
		return v_res;
	}
	else{
		throw std::runtime_error("Matrix multiplication is impossible. The number of columns in the first matrix and the number of rows in the second don't match."); 
	}
}

static CSR_format matrix_multiply_v2(CSR_format mat1, CSR_format mat2){
	if (mat1.m == mat2.n){
		auto A = mat1;
		auto B = mat2;
		int s;
		int x;
		std::vector<std::vector<float>> v_res(0, std::vector<float> (0));
		for(int i = 0; i < mat1.value.size(); i++){
			x = A.row[i];
			for(int ii = 0; ii < B.n; ii++){
				if(B.matrix_value(ii+1,A.col[i]+1) != 0){
					s = A.matrix_value(A.col[i]+1,x+1) * B.matrix_value(ii+1,A.col[i]+1);
					std::cout << s << " " << x << " " << ii;
					std::cout << "\n";
					
				}
			}
		}
		CSR_format res(v_res);
		return v_res;
	}
	else{
		throw std::runtime_error("Matrix multiplication is impossible. The number of columns in the first matrix and the number of rows in the second don't match."); 
	}
}