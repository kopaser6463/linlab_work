#include "first_task.h"
#include "second_task.cpp"
#include "third_task.cpp"

int main(){
	CSR_format mat1;
	CSR_format mat2;
	mat1.input();
	mat2.input();
	CSR_format res = matrix_multiply_mem(mat1, mat2);
	res.output();
}