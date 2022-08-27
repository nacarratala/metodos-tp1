//
// Created by Nicolas Carratala on 27/08/2022.
//
#include <tuple>
#include <iostream>
#include <vector>
using namespace std;

#ifndef PAGERANK_COOMATRIX_H
#define PAGERANK_COOMATRIX_H

class COOMatrix {
private:
    vector<tuple<int, int, int>> matrix;

public:
    int getValue(int row, int column);
    void setValue(int row, int column, int value);
    void size();
};

#endif
