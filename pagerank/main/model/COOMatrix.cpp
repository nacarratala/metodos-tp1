//
// Created by Nicolas Carratala on 27/08/2022.
//

#include "COOMatrix.h"

int COOMatrix::getValue(int row, int column) {
    for (int i = 0; i < matrix.size(); i++) {
        if (get<0>(matrix[i]) == row && get<1>(matrix[i]) == column) {
            return get<2>(matrix[i]);
        }
    }
    return 0;
}

//TODO: erase when value = 0
// TODO: ignore pushback when value already exist
void COOMatrix::setValue(int row, int column, int value) {
    auto valueToSet = make_tuple(row, column, value);
    for (int i = 0; i < matrix.size(); i++) {
        if (get<0>(matrix[i]) == row && get<1>(matrix[i]) == column) {
            matrix[i] = valueToSet;
            return;
        }
    }
    matrix.push_back(valueToSet);
}

void COOMatrix::size() {
    cout << matrix.size() << std::endl;
}