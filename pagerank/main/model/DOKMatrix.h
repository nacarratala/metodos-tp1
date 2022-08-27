//
// Created by Nicolas Carratala on 27/08/2022.
//
#include <map>
#include <tuple>

using namespace std;

#ifndef PAGERANK_DOKMATRIX_H
#define PAGERANK_DOKMATRIX_H

class DOKMatrix {

private:
    map<pair<int, int>, int> matrix;

public:
    int getValue(int row, int column);
    void setValue(int row, int column, int value);
    void size();

};

#endif