//
// Created by Nicolas Carratala on 04/09/2022.
//
#include <vector>
#include "model/LILMatrix.h"


#ifndef PAGERANK_GAUSS_H
#define PAGERANK_GAUSS_H

class Gauss {

public:

    static std::vector<double> gaussianElimination(LILMatrix& A, std::vector<double>& b);
    static std::vector<double> gaussianElimination2(LILMatrix& A, std::vector<double>& b);

    static void triangulation(LILMatrix &A, std::vector<double> &b);


    static void triangulate_rows_backup(LILMatrix &A, lilmatrix_rows_t::iterator row_j_it, lilmatrix_rows_t::iterator row_i_it,
                                 std::vector<double> &b);

    static void triangulate_rows(LILMatrix &A, lilmatrix_rows_t::iterator row_j_it, lilmatrix_rows_t::iterator row_i_it,
                                 std::vector<double> &b);
};

#endif
