#include <iostream>
#include <fstream>
#include <cmath>
#include "model/DOKMatrix.h"
#include "model/LILMatrix.h"
#include "model/COOMatrix.h"
#include "model/CSRMatrix.h"
#include "model/CSCMatrix.h"
#include "model/Gauss.h"

using namespace std;

void normalizeVector(vector<double>* vector){
    double elementsRaisedSumatory = 0;
    for (double i : *vector){
        elementsRaisedSumatory += i * i;
    }
    double module = sqrt(elementsRaisedSumatory);
    for (double & i : *vector){
        i = i / module;
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Cantidad de parametros incorrecta.\n");
        return 1;
    }
    char *inputFile = argv[1];
    double p = atof(argv[2]);
    ifstream fileInput;
    fileInput.open(inputFile);
    int pages;
    int links;
    fileInput >> pages >> links;
    LILMatrix W(links, fileInput);
    vector<double> D(pages);
    for (int i = 0; i < pages; i++) {
        double pageGrade = W.getPageGrade(i);
        D[i] = pageGrade == 0 ? 0 : pageGrade;
    }
    vector<double> z(pages);
    for (int i = 0; i < pages; i++) {
        double pageGrade = W.getPageGrade(i);
        z[i] = pageGrade == 0 ? 1.0 / pages : (1 - p) / pages;
    }
    vector<double> e(pages, 1);
    W.multiplicationByScalar(p);
    W.multiplicationByDiagonalMatrix(D);
    W.identitySubstractSelf();
    auto res = Gauss::gaussianElimination(W, e);
    normalizeVector(&res);
    ofstream Output;
    Output.open(string(inputFile) + ".out");
    //Output.open("/Users/nacarratala/Desktop/test.txt");
    Output << "Result" << "\n";
    for (double re : res){
        Output << re << "\n";
    }
//    Output << W.size() << "\n";
//    Output << W.columns() << "\n";
//    Output << W.rows() << "\n";
//    Output << "\n" << "\n";
//    Output.close();
//
//    std::cout << "W" << std::endl;
//    std::cout << W.size() << std::endl;
//    std::cout << W.columns() << std::endl;
//    std::cout << W.rows() << std::endl;
//    std::cout << std::endl;
    return 0;

}
