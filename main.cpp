#include "first_task.h"
#include "first_task.cpp"
#include "second_task.cpp"
#include "third_task.cpp"

int test(){
	
	std::vector<std::vector<float>> array(2, std::vector<float> (3));
	CSR_format mat(array);
	mat.input();
	mat.output();

	return 0;
}
int input_output_determ(){
	return 0;
	
	
}

int main(){
    test();
    return 0;
}