//
// Created by Nicolas Carratala on 04/09/2022.
//
#include "metnum.h"


using namespace std;

// TODO: chequear warning
// TODO: chequer int i = 0 (difere con pseudocodigo


void metnum::triangulate_rows(lilmatrix_rows_t::iterator row_j_it, lilmatrix_rows_t::iterator row_i_it,  std::vector<double> &b)
{
    auto row_i = row_i_it->first;
    auto row_j = row_j_it ->first;

    auto col_it_i = row_i_it ->second.begin();
    auto col_it_j = row_j_it ->second.begin();


    bool cols_row_i_reached_end = (col_it_i == row_i_it->second.end());
    bool cols_row_j_reached_end = (col_it_j == row_j_it->second.end());
    bool keep_row_transformation = (!cols_row_i_reached_end && !cols_row_j_reached_end);

    while(keep_row_transformation)
    {
        auto col_1 = col_it_i->first;
        auto col_2 = col_it_j->first;

        if (col_2 < row_i_it ->first)
        {
            /* A la izquierda de la diagonal tienen que quedar ceros, esto podria no ser asi por error de redondeo
             * asi que forzamos el cero. Los elementos a la izquierda de la diagonal son los que tienen col_2 < i.
             * Un elemento cero implica borrar el elemento de la fila. */
            row_j_it->second.erase(col_it_j);
        }
        else if (col_2  == col_1 )
        {

            auto a_ji = col_it_j->second;
            auto a_ii = col_it_i->second;
            double m = a_ji / a_ii ;

            col_it_j->second = a_jk - m * a_ik;
        }
        else if (col_2 < col_1)
        {

        }
        else
        {

        }




    }



}

void metnum::triangulation(LILMatrix& A, vector<double>& b){
//    int n = A.rows();
//    for(int i = 0; i < n-1; i++){
//        for(int j = i+1; j < n; j++){
//            auto a_ji = A.getValue(j,i);
//            auto a_ii = A.getValue(i,i);
//            double m = a_ji / a_ii ;
//            for (int k = i; k < n; k++) {
//                auto a_jk = A.getValue(j,k);
//                auto a_ik = A.getValue(i,k);
//                A.setValue(j, k, a_jk - m * a_ik);
//            }
//            b[j] = b[j] - m * b[i];
//        }
//    }

    for(int i = 0; i < n-1; i++) {
        for (int j = i + 1; j < n; j++) {
            auto col_it_1 = A.findLowerBoundRow(i);
            auto col_it_2 = A.findLowerBoundRow(j);



        }
    }
}

vector<double> metnum::gaussianElimination(LILMatrix& A, vector<double>& b){
    int n = A.rows(); // Matriz cuadrada rows == columns.
    triangulation(A,b);
    vector<double> result;
    for(int i = 0; i < n; i++){
        result.push_back(-1);
    }
    for(int i = n-1; i >= 0; i--){
        double res = b[i];
        for(int j = i+1; j < n; j++){
            res = res - A.getValue(i,j)*result[j];
        }
        result[i] = res/A.getValue(i,i);
    }
    return result;
}
