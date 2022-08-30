//
// Created by Nicolas Carratala on 27/08/2022.
//
#include <iostream>
#include <vector>
using namespace std;

#ifndef PAGERANK_LILMATRIX_H
#define PAGERANK_LILMATRIX_H

using lilmatrix_value_t = std::pair<int, int>;
	using lilmatrix_cols_t = std::vector<lilmatrix_value_t>;
	using lilmatrix_row_t = std::pair<int, lilmatrix_cols_t>;
	using lilmatrix_rows_t = std::vector<lilmatrix_row_t>;

class LILMatrix {
	
	// using lilmatrix_value_t = std::pair<int, int>;
	// using lilmatrix_cols_t = std::vector<int, lilmatrix_value_t>;
	// using lilmatrix_row_t = std::pair<int, lilmatrix_col_t>;
	
	

private:
  
    static int findValue(vector<pair<int,int>>, int column);
	
	
	//static lilmatrix_cols_t findLowerBoundCol(lilmatrix_cols_t& cols, int col);
	
	int m_rows;
	int m_columns;
	lilmatrix_rows_t matrix;
	int m_size;

public:
	
	lilmatrix_rows_t::iterator findLowerBoundRow(int row);
	lilmatrix_cols_t::iterator findLowerBoundCol(lilmatrix_cols_t& cols, int column);
	
	LILMatrix();
	LILMatrix(int rows, int columns);
	
	//LilMatrix(int rows, int columns);
    int getValue(int row, int column);
    void setValue(int row, int column, int value);
    int size();
	
	int rows ();
	int columns();

};

#endif
