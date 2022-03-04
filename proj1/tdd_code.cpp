//======== Copyright (c) 2021, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     Test Driven Development - priority queue code
//
// $NoKeywords: $ivs_project_1 $tdd_code.cpp
// $Author:     Matúš Juštik <xjusti00@stud.fit.vutbr.cz>
// $Date:       $2021-10-03
//============================================================================//
/**
 * @file tdd_code.cpp
 * @author Matúš Juštik
 * 
 * @brief Implementace metod tridy prioritni fronty.
 */

#include <stdlib.h>
#include <stdio.h>

#include "tdd_code.h"


//============================================================================//
// ** ZDE DOPLNTE IMPLEMENTACI **
//
// Zde doplnte implementaci verejneho rozhrani prioritni fronty (Priority Queue)
// 1. Verejne rozhrani fronty specifikovane v: tdd_code.h (sekce "public:")
//    - Konstruktor (PriorityQueue()), Destruktor (~PriorityQueue())
//    - Metody Insert/Remove/Find a GetHead
//    - Pripadne vase metody definovane v tdd_code.h (sekce "protected:")
//
// Cilem je dosahnout plne funkcni implementace prioritni fronty implementovane
// pomoci tzv. "double-linked list", ktera bude splnovat dodane testy 
// (tdd_tests.cpp).
//============================================================================//

PriorityQueue::PriorityQueue()
{
    m_pHead = NULL;
}

PriorityQueue::~PriorityQueue()
{
    Element_t *tmp = m_pHead;
    Element_t *tmp1 = m_pHead;
    while (tmp != NULL){
        tmp = tmp1;
        tmp1 = tmp1->pNext;
        delete (tmp);
        tmp=tmp1;
    }

    //m_pHead = NULL;

}

void PriorityQueue::Insert(int value) {

    Element_t *tmp = new Element_t{
            .pNext= NULL,
            .value= value,
    };
    if (m_pHead == NULL) {
        m_pHead = tmp;
    } else{
        if (value > m_pHead->value){
            tmp->pNext= m_pHead;
            m_pHead = tmp;
        } else{
            Element_t *tmp1 = m_pHead;
            while (tmp1->pNext != NULL && value < tmp1->pNext->value){
                tmp1 = tmp1->pNext;
            }
            tmp->pNext= tmp1->pNext;
            tmp1->pNext = tmp;
        }
    }
}
bool PriorityQueue::Remove(int value){

    if (m_pHead == NULL) {
        return false;
    }else{
        if (value > m_pHead->value){
            return false;
        } else{
            Element_t *tmp = NULL;
            Element_t *tmp1 = m_pHead;
            while (tmp1 != NULL && value < tmp1->value){

                tmp = tmp1;
                tmp1 = tmp1->pNext;
            }
            if (tmp1 == NULL){
                return false;
            }
            if (tmp1->value == value){
                if (tmp == NULL){
                    m_pHead = tmp1->pNext;
                }
                else{
                    tmp->pNext = tmp1->pNext;
                }
                delete tmp1;
                return true;
            }
        }
    }
    return false;
}

PriorityQueue::Element_t *PriorityQueue::Find(int value) {

    if (m_pHead == NULL) {
        return NULL;
    } else{
        if (value == m_pHead->value){
            return m_pHead;
        } else{
            Element_t *tmp1 = m_pHead;
            while (tmp1->pNext != NULL && value <= tmp1->pNext->value){

                tmp1 = tmp1->pNext;
            }
            if (tmp1->value == value){
                return tmp1;
            }

            return NULL;
        }
    }

}

size_t PriorityQueue::Length()
{

    int i= 1;
    if (m_pHead == NULL) {
        return 0;
    }else {
            Element_t *tmp = m_pHead;
            while (tmp->pNext != NULL ){
                tmp = tmp->pNext;
                i++;
            }
            return i;
    }

}

PriorityQueue::Element_t *PriorityQueue::GetHead()
{
    return m_pHead;
}

/*** Konec souboru tdd_code.cpp ***/
