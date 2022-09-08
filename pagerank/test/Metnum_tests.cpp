#include <gtest/gtest.h>
#include "model/Gauss.h"
#include "model/LILMatrix.h"
/**
 * Test simple básico
 */
 
 
TEST(metnum_tp1_Metnmum, LILMatrix_static_creation_identity)
{
	LILMatrix lil_matrix (
            {
                {1,0,0},
                {0,1,0},
                {0,0,1},
                });

    EXPECT_EQ(lil_matrix.rows(), 3);
    EXPECT_EQ(lil_matrix.columns(), 3);
	EXPECT_EQ(lil_matrix.size(), 3);

    EXPECT_EQ(lil_matrix.getValue(0,0), 1);
    EXPECT_EQ(lil_matrix.getValue(0,1), 0);
    EXPECT_EQ(lil_matrix.getValue(0,2), 0);

    EXPECT_EQ(lil_matrix.getValue(1,0), 0);
    EXPECT_EQ(lil_matrix.getValue(1,1), 1);
    EXPECT_EQ(lil_matrix.getValue(1,2), 0);

    EXPECT_EQ(lil_matrix.getValue(2,0), 0);
    EXPECT_EQ(lil_matrix.getValue(2,1), 0);
    EXPECT_EQ(lil_matrix.getValue(2,2), 1);


}


TEST(metnum_tp1_Metnmum, LILMatrix_static_creation_with_empty_row)
{
    LILMatrix lil_matrix (
            {
                    {1,0,1},
                    {0,0,0},
                    {1,1,1},
            });

    EXPECT_EQ(lil_matrix.rows(), 3);
    EXPECT_EQ(lil_matrix.columns(), 3);
    EXPECT_EQ(lil_matrix.size(), 5);

    EXPECT_EQ(lil_matrix.getValue(0,0), 1);
    EXPECT_EQ(lil_matrix.getValue(0,1), 0);
    EXPECT_EQ(lil_matrix.getValue(0,2), 1);

    EXPECT_EQ(lil_matrix.getValue(1,0), 0);
    EXPECT_EQ(lil_matrix.getValue(1,1), 0);
    EXPECT_EQ(lil_matrix.getValue(1,2), 0);

    EXPECT_EQ(lil_matrix.getValue(2,0), 1);
    EXPECT_EQ(lil_matrix.getValue(2,1), 1);
    EXPECT_EQ(lil_matrix.getValue(2,2), 1);
}

TEST(metnum_tp1_Metnmum, LILMatrix_static_creation_with_empty_rows)
{
    LILMatrix lil_matrix (
            {
                    {0,0,0},
                    {0,1,0},
                    {1,0,1},
                    {0,0,0}
            });

    EXPECT_EQ(lil_matrix.rows(), 4);
    EXPECT_EQ(lil_matrix.columns(), 3);
    EXPECT_EQ(lil_matrix.size(), 3);

    EXPECT_EQ(lil_matrix.getValue(0,0), 0);
    EXPECT_EQ(lil_matrix.getValue(0,1), 0);
    EXPECT_EQ(lil_matrix.getValue(0,2), 0);

    EXPECT_EQ(lil_matrix.getValue(1,0), 0);
    EXPECT_EQ(lil_matrix.getValue(1,1), 1);
    EXPECT_EQ(lil_matrix.getValue(1,2), 0);

    EXPECT_EQ(lil_matrix.getValue(2,0), 1);
    EXPECT_EQ(lil_matrix.getValue(2,1), 0);
    EXPECT_EQ(lil_matrix.getValue(2,2), 1);

    EXPECT_EQ(lil_matrix.getValue(3,0), 0);
    EXPECT_EQ(lil_matrix.getValue(3,1), 0);
    EXPECT_EQ(lil_matrix.getValue(3,2), 0);
}


TEST(metnum_tp1_Metnmum, Metnum_triangulation_stair_matrix_3_3)
{
    LILMatrix A (
            {
                    {1,0,0},
                    {1,1,0},
                    {1,1,1},
            });

    EXPECT_EQ(A.rows(), 3);
    EXPECT_EQ(A.columns(), 3);
    EXPECT_EQ(A.size(), 6);

    std::vector<double> b = {1.0, 2.0, 3.0};

    Gauss::triangulation(A, b);
    EXPECT_EQ(A.rows(), 3);
    EXPECT_EQ(A.columns(), 3);
    EXPECT_EQ(A.size(), 3);

    EXPECT_EQ(b[0], 1.0);
    EXPECT_EQ(b[1], 1.0);
    EXPECT_EQ(b[2], 1.0);

}



TEST(metnum_tp1_Metnmum, Metnum_triangulation_stair_matrix_5_5)
{
    LILMatrix A (
            {
                    {1,0,0,0,0},
                    {1,1,0,0,0},
                    {1,1,1,0,0},
                    {1,1,1,1,0},
                    {1,1,1,1,1}
            });

    EXPECT_EQ(A.rows(), 5);
    EXPECT_EQ(A.columns(), 5);
    EXPECT_EQ(A.size(), 15);

    std::vector<double> b = {1.0, 2.0, 3.0, 4.0, 5.0};

    Gauss::triangulation(A, b);
    EXPECT_EQ(A.rows(), 5);
    EXPECT_EQ(A.columns(), 5);
    EXPECT_EQ(A.size(), 5);

    EXPECT_EQ(b[0], 1.0);
    EXPECT_EQ(b[1], 1.0);
    EXPECT_EQ(b[2], 1.0);
    EXPECT_EQ(b[3], 1.0);
    EXPECT_EQ(b[4], 1.0);

}


//https://www.math.usm.edu/lambers/mat610/sum10/lecture4.pdf
TEST(metnum_tp1_Metnmum, Metnum_triangulation_usm_example)
{
    LILMatrix A (
            {
                    {1,2,1,-1},
                    {3,2,4,4},
                    {4,4,3,4},
                    {2,0,1,5}
            });

    EXPECT_EQ(A.rows(), 4);
    EXPECT_EQ(A.columns(), 4);
    EXPECT_EQ(A.size(), 15);

    std::vector<double> b = {5, 16, 22, 15};

    Gauss::triangulation(A, b);
    EXPECT_EQ(A.rows(), 4);
    EXPECT_EQ(A.columns(), 4);
    EXPECT_EQ(A.size(), 10);


    EXPECT_EQ(A.getValue(0,0), 1);
    EXPECT_EQ(A.getValue(0,1), 2);
    EXPECT_EQ(A.getValue(0,2), 1);
    EXPECT_EQ(A.getValue(0,3), -1);

    EXPECT_EQ(A.getValue(1,0), 0);
    EXPECT_EQ(A.getValue(1,1), -4);
    EXPECT_EQ(A.getValue(1,2), 1);
    EXPECT_EQ(A.getValue(1,3), 7);

    EXPECT_EQ(A.getValue(2,0), 0);
    EXPECT_EQ(A.getValue(2,1), 0);
    EXPECT_EQ(A.getValue(2,2), -2);
    EXPECT_EQ(A.getValue(2,3), 1);

    EXPECT_EQ(A.getValue(3,0), 0);
    EXPECT_EQ(A.getValue(3,1), 0);
    EXPECT_EQ(A.getValue(3,2), 0);
    EXPECT_EQ(A.getValue(3,3), -1);

    EXPECT_EQ(b[0], 5);
    EXPECT_EQ(b[1], 1);
    EXPECT_EQ(b[2], 1);
    EXPECT_EQ(b[3], 3);

}

