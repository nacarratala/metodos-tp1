#include <iostream>
#include "model/DOKMatrix.h"
#include "model/LILMatrix.h"
#include "model/COOMatrix.h"

using namespace std;

int main() {
    cout << "DOKMatrix " << endl;
    DOKMatrix dokMatrix = *new DOKMatrix();
    dokMatrix.size();
    dokMatrix.setValue(0, 0, 4);
    dokMatrix.size();
    cout << dokMatrix.getValue(0, 0) << endl;
    cout << dokMatrix.getValue(0, 1) << endl;
    cout << "LILMatrix " << endl;
    LILMatrix lilMatrix = *new LILMatrix();
    lilMatrix.size();
    lilMatrix.setValue(0, 0, 4);
    lilMatrix.size();
    cout << lilMatrix.getValue(0, 0) << endl;
    cout << lilMatrix.getValue(0, 1) << endl;
    cout << "COOMatrix " << endl;
    COOMatrix cooMatrix = *new COOMatrix();
    cooMatrix.size();
    cooMatrix.setValue(0, 0, 4);
    cooMatrix.size();
    cout << cooMatrix.getValue(0, 0) << endl;
    cout << cooMatrix.getValue(0, 1) << endl;
    return 0;
}
