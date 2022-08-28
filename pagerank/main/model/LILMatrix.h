//
// Created by Nicolas Carratala on 27/08/2022.
//
#include <iostream>
#include <vector>
using namespace std;

#ifndef PAGERANK_LILMATRIX_H
#define PAGERANK_LILMATRIX_H


class LILMatrix {

private:
    vector<vector<pair<int, int>>> matrix;
    static int findValue(vector<pair<int,int>>, int column);

public:
    int getValue(int row, int column);
    void setValue(int row, int column, int value);
    void size();

};

#endif
