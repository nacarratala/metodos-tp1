//
// Created by Nicolas Carratala on 27/08/2022.
//

#include "LILMatrix.h"
#include <algorithm>
using namespace std;

LILMatrix::LILMatrix() :
        m_rows(0),
        m_columns(0),
        matrix(lilmatrix_rows_t(0)),
        m_size(0) {}

// Inicializamos un vector con vectores representando filas vacias.
LILMatrix::LILMatrix(int rows, int columns)
        : m_rows(rows),
          m_columns(columns),
          matrix(lilmatrix_rows_t(0)),
          m_size(0) {}

//https://www.includehelp.com/stl/std-lower_bound-function-with-example-in-cpp-stl.aspx?ref=rp
lilmatrix_rows_t::iterator LILMatrix::findLowerBoundRow(int row) {
    return std::lower_bound(
            matrix.begin(),
            matrix.end(),
            row,
            [](const lilmatrix_row_t &row_element, int value) {
                int row_num = row_element.first; // row_element.first
                // std::cout << "value: " << value << " row_num: " << row_num;
                return value < row_num;
            });
}

lilmatrix_cols_t::iterator LILMatrix::findLowerBoundCol(lilmatrix_cols_t &cols, int column) {
    return std::lower_bound(
            cols.begin(),
            cols.end(),
            column,
            [](const lilmatrix_value_t &col_element, int value) {
                int col_num = col_element.first; // row_element.first
                return value < col_num;
            });
}

int LILMatrix::getValue(int row, int column) {
    auto itRows = findLowerBoundRow(row);
    // std::cout << "row: " << itRows->first << std::endl;
    if (itRows->first != row) return 0;

    auto itCols = findLowerBoundCol(itRows->second, column);
    // std::cout << "col: " << itCols->first << std::endl;
    if (itCols->first != column) return 0;

    return itCols->second;
}

void LILMatrix::setValue(int row, int column, int value) {
    // std::cout << "setValue " << row << ", " << column << ", " << value << std::endl;
    auto itRow = findLowerBoundRow(row);

    // Caso donde no hay filas
    if (itRow == matrix.end()) {
        matrix.push_back(lilmatrix_row_t(row, lilmatrix_cols_t(0)));
        auto &row_elem = matrix.back();
        row_elem.second.emplace_back(column, value);
        // std::cout << "row: " << matrix[0].first  << std::endl;
        // std::cout << "col: " << matrix[0].second[0].first  << std::endl;
        // std::cout << "value: " << matrix[0].second[0].second  << std::endl;
        m_size++;
        return;
    }

    // Caso donde hay filas pero no es la buscada (insertamos de forma ordenada)
    if (itRow->first != row) {
        // std::cout << itRow-> first << std::endl;
        itRow = matrix.insert(itRow, lilmatrix_row_t(row, lilmatrix_cols_t(0)));
        auto &row_elem = itRow->second;
        row_elem.emplace_back(column, value);
        // std::cout << "row: " << itRow->first << std::endl;
        // std::cout << "col: " << itRow->second[0].first  << std::endl;
        // std::cout << "value: " << itRow->second[0].second  << std::endl;
        m_size++;
        return;
    }

    // Caso donde se encontro la fila, hay que hacer busqueda binaria en columnas
    auto &row_elem = itRow->second;
    auto itCol = findLowerBoundCol(row_elem, column);
    if (itCol == row_elem.end() && value != 0) {
        row_elem.emplace_back(column, value);
        m_size++;
        return;
    }

    if (itCol->first != column && value != 0) {

        row_elem.insert(itCol, lilmatrix_value_t(column, value));
        m_size++;
        return;
    }

    if (itCol->first == column) {
        if (value != 0) {
            itCol->second = value;
            return;
        }
        row_elem.erase(itCol);
        m_size--;
        if (row_elem.empty()) matrix.erase(findLowerBoundRow(row));
    }
}

int LILMatrix::size() {
    return matrix.size();
}

int LILMatrix::rows() {
    return m_rows;
}

int LILMatrix::columns() {
    return m_columns;
}