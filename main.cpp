#include "first_task.h"
#include "second_task.cpp"
#include "third_task.cpp"

void test3(){
	//Тест нахождения определителя матрицы.
	std::vector<std::vector<float>> mat = {{9, 1, 3}, {3, 192, 4}, {-5, 8, 2}};
	find_det(mat);
}


void task1(){
  //Базовый тест проверяющий работу ввода и вывода значений матрицы.
	CSR_format mat;
	mat.input();
	short num_oper;
	std::cout<<"Operation numbers:\n1 - matrix trace calculation;\n2 - matrix element output by index and column (numbering from one).\n\nEnter the operation number: ";
	std::cin>>num_oper;
	if (num_oper == 1){
		std::cout<<"Trace = " << mat.trace();
	}
	else if (num_oper == 2){
		int row;
		int col;
		std::cout<<"Enter row number: ";
		std::cin>>row;
		std::cout<<"Enter col number: ";
		std::cin>>col;
		std::cout<<"Element [" << row << "][" << col << "] = " << mat.matrix_value(col, row);
	}
	else{
		std::cout << "ERROR: Invalid operation number entered.";
	}
}

void task2(){
	short num_oper;
	std::cout<<"Operation numbers:\n1 - matrix addition;\n2 - matrix multiplication by scalar;\n3 - matrix multiplication.\n\nEnter the operation number: ";
	std::cin>>num_oper;
	std::cin.ignore();
	if (num_oper == 1){
		CSR_format mat1;
		CSR_format mat2;
		std::cout<<"Enter matrix 1:\n";
		mat1.input();
		std::cout<<"Enter matrix 2:\n";
		mat2.input();
		CSR_format res = sum_matrix(mat1, mat2);
		std::cout<<"Addition results:\n";
		res.output();
	}
	else if (num_oper == 2){
		CSR_format mat;
		std::cout<<"Enter matrix:\n";
		mat.input();
		std::cout<<"Enter scalar: ";
		float scalar;
		std::cin>>scalar;
		std::cout<<"Results of matrix-scalar multiplication: \n";
		CSR_format res = matrix_const_multiply(scalar, mat);
		res.output();		
	}
	else if (num_oper == 3){
		CSR_format mat1;
		CSR_format mat2;
		std::cout<<"Enter matrix 1:\n";
		mat1.input();
		std::cout<<"Enter matrix 2:\n";
		mat2.input();
		CSR_format res = matrix_multiply(mat1, mat2);
		std::cout<<"Results of matrix multiplication:\n";
		res.output();
	}
	else{
		std::cout << "ERROR: Invalid operation number entered.";
	}
}

void task3(){
	CSR_format mat;
	mat.input();
	find_det(mat.csr_to_std());
}

void test3(){
	std::vector<std::vector<float>> mat = {{9, 1, 3}, {3, 192, 4}, {-5, 8, 2}};
	find_det(mat);
}



void test2(){
	//Тест сложения двух матриц.
	std::vector<std::vector<float>> matrix1 = {{1, 1, 0, 0, 1, 0}, {1, 0, 0, 1, 0, 1}};
	std::vector<std::vector<float>> matrix2 = {{0, 1, 0, 1, 1, 0}, {1, 0, 0, 1, 0, 0}};
	CSR_format mat1(matrix1);
	CSR_format mat2(matrix2);
	CSR_format mat = sum_matrix(mat1, mat2);
	for (int i = 0; i < mat.value.size(); i++){
		std::cout << i << " [" << mat.row[i] << "][" << mat.col[i] << "] = " << mat.value[i] << std::endl;
	}
	//Тест умножения двух матрицю
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
    // task1();
	// task2();
	// task3();
    return 0;
}