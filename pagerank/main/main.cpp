#include <iostream>
#include "model/DOKMatrix.h"
#include "model/LILMatrix.h"
#include "model/COOMatrix.h"
#include "model/CSRMatrix.h"
#include "model/CSCMatrix.h"

using namespace std;

int main() {
    cout << "DOKMatrix " << endl;
    auto dokMatrix = *new DOKMatrix();
    dokMatrix.size();
    dokMatrix.setValue(0, 0, 4);
    dokMatrix.size();
    cout << dokMatrix.getValue(0, 0) << endl;
    cout << dokMatrix.getValue(0, 1) << endl;
    cout << "LILMatrix " << endl;
    auto lilMatrix = *new LILMatrix();
    lilMatrix.size();
    lilMatrix.setValue(0, 0, 4);
    lilMatrix.size();
    cout << lilMatrix.getValue(0, 0) << endl;
    cout << lilMatrix.getValue(0, 1) << endl;
    cout << "COOMatrix " << endl;
    auto cooMatrix = *new COOMatrix();
    cooMatrix.size();
    cooMatrix.setValue(0, 0, 4);
    cooMatrix.size();
    cout << cooMatrix.getValue(0, 0) << endl;
    cout << cooMatrix.getValue(0, 1) << endl;
    cout << "CSRMatrix " << endl;
    auto csrMatrix = *new CSRMatrix();
    csrMatrix.size();
    csrMatrix.setValue(0, 0, 7);
    csrMatrix.setValue(0, 1, 8);
    csrMatrix.setValue(1, 0, 1);
    cout << csrMatrix.getValue(0, 0) << endl;
    cout << csrMatrix.getValue(0, 1) << endl;
    cout << csrMatrix.getValue(1, 0) << endl;
    cout << csrMatrix.getValue(5, 5) << endl;
    csrMatrix.size();
    cout << "CSCMatrix " << endl;
    auto cscMatrix = *new CSCMatrix();
    cscMatrix.size();
    cscMatrix.setValue(0, 0, 7);
    cscMatrix.setValue(3, 0, 8);
    cscMatrix.setValue(0, 1, 9);
    cscMatrix.setValue(3, 0, 18);
    cout << cscMatrix.getValue(0, 0) << endl;
    cout << cscMatrix.getValue(3, 0) << endl;
    cout << cscMatrix.getValue(0, 1) << endl;
    cout << cscMatrix.getValue(5, 5) << endl;
    cscMatrix.size();
    return 0;
}
