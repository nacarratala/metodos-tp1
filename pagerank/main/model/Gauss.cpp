//
// Created by Nicolas Carratala on 04/09/2022.
//
#include "Gauss.h"
#include "LILMatrix.h"


using namespace std;

void Gauss::triangulate_rows(LILMatrix &A, lilmatrix_rows_t::iterator row_j_it, lilmatrix_rows_t::iterator row_i_it,
                             std::vector<double> &b) {
    auto row_i = row_i_it->first;
    auto row_j = row_j_it->first;

    auto col_it_i = row_i_it->second.begin();
    auto col_it_j = row_j_it->second.begin();

    bool cols_row_i_reached_end = (col_it_i == row_i_it->second.end());
    bool cols_row_j_reached_end = (col_it_j == row_j_it->second.end());

    auto col_row_i = col_it_i->first;
    auto col_row_j = col_it_j->first;

    double m = 0.0;
    if (col_row_j == col_row_i) {
        auto a_ji = col_it_j->second;
        auto a_ii = col_it_i->second;
        m = a_ji / a_ii;
    }
    b[row_j] = b[row_j] - m * b[row_i];

    bool keep_row_transformation = (!cols_row_i_reached_end) && (m != 0.0);
    while (keep_row_transformation) {
        col_row_i = col_it_i->first;
        if (!cols_row_j_reached_end)
            col_row_j = col_it_j->first;
        if (cols_row_j_reached_end) {
            auto a_jk = col_it_i->second;
            auto new_a_jk = (-m) * a_jk;
            auto element = make_pair(col_it_i->first, new_a_jk);
            col_it_j = row_j_it->second.insert(col_it_j, element);
            A.m_size++;
            col_it_i++;
        } else if (col_row_j > col_row_i) {
            auto a_jk = col_it_i->second;
            auto new_a_jk = (-m) * a_jk;
            auto element = make_pair(col_it_i->first, new_a_jk);
            col_it_j = row_j_it->second.insert(col_it_j, element);
            A.m_size++;
            //TODO: chequear que si colt_it_j esta aputando al nuevo elemento o al siguiente del nuevo, tal vez haya que avanzarlo
            col_it_i++;
            col_it_j++;
        }
        // CASO DONDE LA RESTADORA ES MAYOR QUE LA RESTADA
        else if (col_row_j == col_row_i) {
            auto a_jk = col_it_j->second;
            auto a_ik = col_it_i->second;
            auto new_a_jk = a_jk - m * a_ik;
            if (new_a_jk == 0) {
                col_it_j = row_j_it->second.erase(col_it_j);
                A.m_size--;
            } else {
                col_it_j->second = new_a_jk;
                col_it_j++;
            }
            col_it_i++;
        } else {
            col_it_j++;
        }
        cols_row_i_reached_end = (col_it_i == row_i_it->second.end());
        cols_row_j_reached_end = (col_it_j == row_j_it->second.end());
        keep_row_transformation = (!cols_row_i_reached_end);
    }
}

void Gauss::triangulation(LILMatrix &A, vector<double> &b) {
    auto row_i_it = A.matrix.begin();
    auto row_j_it = (row_i_it + 1);

    bool row_i_it_reached_end = (row_i_it == A.matrix.end());
    bool row_j_it_reached_end;

    bool keep_triangulating = !row_i_it_reached_end;
    while (keep_triangulating) {
        triangulate_rows(A, row_j_it, row_i_it, b);
        row_j_it++;
        row_j_it_reached_end = (row_j_it == A.matrix.end());
        if (row_j_it_reached_end) {
            row_i_it++;
            row_j_it = row_i_it + 1;
        }
        row_j_it_reached_end = (row_j_it == A.matrix.end());
        row_i_it_reached_end = (row_i_it == A.matrix.end());
        keep_triangulating = !row_i_it_reached_end && !row_j_it_reached_end;
    }
}

vector<double> Gauss::gaussianElimination(LILMatrix &A, vector<double> &b) {
    int n = A.rows();
    triangulation(A, b);
    vector<double> result;
    for (int i = 0; i < n; i++) {
        result.push_back(-1);
    }
    for (int i = n - 1; i >= 0; i--) {
        double res = b[i];
        for (int j = i + 1; j < n; j++) {
            res = res - A.getValue(i, j) * result[j];
        }
        auto pepe = A.getValue(i, i);
        result[i] = res / A.getValue(i, i);
    }
    return result;
}