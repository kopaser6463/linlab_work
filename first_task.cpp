#include "CSR_format.cpp"

	float trace(CSR_format mat){
		float res = 0;
		for (int i = 0; i < mat.value.size(); i++){
			if (mat.row[i] == mat.col[i]){
				res += mat.value[i];
			}
		}
		return res;
	}

//simple 

int main(){
	return 0;
}
