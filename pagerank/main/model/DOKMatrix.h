//
// Created by Nicolas Carratala on 27/08/2022.
//
#include <map>
#include <tuple>

using namespace std;

#ifndef PAGERANK_DOKMATRIX_H
#define PAGERANK_DOKMATRIX_H

using dimension_t = int;
using value_t = int;

class DOKMatrix {

private:
    map<pair<dimension_t, dimension_t>, value_t> matrix;
    dimension_t m_rows;
    dimension_t m_columns;

    void setZero(dimension_t row, dimension_t column);

    pair<int, int> findUpperBoundRowAndColumn();

public:
    DOKMatrix();

    value_t getValue(dimension_t row, dimension_t column);

    void setValue(dimension_t row, dimension_t column, dimension_t value);

    dimension_t size();

    dimension_t rows();

    dimension_t columns();
};

#endif