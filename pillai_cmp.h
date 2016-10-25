#ifndef PILLAI_CMP_H
#define	PILLAI_CMP_H

#include "pillai_op.h"


struct setCompareEqual {

    bool operator () (const pillai_op* p_lhs, const pillai_op* p_rhs) {
        return ( ((p_lhs->getValue()) < (p_rhs->getValue())) || ((p_lhs->getValue() == p_rhs->getValue()) && (p_lhs->getPosition() < p_rhs->getPosition()) && (p_lhs->getPosition() != 0) )) ? true : false;
    }
};

#endif	/* PILLAI_CMP_H */
