/*
 * pillaiop.cpp
 *	Class of Operators of Pillai.
 *  Created on: Oct 31, 2011
 *      Author: Laszlo Kovacs
 *      Version: 001
 */
#include <stdlib.h>
#include <sstream>
#include "pillai_op.h"
#include "iostream"
#include "ToolBox_Math.h"

pillai_op::pillai_op() {
    this->value = 0;
    this->position = 0;
    this->postOp = false;
    this->preOp = false;
    this->simOp = NULL;
//    this->postReqBitset = NULL;
//    this->capColBitset = NULL;
//    this->curCapColBitset = NULL;
//    this->prereq = NULL;
//    this->postreq = NULL;
//    this->prereqP = NULL;
//    this->postreqP = NULL;
}

pillai_op::pillai_op(unsigned short int value, unsigned short int position, bool postOp, bool preOp,unsigned short int n) {
    this->value = (value);
    this->position = (position);
    this->postOp = postOp;
    this->preOp = preOp;
    this->simOp = NULL;
//    this->postReqBitset = new std::bitset<BITSET_SIZE> ();
//    this->capColBitset = new std::bitset<BITSET_SIZE> ();
//    this->curCapColBitset = new std::bitset<BITSET_SIZE> ();
//    this->prereq = NULL;
//    this->postreq = NULL;
//    this->prereqP = NULL;
//    this->postreqP = NULL;
}

pillai_op::pillai_op(unsigned short int value, unsigned short int position, bool postOp, bool preOp,unsigned short int n, std::bitset<BITSET_SIZE> extBitset) {
    this->value = (value);
    this->position = (position);
    this->postOp = postOp;
    this->preOp = preOp;
    this->simOp = NULL;
//    this->postReqBitset = new std::bitset<BITSET_SIZE> ();
//    this->capColBitset = new std::bitset<BITSET_SIZE> ();
//    this->curCapColBitset = new std::bitset<BITSET_SIZE> ();
    this->extBitset = extBitset;
//    this->prereq = NULL;
//    this->postreq = NULL;
//    this->prereqP = NULL;
//    this->postreqP = NULL;
}

pillai_op::pillai_op(unsigned short int value, unsigned short int position, bool postOp, bool preOp, unsigned short int n, std::vector<unsigned short int> prereq, std::vector<unsigned short int> postreq) {
    this->value = (value);
    this->position = (position);
    this->postOp = postOp;
    this->preOp = preOp;
    this->simOp = NULL;
//    this->postReqBitset = new boost::dynamic_bitset<> (n);
//    this->capColBitset = new boost::dynamic_bitset<> (n);
//    //this->capColBitset->reset();
//    this->curCapColBitset = new boost::dynamic_bitset<> (n);
//    //this->curCapColBitset->reset();
//    this->postReqBitset = new std::bitset<BITSET_SIZE> ();
//    this->capColBitset = new std::bitset<BITSET_SIZE> ();
//    this->curCapColBitset = new std::bitset<BITSET_SIZE> ();
//    this->prereq = NULL;
//    this->postreq = NULL;
    
    if (!prereq.empty()) {
        this->prereq.assign(prereq.begin(), prereq.end());
    }
    if (!postreq.empty()) {
        this->postreq.assign(postreq.begin(), postreq.end());
    }
    //    this->prereqP = NULL;
    //    this->postreqP = NULL;
}

pillai_op::pillai_op(unsigned short int value, unsigned short int position, bool postOp, bool preOp, unsigned short int n, std::vector<unsigned short int> prereq, std::vector<unsigned short int> postreq, unsigned short int sizePreP, unsigned short int sizePostP) {
    this->value = (value);
    this->position = (position);
    this->postOp = postOp;
    this->preOp = preOp;
    this->simOp = NULL;
//    this->postReqBitset = new boost::dynamic_bitset<> (n);
//    this->capColBitset = new boost::dynamic_bitset<> (n);
//    this->curCapColBitset = new boost::dynamic_bitset<> (n);
//    this->postReqBitset = new std::bitset<BITSET_SIZE> ();
//    this->capColBitset = new std::bitset<BITSET_SIZE> ();
//    this->curCapColBitset = new std::bitset<BITSET_SIZE> ();

    //this->prereq = NULL;
    //this->postreq = NULL;
    if (!prereq.empty()) {
        this->prereq.assign(prereq.begin(), prereq.end());
    }
    if (!postreq.empty()) {
        this->postreq.assign(postreq.begin(), postreq.end());
    }

//    this->prereqP = NULL;
//    this->postreqP = NULL;
    if (sizePreP != 0) {
        this->prereqP.reserve(sizePreP);
    }
    if (sizePostP != 0) {
        this->postreqP.reserve(sizePostP);
    }
}

pillai_op::pillai_op(unsigned short int value, unsigned short int position, bool postOp, bool preOp, unsigned short int n, std::vector<unsigned short int> prereq, std::vector<unsigned short int> postreq, unsigned short int sizePreP, unsigned short int sizePostP, std::bitset<BITSET_SIZE> extBitset) {
    this->value = (value);
    this->position = (position);
    this->postOp = postOp;
    this->preOp = preOp;
    this->simOp = NULL;
//    this->postReqBitset = new boost::dynamic_bitset<> (n);
//    this->capColBitset = new boost::dynamic_bitset<> (n);
//    this->curCapColBitset = new boost::dynamic_bitset<> (n);
//    this->postReqBitset = new std::bitset<BITSET_SIZE> ();
//    this->capColBitset = new std::bitset<BITSET_SIZE> ();
//    this->curCapColBitset = new std::bitset<BITSET_SIZE> ();
    this->extBitset = extBitset;

    //this->prereq = NULL;
    //this->postreq = NULL;
    if (!prereq.empty()) {
        this->prereq.assign(prereq.begin(), prereq.end());
    }
    if (!postreq.empty()) {
        this->postreq.assign(postreq.begin(), postreq.end());
    }

//    this->prereqP = NULL;
//    this->postreqP = NULL;
    if (sizePreP != 0) {
        this->prereqP.reserve(sizePreP);
    }
    if (sizePostP != 0) {
        this->postreqP.reserve(sizePostP);
    }
}

//pillai_op::pillai_op(unsigned short int value, unsigned short int position, bool postOp, bool preOp, boost::dynamic_bitset<> postReqBitset, unsigned short int n, std::vector<unsigned short int>* prereq, std::vector<unsigned short int>* postreq, unsigned short int sizePreP, unsigned short int sizePostP) {
pillai_op::pillai_op(unsigned short int value, unsigned short int position, bool postOp, bool preOp, std::bitset<BITSET_SIZE> postReqBitset, unsigned short int n, std::vector<unsigned short int> prereq, std::vector<unsigned short int> postreq, unsigned short int sizePreP, unsigned short int sizePostP) {
    this->value = (value);
    this->position = (position);
    this->postOp = postOp;
    this->preOp = preOp;
    this->simOp = NULL;
//    this->postReqBitset = new boost::dynamic_bitset<> (postReqBitset);
    this->postReqBitset = postReqBitset;
//    this->capColBitset = new boost::dynamic_bitset<> (n);
//   //this->capColBitset->reset();
//    this->curCapColBitset = new boost::dynamic_bitset<> (n);
//    //this->curCapColBitset->reset();
//    this->capColBitset = new std::bitset<BITSET_SIZE> ();
//    this->curCapColBitset = new std::bitset<BITSET_SIZE> ();

//    this->prereq = NULL;
//    this->postreq = NULL;
    if (!prereq.empty()) {
        this->prereq.assign(prereq.begin(), prereq.end());
    }
    if (!postreq.empty()) {
        this->postreq.assign(postreq.begin(), postreq.end());
    }

//    this->prereqP = NULL;
//    this->postreqP = NULL;
    if (sizePreP != 0) {
        this->prereqP.reserve(sizePreP);
    }
    if (sizePostP != 0) {
        this->postreqP.reserve(sizePostP);
    }
}
pillai_op::pillai_op(unsigned short int value, unsigned short int position, bool postOp, bool preOp, std::bitset<BITSET_SIZE> postReqBitset, unsigned short int n, std::vector<unsigned short int> prereq, std::vector<unsigned short int> postreq, unsigned short int sizePreP, unsigned short int sizePostP, std::bitset<BITSET_SIZE> extBitset) {
    this->value = (value);
    this->position = (position);
    this->postOp = postOp;
    this->preOp = preOp;
    this->simOp = NULL;
//    this->postReqBitset = new boost::dynamic_bitset<> (postReqBitset);
    this->postReqBitset = postReqBitset;
    this->extBitset =extBitset;
//    this->capColBitset = new boost::dynamic_bitset<> (n);
//   //this->capColBitset->reset();
//    this->curCapColBitset = new boost::dynamic_bitset<> (n);
//    //this->curCapColBitset->reset();
//    this->capColBitset = new std::bitset<BITSET_SIZE> ();
//    this->curCapColBitset = new std::bitset<BITSET_SIZE> ();

//    this->prereq = NULL;
//    this->postreq = NULL;
    if (!prereq.empty()) {
        this->prereq.assign(prereq.begin(), prereq.end());
    }
    if (!postreq.empty()) {
        this->postreq.assign(postreq.begin(), postreq.end());
    }

//    this->prereqP = NULL;
//    this->postreqP = NULL;
    if (sizePreP != 0) {
        this->prereqP.reserve(sizePreP);
    }
    if (sizePostP != 0) {
        this->postreqP.reserve(sizePostP);
    }
}

pillai_op::pillai_op(pillai_op* op) {
    if (!op->isNull()) {
        this->value = (op->getValue());
        this->position = (op->getPosition());
        this->postOp = op->isPostOp();
        this->preOp = op->isPreOp();
        this->simOp = op->simOp;
        this->postReqBitset = op->postReqBitset;
        this->capColBitset = op->capColBitset;
        this->curCapColBitset = op->curCapColBitset;
        this->extBitset = op->extBitset;

//        this->prereq = NULL;
//        this->postreq = NULL;
//        this->prereqP = NULL;
//        this->postreqP = NULL;
        if (!op->prereq.empty()) {
            this->prereq.assign(op->prereq.begin(), op->prereq.end());
        }
        if (!op->postreq.empty()) {
            this->postreq.assign(op->postreq.begin(), op->postreq.end());
        }
        if (!op->prereqP.empty()) {
            this->prereqP.assign(op->prereqP.begin(), op->prereqP.end());
        }
        if (!op->postreqP.empty()) {
            this->postreqP.assign(op->postreqP.begin(), op->postreqP.end());
        }
    } else {
        this->value = 0;
        this->position = 0;
        this->postOp = false;
        this->preOp = false;
        this->simOp = NULL;

//        this->postReqBitset = new std::bitset<BITSET_SIZE> ();
//        this->capColBitset = new std::bitset<BITSET_SIZE> ();
//        this->curCapColBitset = new std::bitset<BITSET_SIZE> ();
//        this->prereq = NULL;
//        this->postreq = NULL;
//        this->prereqP = NULL;
//        this->postreqP = NULL;
    }
}

pillai_op::pillai_op(pillai_op* op, unsigned short int n) {
    if (!op->isNull()) {
        this->value = (op->getValue());
        this->position = (op->getPosition());
        this->postOp = op->isPostOp();
        this->preOp = op->isPreOp();
        this->simOp = op->simOp;

        this->postReqBitset = op->postReqBitset;
        this->capColBitset = op->capColBitset;
        this->curCapColBitset = op->curCapColBitset;
        this->extBitset = op->extBitset;
        
//        this->prereq = NULL;
//        this->postreq = NULL;
//        this->prereqP = NULL;
//        this->postreqP = NULL;
        if (!op->prereq.empty()) {
            this->prereq.assign(op->prereq.begin(), op->prereq.end());
        }
        if (!op->postreq.empty()) {
            this->postreq.assign(op->postreq.begin(), op->postreq.end());
        }
        if (!op->prereqP.empty()) {
            this->prereqP.assign(op->prereqP.begin(), op->prereqP.end());
        }
        if (!op->postreqP.empty()) {
            this->postreqP.assign(op->postreqP.begin(), op->postreqP.end());
        }
    } else {
        this->value = 0;
        this->position = 0;
        this->postOp = false;
        this->preOp = false;
        this->simOp = NULL;

//        this->postReqBitset = new std::bitset<BITSET_SIZE> ();
//        this->capColBitset = new std::bitset<BITSET_SIZE> ();
//        this->curCapColBitset = new std::bitset<BITSET_SIZE> ();
//        this->prereq = NULL;
//        this->postreq = NULL;
//        this->prereqP = NULL;
//        this->postreqP = NULL;
    }
}

pillai_op::pillai_op(pillai_op* op, unsigned short int n, std::vector<unsigned short int> prereq, std::vector<unsigned short int> postreq) {
    if (!op->isNull()) {
        this->value = (op->getValue());
        this->position = (op->getPosition());
        this->postOp = op->isPostOp();
        this->preOp = op->isPreOp();
        this->simOp = op->simOp;
//        this->postReqBitset = new boost::dynamic_bitset<> (op->postReqBitset->to_ulong());
//        this->capColBitset = new boost::dynamic_bitset<> (op->capColBitset->to_ulong());
//        this->curCapColBitset = new boost::dynamic_bitset<> (op->curCapColBitset->to_ulong());
        this->postReqBitset = op->postReqBitset;
        this->capColBitset = op->capColBitset;
        this->curCapColBitset = op->curCapColBitset;
        this->extBitset = op->extBitset;
//        this->capColBitset = this->capColBitset = new boost::dynamic_bitset<> (op->capColBitset->to_ulong());
//        this->curCapColBitset = this->curCapColBitset = new boost::dynamic_bitset<> (op->curCapColBitset->to_ulong());
//        this->prereq = NULL;
//        this->postreq = NULL;
//        this->prereqP = NULL;
//        this->postreqP = NULL;
        if (!prereq.empty()) {
            this->prereq.assign(prereq.begin(), prereq.end());
        }
        if (!postreq.empty()) {
            this->postreq.assign(postreq.begin(), postreq.end());
        }
    } else {
        this->value = 0;
        this->position = 0;
        this->postOp = false;
        this->preOp = false;
        this->simOp = NULL;
//        this->capColBitset = new boost::dynamic_bitset<> (n);
////        this->capColBitset->reset();
//        this->prereq = NULL;
//        this->postreq = NULL;
//        this->prereqP = NULL;
//        this->postreqP = NULL;
    }
}

pillai_op::~pillai_op() {
//    delete postReqBitset;
//    delete capColBitset;
//    delete curCapColBitset;
//    delete prereq;
//    delete postreq;
//    delete postreqP;
//    delete prereqP;
    delete simOp;
}

unsigned short int pillai_op::getPosition() const {
    return position;
}

unsigned short int pillai_op::getValue() const {
    return value;
}

std::bitset<BITSET_SIZE>& pillai_op::getPostReqBitset() {
    return postReqBitset;
}

std::bitset<BITSET_SIZE>& pillai_op::getCapColBitset() {
    return capColBitset;
}

std::bitset<BITSET_SIZE>& pillai_op::getCurCapColBitset() {
    return curCapColBitset;
}
std::bitset<BITSET_SIZE>& pillai_op::getExtBitset() {
    return extBitset;
}

std::vector<unsigned short int>& pillai_op::getPostreq() {
    return postreq;
}

std::vector<pillai_op*>& pillai_op::getPostreqP() {
    return postreqP;
}

std::vector<pillai_op*>& pillai_op::getPrereqP() {
    return prereqP;
}

void pillai_op::setPrereqP(std::vector<pillai_op*> prereqP) {
    this->prereqP = prereqP;
}

void pillai_op::setPostreqP(std::vector<pillai_op*> postreqP) {
    this->postreqP = postreqP;
}

void pillai_op::setPostreq(std::vector<unsigned short int> postreq) {
    this->postreq = postreq;
}

std::vector<unsigned short int>& pillai_op::getPrereq() {
    return prereq;
}

void pillai_op::setPrereq(std::vector<unsigned short int> prereq) {
    this->prereq = prereq;
}

void pillai_op::setCurCapColBitset(std::bitset<BITSET_SIZE> newBitset) {
    (this)->curCapColBitset = newBitset;
}

//void pillai_op::setCurCapColBitset(std::bitset<BITSET_SIZE>* newBitset) {
//    (this)->curCapColBitset = newBitset;
//}

//void pillai_op::setCapColBitset(std::bitset<BITSET_SIZE> *newBitset) {
//    (this)->capColBitset = newBitset;
//}

void pillai_op::setPosition(unsigned short int position) {
    (this)->position = position;
}

void pillai_op::setValue(unsigned short int value) {
    (this->value) = value;
}

bool pillai_op::is_similar(const pillai_op& op) const {
    if (!(this->isNull()) && !(op.isNull() )) {
        if ((this->value) == (op.value)) {
            return true;
        }
    }
    return false;
}

bool pillai_op::operator==(const pillai_op& op) const {
    return ( (((this->value) == (op.value)) && ((this->position) == (op.position))) || ((op.position) == (0)) || ((this->position) == (0))) ? true : false;
}

bool pillai_op::operator!=(const pillai_op& op) const {
    return !(*this == op);
}

bool pillai_op::operator<(const pillai_op& op) const {
    return ( (this->value < op.value) || ((this->value == op.value) && (this->position < op.position) && (this->position != 0))) ? true : false;
}

bool pillai_op::isNull() const {
//    return ( (this == NULL) || (this->getPosition() == 0) || (this->getValue() == 0)) ? true : false;
    return ( (this == NULL) || (this->getValue() == 0)) ? true : false;
}

void pillai_op::print() const {
    std::cout << "(" << this->getValue() << ", " << this->getPosition() << "); ";
}

void pillai_op::printall() const {
    std::cout << "(" << this->getValue() << ", " << this->getPosition() << "); ";
    std::cout<<this->postReqBitset<<"; ";
    if (!this->prereq.empty()) {
        for (unsigned short int i = 0; i < this->prereq.size(); i++) {
            std::cout << (this->prereq)[i] << " ";
        }
    } else {
        std::cout << 0 << " ";
    }
    std::cout << "; ";
    if (!this->postreq.empty()) {
        for (unsigned short int i = 0; i < this->postreq.size(); i++) {
            std::cout << (this->postreq)[i] << " ";
        }
    } else {
        std::cout << 0;
    }
    std::cout<<"; ";
    std::cout<<this->capColBitset<<"; ";
    std::cout<<this->curCapColBitset<<"; ";
    std::cout << std::endl;
}

std::string pillai_op::print_toString() {
    std::stringstream str;
    str << "(" << this->getValue() << ", " << this->getPosition() << "); ";
    return str.str();
}

std::string pillai_op::printall_toString() {
    std::stringstream str;
    
    str << "(" << this->getValue() << ", " << this->getPosition() << "); ";
    str <<this->postReqBitset<<"; ";
    if (this->prereq.empty()) {
        for (unsigned short int i = 0; i < this->prereq.empty(); i++) {
            str << (this->prereq)[i] << " ";
        }
    } else {
        str << 0 << " ";
    }
    str << "; ";
    if (this->postreq.empty()) {
        for (unsigned short int i = 0; i < this->postreq.size(); i++) {
            str << (this->postreq)[i] << " ";
        }
    } else {
        str << 0;
    }
    str <<"; ";
    str <<this->capColBitset<<"; ";
    str <<this->curCapColBitset<<"; ";
    str << std::endl;
    
    return str.str();
}

bool pillai_op::isConnOp() const {
    return this->isPostOp() || this->isPreOp();
}

bool pillai_op::isPreOp() const {
    return this->preOp;
}

bool pillai_op::isPostOp() const {
    return this->postOp;
}

void pillai_op::setPreOp(bool preOp) {
    this->preOp = preOp;
}
    
void pillai_op::setPostOp(bool postOp) {
    this->postOp = postOp;
}

void pillai_op::setSimOp(pillai_op* simOp) {
    this->simOp = simOp;
}

pillai_op* pillai_op::getSimOp() const {
    return this->simOp;
}

//boost::dynamic_bitset<>& pillai_op::get_allPrereqopBitset() {
//    return _allPrereqopBitset;
//}
//
//boost::dynamic_bitset<>& pillai_op::get_allPostreqopBitset() {
//    return _allPostreqopBitset;
//}
