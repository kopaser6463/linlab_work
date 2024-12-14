#include "first_task.h"
#include "first_task.cpp"
#include "second_task.cpp"
#include "third_task.cpp"
#include "cassert"
#include "vector"
int test(){
	//Проверка работы assert
	assert(true);
	
	//CSR Creation
	std::vector<std::vector<float>> array (3, std::vector<float> (2, 4));
	CSR_format mat(array);
	assert((mat.value == std::vector<float> {4,4,4,4,4,4}));
	assert((mat.row ==     std::vector<int> {0,0,1,1,2,2}));
	assert((mat.col ==     std::vector<int> {0,1,0,1,0,1}));
	assert((mat.n == 3));
	assert((mat.m == 2));
	assert((mat.matrix_value(1 + 1, 0 + 1) == array[0][1]));
	
	std::vector<std::vector<float>> array2 (3, std::vector<float> (3, 0));
	array2[1][0] = 1;
	array2[1][1] = 3;
	array2[2][0] = 1;
	array2[1][2] = 9;
	CSR_format mat2(array2);
	assert((mat2.value == std::vector<float> {1,3,9,1}));
	assert((mat2.row ==     std::vector<int> {1,1,1,2}));
	assert((mat2.col ==     std::vector<int> {0,1,2,0}));
	assert((mat2.n == 3));
	assert((mat2.m == 3));
	assert((mat2.matrix_value(0 + 1, 1 + 1) == array2[1][0]));
	assert((mat2.matrix_value(1 + 1, 1 + 1) == array2[1][1]));
	assert((mat2.matrix_value(0 + 1, 1 + 1) == array2[2][0]));
	assert((mat2.matrix_value(2 + 1, 1 + 1) == array2[1][2]));
	assert((mat2.trace() == array2[0][0] + array2[1][1] + array2[2][2]));
	
	std::vector<std::vector<float>> array3 = {{2, 0, 3}, {0, 0, 0}, {0, 7, 0}};
	CSR_format mat3(array3);
	assert((mat3.value == std::vector<float> {2,3,7}));
	assert((mat3.row ==     std::vector<int> {0,0,2}));
	assert((mat3.col ==     std::vector<int> {0,2,1}));
	assert((mat3.n == 3));
	assert((mat3.m == 3));
	assert((mat3.matrix_value(0 + 1, 0 + 1) == array3[0][0]));
	assert((mat3.matrix_value(2 + 1, 0 + 1) == array3[0][2]));
	assert((mat3.matrix_value(1 + 1, 2 + 1) == array3[2][1]));
	assert((mat3.trace() == array3[0][0] + array3[1][1] + array3[2][2]));
	
	std::vector<std::vector<float>> array4 = {{1,1,1,1}, {2,0,0,0}, {0,6,5,1}, {0,6,5,1}};
	CSR_format mat4(array4);
	assert((mat4.value == std::vector<float> {1,1,1,1,2,6,5,1,6,5,1}));
	assert((mat4.row ==     std::vector<int> {0,0,0,0,1,2,2,2,3,3,3}));
	assert((mat4.col ==     std::vector<int> {0,1,2,3,0,1,2,3,1,2,3}));
	assert((mat4.n == 4));
	assert((mat4.m == 4));
	assert((mat4.matrix_value(3 + 1, 0 + 1) == array4[0][3]));
	assert((mat4.matrix_value(1 + 1, 2 + 1) == array4[2][1]));
	assert((mat4.matrix_value(1 + 1, 3 + 1) == array4[3][1]));
	assert((mat4.trace() == array4[0][0] + array4[1][1] + array4[2][2] + array4[3][3]));
	
	return 0;
}

int test2(){
	std::vector<std::vector<float>> array = {{1,1}, {2,0}};
	std::vector<std::vector<float>> array2 = {{1,1}, {2,1}};
	std::vector<std::vector<float>> array3 = {{2,2}, {4,1}};
	CSR_format mat(array);
	CSR_format mat2(array);
	CSR_format mat3 = sum_matrix(mat, mat2);
	mat3.output();
	
	return 0;
}
int test3(){
	std::vector<std::vector<float>> array = {{1,1}, {2,0}};
	std::vector<std::vector<float>> array2 = {{2,2}, {4,0}};
	CSR_format mat(array);
	CSR_format mat2(array2);
	CSR_format mat3 = matrix_const_multiply(2, mat);
	assert((mat3.value == mat2.value));
	assert((mat3.row   == mat2.row));
	assert((mat3.col   == mat2.col));
	return 0;
}
int test4(){
	std::vector<std::vector<float>> array = {{1}};
	std::vector<std::vector<float>> array2 = {{15}};
	CSR_format mat(array);
	CSR_format mat2(array2);
	CSR_format mat3 = matrix_const_multiply(15, mat);
	assert((mat3.value == mat2.value));
	assert((mat3.row   == mat2.row));
	assert((mat3.col   == mat2.col));
	
	
	return 0;
}
int test5(){
	std::vector<std::vector<float>> array = {{2,2,6,4},{2,2,4,4}};
	std::vector<std::vector<float>> array2 = {{1,1,3,2},{1,1,2,2}};
	CSR_format mat(array);
	CSR_format mat2(array2);
	CSR_format mat3 = matrix_const_multiply(0.5, mat);
	assert((mat3.value == mat2.value));
	assert((mat3.row   == mat2.row));
	assert((mat3.col   == mat2.col));
	
	
	return 0;
}
int test6(){
	std::vector<std::vector<float>> array = {{2,2,6},{2,2,4},{2,2,6}};
	std::vector<std::vector<float>> array2 = {{2,2,6},{2,2,4},{2,2,6}};
	std::vector<std::vector<float>> array3 = {{20,20,56},{16,16,44},{20,20,56}};
	CSR_format mat(array);
	CSR_format mat2(array2);
	CSR_format mat3(array3);
	CSR_format mat4 = matrix_multiply(mat, mat2);
	assert((mat3.value == mat4.value));
	assert((mat3.row   == mat4.row));
	assert((mat3.col   == mat4.col));
	
	
	return 0;
}
int test7(){
	std::vector<std::vector<float>> array = {{2,2,6},{2,2,4}};
	std::vector<std::vector<float>> array2 = {{2,2},{2,2},{2,2}};
	std::vector<std::vector<float>> array3 = {{20,20},{16,16}};
	CSR_format mat(array);
	CSR_format mat2(array2);
	CSR_format mat3(array3);
	CSR_format mat4 = matrix_multiply(mat, mat2);
	assert((mat3.value == mat4.value));
	assert((mat3.row   == mat4.row));
	assert((mat3.col   == mat4.col));
	
	
	return 0;
}

int test8(){
	std::vector<std::vector<float>> array = {{2}};
	std::vector<std::vector<float>> array2 = {{200}};
	std::vector<std::vector<float>> array3 = {{400}};
	CSR_format mat(array);
	CSR_format mat2(array2);
	CSR_format mat3(array3);
	CSR_format mat4 = matrix_multiply(mat, mat2);
	assert((mat3.value == mat4.value));
	assert((mat3.row   == mat4.row));
	assert((mat3.col   == mat4.col));
	
	return 0;
}

int test9(){
	std::vector<std::vector<float>> array = {{2,2,6},{2,2,4},{1,2,6}};
	CSR_format mat(array);
	find_det(array);
	//assert((find_det(mat.csr_to_std()) == 4.0));
	
	return 0;
}
int main(){
	//4 transformations, 4 index checks, 3 trace checks
	test();
	//sum test fail
	//test2()
	//3 conts mul checks
	test3();
	test4();
	test5();
	//3 mat mul checks
    test6();
	test7();
	test8();
	
	test9();
    return 0;
}
/*
	mat3.output();

*/