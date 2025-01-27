#include "first_task.h"
#include "second_task.cpp"
#include "third_task.cpp"

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
		std::cout<<"Element [" << row << "][" << col << "] = " << mat.matrix_value(row, col);
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

int main(){
    // task1();
	// task2();
	// task3();
	return 0;
}