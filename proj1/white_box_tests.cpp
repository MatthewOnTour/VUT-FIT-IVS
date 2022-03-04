//======== Copyright (c) 2021, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     White Box - Tests suite
//
// $NoKeywords: $ivs_project_1 $white_box_code.cpp
// $Author:     Matúš Juštik <xjusti00@stud.fit.vutbr.cz>
// $Date:       $2021-10-03
//============================================================================//
/**
 * @file white_box_tests.cpp
 * @author Matúš Juštik
 * 
 * @brief Implementace testu prace s maticemi.
 */

#include "gtest/gtest.h"
#include "white_box_code.h"

//============================================================================//
// ** ZDE DOPLNTE TESTY **
//
// Zde doplnte testy operaci nad maticemi. Cilem testovani je:
// 1. Dosahnout maximalniho pokryti kodu (white_box_code.cpp) testy.
// 2. Overit spravne chovani operaci nad maticemi v zavislosti na rozmerech 
//    matic.
//============================================================================//

class matica1x1 : public :: testing::Test{
    protected:
    Matrix m{};
};

TEST(BasicTest, MatrixBasicTests){
    Matrix matrix{};
    EXPECT_EQ(matrix.get(0,0), 0);
    Matrix matrix1{2,2};
    EXPECT_ANY_THROW(Matrix(0,-1));
    Matrix matrix2{};
    matrix2.set(0 , 0 , 0);
    matrix2.set(1 , 1 , 0);

    Matrix matrix3{3,3};
    std::vector<std::vector< double > > values {
            {1,2,3},
            {4,5,6},
            {7,8,9}
    };
    matrix3.set(values);
    std::vector<std::vector< double > > values2 {
            {1,2,3,0},
            {4,5,6,0},
            {7,8,9,10}
    };
    matrix3.set(values2);
    std::vector<std::vector< double > > values3 {
            {1,2},
            {4,5},
            {7,8},
            {7,8}
    };
    matrix3.set(values3);

}
TEST(BasicTest, MatrixEKV){
    Matrix matrix{};
    Matrix matrix1{};
    Matrix matrix2(4,4);
    matrix.set(0,0,1);
    matrix1.set(0,0,1);
    matrix2.set(4,2,2);
    EXPECT_EQ(matrix, matrix1);
    EXPECT_ANY_THROW(matrix.operator==(matrix2));
    matrix1.set(0,0,5);
    EXPECT_EQ(matrix.operator==(matrix1),false);
    EXPECT_ANY_THROW(matrix.get(3,2));
}
TEST(BasicTest, MatrixSUM){
    Matrix matrix{};
    Matrix matrix1{};
    Matrix matrix2(4,4);
    matrix.set(3,0,2);
    matrix1.set(0,2,1);
    Matrix result = matrix.operator+(matrix1);
    EXPECT_ANY_THROW(matrix.operator+(matrix2));
    Matrix matrix3 {3,3};
    Matrix matrix4 {4,4};
    EXPECT_ANY_THROW(matrix3.operator+(matrix4));

}
TEST(BasicTest, MatrixMULT){
    Matrix matrix{2,2};
    Matrix matrix1{2,2};
    matrix.set(2,2,1);
    matrix1.set(0,2,1);
    Matrix matrix2{};
    matrix2 = matrix.operator*(matrix1);
    EXPECT_EQ(matrix2.operator==(matrix1),true);
    Matrix matrix3 {3,3};
    Matrix matrix4 {3,3};
    matrix3 = matrix2.operator*(2);
    matrix4.set(4,4,1);
}
TEST(BasicTest, MatrixEQUA){
    Matrix matrix{3,3};
    Matrix matrix1{3,1};
    std::vector<std::vector< double > > values {
            {0,4,1},
            {2,1,4},
            {0,1,0}
    };
    matrix.set(values);
    std::vector<std::vector< double > > values2{
            {6,1,-3},
    };
    matrix.solveEquation({1,1,1});
}

TEST(BasicTest, MatrixTransponse){
    Matrix matrix{2,2};
    Matrix matrix1{2,2};
    std::vector<std::vector< double > > values {
            {1,1},
            {0,0}
    };
    matrix.set(values);
    std::vector<std::vector< double > > values1 {
            {1,0},
            {1,0}
    };
    matrix1.set(values1);
    matrix.transpose();
    EXPECT_EQ(matrix.operator==(matrix1),false);
}

TEST(BasicTest, MatrixInverse){
    Matrix matrix{2,2};
    Matrix matrix1{2,2};
    std::vector<std::vector< double > > values {
            {4,5},
            {1,1}
    };
    matrix.set(values);
    std::vector<std::vector< double > > values1 {
            {-1,5},
            {1,-4}
    };
    matrix1.set(values1);
    matrix.inverse();
    EXPECT_EQ(matrix.operator==(matrix1),false);

    Matrix matrix2{3,3};
    Matrix matrix3{3,3};
    std::vector<std::vector< double > > values2 {
            {0,1,0},
            {1,0,0},
            {0,2,1}
    };
    matrix2.set(values2);
    std::vector<std::vector< double > > values3 {
            {0,1,0},
            {1,0,0},
            {-2,0,1}
    };
    matrix3.set(values3);
    matrix2.inverse();
    EXPECT_EQ(matrix2.operator==(matrix3),false);
    Matrix matrix4{2,2};
    std::vector<std::vector< double > > values4 {
            {0,1},
            {0,0}
    };
    matrix.set(values4);
    EXPECT_ANY_THROW(matrix4.inverse());
}

TEST(BasicTest, MatrixELSE){

}


/*** Konec souboru white_box_tests.cpp ***/
