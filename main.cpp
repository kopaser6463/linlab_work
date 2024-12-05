#include <iostream>
#include <vector>

class CSR_format{
private:
	short n;
	short m;
	std::vector<int>row;
	std::vector<int>col;
	std::vector<float>value;
public:
	CSR_format(std::vector<std::vector<float>> matrix_nformat){
		this->n = matrix_nformat.size();
		this->m = matrix_nformat[0].size();
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (matrix_nformat[i][j] != 0){
					this->row.push_back(i);
					this->col.push_back(j);
					this->value.push_back(matrix_nformat[i][j]);
				}
			}
		}
	}

	float trace(){
		float res = 0;
		for (int i = 0; i < value.size(); i++){
			if (row[i] == col[i]){
				res += value[i];
			}
		}
		return res;
	}
};


int main(){
	return 0;
}
