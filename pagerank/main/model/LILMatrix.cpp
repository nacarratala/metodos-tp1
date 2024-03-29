//
// Created by Nicolas Carratala on 27/08/2022.
//

#include "LILMatrix.h"
#include <algorithm>
#include <fstream>
#include <assert.h>

using namespace std;

LILMatrix::LILMatrix() :
        m_rows(0),
        m_columns(0),
        matrix(lilmatrix_rows_t(0)),
        m_size(0) {
}



LILMatrix::LILMatrix(const std::vector<std::vector<double>> &matrix_vec) :
        m_rows(matrix_vec.size()),
        m_columns(matrix_vec[0].size()),
        matrix(lilmatrix_rows_t(0)),
        m_size(0) {
    for (int i = 0; i < matrix_vec.size(); ++i)
        for (int j = 0; j < matrix_vec[i].size(); ++j)
            setValue(i, j, matrix_vec[i][j]);
}

//LILMatrix::LILMatrix(int rows, int columns, lilmatrix_rows_t &m_rows_t, int size) :
//        m_rows(rows),
//        m_columns(columns),
//        matrix(m_rows_t),
//        m_size(size){}

LILMatrix::LILMatrix(int links, ifstream &inputFile) :
        m_rows(0),
        m_columns(0),
        m_size(0),
        matrix(lilmatrix_rows_t(0)) {
    for (int i = 0; i < links; i++) {
        int srcPage, dstPage;
        inputFile >> srcPage >> dstPage;
        setValue(srcPage-1, dstPage-1, 1);
    }
}

double LILMatrix::getValue(int row, int column) {
    auto itRows = findLowerBoundRow(row);
    // std::cout << "row: " << itRows->first << std::endl;
    if (matrix.end() == itRows || itRows->first != row) return 0;
    auto itCols = findLowerBoundCol(itRows->second, column);
    // std::cout << "col: " << itCols->first << std::endl;
    if (itRows->second.end() == itCols || itCols->first != column) return 0;
    return itCols->second;
}


//TODO: Arreglar este metodo, demasiados parches y la logica es innecesariamente complicada
void LILMatrix::setValue(int row, int column, double value) {
    assert(row >= 0 && "Row out of bounds");
    assert(column >= 0 && "Column out of bounds");
    // std::cout << "setValue " << row << ", " << column << ", " << value << std::endl;
    auto itRow = findLowerBoundRow(row);

    // Caso donde no hay filas
    if (matrix.empty()) {

        if ( value == 0.0) return;

        matrix.push_back(lilmatrix_row_t(row, lilmatrix_cols_t(0)));
        auto &row_elem = matrix.back();
        row_elem.second.emplace_back(column, value);
        // std::cout << "row: " << matrix[0].first  << std::endl;
        // std::cout << "col: " << matrix[0].second[0].first  << std::endl;
        // std::cout << "value: " << matrix[0].second[0].second  << std::endl;
        m_rows =  m_rows > (row+1) ? m_rows : (row+1) ;;
        m_columns = m_columns > (column+1) ? m_columns : (column+1) ;;
        m_size++;
        return;
    }

//    if (itRow == matrix.end())
//        /* Si no encuentra cota inferior es porque todos los elmenetos son mayores entonces apunta a end.
//         * Tenemos que insertar uno antes para que no sea el final*/
//        itRow = itRow - 1;

    // Caso donde hay filas pero no es la buscada (insertamos de forma ordenada)
    if (itRow == matrix.end() || itRow->first != row) {
        // std::cout << itRow-> first << std::endl;

        if (value == 0.0) return;

        itRow = matrix.insert(itRow, lilmatrix_row_t(row, lilmatrix_cols_t(0)));
        auto &row_elem = itRow->second;
        row_elem.emplace_back(column, value);
        // std::cout << "row: " << itRow->first << std::endl;
        // std::cout << "col: " << itRow->second[0].first  << std::endl;
        // std::cout << "value: " << itRow->second[0].second  << std::endl;
        m_rows = m_rows > (row+1)  ? m_rows : (row+1) ;
        m_columns = m_columns > (column+1)  ? m_columns : (column+1) ;
        m_size++;
        return;
    }

    // Caso donde se encontro la fila, hay que hacer busqueda binaria en columnas
    auto &row_elem = itRow->second;
    auto itCol = findLowerBoundCol(row_elem, column);

    bool element_found = (itCol != row_elem.end() && itCol->first == column);
    if (element_found)
    {
        if (value != 0)
        {
            itCol->second = value;
            return;
        }

        row_elem.erase(itCol);
        m_size--;
        if (column+1 == m_columns)
        {
            m_columns = findUpperBoundColumn() +1;
        }
        if (row_elem.empty())
        {
            matrix.erase(findLowerBoundRow(row));
            if (m_rows == row+1)
                m_rows = findUpperBoundRow() +1;
        }
    }
    else
    {
        if ( (itCol == row_elem.end() || itCol->first != column ) && value != 0)
        {
//        row_elem.emplace_back(column, value);
            row_elem.insert(itCol, lilmatrix_value_t(column,value));
            m_size++;
            m_columns = m_columns > (column+1)  ? m_columns : (column+1) ;
            return;
        }

//        else if (itCol->first != column && value != 0)
//        {
//            row_elem.insert(itCol, lilmatrix_value_t(column, value));
//            m_size++;
//            m_columns = m_columns > column ? m_columns : column;
//            return;
//        }
    }

}

int LILMatrix::getPageGrade(int page) {
    int res = 0;
    for (int i = 0; i < m_columns; i++)
        res += getValue(page, i);
    return res;
}

//https://www.includehelp.com/stl/std-lower_bound-function-with-example-in-cpp-stl.aspx?ref=rp
lilmatrix_rows_t::iterator LILMatrix::findLowerBoundRow(int row) {
    return std::lower_bound(
            matrix.begin(),
            matrix.end(),
            row,
            [](const lilmatrix_row_t &row_element, int value) {
                int row_num = row_element.first; // row_element.first
                // std::cout << "value: " << value << " row_num: " << row_num;
                return value > row_num;
            });
}

lilmatrix_cols_t::iterator LILMatrix::findLowerBoundCol(lilmatrix_cols_t &cols, int column) {
    return std::lower_bound(
            cols.begin(),
            cols.end(),
            column,
            [](const lilmatrix_value_t &col_element, int value) {
                int col_num = col_element.first; // row_element.first
                return value > col_num;
            });
}

int LILMatrix::findUpperBoundRow() {
    if (matrix.empty()) return 0;
    return matrix.end()->first;
}

int LILMatrix::findUpperBoundColumn() {
    auto maxColumn = 0;
    for (auto &i: matrix)
        for (auto &j: i.second)
            if (j.first > maxColumn)
                maxColumn = j.first;
    return maxColumn;
}

void LILMatrix::multiplicationByScalar(double scalar) {
    if (scalar == 0) {
        matrix = lilmatrix_rows_t(0);
        m_size = 0;
        m_columns = 0;
        m_rows = 0;
    }
    for (auto &i: matrix)
        for (auto &j: i.second)
            j.second = j.second * scalar;
}

void LILMatrix::multiplicationByDiagonalMatrix(vector<double> triangularMatrix) {
    for (auto &i : matrix)
        for (auto &j : i.second)
            j.second = triangularMatrix[j.first] * getValue(i.first, j.first);
}

void LILMatrix::identitySubstractSelf() {
    for (auto& i : matrix)
        for (auto &j: i.second)
            setValue(
                    i.first,
                    j.first,
                    (-1) * getValue(i.first, j.first)
            );
    for (int k = 0; k < m_columns; k++)
        setValue(k,k,1); // considering always zero values in the self diagonal
    //setValue(k,k, 1 - getValue(k,k)); // considering nonzero values in the self diagonal
}


int LILMatrix::size() {
    return m_size;
}


int LILMatrix::rows() {
    return m_rows;
}


int LILMatrix::columns() {
    return m_columns;
}


void LILMatrix::debug_print()
{
    for(int i = 0; i < m_rows; ++i)
    {
        for(int j = 0; j < m_columns; ++j)
        {
            std::cout << getValue(i, j);
            if (j+1 < m_columns) std::cout << ", ";
        }
        std::cout << std::endl;
    }
}

//LILMatrix LILMatrix::row(int row)
//{
//
//}