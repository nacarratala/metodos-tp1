//
// Created by Nicolas Carratala on 04/09/2022.
//
#include "Metnum.h"
#include "LILMatrix.h"


using namespace std;

// TODO: chequear warning
// TODO: chequer int i = 0 (difere con pseudocodigo


void Metnum::triangulate_rows(LILMatrix &A, lilmatrix_rows_t::iterator row_j_it, lilmatrix_rows_t::iterator row_i_it,
                              std::vector<double> &b)
{
    auto row_i = row_i_it->first;
    auto row_j = row_j_it ->first;

    //i restadora
    //j restada
    auto col_it_i = row_i_it ->second.begin();
    auto col_it_j = row_j_it ->second.begin();

    bool cols_row_i_reached_end = (col_it_i == row_i_it->second.end());
    bool cols_row_j_reached_end = (col_it_j == row_j_it->second.end());

//    auto a_ji = col_it_j->second;
//    auto a_ii = col_it_i->second;
//    double m = a_ji / a_ii ;
//

    auto col_row_i = col_it_i->first;
    auto col_row_j = col_it_j->first;

    double m = 0.0;
    if (col_row_j == col_row_i)
    {
        auto a_ji = col_it_j->second;
        auto a_ii = col_it_i->second;
        m = a_ji / a_ii ;
    }

    bool keep_row_transformation = (!cols_row_i_reached_end || !cols_row_j_reached_end) && (m != 0.0);

    while(keep_row_transformation)
    {
        col_row_i = col_it_i->first;
        col_row_j = col_it_j->first;




//        if (col_row_j < row_i_it ->first)
//        {
//            /* A la izquierda de la diagonal tienen que quedar ceros, esto podria no ser asi por error de redondeo
//             * asi que forzamos el cero. Los elementos a la izquierda de la diagonal son los que tienen col_row_j < i.
//             * Un elemento cero implica borrar el elemento de la fila. */
//            row_j_it->second.erase(col_it_j);
//        }
//        else if (col_row_j  == col_row_i )
        if (col_row_j == col_row_i ) {
            auto a_jk = col_it_j->second;
            auto a_ik = col_it_i->second;
            auto new_a_jk = a_jk - m * a_ik;


            if (new_a_jk == 0)
            {
                row_j_it->second.erase(col_it_j);
            }
            else
            {
                col_it_j->second = new_a_jk;
            }

            col_row_i++;
            col_row_j++;

        }
        else if (col_row_j > col_row_i)
        {
            auto a_ji = col_it_i->second;
            col_it_j->second = a_ji * (-1);
            row_j_it->second.insert(col_it_j, make_pair(col_it_i->first,a_ji));
            //TODO: chequear que si colt_it_j esta aputando al nuevo elemento o al siguiente del nuevo, tal vez haya que avanzarlo
            col_row_i++;
            col_row_j++;

        }
        // CASO DONDE LA RESTADORA ES MAYOR QUE LA RESTADA
        else
        {
            col_row_j++;
        }

        cols_row_i_reached_end = (col_it_i == row_i_it->second.end());
        cols_row_j_reached_end = (col_it_j == row_j_it->second.end());
        keep_row_transformation = (!cols_row_i_reached_end || !cols_row_j_reached_end);

    }























}

void Metnum::triangulation(LILMatrix& A, vector<double>& b){
    int n = A.rows();
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


    auto row_i_it = A.matrix.begin();
    auto row_j_it = (row_i_it+1);

    bool row_i_it_reached_end = (row_i_it == A.matrix.end());


    bool keep_triangulating = !row_i_it_reached_end;
    while (keep_triangulating)
    {
        auto row_i = row_i_it->first;
        auto row_j = row_j_it->first;


        triangulate_rows(A, row_j_it, row_i_it, b);

        bool row_j_it_reached_end = (row_j_it == A.matrix.end());
        if (row_j_it_reached_end)
        {
            row_i_it++;
            row_j_it = row_i_it+1;
        }

    }


}

vector<double> Metnum::gaussianElimination(LILMatrix& A, vector<double>& b){
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
