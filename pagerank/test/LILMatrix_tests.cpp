#include <gtest/gtest.h>
#include "model/LILMatrix.h"
/**
 * Test simple básico
 */
 
 
TEST(metnum_tp1_LILMatrix, new_LILMatrix_is_empty) 
{
	LILMatrix lil_matrix;
	EXPECT_EQ(lil_matrix.size(), 0);
}


TEST(metnum_tp1_LILMatrix, new_LILMatrix_dimension_zero) 
{
	LILMatrix lil_matrix;
	EXPECT_EQ(lil_matrix.rows(), 0);
	EXPECT_EQ(lil_matrix.columns(), 0);
} 

TEST(metnum_tp1_LILMatrix, new_LILMatrix_dimension_not_zero) 
{
	LILMatrix lil_matrix(7,5);
	EXPECT_EQ(lil_matrix.rows(), 7);
	EXPECT_EQ(lil_matrix.columns(), 5);
} 


TEST(metnum_tp1_LILMatrix, LILMatrix_correctly_set_one_value) 
{
	LILMatrix lil_matrix(4,5);
	EXPECT_EQ(lil_matrix.rows(), 4);
	EXPECT_EQ(lil_matrix.columns(), 5);
	EXPECT_EQ(lil_matrix.size(), 0);
	
	lil_matrix.setValue(2,3,55);
	EXPECT_EQ(lil_matrix.rows(), 4);
	EXPECT_EQ(lil_matrix.columns(), 5);
	EXPECT_EQ(lil_matrix.getValue(2,3), 55);
	EXPECT_EQ(lil_matrix.size(), 1);
} 



TEST(metnum_tp1_LILMatrix, LILMatrix_correctly_set_multiple_values) 
{
	LILMatrix lil_matrix(4,4);
	lil_matrix.setValue(2,3,55);
	EXPECT_EQ(lil_matrix.rows(), 4);
	EXPECT_EQ(lil_matrix.columns(), 4);
	EXPECT_EQ(lil_matrix.getValue(2,3), 55);
	EXPECT_EQ(lil_matrix.size(), 1);
	
	lil_matrix.setValue(0,0,15);
	EXPECT_EQ(lil_matrix.rows(), 4);
	EXPECT_EQ(lil_matrix.columns(), 4);
	EXPECT_EQ(lil_matrix.getValue(2,3), 55);
	EXPECT_EQ(lil_matrix.getValue(0,0), 15);
	EXPECT_EQ(lil_matrix.size(), 2);
	
	lil_matrix.setValue(3,2,100);
	EXPECT_EQ(lil_matrix.rows(), 4);
	EXPECT_EQ(lil_matrix.columns(), 4);
	EXPECT_EQ(lil_matrix.getValue(2,3), 55);
	EXPECT_EQ(lil_matrix.getValue(0,0), 15);
	EXPECT_EQ(lil_matrix.getValue(3,2), 100);
	EXPECT_EQ(lil_matrix.size(), 3);
} 


TEST(metnum_tp1_LILMatrix, LILMatrix_correctly_modify_value) 
{
	LILMatrix lil_matrix(4,4);
	lil_matrix.setValue(2,3,55);
	EXPECT_EQ(lil_matrix.rows(), 4);
	EXPECT_EQ(lil_matrix.columns(), 4);
	EXPECT_EQ(lil_matrix.getValue(2,3), 55);
	EXPECT_EQ(lil_matrix.size(), 1);
	
	lil_matrix.setValue(0,0,15);
	EXPECT_EQ(lil_matrix.rows(), 4);
	EXPECT_EQ(lil_matrix.columns(), 4);
	EXPECT_EQ(lil_matrix.getValue(2,3), 55);
	EXPECT_EQ(lil_matrix.getValue(0,0), 15);
	EXPECT_EQ(lil_matrix.size(), 2);
	
	lil_matrix.setValue(0,0,100);
	EXPECT_EQ(lil_matrix.rows(), 4);
	EXPECT_EQ(lil_matrix.columns(), 4);
	EXPECT_EQ(lil_matrix.getValue(2,3), 55);
	EXPECT_EQ(lil_matrix.getValue(0,0), 100);
	EXPECT_EQ(lil_matrix.size(), 2);
} 


TEST(metnum_tp1_LILMatrix, LILMatrix_correctly_set_value_to_zero) 
{
	LILMatrix lil_matrix(4,4);
	lil_matrix.setValue(2,3,55);
	EXPECT_EQ(lil_matrix.rows(), 4);
	EXPECT_EQ(lil_matrix.columns(), 4);
	EXPECT_EQ(lil_matrix.getValue(2,3), 55);
	EXPECT_EQ(lil_matrix.size(), 1);
	
	lil_matrix.setValue(0,0,15);
	EXPECT_EQ(lil_matrix.rows(), 4);
	EXPECT_EQ(lil_matrix.columns(), 4);
	EXPECT_EQ(lil_matrix.getValue(2,3), 55);
	EXPECT_EQ(lil_matrix.getValue(0,0), 15);
	EXPECT_EQ(lil_matrix.size(), 2);
	
	lil_matrix.setValue(3,2,100);
	EXPECT_EQ(lil_matrix.rows(), 4);
	EXPECT_EQ(lil_matrix.columns(), 4);
	EXPECT_EQ(lil_matrix.getValue(2,3), 55);
	EXPECT_EQ(lil_matrix.getValue(0,0), 15);
	EXPECT_EQ(lil_matrix.getValue(3,2), 100);
	EXPECT_EQ(lil_matrix.size(), 3);
	
	lil_matrix.setValue(2,2,0);
	EXPECT_EQ(lil_matrix.rows(), 4);
	EXPECT_EQ(lil_matrix.columns(), 4);
	EXPECT_EQ(lil_matrix.getValue(2,3), 55);
	EXPECT_EQ(lil_matrix.getValue(0,0), 15);
	EXPECT_EQ(lil_matrix.getValue(3,2), 100);
	EXPECT_EQ(lil_matrix.getValue(2,2), 0);
	EXPECT_EQ(lil_matrix.size(), 3);
	
	lil_matrix.setValue(0,0,0);
	EXPECT_EQ(lil_matrix.rows(), 4);
	EXPECT_EQ(lil_matrix.columns(), 4);
	EXPECT_EQ(lil_matrix.getValue(2,3), 55);
	EXPECT_EQ(lil_matrix.getValue(0,0), 0);
	EXPECT_EQ(lil_matrix.getValue(3,2), 100);
	EXPECT_EQ(lil_matrix.size(), 2);
	
	lil_matrix.setValue(2,3,0);
	EXPECT_EQ(lil_matrix.rows(), 4);
	EXPECT_EQ(lil_matrix.columns(), 4);
	EXPECT_EQ(lil_matrix.getValue(2,3), 0);
	EXPECT_EQ(lil_matrix.getValue(0,0), 0);
	EXPECT_EQ(lil_matrix.getValue(3,2), 100);
	EXPECT_EQ(lil_matrix.size(), 1);
	
} 

