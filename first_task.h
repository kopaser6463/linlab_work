#ifndef FIRST_TASK_H
#define FIRST_TASK_H

#include <iostream>
#include <vector>

class CSR_format{
public:
    short n;
	short m;
	std::vector<int>row;
	std::vector<int>col;
	std::vector<float>value;

	CSR_format(std::vector<std::vector<float>> matrix_std);
    float trace();
    std::vector<std::vector<float>> csr_to_std();
	float matrix_value(const int col, const int row);
};
#endif //FIRST_TASK_H