#include "first_task.h"
#include "first_task.cpp"
#include "second_task.cpp"
#include "third_task.cpp"

void test3(){
	std::vector<std::vector<float>> mat = {{9, 1, 3}, {3, 192, 4}, {-5, 8, 2}};
	find_det(mat);
}

int test(){
	
	std::vector<std::vector<float>> array(2, std::vector<float> (3));
	CSR_format mat(array);
	mat.input();
	mat.output();
	std::cout << "\n";
	return 0;
}
int input_output_determ(){
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
	std::cout << "\n";
	mat2_1.output();
	std::cout << "\n";
	mat2_2.output();
	//std::cout << mat2_1.matrix_value(1,1) << "\n";
	std::cout << "\n";
	//matrix_multiply_v2(mat2_1, mat2_2);
}

int main(){
    test();
	test2();
    test3();
    return 0;
}