#include <gtest/gtest.h>
#include "model/CSRMatrix.h"
/**
 * Test simple básico
 */
 
 
TEST(metnum_tp1_CSRMatrix, new_CSRMatrix_is_empty) 
{
	CSRMatrix csr_matrix;
	EXPECT_EQ(csr_matrix.size(), 0);
}


TEST(metnum_tp1_CSRMatrix, new_CSRMatrix_dimension_zero) 
{
	CSRMatrix csr_matrix;
	EXPECT_EQ(csr_matrix.rows(), 0);
	EXPECT_EQ(csr_matrix.columns(), 0);
} 


TEST(metnum_tp1_CSRMatrix, new_CSRMatrix_dimension_not_zero) 
{
	CSRMatrix csr_matrix(7,5);
	EXPECT_EQ(csr_matrix.size(), 0);
	EXPECT_EQ(csr_matrix.rows(), 7);
	EXPECT_EQ(csr_matrix.columns(), 5);
} 


TEST(metnum_tp1_CSRMatrix, CSRMatrix_correctly_set_one_value)
{
	CSRMatrix csr_matrix(4,5);
	EXPECT_EQ(csr_matrix.rows(), 4);
	EXPECT_EQ(csr_matrix.columns(), 5);
	EXPECT_EQ(csr_matrix.size(), 0);

	csr_matrix.setValue(2,3,55);
	EXPECT_EQ(csr_matrix.rows(), 4);
	EXPECT_EQ(csr_matrix.columns(), 5);
	EXPECT_EQ(csr_matrix.getValue(2,3), 55);
	EXPECT_EQ(csr_matrix.size(), 1);
}



 TEST(metnum_tp1_CSRMatrix, CSRMatrix_correctly_set_multiple_values)
 {
     CSRMatrix csrMatrix(4, 4);
	 csrMatrix.setValue(2, 3, 55);
	 EXPECT_EQ(csrMatrix.rows(), 4);
	 EXPECT_EQ(csrMatrix.columns(), 4);
	 EXPECT_EQ(csrMatrix.getValue(2, 3), 55);
	 EXPECT_EQ(csrMatrix.size(), 1);
	
	 csrMatrix.setValue(0, 0, 15);
	 EXPECT_EQ(csrMatrix.rows(), 4);
	 EXPECT_EQ(csrMatrix.columns(), 4);
	 EXPECT_EQ(csrMatrix.getValue(2, 3), 55);
	 EXPECT_EQ(csrMatrix.getValue(0, 0), 15);
	 EXPECT_EQ(csrMatrix.size(), 2);
	
	 csrMatrix.setValue(3, 2, 100);
	 EXPECT_EQ(csrMatrix.rows(), 4);
	 EXPECT_EQ(csrMatrix.columns(), 4);
	 EXPECT_EQ(csrMatrix.getValue(2, 3), 55);
	 EXPECT_EQ(csrMatrix.getValue(0, 0), 15);
	 EXPECT_EQ(csrMatrix.getValue(3, 2), 100);
	 EXPECT_EQ(csrMatrix.size(), 3);

     csrMatrix.setValue(1, 1, 77);
	 EXPECT_EQ(csrMatrix.rows(), 4);
	 EXPECT_EQ(csrMatrix.columns(), 4);
	 EXPECT_EQ(csrMatrix.getValue(2, 3), 55);
	 EXPECT_EQ(csrMatrix.getValue(0, 0), 15);
	 EXPECT_EQ(csrMatrix.getValue(3, 2), 100);
     EXPECT_EQ(csrMatrix.getValue(1, 1), 77);
	 EXPECT_EQ(csrMatrix.size(), 4);
 }


 TEST(metnum_tp1_CSRMatrix, CSRMatrix_correctly_modify_value)
 {
     CSRMatrix csrMatrix(4, 4);
	 csrMatrix.setValue(2, 3, 55);
	 EXPECT_EQ(csrMatrix.rows(), 4);
	 EXPECT_EQ(csrMatrix.columns(), 4);
	 EXPECT_EQ(csrMatrix.getValue(2, 3), 55);
	 EXPECT_EQ(csrMatrix.size(), 1);
	
	 csrMatrix.setValue(0, 0, 15);
	 EXPECT_EQ(csrMatrix.rows(), 4);
	 EXPECT_EQ(csrMatrix.columns(), 4);
	 EXPECT_EQ(csrMatrix.getValue(2, 3), 55);
	 EXPECT_EQ(csrMatrix.getValue(0, 0), 15);
	 EXPECT_EQ(csrMatrix.size(), 2);
	
	 csrMatrix.setValue(0, 0, 100);
	 EXPECT_EQ(csrMatrix.rows(), 4);
	 EXPECT_EQ(csrMatrix.columns(), 4);
	 EXPECT_EQ(csrMatrix.getValue(2, 3), 55);
	 EXPECT_EQ(csrMatrix.getValue(0, 0), 100);
	 EXPECT_EQ(csrMatrix.size(), 2);
 }


 TEST(metnum_tp1_CSRMatrix, CSRMatrix_correctly_set_value_to_zero)
 {
     CSRMatrix csrMatrix(4, 4);
	 csrMatrix.setValue(2, 3, 55);
	 EXPECT_EQ(csrMatrix.rows(), 4);
	 EXPECT_EQ(csrMatrix.columns(), 4);
	 EXPECT_EQ(csrMatrix.getValue(2, 3), 55);
	 EXPECT_EQ(csrMatrix.size(), 1);
	
	 csrMatrix.setValue(0, 0, 15);
	 EXPECT_EQ(csrMatrix.rows(), 4);
	 EXPECT_EQ(csrMatrix.columns(), 4);
	 EXPECT_EQ(csrMatrix.getValue(2, 3), 55);
	 EXPECT_EQ(csrMatrix.getValue(0, 0), 15);
	 EXPECT_EQ(csrMatrix.size(), 2);
	
	 csrMatrix.setValue(3, 2, 100);
	 EXPECT_EQ(csrMatrix.rows(), 4);
	 EXPECT_EQ(csrMatrix.columns(), 4);
	 EXPECT_EQ(csrMatrix.getValue(2, 3), 55);
	 EXPECT_EQ(csrMatrix.getValue(0, 0), 15);
	 EXPECT_EQ(csrMatrix.getValue(3, 2), 100);
	 EXPECT_EQ(csrMatrix.size(), 3);
	
	 csrMatrix.setValue(2, 2, 0);
	 EXPECT_EQ(csrMatrix.rows(), 4);
	 EXPECT_EQ(csrMatrix.columns(), 4);
	 EXPECT_EQ(csrMatrix.getValue(2, 3), 55);
	 EXPECT_EQ(csrMatrix.getValue(0, 0), 15);
	 EXPECT_EQ(csrMatrix.getValue(3, 2), 100);
	 EXPECT_EQ(csrMatrix.getValue(2, 2), 0);
	 EXPECT_EQ(csrMatrix.size(), 3);
	
	 csrMatrix.setValue(0, 0, 0);
	 EXPECT_EQ(csrMatrix.rows(), 4);
	 EXPECT_EQ(csrMatrix.columns(), 4);
	 EXPECT_EQ(csrMatrix.getValue(2, 3), 55);
	 EXPECT_EQ(csrMatrix.getValue(0, 0), 0);
	 EXPECT_EQ(csrMatrix.getValue(3, 2), 100);
     EXPECT_EQ(csrMatrix.getValue(2, 2), 0);
	 EXPECT_EQ(csrMatrix.size(), 2);
	
	 csrMatrix.setValue(2, 3, 0);
	 EXPECT_EQ(csrMatrix.rows(), 4);
	 EXPECT_EQ(csrMatrix.columns(), 4);
	 EXPECT_EQ(csrMatrix.getValue(2, 3), 0);
	 EXPECT_EQ(csrMatrix.getValue(0, 0), 0);
	 EXPECT_EQ(csrMatrix.getValue(3, 2), 100);
     EXPECT_EQ(csrMatrix.getValue(2, 2), 0);
	 EXPECT_EQ(csrMatrix.size(), 1);

     csrMatrix.setValue(3, 2, 0);
     EXPECT_EQ(csrMatrix.rows(), 4);
     EXPECT_EQ(csrMatrix.columns(), 4);
     EXPECT_EQ(csrMatrix.getValue(2, 3), 0);
     EXPECT_EQ(csrMatrix.getValue(0, 0), 0);
     EXPECT_EQ(csrMatrix.getValue(3, 2), 0);
     EXPECT_EQ(csrMatrix.getValue(2, 2), 0);
     EXPECT_EQ(csrMatrix.size(), 0);

     csrMatrix.setValue(2, 3, 5);
     EXPECT_EQ(csrMatrix.rows(), 4);
     EXPECT_EQ(csrMatrix.columns(), 4);
     EXPECT_EQ(csrMatrix.getValue(2, 3), 5);
     EXPECT_EQ(csrMatrix.getValue(0, 0), 0);
     EXPECT_EQ(csrMatrix.getValue(3, 2), 0);
     EXPECT_EQ(csrMatrix.getValue(2, 2), 0);
     EXPECT_EQ(csrMatrix.size(), 1);
	
 }



TEST(metnum_tp1_CSRMatrix, CSRMatrix_get_row_matrix)
{

    CSRMatrix csrMatrix(4, 4);
    csrMatrix.setValue(2, 3, 55);
    csrMatrix.setValue(0, 0, 15);
    csrMatrix.setValue(3, 2, 100);
    csrMatrix.setValue(2, 0, 5);



    auto row = csrMatrix.row(2);
    EXPECT_EQ(row.rows(), 1);
    EXPECT_EQ(row.columns(), 4);

    EXPECT_EQ(row.getValue(0, 0), 5);
    EXPECT_EQ(row.getValue(0, 0), 5);
    EXPECT_EQ(row.getValue(0, 0), 5);
    EXPECT_EQ(row.getValue(0, 0), 5);

    EXPECT_EQ(row.getValue(0, 0), 5);
    EXPECT_EQ(row.getValue(0, 1), 0);
    EXPECT_EQ(row.getValue(0, 2), 0);
    EXPECT_EQ(row.getValue(0, 3), 55);

}


TEST(metnum_tp1_CSRMatrix, CSRMatrix_add_matrix)
{

    CSRMatrix csrMatrix(4, 4);
    csrMatrix.setValue(2, 3, 55);
    csrMatrix.setValue(0, 0, 15);
    csrMatrix.setValue(3, 2, 100);
    csrMatrix.setValue(2, 0, 5);
    csrMatrix.setValue(3, 3, 7);

    CSRMatrix anotherCsrMatrix(4, 4);
    anotherCsrMatrix.setValue(0, 0, 100);
    anotherCsrMatrix.setValue(3, 2, 250);
    anotherCsrMatrix.setValue(1, 0, 77);

    csrMatrix.add(anotherCsrMatrix);

    EXPECT_EQ(csrMatrix.rows(), 4);
    EXPECT_EQ(csrMatrix.columns(), 4);
    EXPECT_EQ(csrMatrix.getValue(0, 0), 115);
    EXPECT_EQ(csrMatrix.getValue(0, 1), 0);
    EXPECT_EQ(csrMatrix.getValue(0, 2), 0);
    EXPECT_EQ(csrMatrix.getValue(0, 3), 0);

    EXPECT_EQ(csrMatrix.getValue(1, 0), 77);
    EXPECT_EQ(csrMatrix.getValue(1, 1), 0);
    EXPECT_EQ(csrMatrix.getValue(1, 2), 0);
    EXPECT_EQ(csrMatrix.getValue(1, 3), 0);

    EXPECT_EQ(csrMatrix.getValue(2, 0), 5);
    EXPECT_EQ(csrMatrix.getValue(2, 1), 0);
    EXPECT_EQ(csrMatrix.getValue(2, 2), 0);
    EXPECT_EQ(csrMatrix.getValue(2, 3), 55);

    EXPECT_EQ(csrMatrix.getValue(3, 0), 0);
    EXPECT_EQ(csrMatrix.getValue(3, 1), 0);
    EXPECT_EQ(csrMatrix.getValue(3, 2), 350);
    EXPECT_EQ(csrMatrix.getValue(3, 3), 7);

}



TEST(metnum_tp1_CSRMatrix, CSRMatrix_add_matrix_2)  
{

    CSRMatrix csrMatrix(3, 3);
    csrMatrix.setValue(0, 0, 10);
    csrMatrix.setValue(1, 0, 5);
    csrMatrix.setValue(1, 1, 20);

    CSRMatrix anotherCsrMatrix(3, 3);
    anotherCsrMatrix.setValue(0, 0, 15);
    anotherCsrMatrix.setValue(1, 1, 50);
    anotherCsrMatrix.setValue(2, 2, 100);

    csrMatrix.add(anotherCsrMatrix);

    EXPECT_EQ(csrMatrix.rows(), 3);
    EXPECT_EQ(csrMatrix.columns(), 3);
    EXPECT_EQ(csrMatrix.getValue(0, 0), 25);
    EXPECT_EQ(csrMatrix.getValue(0, 1), 0);
    EXPECT_EQ(csrMatrix.getValue(0, 2), 0);

    EXPECT_EQ(csrMatrix.getValue(1, 0), 5);
    EXPECT_EQ(csrMatrix.getValue(1, 1), 70);
    EXPECT_EQ(csrMatrix.getValue(1, 2), 0);

    EXPECT_EQ(csrMatrix.getValue(2, 0), 0);
    EXPECT_EQ(csrMatrix.getValue(2, 1), 0);
    EXPECT_EQ(csrMatrix.getValue(2, 2), 100);

}


TEST(metnum_tp1_CSRMatrix, CSRMatrix_add_matrix_remove_zeros)
{

    CSRMatrix csrMatrix(3, 3);
    csrMatrix.setValue(0, 0, 10);
    csrMatrix.setValue(1, 0, 5);
    csrMatrix.setValue(1, 1, 20);

    CSRMatrix anotherCsrMatrix(3, 3);
    anotherCsrMatrix.setValue(0, 0, -10);
    anotherCsrMatrix.setValue(1, 1, 50);
    anotherCsrMatrix.setValue(1, 0, -5);
    anotherCsrMatrix.setValue(2, 2, 100);

    EXPECT_EQ(csrMatrix.size(), 3);
    EXPECT_EQ(anotherCsrMatrix.size(), 4);

    csrMatrix.add(anotherCsrMatrix);

    EXPECT_EQ(csrMatrix.rows(), 3);
    EXPECT_EQ(csrMatrix.columns(), 3);
    EXPECT_EQ(csrMatrix.size(), 2);
    EXPECT_EQ(csrMatrix.getValue(0, 0), 0);
    EXPECT_EQ(csrMatrix.getValue(0, 1), 0);
    EXPECT_EQ(csrMatrix.getValue(0, 2), 0);

    EXPECT_EQ(csrMatrix.getValue(1, 0), 0);
    EXPECT_EQ(csrMatrix.getValue(1, 1), 70);
    EXPECT_EQ(csrMatrix.getValue(1, 2), 0);

    EXPECT_EQ(csrMatrix.getValue(2, 0), 0);
    EXPECT_EQ(csrMatrix.getValue(2, 1), 0);
    EXPECT_EQ(csrMatrix.getValue(2, 2), 100);

}


TEST(metnum_tp1_CSRMatrix, CSRMatrix_sub)
{

    CSRMatrix csrMatrix(3, 3);
    csrMatrix.setValue(0, 0, 10);
    csrMatrix.setValue(1, 0, 5);
    csrMatrix.setValue(1, 1, 20);

    CSRMatrix anotherCsrMatrix(3, 3);
    anotherCsrMatrix.setValue(0, 0, 10);
    anotherCsrMatrix.setValue(1, 1, 50);
    anotherCsrMatrix.setValue(2, 2, 20);

    csrMatrix.sub(anotherCsrMatrix);

    EXPECT_EQ(csrMatrix.rows(), 3);
    EXPECT_EQ(csrMatrix.columns(), 3);
    EXPECT_EQ(csrMatrix.size(), 3);
    EXPECT_EQ(csrMatrix.getValue(0, 0), 0);
    EXPECT_EQ(csrMatrix.getValue(0, 1), 0);
    EXPECT_EQ(csrMatrix.getValue(0, 2), 0);

    EXPECT_EQ(csrMatrix.getValue(1, 0), 5);
    EXPECT_EQ(csrMatrix.getValue(1, 1), -30);
    EXPECT_EQ(csrMatrix.getValue(1, 2), 0);

    EXPECT_EQ(csrMatrix.getValue(2, 0), 0);
    EXPECT_EQ(csrMatrix.getValue(2, 1), 0);
    EXPECT_EQ(csrMatrix.getValue(2, 2), -20);

}



//
//TEST(metnum_tp1_CSRMatrix, CSRMatrix_add_matrix_2)
//{
//
//    CSRMatrix csrMatrix(3, 3);
//    csrMatrix.setValue(0, 0, 10);
//    csrMatrix.setValue(1, 0, 5);
//    csrMatrix.setValue(1, 1, 20);
//
//    CSRMatrix anotherCsrMatrix(3, 3);
//    anotherCsrMatrix.setValue(0, 0, 15);
//    anotherCsrMatrix.setValue(1, 1, 50);
//    anotherCsrMatrix.setValue(2, 2, 100);
//
//    csrMatrix.add(anotherCsrMatrix);
//
//    EXPECT_EQ(csrMatrix.rows(), 3);
//    EXPECT_EQ(csrMatrix.columns(), 3);
//    EXPECT_EQ(csrMatrix.getValue(0, 0), 25);
//    EXPECT_EQ(csrMatrix.getValue(0, 1), 0);
//    EXPECT_EQ(csrMatrix.getValue(0, 2), 0);
//
//    EXPECT_EQ(csrMatrix.getValue(1, 0), 5);
//    EXPECT_EQ(csrMatrix.getValue(1, 1), 70);
//    EXPECT_EQ(csrMatrix.getValue(1, 2), 0);
//
//    EXPECT_EQ(csrMatrix.getValue(2, 0), 0);
//    EXPECT_EQ(csrMatrix.getValue(2, 1), 0);
//    EXPECT_EQ(csrMatrix.getValue(2, 2), 100);
//
//}