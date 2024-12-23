#include "first_task.h"
/*
 Функция выполняющая сложение 2 матриц между собой.

 mat1 — Первая матрица (Левая)
 mat2 — Вторая матрица (Правая)
 @returns CSR_format
 Если у матриц не сходятся размеры, выйдет ошибка.

*/
static CSR_format sum_matrix(CSR_format mat1, CSR_format mat2){
	//Для сложения матриц написан алгоритм выполняющий сложение матриц без перевода её в обычный вид.
	//Для сложения матриц таким способом выполняется сложение элементов матрицы в случае если у них совпадает ряд и колонка.
	//Если они не совподают есть два варианта, либо это элемент которого нет в первой матрице, либо наоборот его нет уже во второй.
	//В таких случаях соответственно выпоняется либо добавление нового элемента в матрицу или пропуск так как он уже там есть.
	if ((mat1.m == mat2.m) && (mat1.n == mat2.n)){
		short iter1 = 0;
		short iter2 = 0;
		while ((iter1 < mat1.row.size()) && (iter2 < mat2.row.size())){
			if ((mat1.row[iter1] == mat2.row[iter2]) && (mat1.col[iter1] == mat2.col[iter2])){
				mat1.value[iter1] += mat2.value[iter2];
				iter1++;
				iter2++;
			}
			else if ((mat1.row[iter1] >= mat2.row[iter2]) && (mat1.col[iter1] >= mat2.col[iter2])){
				mat1.row.insert(mat1.row.begin() + iter1, mat2.row[iter2]);
				mat1.col.insert(mat1.col.begin() + iter1, mat2.col[iter2]);
				mat1.value.insert(mat1.value.begin() + iter1, mat2.value[iter2]);
				iter1++;
				iter2++;
			}
			else{
				iter1++;
			}
			if (iter1 == mat1.row.size()){
				for (iter2; iter2<mat2.row.size(); iter2++){
					mat1.row.push_back(mat2.row[iter2]);
					mat1.col.push_back(mat2.col[iter2]);
					mat1.value.push_back(mat2.value[iter2]);
				}
			}
		}
		return mat1;
	}
	else{
		throw std::runtime_error("Addition is impossible. Different dimensions of matrices."); 
	}
}

/*
 Функция умножающая матрицу на скалярное число.

 number — число на которое умножается матрица.
 mat — матрица которую мы умножаем.
 @returns CSR_format

*/
static CSR_format matrix_const_multiply(const float number, CSR_format mat){
	//Чтобы умножить все значения матрицы в данном формате, достаточно домножить все элементы массива values.
	if (number != 0){
		for (int i = 0; i < mat.value.size(); i++){
			mat.value[i] *=  number;
		}
	}
	else{
		CSR_format res;
		res.n = mat.n;
		res.m = mat.m;
		return res;
	}
	return mat;
}
/*
 Функция выполняющая умножение 2 матриц между собой.

 mat1 — Первая матрица (Левая)
 mat2 — Вторая матрица (Правая)
 @returns CSR_format
 Если у матриц не сходятся размеры, выйдет ошибка.

*/
static CSR_format matrix_multiply(CSR_format mat1, CSR_format mat2){
	//Для умножения матриц в данной функции производится преобразования оной в обычный формат для матриц (метод csr_to_std), а после простое по-элементное умножение.
	if (mat1.m == mat2.n){
		auto A = mat1.csr_to_std();
		auto B = mat2.csr_to_std();
		std::vector<std::vector<float>> v_res(mat1.n, std::vector<float> (mat2.m, 0));
		for(int i = 0; i < mat1.n; i++){
			for(int j = 0; j < mat2.m; j++){
				for(int k = 0; k < mat1.m; k++){
					v_res[i][j] += A[i][k] * B[k][j];
				}
			}
		}
		CSR_format res(v_res);
		return v_res;
	}
	else{
		throw std::runtime_error("Matrix multiplication is impossible. The number of columns in the first matrix and the number of rows in the second don't match."); 
	}
}
/*
 Функция выполняющая умножение 2 матриц между собой. (WIP)
 ДАННАЯ ФУНКЦИЯ НЕ РАБОТАЕТ, ДЛЯ УМНОЖЕНИЯ МАТРИЦ ИСПОЛЬЗУЙТЕ ФУНКЦИЮ ВЫШЕ.
 mat1 — Первая матрица (Левая)
 mat2 — Вторая матрица (Правая)
 @returns CSR_format
 Данная функции выполняет умножение матриц без их перевода в обычный вид.

*/
static CSR_format matrix_multiply_v2(CSR_format mat1, CSR_format mat2){
	if (mat1.m == mat2.n){
		auto A = mat1;
		auto B = mat2;
		int s;
		int x;
		std::vector<std::vector<float>> v_res(0, std::vector<float> (0));
		for(int i = 0; i < mat1.value.size(); i++){
			x = A.row[i];
			for(int ii = 0; ii < B.n; ii++){
				if(B.matrix_value(ii+1,A.col[i]+1) != 0){
					s = A.matrix_value(A.col[i]+1,x+1) * B.matrix_value(ii+1,A.col[i]+1);
					std::cout << s << " " << x << " " << ii;
					std::cout << "\n";
					
				}
			}
		}
		CSR_format res(v_res);
		return v_res;
	}
	else{
		throw std::runtime_error("Matrix multiplication is impossible. The number of columns in the first matrix and the number of rows in the second don't match."); 
	}
}