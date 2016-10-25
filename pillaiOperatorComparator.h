/* 
 * File:   pillaiOperatorComparator.h
 * Author: addy
 *
 * Created on December 8, 2013, 1:15 PM
 */

#ifndef PILLAIOPERATORCOMPARATOR_H
#define	PILLAIOPERATORCOMPARATOR_H

#include "pillai_op.h"


class pillaiOperatorComparator {
public:
    bool operator()(pillai_op op1, pillai_op op2);
private:

};

#endif	/* PILLAIOPERATORCOMPARATOR_H */

