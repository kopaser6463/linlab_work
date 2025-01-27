#include "first_task.h"
#include "second_task.cpp"
#include "third_task.cpp"
#include "cassert"
// Проверка методов класса CSR_format 
int test(){
	std::vector<std::vector<float>> array (3, std::vector<float> (2, 4));
	CSR_format mat(array);
	assert((mat.value == std::vector<float> {4,4,4,4,4,4}));
	assert((mat.row == std::vector<unsigned int> {0,0,1,1,2,2}));
	assert((mat.col == std::vector<unsigned int> {0,1,0,1,0,1}));
	assert((mat.n == 3));
	assert((mat.m == 2));
	assert((mat.matrix_value(1 + 1, 0 + 1) == array[0][1]));
	assert((mat.csr_to_std() == array));
	
	std::vector<std::vector<float>> array2 = {{0, 0, 0}, {1, 3, 9}, {1, 0, 0}};
	CSR_format mat2(array2);
	assert((mat2.value == std::vector<float> {1,3,9,1}));
	assert((mat2.row == std::vector<unsigned int> {1,1,1,2}));
	assert((mat2.col == std::vector<unsigned int> {0,1,2,0}));
	assert((mat2.n == 3));
	assert((mat2.m == 3));
	assert((mat2.matrix_value(0 + 1, 0 + 1) == array2[0][0]));
	assert((mat2.matrix_value(0 + 1, 1 + 1) == array2[0][1]));
	assert((mat2.matrix_value(1 + 1, 0 + 1) == array2[1][0]));
	assert((mat2.matrix_value(1 + 1, 1 + 1) == array2[1][1]));
	assert((mat2.trace() == array2[0][0] + array2[1][1] + array2[2][2]));
	assert((mat2.csr_to_std() == array2));
	
	std::vector<std::vector<float>> array3 = {{2, 0, 3}, {0, 0, 0}, {0, 7, 0}};
	CSR_format mat3(array3);
	assert((mat3.value == std::vector<float> {2,3,7}));
	assert((mat3.row == std::vector<unsigned int> {0,0,2}));
	assert((mat3.col == std::vector<unsigned int> {0,2,1}));
	assert((mat3.n == 3));
	assert((mat3.m == 3));
	assert((mat3.matrix_value(0 + 1, 0 + 1) == array3[0][0]));
	assert((mat3.matrix_value(0 + 1, 2 + 1) == array3[0][2]));
	assert((mat3.matrix_value(2 + 1, 1 + 1) == array3[2][1]));
	assert((mat3.trace() == array3[0][0] + array3[1][1] + array3[2][2]));
	assert((mat3.csr_to_std() == array3));
	
	std::vector<std::vector<float>> array4 = {{1,1,1,1}, {2,0,0,0}, {0,6,5,1}, {0,6,5,1}};
	CSR_format mat4(array4);
	assert((mat4.value == std::vector<float> {1,1,1,1,2,6,5,1,6,5,1}));
	assert((mat4.row ==     std::vector<unsigned int> {0,0,0,0,1,2,2,2,3,3,3}));
	assert((mat4.col ==     std::vector<unsigned int> {0,1,2,3,0,1,2,3,1,2,3}));
	assert((mat4.n == 4));
	assert((mat4.m == 4));
	assert((mat4.matrix_value(0 + 1, 3 + 1) == array4[0][3]));
	assert((mat4.matrix_value(2 + 1, 1 + 1) == array4[2][1]));
	assert((mat4.matrix_value(3 + 1, 1 + 1) == array4[3][1]));
	assert((mat4.trace() == array4[0][0] + array4[1][1] + array4[2][2] + array4[3][3]));
	assert((mat4.csr_to_std() == array4));
	
	return 0;
}

// Проверка сложения матриц
int test2(){
	std::vector<std::vector<float>> array = {{1,1}, {2,0}};
	std::vector<std::vector<float>> array2 = {{1,1}, {2,1}};
	std::vector<std::vector<float>> array3 = {{2,2}, {4,1}};
	CSR_format mat(array);
	CSR_format mat2(array);
	CSR_format mat3 = sum_matrix(mat, mat2);	
	return 0;
}

// Проверка домножения матрицы на скаляр
int test3(){
	std::vector<std::vector<float>> std_mat = {{1,1}, {2,0}};
	std::vector<std::vector<float>> res = {{2,2}, {4,0}};
	CSR_format mat(std_mat);
	CSR_format true_mat(res);
	CSR_format res_mat = matrix_const_multiply(2, mat);
	assert((res_mat.value == true_mat.value));
	assert((res_mat.row   == true_mat.row));
	assert((res_mat.col   == true_mat.col));

	std::vector<std::vector<float>> std_mat2 = {{1}};
	std::vector<std::vector<float>> res2 = {{15}};
	CSR_format mat2(std_mat2);
	CSR_format true_mat2(res2);
	CSR_format res_mat2 = matrix_const_multiply(15, mat2);
	assert((res_mat2.value == true_mat2.value));
	assert((res_mat2.row   == true_mat2.row));
	assert((res_mat2.col   == true_mat2.col));

	std::vector<std::vector<float>> std_mat3 = {{2,2,6,4},{2,2,4,4}};
	std::vector<std::vector<float>> res3 = {{1,1,3,2},{1,1,2,2}};
	CSR_format mat3(std_mat3);
	CSR_format true_mat3(res3);
	CSR_format res_mat3 = matrix_const_multiply(0.5, mat3);
	assert((res_mat3.value == true_mat3.value));
	assert((res_mat3.row   == true_mat3.row));
	assert((res_mat3.col   == true_mat3.col));

	return 0;
}

// Проверка перемножения матриц v1
int test4(){
	std::vector<std::vector<float>> array = {{2,2,6},{2,2,4},{2,2,6}};
	std::vector<std::vector<float>> array2 = {{2,2,6},{2,2,4},{2,2,6}};
	std::vector<std::vector<float>> array3 = {{20,20,56},{16,16,44},{20,20,56}};
	CSR_format mat(array);
	CSR_format mat2(array2);
	CSR_format mat3(array3);
	CSR_format res1 = matrix_multiply(mat, mat2);
	CSR_format res2 = matrix_multiply_v2(mat, mat2);
	assert((mat3.value == res1.value));
	assert((mat3.row   == res1.row));
	assert((mat3.col   == res1.col));
	assert((mat3.value == res2.value));
	assert((mat3.row   == res2.row));
	assert((mat3.col   == res2.col));
	
	
	return 0;
}

// Проверка перемножения матриц v2
int test5(){
	std::vector<std::vector<float>> array = {{2,2,6},{2,2,4}};
	std::vector<std::vector<float>> array2 = {{2,2},{2,2},{2,2}};
	std::vector<std::vector<float>> array3 = {{20,20},{16,16}};
	CSR_format mat(array);
	CSR_format mat2(array2);
	CSR_format mat3(array3);
	CSR_format res1 = matrix_multiply(mat, mat2);
	CSR_format res2 = matrix_multiply_v2(mat, mat2);
	assert((mat3.value == res1.value));
	assert((mat3.row   == res1.row));
	assert((mat3.col   == res1.col));
	assert((mat3.value == res2.value));
	assert((mat3.row   == res2.row));
	assert((mat3.col   == res2.col));
	
	
	return 0;
}

// Проверка перемножения матриц v3
int test6(){
	std::vector<std::vector<float>> array = {{2}};
	std::vector<std::vector<float>> array2 = {{200}};
	std::vector<std::vector<float>> array3 = {{400}};
	CSR_format mat(array);
	CSR_format mat2(array2);
	CSR_format mat3(array3);
	CSR_format res1 = matrix_multiply(mat, mat2);
	CSR_format res2 = matrix_multiply_v2(mat, mat2);
	assert((mat3.value == res1.value));
	assert((mat3.row   == res1.row));
	assert((mat3.col   == res1.col));
	assert((mat3.value == res2.value));
	assert((mat3.row   == res2.row));
	assert((mat3.col   == res2.col));
	
	return 0;
}

// Проверка нахождения определителя матрицы (True1 = 0, True2 = 18, True3 = 0)
int test7(){
	std::vector<std::vector<float>> array = {{1,2,3},{2,4,6},{5,5,5}};
	find_det(array);

	std::vector<std::vector<float>> array2 = {{4,5,9},{2,2,4},{7,3,1}};
	find_det(array2);

	std::vector<std::vector<float>> array3 = {{4,0,9},{2,0,4},{7,0,1}};
	find_det(array3);
	return 0;
}
int main(){
	test();
	test2();
	test3();
	test4();
	test5();
    test6();
	test7();
    return 0;
}