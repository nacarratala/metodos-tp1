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

TEST(metnum_tp1_DOKMatrix, new_DOKMatrix_dimension_not_zero) 
{
	DOKMatrix dok_matrix(7,5);
	EXPECT_EQ(dok_matrix.rows(), 7);
	EXPECT_EQ(dok_matrix.columns(), 5);
} 


TEST(metnum_tp1_DOKMatrix, new_DOKMatrix_correctly_set_one_value) 
{
	DOKMatrix dok_matrix(4,5);
	EXPECT_EQ(dok_matrix.rows(), 4);
	EXPECT_EQ(dok_matrix.columns(), 5);
	EXPECT_EQ(dok_matrix.size(), 0);
	
	dok_matrix.setValue(2,3,55);
	EXPECT_EQ(dok_matrix.rows(), 4);
	EXPECT_EQ(dok_matrix.columns(), 5);
	EXPECT_EQ(dok_matrix.getValue(2,3), 55);
	EXPECT_EQ(dok_matrix.size(), 1);
} 



TEST(metnum_tp1_DOKMatrix, new_DOKMatrix_correctly_set_multiple_values) 
{
	DOKMatrix dok_matrix(4,4);
	dok_matrix.setValue(2,3,55);
	EXPECT_EQ(dok_matrix.rows(), 4);
	EXPECT_EQ(dok_matrix.columns(), 4);
	EXPECT_EQ(dok_matrix.getValue(2,3), 55);
	EXPECT_EQ(dok_matrix.size(), 1);
	
	dok_matrix.setValue(0,0,15);
	EXPECT_EQ(dok_matrix.rows(), 4);
	EXPECT_EQ(dok_matrix.columns(), 4);
	EXPECT_EQ(dok_matrix.getValue(2,3), 55);
	EXPECT_EQ(dok_matrix.getValue(0,0), 15);
	EXPECT_EQ(dok_matrix.size(), 2);
	
	dok_matrix.setValue(3,2,100);
	EXPECT_EQ(dok_matrix.rows(), 4);
	EXPECT_EQ(dok_matrix.columns(), 4);
	EXPECT_EQ(dok_matrix.getValue(2,3), 55);
	EXPECT_EQ(dok_matrix.getValue(0,0), 15);
	EXPECT_EQ(dok_matrix.getValue(3,2), 100);
	EXPECT_EQ(dok_matrix.size(), 3);
} 


TEST(metnum_tp1_DOKMatrix, new_DOKMatrix_correctly_set_value_to_zero) 
{
	DOKMatrix dok_matrix(4,4);
	dok_matrix.setValue(2,3,55);
	EXPECT_EQ(dok_matrix.rows(), 4);
	EXPECT_EQ(dok_matrix.columns(), 4);
	EXPECT_EQ(dok_matrix.getValue(2,3), 55);
	EXPECT_EQ(dok_matrix.size(), 1);
	
	dok_matrix.setValue(0,0,15);
	EXPECT_EQ(dok_matrix.rows(), 4);
	EXPECT_EQ(dok_matrix.columns(), 4);
	EXPECT_EQ(dok_matrix.getValue(2,3), 55);
	EXPECT_EQ(dok_matrix.getValue(0,0), 15);
	EXPECT_EQ(dok_matrix.size(), 2);
	
	dok_matrix.setValue(3,2,100);
	EXPECT_EQ(dok_matrix.rows(), 4);
	EXPECT_EQ(dok_matrix.columns(), 4);
	EXPECT_EQ(dok_matrix.getValue(2,3), 55);
	EXPECT_EQ(dok_matrix.getValue(0,0), 15);
	EXPECT_EQ(dok_matrix.getValue(3,2), 100);
	EXPECT_EQ(dok_matrix.size(), 3);
	
	dok_matrix.setValue(2,2,0);
	EXPECT_EQ(dok_matrix.rows(), 4);
	EXPECT_EQ(dok_matrix.columns(), 4);
	EXPECT_EQ(dok_matrix.getValue(2,3), 55);
	EXPECT_EQ(dok_matrix.getValue(0,0), 15);
	EXPECT_EQ(dok_matrix.getValue(3,2), 100);
	EXPECT_EQ(dok_matrix.size(), 3);
	
	dok_matrix.setValue(0,0,0);
	EXPECT_EQ(dok_matrix.rows(), 4);
	EXPECT_EQ(dok_matrix.columns(), 4);
	EXPECT_EQ(dok_matrix.getValue(2,3), 55);
	EXPECT_EQ(dok_matrix.getValue(0,0), 0);
	EXPECT_EQ(dok_matrix.getValue(3,2), 100);
	EXPECT_EQ(dok_matrix.size(), 2);
	
	dok_matrix.setValue(2,3,0);
	EXPECT_EQ(dok_matrix.rows(), 4);
	EXPECT_EQ(dok_matrix.columns(), 4);
	EXPECT_EQ(dok_matrix.getValue(2,3), 0);
	EXPECT_EQ(dok_matrix.getValue(0,0), 0);
	EXPECT_EQ(dok_matrix.getValue(3,2), 100);
	EXPECT_EQ(dok_matrix.size(), 1);
	
} 

