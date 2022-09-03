//
// Created by Nicolas Carratala on 27/08/2022.
//

#include <iostream>
#include <assert.h>
#include "DOKMatrix.h"

DOKMatrix::DOKMatrix() : m_rows(0), m_columns(0) {}

value_t DOKMatrix::getValue(dimension_t row, dimension_t column) {
    auto isPresent = matrix.count(make_pair(row, column)) > 0;
    if (!isPresent) return 0;
    return matrix.at(pair<dimension_t, dimension_t>(row, column));
}

void DOKMatrix::setZero(dimension_t row, dimension_t column) {
    assert(row > 0 && "Row out of bounds");
    assert(column > 0 && "Column out of bounds");
    auto elementIt = matrix.find(make_pair(row, column));
    if (elementIt == matrix.end()) return;
    matrix.erase(elementIt);
}

void DOKMatrix::setValue(dimension_t row, dimension_t column, dimension_t value) {
    assert(row > 0 && "Row out of bounds");
    assert(column > 0 && "Column out of bounds");
    if (value == 0) {
        setZero(row, column);
        auto maxRowAndColumn = findUpperBoundRowAndColumn();
        m_rows = maxRowAndColumn.first;
        m_columns = maxRowAndColumn.second;
        return;
    }
    auto key = make_pair(row, column);
    matrix.insert(make_pair(key, value));
    m_rows = m_rows < row ? row : m_rows;
    m_columns = m_columns < column ? column : m_columns;
}

pair<int, int> DOKMatrix::findUpperBoundRowAndColumn() {
    auto maxRow = 0;
    auto maxColumn = 0;
    for (auto it = matrix.begin(); it != matrix.end(); it++) {
        auto mapElement = *it;
        auto row = mapElement.first.first;
        auto column = mapElement.first.second;
        maxRow = maxRow < row ? row : maxRow;
        maxColumn = maxColumn < column ? column : maxColumn;
    }
    return make_pair(maxRow, maxColumn);
}

dimension_t DOKMatrix::rows() {
    return m_rows;
}

dimension_t DOKMatrix::columns() {
    return m_columns;
}

dimension_t DOKMatrix::size() {
    return matrix.size();
}