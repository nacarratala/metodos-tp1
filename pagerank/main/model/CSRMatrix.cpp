//
// Created by Nicolas Carratala on 28/08/2022.
//

#include "CSRMatrix.h"

CSRMatrix::CSRMatrix() :
        m_rows(0),
        m_columns(0),
        m_data(0),
        m_data_column(0),
        m_row_index({0}) {}


CSRMatrix::CSRMatrix(int rows, int columns) :
        m_rows(rows),
        m_columns(columns),
        m_data(0),
        m_data_column(0),
        m_row_index(rows+1, 0) {}


/*
Busqueda binaria sobre el indice con la columna del elemento
*/
vector<int>::iterator CSRMatrix::search_data_column_it(int row_first_index, int row_end_index, int column)
{

    /* Busqueda binaria en los indices de columnas en el rango asignado a la fila*/
	return std::lower_bound(
            m_data_column.begin() + row_first_index,
            m_data_column.begin() + row_end_index,
            column);
}


int CSRMatrix::row_elements_count(int row)
{
	return m_row_index[row+1] - m_row_index[row];
}


int CSRMatrix::row_first_index(int row)
{
	return m_row_index[row];
}


int CSRMatrix::row_end_index(int row)
{
	return m_row_index[row+1];
}


int CSRMatrix::getValue(int row, int column)
{
    auto elem_count = row_elements_count(row);
    if (elem_count == 0) return 0;

    auto first_index = row_first_index(row);
    auto end_index = row_end_index(row);

//    auto index_end_it = m_row_index.begin() + end_index;
    auto index_end_it = m_data_column.begin() + end_index;
    auto index_it = search_data_column_it(first_index, end_index, column);
    bool found_element = (index_it != index_end_it && (*index_it) == column);

    if (found_element)
    {
        auto data_index = std::distance(m_data_column.begin(), index_it);
        return m_data[data_index];
    }

    return 0;
}


void CSRMatrix::increase_row_indexes(int modified_element_row)
{
    /* Los indices a cada elemento son corridos un elemento */
    for (int i = modified_element_row+1; i < m_row_index.size(); ++i)
    {
        m_row_index[i]++;
    }
}


void CSRMatrix::decrease_row_indexes(int modified_element_row)
{
    for (int i = modified_element_row+1; i < m_row_index.size(); ++i)
    {
        m_row_index[i]--;
    }
}


void CSRMatrix::insert_new_element(int row, int column, int insert_index, int value)
{
    auto data_insert_it = m_data.begin() + insert_index;
    auto data_column_insert_it = m_data_column.begin() + insert_index;
    m_data.insert(data_insert_it, value);
    m_data_column.insert(data_column_insert_it, column);
    increase_row_indexes(row);
}


void CSRMatrix::delete_existing_element(int row, int element_index)
{
    auto data_it = m_data.begin() + element_index;
    auto data_column_it = m_data_column.begin() + element_index;
    m_data_column.erase(data_column_it);
    m_data.erase(data_it);
    decrease_row_indexes(row);
}

void CSRMatrix::set_existing_element(int row, int elem_index, int value)
{
    auto data_column_it = m_data_column.begin() + elem_index;
    auto data_it = m_data.begin() + elem_index;

    if (value != 0)
    {
        (*data_it) = value;
    }
    else
    {
        delete_existing_element(row, elem_index);
    }


}

void CSRMatrix::set_new_element(int row, int column, int elem_index, int elem_end_index, int value)
{
    if (value == 0) return;

    insert_new_element(row, column, elem_index, value);

//    auto data_column_it = m_data_column.begin() + elem_index;
//    auto data_column_end_it = m_data_column.begin() + elem_end_index;
//    auto elem_count = row_elements_count(row);
//
//    auto insert_index = std::distance(m_data_column.begin(), data_column_it);
////    if (data_column_it == data_column_end_it && elem_count > 0)
//        /* Si hay elementos (hubo una busqueda) y estoy parado en el iterador final entonces inserto
//         * una posicion antes*/
////        insert_index--;
//
//    auto data_column_insert_it = m_data_column.begin() + insert_index ;
//    auto data_insert_it = m_data.begin() + insert_index;
//
//    m_data_column.insert(data_column_insert_it, column);
//    m_data.insert(data_insert_it, value);
//
//    increase_row_indexes(row);

}

void CSRMatrix::setValue(int row, int column, int value)
{

    if (this->size() == 0)
    {
        m_data_column.push_back(column);
        m_data.push_back(value);
        increase_row_indexes(row);
        return;
    }

    auto first_index = row_first_index(row);
    auto end_index = row_end_index(row);

    auto data_column_end_it = m_data_column.begin() + end_index;
    auto data_column_it = search_data_column_it(first_index, end_index, column);
    bool is_end_iterator = (data_column_it == data_column_end_it);
    bool found_element = (!is_end_iterator && (*data_column_it) == column);
    int elem_index = std::distance(m_data_column.begin(), data_column_it);

    if (found_element)
    {
        set_existing_element(row, elem_index, value);
    }
    else
    {
        set_new_element(row, column, elem_index, end_index, value);
    }

}


int CSRMatrix::size()
{
	return m_data.size();
}


int CSRMatrix::rows()
{
	return m_rows;
}


int CSRMatrix::columns()
{
	return m_columns;
}


CSRMatrix CSRMatrix::row(int row)
{
    vector<int> row_index(2);

    auto first_index = row_first_index(row);
    auto end_index = row_end_index(row);
    row_index[0] = 0;
    row_index[1] =  end_index - first_index;

    auto elements_count = row_elements_count(row);
    vector<int> data(elements_count);
    vector<int> data_column(elements_count);
    for(int i = first_index; i < end_index; ++i)
    {
        data[i - first_index] = m_data[i];
        data_column[i - first_index] = m_data_column[i];
    }

    return CSRMatrix(1, m_columns, data, data_column, row_index);

}

void CSRMatrix::add_rows(CSRMatrix &csr_matrix, int row, int constant_factor = 1)
{

    if (csr_matrix.row_elements_count(row) == 0)
        return;
    if (constant_factor == 0)
        return;

    auto first_index_1 = row_first_index(row);
    auto end_index_1 = row_end_index(row);
    auto first_index_2 = csr_matrix.row_first_index(row);
    auto end_index_2 = csr_matrix.row_end_index(row);

    auto index_1 = first_index_1;
    auto index_2 = first_index_2;

    while(index_1 < end_index_1 || index_2 < end_index_2)
    {

        if ((index_1 < end_index_1) &&
            index_2 != end_index_2)
        {
            auto col_1 = m_data_column[index_1];
            auto col_2 = csr_matrix.m_data_column[index_2];

            if (col_2 < col_1 )
            {
                auto data_2 = csr_matrix.m_data[index_2];
//                auto data_insert_it = m_data.begin() + index_1;
//                auto data_column_insert_it = m_data_column.begin() + index_1;
//                m_data.insert(data_insert_it, data_2);
//                m_data_column.insert(data_column_insert_it, col_2);
//                index_1++;
//                index_2++;
//                increase_row_indexes(row);
                insert_new_element(row, col_2, index_1, constant_factor * data_2);
                index_1++;
                index_2++;
            }
            else if (col_2 == col_1)
            {
                auto data_1 = m_data[index_1];
                auto data_2 = csr_matrix.m_data[index_2];
                auto value = data_1 + (constant_factor * data_2);
                if (value != 0)
                {
                    m_data[index_1] = value;
                    index_1++;
                    index_2++;
                }
                else
                {
                    delete_existing_element(row, index_1);
                    index_2++;
                }
            }
            else
            {
                index_1++;
            }

        }
        else if ( (index_1 == end_index_1) &&
                (index_2 != end_index_2) )
        {
            auto col_2 = csr_matrix.m_data_column[index_2];
            auto data_2 = csr_matrix.m_data[index_2];
//            auto data_insert_it = m_data.begin() + index_1;
//            auto data_column_insert_it = m_data_column.begin() + index_1;
//            m_data.insert(data_insert_it, data_2);
//            m_data_column.insert(data_column_insert_it, col_2);
//            index_1++;
//            index_2++;
//            increase_row_indexes(row);
            insert_new_element(row, col_2, index_1, (constant_factor * data_2));
            index_1++;
            index_2++;

        }
        else if (index_2 == end_index_2)
        {
            index_1 = end_index_1;
        }

        first_index_1 = row_first_index(row);
        end_index_1 = row_end_index(row);
        first_index_2 = csr_matrix.row_first_index(row);
        end_index_2 = csr_matrix.row_end_index(row);


    }
}

void CSRMatrix::sub(CSRMatrix &csr_matrix)
{
    for (int row = 0; row < rows(); ++row)
    {
        add_rows(csr_matrix, row, -1);
    }
}

//TODO: Una version const de los metodos
//TODO: Optimizar la suma
void CSRMatrix::add(CSRMatrix &csr_matrix)
{
    for (int row = 0; row < rows(); ++row) {

        add_rows(csr_matrix, row);
    }
}


CSRMatrix::CSRMatrix(int rows, int columns, const vector<int> &data, const vector<int> &data_column,
                     const vector<int> &row_index)
:
m_rows(rows),
m_columns(columns),
m_data(data),
m_data_column(data_column),
m_row_index(row_index){ }
