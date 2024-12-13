#include "first_task.h"

void matrix_const_multiply(const float number, CSR_format mat){
		for (int i = 0; i < mat.value.size(); i++){
			mat.value[i] *=  number;
    }
}