#ifndef FIRST_TASK_H
#define FIRST_TASK_H

#include <iostream>
#include <vector>
#include <unordered_map>
class CSR_format{
public:
    unsigned int n;
	unsigned int m;
	std::vector<unsigned int>row;
	std::vector<unsigned int>col;
	std::vector<float>value;

	CSR_format(std::vector<std::vector<float>> matrix_std);
	CSR_format(){};
    float trace();
    std::vector<std::vector<float>> csr_to_std();
	float matrix_value(const unsigned int col, const unsigned int row);
	void output();
	void input();
};
#endif //FIRST_TASK_H