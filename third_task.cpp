#include "first_task.h"
/*
 Функция выполняющая подсчет определителя матрицы, и определение существования обратной матрицы.

 mat — матрица в стандартном формате, для которой считается определитель.
 Если матрица не является квадратной, выйдет ошибка.
*/
static void find_det(std::vector<std::vector<float>> mat){
	//Чтобы определить сушествует матрица обратная данной или нет, достаточно знать значение её определителя, если он равен 0 - обратной матрици нет.
	//Для подсчета определителя, использован алгоритм позволяющий посчитать определитель перемножением элементов главной диагонали.
    if (mat.size() == mat[0].size()){
        float sum_c = 0;
        float sum_r = 0;
        for (unsigned int i = 0; i < mat.size(); i++){
            for (unsigned int j = 0; j < mat.size(); j++){
                sum_c += mat[j][i];
                sum_r += mat[i][j];
            }
            if ((sum_c == 0) || (sum_r == 0)){
                std::cout<<"Det = " << 0 << "\nNo, there is no inverse matrix for this one." << std::endl;
                return;
            }
            else{
                sum_c = 0;
                sum_r = 0;
            }
        }
        float koef;
        short inv_det = 1;
        for (unsigned int i = 0; i < mat.size() - 1; i++){
            for (unsigned int j = i+1; j < mat.size(); j++){
                if (mat[i][i] != 0){
                    koef = mat[j][i] / mat[i][i];
                }
                else{
                    for (unsigned int k = j; k < mat.size(); k++){
                        if (mat[k][i] != 0){
                            swap(mat[i], mat[j]);
                            j--;
                            inv_det *= -1;
                        }
                    }
                }
                for (unsigned int k = i; k < mat.size(); k++){
                    mat[j][k] -= mat[i][k] * koef;
				}
            }
        }
        float det = 1;
        for (int i = 0; i<mat.size(); i++){
            det *= mat[i][i];
        }
        if (det != 0){
            std::cout<<"Det = " << det * inv_det << "\nYes, there is an inverse matrix of this one." << std::endl;
        }
        else{
            std::cout<<"Det = " << det << "\nNo, there is no inverse matrix for this one." << std::endl;
        }
    }
    else{
        throw std::runtime_error("Error finding matrix determinant. Matrix is ​​not square.");
    }
}