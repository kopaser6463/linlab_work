#include "first_task.h"
#include "second_task.cpp"
#include "third_task.cpp"

int main(){
	CSR_format mat1;
	mat1.input();
	std::cout << mat1.trace() << "\n";
}