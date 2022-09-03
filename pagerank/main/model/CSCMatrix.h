//
// Created by Nicolas Carratala on 28/08/2022.
//
#include <iostream>
#include <vector>

using namespace std;

#ifndef PAGERANK_CSCMATRIX_H
#define PAGERANK_CSCMATRIX_H

class CSCMatrix {

private:
    vector<int> a;
    vector<int> ja;
    vector<int> ia;

    void addColumn(int column);

    int getNonNullElementsUntilColumn(int column);

    int getNonNullElementsInColumn(int column);

    void updateRowIndex(int x, int pos);

    void updateElements(int x, int pos);

public:
    int getValue(int row, int column);

    void setValue(int row, int column, int value);

    void size();

};


#endif //PAGERANK_CSCMATRIX_H
