//
// Created by Nicolas Carratala on 27/08/2022.
//

#include <iostream>
#include <assert.h>
#include "DOKMatrix.h"


/* Constructor base */
DOKMatrix::DOKMatrix() : m_rows(0), m_columns(0) {}


DOKMatrix::DOKMatrix(dimension_t rows, dimension_t columns) : m_rows(rows), m_columns(columns) {}


value_t DOKMatrix::getValue(dimension_t row, dimension_t column)
{
    auto isPresent = matrix.count(make_pair(row, column)) > 0;
    if (!isPresent) return 0;
	
    return matrix.at(pair<dimension_t, dimension_t>(row, column));
}



void DOKMatrix::setZero(dimension_t row, dimension_t column) 
{
	assert(row < m_rows && "Row out of bounds");
	assert(column < m_columns && "Column out of bounds");
	
	auto elementIt = matrix.find(make_pair(row, column));
    if (elementIt == matrix.end()) return;
	matrix.erase(elementIt);
}


void DOKMatrix::setValue(dimension_t row, dimension_t column, dimension_t value) 
{
	assert(row < m_rows && "Row out of bounds");
	assert(column < m_columns && "Column out of bounds");
	
	if (value == 0) 
	{
		setZero(row, column);
		return;
	}
	
	auto key = make_pair(row, column);
	matrix.insert(make_pair(key, value));
}


dimension_t DOKMatrix::rows() 
{
	return m_rows;
}

dimension_t DOKMatrix::columns() 
{
	return m_columns;
}

dimension_t DOKMatrix::size()
{
	return matrix.size();
}


