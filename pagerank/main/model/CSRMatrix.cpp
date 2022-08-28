//
// Created by Nicolas Carratala on 28/08/2022.
//

#include "CSRMatrix.h"

int CSRMatrix::getValue(int row, int column){
    auto nonNullElementsUntilRow = getNonNullElementsUntilRow(row);
    auto nonNullElementsInRow = getNonNullElementsInRow(row);
    for(int i = nonNullElementsUntilRow; i <= nonNullElementsUntilRow + nonNullElementsInRow; i++){
        if (ja[i] == column){
            return a[i];
        }
    }
    return 0;
}

int CSRMatrix::getNonNullElementsUntilRow(int row){
    auto res = 0;
    for (int i = 0; i < row; i++){
        res += getNonNullElementsInRow(i);
    }
    return res;
}

int CSRMatrix::getNonNullElementsInRow(int row){
    if (row >= ia.size()){
        return 0;
    }
    return ia[row+1] - ia[row];
}

void CSRMatrix::addRow(int row){
    auto lastNonNullElement = ia.empty()
            ? 0
            : ia[ia.size()-1];
    auto actualRows = ia.size();
    for (int i = 0; i < row - actualRows+2; i++){
        ia.push_back(lastNonNullElement);
    }
}
//TODO: erase when value = 0
// TODO: ignore pushback when value already exist
void CSRMatrix::setValue(int row, int column, int value) {
    if (row+1 >= ia.size()) {
        addRow(row);
    }
    auto nonNullElementsInRow = getNonNullElementsInRow(row);
    auto nonNullElementsUntilRow = getNonNullElementsUntilRow(row);
    auto wasAdded = false;
    for( int i = nonNullElementsUntilRow; i < nonNullElementsInRow; i++){
        if (ja[i] > column){
            updateColumnIndex(column, i);
            updateElements(value, i);
            wasAdded = true;
            break;
        }
    }
    if (!wasAdded){
        auto position = nonNullElementsUntilRow + nonNullElementsInRow;
        updateColumnIndex(column, position);
        updateElements(value, position);
    }
    for (int i = row+1; i < ia.size(); i++) {
        ia[i] += 1;
    }
}

void CSRMatrix::updateColumnIndex(int x, int pos){
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

void CSRMatrix::updateElements(int x, int pos){
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

void CSRMatrix::size() {
    cout << a.size() << std::endl;
}
