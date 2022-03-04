//======== Copyright (c) 2017, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     Red-Black Tree - public interface tests
//
// $NoKeywords: $ivs_project_1 $black_box_tests.cpp
// $Author:     Matúš Juštik <xjusti00@stud.fit.vutbr.cz>
// $Date:       $2021-10-03
//============================================================================//
/**
 * @file black_box_tests.cpp
 * @author Matúš Juštik
 * 
 * @brief Implementace testu binarniho stromu.
 */

#include <vector>

#include "gtest/gtest.h"

#include "red_black_tree.h"

//============================================================================//
// ** ZDE DOPLNTE TESTY **
//
// Zde doplnte testy Red-Black Tree, testujte nasledujici:
// 1. Verejne rozhrani stromu
//    - InsertNode/DeleteNode a FindNode
//    - Chovani techto metod testuje pro prazdny i neprazdny strom.
// 2. Axiomy (tedy vzdy platne vlastnosti) Red-Black Tree:
//    - Vsechny listove uzly stromu jsou *VZDY* cerne.
//    - Kazdy cerveny uzel muze mit *POUZE* cerne potomky.
//    - Vsechny cesty od kazdeho listoveho uzlu ke koreni stromu obsahuji
//      *STEJNY* pocet cernych uzlu.
//============================================================================//

class EmptyTree : public ::testing::Test
{
protected:
    BinaryTree tree;
};

class NonEmptyTree : public ::testing::Test
{
protected:
    virtual void SetUp() {
        int values[] = {10, 15, 20, 30, 35, 5, 25, 40, 60, 45, 65, 70, 50, 55};
        for (auto value : values) {
            tree.InsertNode(value);
        }
    }
    BinaryTree tree;
};
/*******************************************************/

TEST_F(EmptyTree, InsertNode){

};

TEST_F(EmptyTree, DeleteNode){

};

TEST_F(EmptyTree, FindNode){

};
/*******************************************************/
TEST_F(NonEmptyTree, InsertNode){

};

TEST_F(NonEmptyTree, DeleteNode){

};

TEST_F(NonEmptyTree, FindNode){

};
/*** Konec souboru black_box_tests.cpp ***/
