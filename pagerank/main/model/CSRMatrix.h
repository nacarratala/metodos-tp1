//
// Created by Nicolas Carratala on 28/08/2022.
//

#include <iostream>
#include <vector>

using namespace std;
#ifndef PAGERANK_CSRMATRIX_H
#define PAGERANK_CSRMATRIX_H


class CSRMatrix {

private:

	CSRMatrix(int m_rows, int m_columns, const vector<int> &m_data, const vector<int> &data_column,
			  const vector<int> &row_index);


    void insert_new_element(int row, int column, int insert_index, int value);

    void delete_existing_element(int row, int element_index);

	void set_existing_element(int row, int elem_index, int value);

	void set_new_element(int row, int column, int elem_index, int elem_end_index, int value);

    void increase_row_indexes(int modified_element_row);

    void decrease_row_indexes(int modified_element_row);
	
	vector<int>::iterator search_data_column_it(int row_first_index, int row_end_index, int column);

	int row_elements_count(int row);

	int row_first_index(int row);

	int row_end_index(int row);

	
	int m_rows;
	int m_columns;
		
	// vector<int> a;
    // vector<int> ja;
    // vector<int> ia;
	vector<int> m_data;
	vector<int> m_data_column;
	vector<int> m_row_index;
public:

	CSRMatrix();

	CSRMatrix(int rows, int columns);

    int getValue(int row, int column);

	void setValue(int row, int column, int value);

	int size();
	
	int rows();

	int columns();

	CSRMatrix row(int row);

	void add(CSRMatrix& csr_matrix);

//    void add_rows(CSRMatrix &csr_matrix, int row, int constant_dactor);


    void add_rows(CSRMatrix &csr_matrix, int row, int constant_factor);

    void sub(CSRMatrix &csr_matrix);
};


#endif
