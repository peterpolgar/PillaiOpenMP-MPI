/* 
 * File:   pillaiOperatorComparator.cpp
 * Author: addy
 * 
 * Created on December 8, 2013, 1:15 PM
 */

#include "pillaiOperatorComparator.h"

bool pillaiOperatorComparator::operator()(pillai_op op1, pillai_op op2) {
    if(op1.getValue() < op2.getValue() )
        return true;
    else
        return false;
}
