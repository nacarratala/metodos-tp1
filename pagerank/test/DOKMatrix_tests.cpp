#include <gtest/gtest.h>
#include "model/DOKMatrix.h"
/**
 * Test simple básico
 */
 
TEST(metnum_tp1_DOKMatrix, new_DOKMatrix_is_empty) 
{
	DOKMatrix dok_matrix;
	EXPECT_EQ(dok_matrix.size(), 0);
}

TEST(metnum_tp1_DOKMatrix, new_DOKMatrix_dimension_zero) 
{
	DOKMatrix dok_matrix;
	EXPECT_EQ(dok_matrix.rows(), 0);
	EXPECT_EQ(dok_matrix.columns(), 0);
} 

TEST(metnum_tp1_DOKMatrix, new_DOKMatrix_correctly_set_one_value) 
{
	DOKMatrix dok_matrix;
	EXPECT_EQ(dok_matrix.rows(), 0);
	EXPECT_EQ(dok_matrix.columns(), 0);
	EXPECT_EQ(dok_matrix.size(), 0);

	dok_matrix.setValue(2,3,55);
	EXPECT_EQ(dok_matrix.rows(), 2);
	EXPECT_EQ(dok_matrix.columns(), 3);
	EXPECT_EQ(dok_matrix.getValue(2,3), 55);
	EXPECT_EQ(dok_matrix.size(), 1);
} 

TEST(metnum_tp1_DOKMatrix, new_DOKMatrix_correctly_set_multiple_values) 
{
	DOKMatrix dok_matrix;
	dok_matrix.setValue(2,3,55);
	EXPECT_EQ(dok_matrix.rows(), 2);
	EXPECT_EQ(dok_matrix.columns(), 3);
	EXPECT_EQ(dok_matrix.getValue(2,3), 55);
	EXPECT_EQ(dok_matrix.size(), 1);
	
	dok_matrix.setValue(1,1,15);
	EXPECT_EQ(dok_matrix.rows(), 2);
	EXPECT_EQ(dok_matrix.columns(), 3);
	EXPECT_EQ(dok_matrix.getValue(2,3), 55);
	EXPECT_EQ(dok_matrix.getValue(1,1), 15);
	EXPECT_EQ(dok_matrix.size(), 2);
	
	dok_matrix.setValue(3,2,100);
	EXPECT_EQ(dok_matrix.rows(), 3);
	EXPECT_EQ(dok_matrix.columns(), 3);
	EXPECT_EQ(dok_matrix.getValue(2,3), 55);
	EXPECT_EQ(dok_matrix.getValue(1,1), 15);
	EXPECT_EQ(dok_matrix.getValue(3,2), 100);
	EXPECT_EQ(dok_matrix.size(), 3);
} 

TEST(metnum_tp1_DOKMatrix, new_DOKMatrix_correctly_set_value_to_zero) 
{
    DOKMatrix dok_matrix;
    dok_matrix.setValue(2,3,55);
    EXPECT_EQ(dok_matrix.rows(), 2);
    EXPECT_EQ(dok_matrix.columns(), 3);
    EXPECT_EQ(dok_matrix.getValue(2,3), 55);
    EXPECT_EQ(dok_matrix.size(), 1);

    dok_matrix.setValue(1,1,15);
    EXPECT_EQ(dok_matrix.rows(), 2);
    EXPECT_EQ(dok_matrix.columns(), 3);
    EXPECT_EQ(dok_matrix.getValue(2,3), 55);
    EXPECT_EQ(dok_matrix.getValue(1,1), 15);
    EXPECT_EQ(dok_matrix.size(), 2);

    dok_matrix.setValue(3,2,100);
    EXPECT_EQ(dok_matrix.rows(), 3);
    EXPECT_EQ(dok_matrix.columns(), 3);
    EXPECT_EQ(dok_matrix.getValue(2,3), 55);
    EXPECT_EQ(dok_matrix.getValue(1,1), 15);
    EXPECT_EQ(dok_matrix.getValue(3,2), 100);
    EXPECT_EQ(dok_matrix.size(), 3);
	
	dok_matrix.setValue(2,2,0);
	EXPECT_EQ(dok_matrix.rows(), 3);
	EXPECT_EQ(dok_matrix.columns(), 3);
	EXPECT_EQ(dok_matrix.getValue(2,3), 55);
	EXPECT_EQ(dok_matrix.getValue(1,1), 15);
	EXPECT_EQ(dok_matrix.getValue(3,2), 100);
	EXPECT_EQ(dok_matrix.size(), 3);
	
	dok_matrix.setValue(1,1,0);
	EXPECT_EQ(dok_matrix.rows(), 3);
	EXPECT_EQ(dok_matrix.columns(), 3);
	EXPECT_EQ(dok_matrix.getValue(2,3), 55);
	EXPECT_EQ(dok_matrix.getValue(1,1), 0);
	EXPECT_EQ(dok_matrix.getValue(3,2), 100);
	EXPECT_EQ(dok_matrix.size(), 2);
	
	dok_matrix.setValue(2,3,0);
	EXPECT_EQ(dok_matrix.rows(), 3);
	EXPECT_EQ(dok_matrix.columns(), 2);
	EXPECT_EQ(dok_matrix.getValue(2,3), 0);
	EXPECT_EQ(dok_matrix.getValue(1,1), 0);
	EXPECT_EQ(dok_matrix.getValue(3,2), 100);
	EXPECT_EQ(dok_matrix.size(), 1);

}