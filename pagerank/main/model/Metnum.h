//
// Created by Nicolas Carratala on 04/09/2022.
//
#include <vector>
#include "model/LILMatrix.h"


#ifndef PAGERANK_METNUM_H
#define PAGERANK_METNUM_H

class Metnum {

public:

    static std::vector<double> gaussianElimination(LILMatrix& A, std::vector<double>& b);

    static void triangulation(LILMatrix &A, std::vector<double> &b);

    static void triangulate_rows(lilmatrix_rows_t::iterator row_j, lilmatrix_rows_t::iterator row_i, std::vector<double> &b);
};

#endif
