//
// Created by Nicolas Carratala on 28/08/2022.
//

#include "CSCMatrix.h"

int CSCMatrix::getValue(int row, int column){
    auto nonNullElementsUntilColumn = getNonNullElementsUntilColumn(column);
    auto nonNullElementsInColumn = getNonNullElementsInColumn(column);
    for(int i = nonNullElementsUntilColumn; i <= nonNullElementsUntilColumn + nonNullElementsInColumn; i++){
        if (ja[i] == row){
            return a[i];
        }
    }
    return 0;
}

int CSCMatrix::getNonNullElementsUntilColumn(int column){
    auto res = 0;
    for (int i = 0; i < column; i++){
        res += getNonNullElementsInColumn(i);
    }
    return res;
}

int CSCMatrix::getNonNullElementsInColumn(int column){
    if (column >= ia.size()){
        return 0;
    }
    return ia[column + 1] - ia[column];
}

void CSCMatrix::addColumn(int column){
    auto lastNonNullElement = ia.empty()
                              ? 0
                              : ia[ia.size()-1];
    auto actualColumns = ia.size();
    for (int i = 0; i < column - actualColumns+2; i++){
        ia.push_back(lastNonNullElement);
    }
}

//TODO: erase when value = 0
// TODO: ignore pushback when value already exist
void CSCMatrix::setValue(int row, int column, int value) {
    if (column + 1 >= ia.size()) {
        addColumn(column);
    }
    auto nonNullElementsInColumn = getNonNullElementsInColumn(column);
    auto nonNullElementsUntilColumn = getNonNullElementsUntilColumn(column);
    auto wasAdded = false;
    for(int i = nonNullElementsUntilColumn; i < nonNullElementsInColumn; i++){
        if (ja[i] > row){
            updateRowIndex(row, i);
            updateElements(value, i);
            wasAdded = true;
            break;
        }
    }
    if (!wasAdded){
        auto position = nonNullElementsUntilColumn + nonNullElementsInColumn;
        updateRowIndex(row, position);
        updateElements(value, position);
    }
    for (int i = column+1; i < ia.size(); i++) {
        ia[i] += 1;
    }
}

void CSCMatrix::updateRowIndex(int x, int pos){
    if (ja.empty()){
        ja.push_back(x);
        return;
    }
    ja.push_back(0);
    int vectorSize = (int) ja.size();
    for (int i = vectorSize; i >= pos; i--)
        ja[i] =ja[i - 1];
    ja[pos] = x;
}

void CSCMatrix::updateElements(int x, int pos){
    if (a.empty()){
        a.push_back(x);
        return;
    }
    a.push_back(0);
    int vectorSize = (int) a.size();
    for (int i = vectorSize; i >= pos; i--)
        a[i] =a[i - 1];
    a[pos] = x;
}

void CSCMatrix::size() {
    cout << a.size() << std::endl;
}

