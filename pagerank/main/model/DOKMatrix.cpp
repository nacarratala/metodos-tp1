//
// Created by Nicolas Carratala on 27/08/2022.
//

#include <iostream>
#include "DOKMatrix.h"

int DOKMatrix::getValue(int row, int column){
    auto isPresent = matrix.count(make_pair(row, column)) > 0;
    if (!isPresent){
        return 0;
    }
    return matrix.at(pair<int, int>(row, column));
}

//TODO: erase when value = 0
// TODO: ignore pushback when value already exist
void DOKMatrix::setValue(int row, int column, int value) {
        auto key = make_pair(row, column);
        matrix.insert(make_pair(key, value));
    }

void DOKMatrix::size(){
        cout << matrix.size() << std::endl;
}


