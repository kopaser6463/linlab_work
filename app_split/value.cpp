#include "first_task.h"
#include "second_task.cpp"
#include "third_task.cpp"

int main(){
	CSR_format mat1;
	mat1.input();
	std::string a;
	std::string b;
	
	std::getline(std::cin, a);
	std::getline(std::cin, b);
	
	int int_a = std::stoi(a);
	int int_b = std::stoi(b);
	
	std::cout << mat1.matrix_value(int_a,int_b) << "\n";
}