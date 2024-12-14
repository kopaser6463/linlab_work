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
        for (int i = 0; i < mat.size() - 1; i++){
            for (int j = i+1; j < mat.size(); j++){
                float koef = mat[j][i] / mat[i][i]; 
                for (int k = i; k < mat.size(); k++){
                    mat[j][k] -= mat[i][k] * koef;
				}
            }
        }
        float det = 1;
        for (int i = 0; i<mat.size(); i++){
            det *= mat[i][i];
        }
        if (det != 0){
            std::cout<<"Det = " << det << "\nYes, there is an inverse matrix of this one." << std::endl;
        }
        else{
            std::cout<<"Det = " << det << "\nNo, there is no inverse matrix for this one." << std::endl;
        }
    }
    else{
        throw std::runtime_error("Error finding matrix determinant. Matrix is ​​not square.");
    }
}