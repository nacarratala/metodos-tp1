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
    vector<int> a;
    vector<int> ja;
    vector<int> ia;
    void addRow(int row);
    int getNonNullElementsUntilRow(int row);
    int getNonNullElementsInRow(int row);
    void updateColumnIndex(int x, int pos);
    void updateElements(int x, int pos);

public:
    int getValue(int row, int column);
    void setValue(int row, int column, int value);
    void size();

};


#endif
