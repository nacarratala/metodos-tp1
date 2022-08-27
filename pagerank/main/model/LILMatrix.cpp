//
// Created by Nicolas Carratala on 27/08/2022.
//

#include "LILMatrix.h"
using namespace std;


int LILMatrix::getValue(int row, int column){
    if (matrix.size() >= row+1){
        return findValue(matrix[row], column);
    }
    return 0;
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
void LILMatrix::setValue(int row, int column, int value) {
    if (matrix.size() > row){
        matrix[row].push_back(make_pair(column, value));
        return;
    }
    vector<pair<int,int>> emptyRow;
    for (int i = 0; i < row - matrix.size() + 1; i++){
        matrix.push_back(emptyRow);
    }
    auto columnAndValue = make_pair(column, value);
    matrix[row].push_back(columnAndValue);
}

void LILMatrix::size(){
    cout << matrix.size() << std::endl;

}