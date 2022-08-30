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


/*
Inicializamos un vector con vectores representando filas vacias.
*/
LILMatrix::LILMatrix(int rows, int columns) 
: m_rows(rows), 
m_columns(columns), 
matrix(lilmatrix_rows_t(0)),
m_size(0) {}






/*
https://www.includehelp.com/stl/std-lower_bound-function-with-example-in-cpp-stl.aspx?ref=rp
*/
lilmatrix_rows_t::iterator LILMatrix::findLowerBoundRow(int row) 
{
	return std::lower_bound(
		matrix.begin(),
		matrix.end(), 
		row, 
		[](const lilmatrix_row_t& row_element, int value){
			int row_num = row_element.first; // row_element.first
			// std::cout << "value: " << value << " row_num: " << row_num;
			return value < row_num;
          });
}


lilmatrix_cols_t::iterator LILMatrix::findLowerBoundCol(lilmatrix_cols_t& cols, int column) 
{
	return std::lower_bound(
		cols.begin(),
		cols.end(), 
		column, 
		[]( const lilmatrix_value_t& col_element, int value){
			int col_num = col_element.first; // row_element.first
			return value < col_num;
          });
}




int LILMatrix::getValue(int row, int column){
	auto itRows = findLowerBoundRow(row);
	// std::cout << "row: " << itRows->first << std::endl;
	if (itRows->first != row) return 0;
	
	auto itCols = findLowerBoundCol(itRows->second, column);
	// std::cout << "col: " << itCols->first << std::endl;
	if (itCols->first != column) return 0;
	
	return itCols->second;
	
	
	
}

int LILMatrix::findValue(vector<pair<int, int>> row, int column){
    for (int i = 0; i < row.size(); i++){
        if (row[i].first == column){
            return row[i].second;
        }
    }
    return 0;
}

//TODO: erase when value = 0
// TODO: ignore pushback when value already exist
// void LILMatrix::setValue(int row, int column, int value) {
    // if (matrix.size() > row){
        // matrix[row].push_back(make_pair(column, value));
        // return;
    // }
    // vector<pair<int,int>> emptyRow;
    // for (int i = 0; i < row - matrix.size() + 1; i++){
        // matrix.push_back(emptyRow);
    // }
    // auto columnAndValue = make_pair(column, value);
    // matrix[row].push_ba0ck(columnAndValue);
// }

void LILMatrix::setValue(int row, int column, int value) {
	// std::cout << "setValue " << row << ", " << column << ", " << value << std::endl;
	auto itRow = findLowerBoundRow(row);
	
	/*
	1°) Caso donde no hay filas 
	*/
	if (itRow == matrix.end())
	{
		
		matrix.push_back(lilmatrix_row_t(row,lilmatrix_cols_t(0)));
		auto& row_elem = matrix.back();
		
		row_elem.second.push_back(lilmatrix_value_t(column, value));
		
		// std::cout << "row: " << matrix[0].first  << std::endl;
		// std::cout << "col: " << matrix[0].second[0].first  << std::endl;
		// std::cout << "value: " << matrix[0].second[0].second  << std::endl;
		m_size++;
		return;
	}
	
	/*
	2°) Caso donde hay filas pero no es la buscada (insertamos de forma ordenada)
	*/
	if (itRow->first != row) 
	{
		// std::cout << itRow-> first << std::endl;
		itRow = matrix.insert(itRow, lilmatrix_row_t(row,lilmatrix_cols_t(0)));
		auto& row_elem = itRow->second;
		
		row_elem.push_back(lilmatrix_value_t(column, value));
		
		// std::cout << "row: " << itRow->first << std::endl;
		// std::cout << "col: " << itRow->second[0].first  << std::endl;
		// std::cout << "value: " << itRow->second[0].second  << std::endl;
		m_size++;
		return;	
	}
	
	/*
	3°) Caso donde se encontro la fila, hay que hacer busqueda binaria en columnas
	*/
	auto& row_elem = itRow->second;
	auto itCol = findLowerBoundCol(row_elem, row);
	
	
	if (itCol == row_elem.end())
	{
		row_elem.push_back(lilmatrix_value_t(column, value));
		m_size++;
		return;
	}
	
	if (itCol->first != column)
	{
		row_elem.insert(itCol, lilmatrix_value_t(column, value));
		m_size++;
		return;
	}
	
	if (itCol->first == column)
	{
		if (value != 0) 
		{
			itCol->second = value;
			return;
		}
		
		row_elem.erase(itCol);
		m_size--;
		if(row_elem.size() == 0) matrix.erase(findLowerBoundRow(row));
		
	}
	
	
		
	
}


int LILMatrix::size() 
{
    return matrix.size();
}


int LILMatrix::rows() 
{
	return m_rows;
}


int LILMatrix::columns() 
{
	return m_columns;
}