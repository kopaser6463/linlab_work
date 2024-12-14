#include "first_task.h"

static void find_det(std::vector<std::vector<float>> mat){
    if (mat.size() == mat[0].size()){
        for (int i = 0; i < mat.size() - 1; i++){
            for (int j = i+1; j < mat.size(); j++){
                float koef = mat[j][i] / mat[i][i]; 
                for (int k = i; k < mat.size(); k++){
                    mat[j][k] -= mat[i][k] * koef;               }
            }
        }
        float det = 1;
        for (int i = 0; i<mat.size(); i++){
            det *= mat[i][i];
        }
        if (det != 0){
            std::cout<<"Det = " << det << "\nДа, существует обратная матрица данной." << std::endl;
        }
        else{
            std::cout<<"Det = " << det << "\nНет, не существует обратная матрица данной." << std::endl;
        }
    }
    else{
        throw std::runtime_error("Error finding matrix determinant. Matrix is ​​not square.");
    }
}