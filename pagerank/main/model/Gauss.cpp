//
// Created by Nicolas Carratala on 04/09/2022.
//
#include "model/LILMatrix.h"
#include "Gauss.h"


using namespace std;

// TODO: chequear warning
// TODO: chequer int i = 0 (difere con pseudocodigo
void triangulation(LILMatrix& A, vector<double>& b){
    int n = A.rows();
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            auto a_ji = A.getValue(j,i);
            auto a_ii = A.getValue(i,i);
            double m = a_ji / a_ii ;
            for (int k = i; k < n; k++) {
                auto a_jk = A.getValue(j,k);
                auto a_ik = A.getValue(i,k);
                A.setValue(j, k, a_jk - m * a_ik);
            }
            b[j] = b[j] - m * b[i];
        }
    }
}

vector<double> Gauss::gaussianElimination(LILMatrix& A, vector<double>& b){
    int n = A.rows(); // Matriz cuadrada rows == columns.
    triangulation(A,b);
    vector<double> result;
    for(int i = 0; i < n; i++){
        result.push_back(-1);
    }
    for(int i = n-1; i >= 0; i--){
        double res = b[i];
        for(int j = i+1; j < n; j++){
            res = res - A.getValue(i,j)*result[j];
        }
        result[i] = res/A.getValue(i,i);
    }
    return result;
}
