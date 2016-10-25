/*
 * pillai.cpp
 *
 *  Created on: Nov 5, 2011
 *      Author: addy
 */

#include <sstream>
#include <set>
#include <math.h>
#include <vector>

#include "pillai.h"
#include "iostream"
#include "ToolBox_Math.h"
#include "pillai_bt.h"
#include <stdio.h>

std::set<pillai_op*, setCompareEqual> pillai::_ops;
std::set<pillai_op*, setCompareEqual> pillai::_usedPOps;
unsigned short int pillai::_capCov;
bool pillai::_done;
std::bitset<BITSET_SIZE> pillai::_prereqopBitset;
std::bitset<BITSET_SIZE> pillai::_postreqopBitset;
std::bitset<BITSET_SIZE> pillai::_allPrereqopBitset;
std::bitset<BITSET_SIZE> pillai::_allPostreqopBitset;
std::bitset<BITSET_SIZE> pillai::_evenBitset;
std::bitset<BITSET_SIZE> pillai::_oddBitset;
std::bitset<BITSET_SIZE> pillai::_cenBitset;
std::vector<std::bitset<BITSET_SIZE> > pillai::_cenBitsetVector;
//std::vector<pillai_op*> pillai_bt::_solV;
std::set<pillai_op*, pillaiOperatorComparator> pillai_bt::_solV;

pillai::pillai() {
    _parent = NULL;
    _op = NULL;
    _depth = 0;
    _chOpType = 0;
    _maxC = 0;
    _evenC = 0;
    _oddC = 0;
    _simChainFlag = true;
}

pillai::pillai(const unsigned short int& n) {
    _state = std::bitset<BITSET_SIZE> (n);
    _state.set();
    _parent = NULL;
    _op = NULL;
    _applicable = std::set<pillai_op*, setCompareEqual > (_ops);
    _depth = 0;
    _chOpType = 0;
    _maxC = _capCov;
    _evenC = 0;
    _oddC = 0;
    _simChainFlag = true;
    
    _usedopBitset = std::bitset<BITSET_SIZE> (n);
    _usedopBitset.reset();
}

pillai::pillai(const std::bitset<BITSET_SIZE>& bitset) {
    _state = std::bitset<BITSET_SIZE> (bitset);
    _parent = NULL;
    _op = NULL;
    _applicable = std::set<pillai_op*, setCompareEqual > (_ops);
    _depth = 0;
    _chOpType = 0;
    _maxC = _capCov;
    _evenC = 0;
    _oddC = 0;
    _simChainFlag = true;
    
    _usedopBitset = std::bitset<BITSET_SIZE> (bitset.size());
    _usedopBitset.reset();
}

pillai::pillai(const pillai& pillai_state) {
    _state = std::bitset<BITSET_SIZE> (pillai_state._state);
    _parent = pillai_state._parent;
    _op = pillai_state._op;
    _applicable = std::set<pillai_op*, setCompareEqual > (pillai_state._applicable);
    _depth = pillai_state._depth;
    _chOpType = pillai_state._chOpType;
    _maxC = pillai_state._maxC;
    _evenC = pillai_state._evenC;
    _oddC = pillai_state._oddC;
    _simChainFlag = pillai_state._simChainFlag;
    //_usedopBitset = pillai_state._usedopBitset;
    
     _usedopBitset = std::bitset<BITSET_SIZE> (pillai_state._usedopBitset);

}

pillai::pillai(const pillai& pillai_state, const std::set<pillai_op*, setCompareEqual>& ops) {
    _state = std::bitset<BITSET_SIZE> (pillai_state._state);
    _parent = pillai_state._parent;
    _op = pillai_state._op;
    _applicable = std::set<pillai_op*, setCompareEqual > (ops);
    _depth = pillai_state._depth;
    _chOpType = pillai_state._chOpType;
    _maxC = pillai_state._maxC;
    _evenC = pillai_state._evenC;
    _oddC = pillai_state._oddC;
    _simChainFlag = pillai_state._simChainFlag;
    //_usedopBitset = pillai_state._usedopBitset;
     _usedopBitset = std::bitset<BITSET_SIZE> (pillai_state._usedopBitset);

}

pillai::pillai(const std::bitset<BITSET_SIZE>& state, const std::set<pillai_op*, setCompareEqual>& applicable , unsigned short int& depth) {
    _state = state;
    _parent = NULL;
    _op = NULL;
    _applicable = std::set<pillai_op*, setCompareEqual > (applicable);
    _depth = depth;
    _chOpType = 0;
    _maxC = 0;
    _evenC = 0;
    _oddC = 0;
    _simChainFlag = true;
}

pillai::~pillai() {
    _parent = NULL;
    _op = NULL;
    _applicable.clear();
    delete _op;
    delete _parent;
}

void pillai::set_state(const std::bitset<BITSET_SIZE>& pillaiBitset) {
    _state = pillaiBitset;
}

std::bitset<BITSET_SIZE>& pillai::get_state() {
    return this->_state;
}

bool pillai::operator==(const pillai& pillai) const {
    return (this->_state == pillai._state);
}

bool pillai::operator !=(const pillai& p) const {
    return !(*this == p);
}

const bool pillai::isEmpty() const {
//    return this->_state.empty();
    return this->_state.all();
}

void pillai::print() const {
    if(this != NULL)
        std::cout << "[" << _state << "]" << std::endl;
    else
        std::cout<<"NULL"<<std::endl;
}

std::string pillai::print_toString() {
    std::stringstream str;
    
    if(this != NULL)
        str << "[" << _state << "]" << std::endl;
    else
        str<<"NULL"<<std::endl;

    return str.str();
}

void pillai::print_all() const {
    if(this != NULL) {
        std::cout << "State: [" << _state << "]" << std::endl;
        std::cout<<"Parent:";
        if(_parent == NULL) {
            std::cout << " NULL"<<std::endl;
        }
        else {
            _parent->print();
        }
        std::cout<<"Operator:";
        if(_op == NULL) {
            std::cout << " NULL";
        }
        else {
            _op->print();
        }
        std::cout<<"\nApp_Operators:";
        for (std::set<pillai_op *, setCompareEqual>::iterator it = _applicable.begin(); it != _applicable.end(); ++it) {
            (*it)->print();
        }
        std::cout << "\nchOpType: " << _chOpType << "" << std::endl;
        std::cout << "depth: " << _depth << "" << std::endl;
        std::cout << "maxC: " << _maxC << "" << std::endl;
        std::cout << "evenC: " << _evenC << "" << std::endl;
        std::cout << "oddC: " << _oddC << "\n\n" << std::endl;
        
//        std::cout << "PostreqopBitset: [" << _postreqopBitset << "]" << std::endl;
//        std::cout << "PrereqopBitset: [" << _prereqopBitset << "]" << std::endl;
//        std::cout << "UsedopBitset: [" << _usedopBitset << "]" << std::endl;
        
    }
    else std::cout << "NULL" << _oddC << "\n\n" << std::endl;
}

std::string pillai::print_all_toString() {
    std::stringstream str;
    
    if(this != NULL) {
        str << "State: [" << _state << "]" << std::endl;
        str << "Parent:";
        if(_parent == NULL) {
            str << " NULL"<<std::endl;
        }
        else {
            str << _parent->print_toString();
        }
        str << "Operator:";
        if(_op == NULL) {
            str << " NULL";
        }
        else {
            str << _op->print_toString();
        }
        str << "\nApp_Operators:";
        for (std::set<pillai_op *, setCompareEqual>::iterator it = _applicable.begin(); it != _applicable.end(); ++it) {
            str << (*it)->print_toString();
        }
        str << "\nchOpType: " << _chOpType << "" << std::endl;
        str << "depth: " << _depth << "" << std::endl;
        str << "maxC: " << _maxC << "" << std::endl;
        str << "evenC: " << _evenC << "" << std::endl;
        str << "oddC: " << _oddC << "\n\n" << std::endl;
        
    }
    else str << "NULL" << _oddC << "\n\n" << std::endl;
    
    return str.str();
}

void pillai::print_sol() {
    // Collect operators for solution:
    std::vector<pillai_op*> solV;
    for (pillai *ps = this; ps->_parent!= NULL; ps = ps->_parent) {
        solV.push_back(ps->_op);
        ps->_op->print();
    }
    for(std::set<pillai_op*>::iterator it=pillai_bt::_solV.begin(); it!=pillai_bt::_solV.end(); ++it) {
        solV.push_back(*it);
        (*it)->print();
    } 
//    for (int i = pillai_bt::_solV.size()-1; i >= 0; i--) {
//        solV.push_back(pillai_bt::_solV.at(i));
//        pillai_bt::_solV.at(i)->print();
//    }
    std::cout<<std::endl;
    
    // Build state: normal operators
    std::vector<unsigned long int> stateVector(_state.size(),0);
    std::vector<pillai_op*> opVector;
    for (int i = solV.size()-1; i >= 0 ; i--) {
        for (unsigned int j = solV[i]->getPosition()-1; j < stateVector.size(); j+=solV[i]->getValue()) 
        {
            if(stateVector[j] == 0)
                stateVector[j] = solV[i]->getValue();
        }
        if(!solV[i]->getPostreqP().empty())
        {
            for (std::vector<pillai_op*>::iterator it = solV[i]->getPostreqP().begin(); it != solV[i]->getPostreqP().end(); it++) {
                for (unsigned int j = (*it)->getPosition()-1; j < stateVector.size(); j+=(*it)->getValue()) 
                {
                    opVector.insert(opVector.end(), (*it));
                }
            }
        }
    }
    
    // Build state2: prereq operators
    for (std::vector<pillai_op*>::iterator it = opVector.begin(); it != opVector.end(); it++) {
        for (unsigned int j = (*it)->getPosition()-1; j < stateVector.size(); j+=(*it)->getValue()) 
        {
            if(stateVector[j] == 0)
                stateVector[j] = (*it)->getValue();
        }
    }

    // Print:
    std::cout << "[";
    for (unsigned int j = 0; j < stateVector.size(); j++) {
            std::cout << stateVector[j] << " ";
    }
    std::cout << "]" << std::endl;
    this->print_all();
    
    //pillai_bt::_solV.clear();
}

std::string pillai::print_sol_toString() {
    std::stringstream str;
    
    // Collect operators for solution:
    std::vector<pillai_op*> solV;
    for (pillai *ps = this; ps->_parent!= NULL; ps = ps->_parent) {
        solV.push_back(ps->_op);
        str << ps->_op->print_toString() << " ";
    }
    for(std::set<pillai_op*>::iterator it=pillai_bt::_solV.begin(); it!=pillai_bt::_solV.end(); ++it) {
        solV.push_back(*it);
        str << (*it)->print_toString() << " ";
    } 
//    for (int i = pillai_bt::_solV.size()-1; i >= 0; i--) {
//        solV.push_back(pillai_bt::_solV.at(i));
//        str << pillai_bt::_solV.at(i)->print_toString() << " ";
//    }
    str << std::endl;
    
    // Build state: normal operators
    std::vector<unsigned long int> stateVector(_state.size(),0);
    std::vector<pillai_op*> opVector;
    for (int i = solV.size()-1; i >= 0 ; i--) {
        for (unsigned int j = solV[i]->getPosition()-1; j < stateVector.size(); j+=solV[i]->getValue()) 
        {
            if(stateVector[j] == 0)
                stateVector[j] = solV[i]->getValue();
        }
        if(!solV[i]->getPostreqP().empty())
        {
            for (std::vector<pillai_op*>::iterator it = solV[i]->getPostreqP().begin(); it != solV[i]->getPostreqP().end(); it++) {
                for (unsigned int j = (*it)->getPosition()-1; j < stateVector.size(); j+=(*it)->getValue()) 
                {
                    opVector.insert(opVector.end(), (*it));
                }
            }
        }
    }
    
    // Build state2: prereq operators
    for (std::vector<pillai_op*>::iterator it = opVector.begin(); it != opVector.end(); it++) {
        for (unsigned int j = (*it)->getPosition()-1; j < stateVector.size(); j+=(*it)->getValue()) 
        {
            if(stateVector[j] == 0)
                stateVector[j] = (*it)->getValue();
        }
    }

    // Print:
    str << "[";
    for (unsigned int j = 0; j < stateVector.size(); j++) {
            str << stateVector[j] << " ";
    }
    str << "]" << std::endl;
    str << this->print_all_toString();
    
    pillai_bt::_solV.clear();
    
    return str.str();
}

std::string pillai::statePrintToString() {
    std::stringstream str;
    
    // Collect operators for solution:
    std::vector<pillai_op*> solV;
    for (pillai *ps = this; ps->_parent!= NULL; ps = ps->_parent) {
        solV.push_back(ps->_op);
    }
    
    // Build state: normal operators
    std::vector<unsigned long int> stateVector(_state.size(),0);
    std::vector<pillai_op*> opVector;
    for (int i = solV.size()-1; i >= 0 ; i--) {
        for (unsigned int j = solV[i]->getPosition()-1; j < stateVector.size(); j+=solV[i]->getValue()) 
        {
            if(stateVector[j] == 0)
                stateVector[j] = solV[i]->getValue();
        }
        if(!solV[i]->getPostreqP().empty())
        {
            for (std::vector<pillai_op*>::iterator it = solV[i]->getPostreqP().begin(); it != solV[i]->getPostreqP().end(); it++) {
                for (unsigned int j = (*it)->getPosition()-1; j < stateVector.size(); j+=(*it)->getValue()) 
                {
                    opVector.insert(opVector.end(), (*it));
                }
            }
        }
    }
    
    // Build state2: prereq operators
    for (std::vector<pillai_op*>::iterator it = opVector.begin(); it != opVector.end(); it++) {
        for (unsigned int j = (*it)->getPosition()-1; j < stateVector.size(); j+=(*it)->getValue()) 
        {
            if(stateVector[j] == 0)
                stateVector[j] = (*it)->getValue();
        }
    }

    // Print:
    for (unsigned int j = 0; j < stateVector.size(); j++) {
            str << stateVector[j] << " ";
    }
    
    return str.str();
}

pillai* pillai::init_pillai(const unsigned short int& n, std::vector<unsigned short int> *primesV, const unsigned short int& d) {
    unsigned short int *a, *b, nprime=0, limit_f = 1, limit_s = 1, unicFlag = 0;
    _done = false;

    // Generate adequate primes if needed.
    if (primesV->empty()) {
        a = TB_Math::gGraterPrimes(d, n);
        primesV->assign(a, a + n);
  
     
        if (d > 1) {
            b = TB_Math::gSmallerPrimes(d + 1);
            unsigned short int exMaxArray [b[0] + 1], exCurArray [b[0] + 1], prod = 1;
            exMaxArray[0] = b[0];
            exCurArray[0] = b[0];

            // Compute max primes' extensions 
            for (unsigned short int r = 1; r <= b[0]; ++r) {
                for (unsigned short int ex = 1;; ex++) {
                    if ((nprime = powl(b[r], ex)) > d) {
                        
                        exMaxArray[r] = ex;
                        exCurArray[r] = 0;
                        prod *= (ex + 1);

                        //primesV->insert(primesV->begin(), nprime);
                        break;
                    }
                }
            }

            // compute all poss "multiply ext. combination"
            unsigned short int r = 1;
            std::vector<unsigned short int> nPrimeVector(prod, 0);
            for (unsigned short int finishFlag = 1; finishFlag != 0;) {
                if (exCurArray[r] < exMaxArray[r] && r <= b[0]) {
                    exCurArray[r]++;
                } else {
                    ++r;
                    if (r <= b[0] && exCurArray[r - 1] == exMaxArray[r - 1] && exCurArray[r] < exMaxArray[r]) {
                        exCurArray[r]++;
                        while (r > 1) {
                            --r;
                            exCurArray[r] = 0;
                        }

                    } else if (r <= b[0] && exCurArray[r - 1] == exMaxArray[r - 1] && exCurArray[r] == exMaxArray[r]) continue;
                    else break;

                }

                // compute next prime
                nprime = 1;

                for (unsigned short int t = 1; t <= b[0]; ++t) { 
                    //std::cout<<b[t]<<" "<<exCurArray[t]<<std::endl; //***
//                    std::cout<<nprime<<std::endl; //***
                    nprime = nprime * powl(b[t], exCurArray[t]);
                    //std::cout<<nprime<<std::endl; //***
                }
//std::cout<<":"<<nprime<<std::endl; //***
                // search significant prime:
                if (nprime > d) {

                    unsigned short int i, pieceOfPrime = 0;
                    for (i = 0; i < nPrimeVector.size() && nPrimeVector[i] != 0 && nprime % nPrimeVector[i] != 0 && nPrimeVector[i] % nprime != 0 && nprime <= n; i++);
                                    
                    if (nPrimeVector[i] == 0) {
                        nPrimeVector[i] = nprime;
                        pieceOfPrime++;

                    } else if (nPrimeVector[i] % nprime == 0) {
                        nPrimeVector[i] = nprime;

                    }
                }
            }

            // add significant prime to prime set
            for (unsigned short int i = 0; i < nPrimeVector.size() && nPrimeVector[i] != 0; i++) {
                primesV->insert(primesV->begin(), nPrimeVector[i]);
            }

            // free memory
            delete [] b;
        }
    }

    // free memory
    delete [] a;
    
    //zeroBitset initialization
    //pillaiai_bt::zeroBitset = pillaiai_bt::bitsetInit(n, 0, 1);
    //_zeroBitset = boost::dynamic_bitset<>(n);
    //_zeroBitset.set();

    //usedopBitset initialization
    //pillaiai_bt::usedopBitset = pillaiai_bt::bitsetInit(n, 0, 0);
//    _usedopBitset = boost::dynamic_bitset<>(n);
//    _usedopBitset.reset();

    //prereqopBitset initialization
    //pillaiai_bt::prereqopBitset = pillaiai_bt::bitsetInit(n, 0, 0);
//    _prereqopBitset = boost::dynamic_bitset<>(n);
    _prereqopBitset = std::bitset<BITSET_SIZE>();
    //_prereqopBitset.reset();

    //postreqopBitset initialization
    //pillaiai_bt::postreqopBitset = pillaiai_bt::bitsetInit(n, 0, 0);
//    _postreqopBitset = boost::dynamic_bitset<>(n);
    _postreqopBitset = std::bitset<BITSET_SIZE>();
    //_postreqopBitset.reset();

    //evenBitset initialization
    //pillaiai_bt::evenBitset = pillaiai_bt::bitsetInit(n, 1, 2);
    bitset_init_set(_evenBitset, n, 1, 2);

    //oddBitset initialization
    //pillaiai_bt::oddBitset = pillaiai_bt::bitsetInit(n, 0, 2);
    bitset_init_set(_oddBitset, n, 0, 2);

    //class _ops initialization
    _ops = std::set<pillai_op*, setCompareEqual > ();

    //Generate all possible operators to operators set of class
    //pillai *newPillaiS = new pillai(n);
//    gen_operators(n, d, primesV, newPillaiS->_prereqopBitset, newPillaiS->_postreqopBitset);
   // for (int i = 0; i < primesV->size(); i++) {
       //std::cout<<primesV->at()<<std::endl;    }

    gen_operators(n, d, primesV, _prereqopBitset, _postreqopBitset);
    //build symmetry network:
    gen_symmetry();
//    pillai_op::get_allPostreqopBitset() = _postreqopBitset;
//    pillai_op::get_allPrereqopBitset() = _prereqopBitset;
    _allPostreqopBitset = _postreqopBitset;
    _allPrereqopBitset = _prereqopBitset;
    
//    int sum = 0;
//    for (std::set<pillai_op*>::iterator it = _ops.begin(); it != _ops.end(); it++)
//    {
//        (*it)->printall();
//        if((*it)->getValue()<BITSET_SIZE && (*it)->getPosition()==1)
//            sum++;
//    }std::cout<<std::endl;
//    std::cout<<"SUM="<<sum<<std::endl;
//    std::cout<<BITSET_SIZE/5<<std::endl;
//    pillai_op *temp = new pillai_op(9,0,n);
//    temp->printall();
//    std::cout<<"test: "<<(_ops.find(temp) != _ops.end())<<std::endl;
//     *temp = new pillai_op(9,1,n);
//    temp->printall();
//    std::cout<<"test: "<<(_ops.find(temp) != _ops.end())<<std::endl;
//     *temp = new pillai_op(6,0,n);
//    temp->printall();
//    std::cout<<"test: "<<(_ops.find(temp) != _ops.end())<<std::endl;
//     *temp = new pillai_op(6,1,n);
//    temp->printall();
//    (*(_ops.find(temp)))->printall();
//    std::cout<<"test: "<<(_ops.find(temp) != _ops.end())<<std::endl;
    
    //cenBitset initialization
    _cenBitset.set();
 
//    _cenBitsetVector.insert(_cenBitsetVector.end(),_cenBitset);
//    for (int i = 0; i < floor(BITSET_SIZE/2)-1; i++) {
//        _cenBitset.reset(i);
//        _cenBitset.reset(BITSET_SIZE-1-i);
//        _cenBitsetVector.insert(_cenBitsetVector.end(),_cenBitset);
////        _cenBitsetVector.insert(_cenBitsetVector.begin(),_cenBitset);
//    }
//    for(std::vector<std::bitset<BITSET_SIZE> >::iterator it = _cenBitsetVector.begin(); it != _cenBitsetVector.end(); ++it)
//        std::cout<<*it<<std::endl;
    
    _cenBitset.set();
    double div = 5, diff = 0.0;
    for (int i = 0; i < floor(BITSET_SIZE/div-diff); i++) {
//    for (int i = 0; i < sum; i++) {
        _cenBitset.reset(i);
        _cenBitset.reset(BITSET_SIZE-1-i);
    }
    
//    for (int i = BITSET_SIZE-floor(BITSET_SIZE/div-diff); i < BITSET_SIZE; i++) {
//        _cenBitset.reset(i);
//    }
//    std::cout<<_cenBitset<<std::endl;

    //Calculate capable of operators covering:
    _capCov = cap_cal(n, _ops);
   /* int flag = 0;
    for (std::set<pillai_op*>::iterator it = _ops.begin(); it != _ops.end(); it++)
    {
        if(flag != (*it)->getValue()) {
           (*it)->printall();
           flag = (*it)->getValue();
           std::cout<<std::endl;
        }
//        std::cout<<(*it)->isPostOp()<<std::endl;
//        std::cout<<(*it)->isPreOp()<<std::endl;
////        std::cout<<*(*it)->getCapColBitset()<<std::endl;
////        std::cout<<*(*it)->getCurCapColBitset()<<std::endl;
    }std::cout<<std::endl;*/

//    return new pillai(*newPillaiS, _ops);
    return new pillai(n);
}

//void pillai::bitset_init_set(boost::dynamic_bitset<>& tempBitset, const unsigned short int& n, const unsigned short int& startPos, const unsigned short int& type) {
void pillai::bitset_init_set(std::bitset<BITSET_SIZE>& tempBitset, const unsigned short int& n, const unsigned short int& startPos, const unsigned short int& type) {
//    tempBitset = boost::dynamic_bitset<>(n);
    tempBitset = std::bitset<BITSET_SIZE>(n);
    tempBitset.reset();

    for (unsigned short int i = startPos; type != 0 && i < n; i += type) {
        tempBitset.set(i);
    }
}

//void pillai::gen_operators(const unsigned short int& n, const unsigned short int& d, std::vector<unsigned short int> *primesV, boost::dynamic_bitset<>& prereqopBitset, boost::dynamic_bitset<>& postreqopBitset) {
void pillai::gen_operators(const unsigned short int& n, const unsigned short int& d, std::vector<unsigned short int> *primesV, std::bitset<BITSET_SIZE>& prereqopBitset, std::bitset<BITSET_SIZE>& postreqopBitset) {
  
    bool extFlag = 0;
    std::bitset<BITSET_SIZE> tempExtBitset, preTempExtBitset;
    //_ops
    for (unsigned short int pr = 0; pr < (unsigned short int) primesV->size(); ++pr) {    
        //not relevant primes
        if ((*primesV)[pr] >= n) {    
            continue;
        }
    
//        boost::dynamic_bitset<> tempPostReqBitset(n);
        std::bitset<BITSET_SIZE> tempPostReqBitset;
        //relevant primes positions
        for (int pos = 1; pos <= (*primesV)[pr]; ++pos) {
            if ((n >= ((*primesV)[pr] + pos)) /*&& (0 <= ((*primesV)[pr] - pos))*/) {
                if(n < ((*primesV)[pr] + (*primesV)[pr])) {
                    extFlag = 1;
                }
                
                if (!TB_Math::isPrime((*primesV)[pr])) {
                    //std::cout<<(*primesV)[pr]<<std::endl;

                    // PostReq: find the core prime(s)
                    for (unsigned short int di = 2; di <= d; di++) {

                        unsigned short int ei = 2, postPrime = powl(di, ei);
                        for (; postPrime < (*primesV)[pr]; ei++, postPrime = powl(di, ei));

                        //relevant extension is found for this prime core:
                        if (postPrime == (*primesV)[pr]) {
                            //std::cout<<"PostPrime: "<<postPrime<< " " << di<<" "<<ei << ""<<std::endl;
                            std::vector<unsigned short int> *temp_PostPreC = new std::vector<unsigned short int>();

                            //find connected pre prime for founded prime core
                            tempPostReqBitset.reset();
                            for (unsigned short int pre = 0, count = 1; pre < (unsigned short int) primesV->size(); ++pre) {
                                //Connected PreReq: search successful
                                if ((*primesV)[pre] % di == 0 && (*primesV)[pre] != (*primesV)[pr]) {
                                    //std::cout<<"PrePrime: "<<(*primesV)[pre]<<std::endl;
                                    temp_PostPreC->resize(count, (*primesV)[pre]);
                                    count++;
                                    //(*temp_PostPreC)[count-1] = (*primesV)[pre];

                                    //std::cout<<"PostPrime: "<<(*primesV)[pr]<< " PrePrime " << (*primesV)[pre]<<std::endl;

                                    pillai_op *op = NULL;

                                    //Reverse connection:
                                    for (std::set<pillai_op*, setCompareEqual>::iterator it = _ops.begin(); it != _ops.end(); it++) {
                                        if ((*it)->getValue() == (*primesV)[pre]) {
                                            op = *it;
                                            //tempPostReqBitset.set((*primesV)[pre],1);
                                            //std::cout<<"TTT: "<<tempPostReqBitset<<std::endl;
                                            //op->printall();
                                            break;
                                        }
                                        //(*it)->printall();
                                    }

                                    //Create new PreOperator
                                    if (op == NULL) {
                                        //std::cout<<"TTTTT: "<<(*primesV)[pre]<<std::endl;
                                        std::vector<unsigned short int> *temp_PrePostC = new std::vector<unsigned short int>(2);
                                        (*temp_PrePostC)[0] = (*primesV)[pr];
//                                        add_ops(new pillai_op((*primesV)[pre], 0, n, temp_PrePostC, NULL, temp_PrePostC->size(), 0));
                                        if(n >= ((*primesV)[pr] + (*primesV)[pr])) {

                                            add_ops(new pillai_op((*primesV)[pre], 0, false, true, tempPostReqBitset.set((*primesV)[pr],1), n, *temp_PrePostC, std::vector<unsigned short int>(), temp_PrePostC->size(), 0));
                                        }
                                        else {
                                            // Identify extension positions:
                                            if(pos == 1) {
                                                tempExtBitset.reset();
                                                for (int p = n-(*primesV)[pr]+1; p <= (*primesV)[pr]; p++) {

                                                    tempExtBitset.set(p-1);
                                                }
                                                tempExtBitset ^= preTempExtBitset;
                                                preTempExtBitset |= tempExtBitset;
                                            }
                                           
                                            add_ops(new pillai_op((*primesV)[pre], 0, false, true, tempPostReqBitset.set((*primesV)[pr],1), n, *temp_PrePostC, std::vector<unsigned short int>(), temp_PrePostC->size(), 0, tempExtBitset));
                                        }
                                        prereqopBitset.set((*primesV)[pre]);

                                        delete temp_PrePostC;
                                    }//Refresh existing PreOperator
                                    else {
                                        //std::cout<<"TTTTTTTTTTTTTTT: "<<(*primesV)[pr]<<std::endl;
                                        //std::cout<<"TTTTTTTTTTTTTTT: "<<(*primesV)[pre]<<std::endl;
                                        // Check the reverse connection is alive
                                        unsigned short j = 0;
                                        for (; j < op->getPrereq().size(); j++) { 
                                            if (op->getPrereq().at(j) == (*primesV)[pr]) {
                                                break;
                                            }
                                        }
                                         
                                        // if not alive build it
                                        if (j == op->getPrereq().size()) {
                                            op->getPrereq().resize(op->getPrereq().size() + 1, (*primesV)[pr]);
                                            op->getPrereqP().resize(op->getPrereq().size() + 1, NULL);
 
                                            op->getPostReqBitset().set((*primesV)[pr], 1);
                                        }
                                    }
                                }
                            }
                            //std::cout<<(*primesV)[pr]<<" "<< temp_PostPreC->size()<<" "<<temp_PostPreC->at(0)<<std::endl;
                            if(n >= ((*primesV)[pr] + (*primesV)[pr])) {
                                add_ops(new pillai_op((*primesV)[pr], pos, true, false, n, std::vector<unsigned short int>(), *temp_PostPreC, 0, temp_PostPreC->size()));
                            }
                            else {
                                // Identify extension positions:
                                if(pos == 1) {
                                    tempExtBitset.reset();
                                    for (int p = n-(*primesV)[pr]+1; p <= (*primesV)[pr]; p++) {
 
                                        tempExtBitset.set(p-1);
                                    }
                                    tempExtBitset ^= preTempExtBitset;
                                    preTempExtBitset |= tempExtBitset;
                                }
                                
                                add_ops(new pillai_op((*primesV)[pr], pos, true, false, n, std::vector<unsigned short int>(), *temp_PostPreC, 0, temp_PostPreC->size(),tempExtBitset));
                            }

                            postreqopBitset.set((*primesV)[pr]);
                            delete temp_PostPreC;
                        }

                    }

                } else {
                    if(n >= ((*primesV)[pr] + (*primesV)[pr])) {
                        add_ops(new pillai_op((*primesV)[pr], pos, false, false, n));
                    }
                    else {
                        // Identify extension positions:
                        if(pos == 1) {
                            tempExtBitset.reset();
                            for (int p = n-(*primesV)[pr]+1; p <= (*primesV)[pr]; p++) {
     
                                tempExtBitset.set(p-1);
                            }
                            tempExtBitset ^= preTempExtBitset;
                            preTempExtBitset |= tempExtBitset;
                        }

                        add_ops(new pillai_op((*primesV)[pr], pos, false, false, n, tempExtBitset));
                    }
                }
            } else {
                continue;
            }
        }
    }

//    int flag = 0;                                
//    for (std::set<pillai_op*>::iterator it = _ops.begin(); it != _ops.end(); it++)
//    {
//        if(flag != (*it)->getValue()) {
//           (*it)->printall();
//           flag = (*it)->getValue();
//           std::cout<<std::endl;
//        }
//    }
    
    //create link between PostReq and PreReq operators
    for (std::set<pillai_op*, setCompareEqual>::iterator it = _ops.begin(); it != _ops.end(); ++it) {
        //(*it)->printall();
        
        if (!(*it)->getPostreq().empty()) {
            //                        (*it)->printall();
            for (unsigned short int i = 0; (i < (*it)->getPostreq().size()) && ((*it)->getPostreq().at(i) != 0); i++) {
                //                //std::cout<<(*it)->getPostreq()->size()<<" check: "<<(*it)->getPostreq()->at(i)<<std::endl;
                //(*it)->getPostreqP().at(i) = NULL;
                (*it)->getPostreqP().insert((*it)->getPostreqP().end(),NULL);
                for (std::set<pillai_op*, setCompareEqual>::iterator itp = _ops.begin(); itp != _ops.end(); ++itp) {
                    if ((*itp)->getValue() == (*it)->getPostreq().at(i)) {
                        //(*it)->getPostreqP().assign(i, *itp); //(*it)->printall(); //(*it)->getPostreqP().insert((*it)->getPostreqP().end(), *itp);
                        (*it)->getPostreqP().assign(i, *itp);
                    }
                }
            }
            continue;
        }
    }
}

void pillai::add_ops(pillai_op* op) {
    pillai::_ops.insert(op);
}

/**
 * Calculate the applicable operators max cover capacity.
 * @param n is a length of state
 * @param ops is a pointer to applicable operators set.
 * @return max cover capacity number.
 */
unsigned short int pillai::cap_cal(const unsigned short int& n, const std::set<pillai_op*, setCompareEqual>& ops) {
    unsigned short int sum = 0, flag = 0;

    //    boost::dynamic_bitset<> tempBitset = boost::dynamic_bitset<>(n);
    std::bitset<BITSET_SIZE> tempBitset;
    tempBitset.set();
    //    boost::dynamic_bitset<> patternBitset = boost::dynamic_bitset<>(n);
    std::bitset<BITSET_SIZE> patternBitset;
    patternBitset.set();

    //    std::cout<<ops.size()<<std::endl;int count =1;
    //    for (std::set<pillai_op*, setCompareEqual>::iterator it = ops.begin(); it != ops.end(); ++it) {
    ////        (*it)->printall();
    //        std::cout<<(*it)->getCapColBitset()->size()<<std::endl;
    //        std::cout<<count++<<std::endl;
    //    }
    for (std::set<pillai_op*, setCompareEqual>::iterator it = ops.begin(); it != ops.end(); ++it) {
        //special operators (6<=2*3)
        //        (*it)->printall();
        //        if ((*it)->getPosition() == 0) { 
        //
        //            unsigned short int tempSize = (unsigned short int) ceil((double) n / (double) (*it)->getValue());
        //            sum += tempSize;
        //            (*it)->getCapColBitset()->set();
        //            (*it)->getCurCapColBitset()->set();
        //
        //            continue;
        //        }

        //normal operators
        for (unsigned int i = ((*it)->getPosition() == 0) ? 1 : (*it)->getPosition(); (i <= n) && (i <= (*it)->getCapColBitset().size()); i += (*it)->getValue()) {
            (*it)->getCapColBitset().set(i - 1);
            (*it)->getCurCapColBitset().set(i - 1);
        }

        if ((flag == 0) || (flag != (*it)->getValue())) {
            flag = (*it)->getValue();
            tempBitset = patternBitset & (*it)->getCapColBitset();
            sum += tempBitset.count();
        }

    }
    //    std::cout<<"H"<<std::endl;
    return sum;
}

const bool pillai::is_null() const {
    //    return ((this == NULL) || (_state.empty()));
    return ((this == NULL));
}

const bool pillai::is_finish() const {
    return _state.count() == 0;
}

void pillai::update_op_bitset() {

    unsigned short int flag = 0, max = 0, maxCC = 0, maxE = 0, maxEC = 0, maxO = 0, maxOC = 0, sumCapCal = 0;

    this->_maxC = 0;
    this->_maxCC = 0;
    this->_evenC = 0;
    this->_oddC = 0;

    //     boost::dynamic_bitset<> temp, tempEven, tempOdd;
    std::bitset<BITSET_SIZE> temp, tempEven, tempOdd, tempEvenBC, tempOddBC;

    //refresh values:
    for (std::set<pillai_op*, setCompareEqual>::iterator fit, it = this->_applicable.begin(); it != this->_applicable.end(); it++) {
        sumCapCal = 0;
        //        temp.clear();
        temp.reset();

        //special operators (6<=2*3)
        if ((*it)->isPreOp()) {
            //std::cout<<(*it)->getPostReqBitset()<<std::endl;
            //check pre usage:
            unsigned int i = 0, count = 0, dArray[4] = {0};
            //            while ((i = (*it)->getPostReqBitset()->_Find_next(i)) != -1) {
            //i = (*it)->getPostReqBitset()._Find_next(i);
            //(*it)->print();

            while ((i = (*it)->getPostReqBitset()._Find_next(i))!= (*it)->getPostReqBitset().size()) {
                //i = (*it)->getPostReqBitset()._Find_next(i);
                //std::cout<<i<<std::endl;
                //(new pillai_op(i, 0, true, false, this->_state.size()))->print();
                if ((fit = _usedPOps.find(new pillai_op(i, 0, true, false, this->_state.size()))) == _usedPOps.end()) {
                    break;
                } else {

                    //determine two determiners:
                    count++;
                    dArray[count - 1] = (*fit)->getValue();
                    dArray[count - 1 + 2] = (*fit)->getPosition();
                }
            }

//std::cout<<(*it)->getPostReqBitset().size()<<std::endl;
            //refresh position:
            if (count == 2) {
                count = 0;
                //std::cout<<dArray[2]<<std::endl;
                (*it)->setPosition(((dArray[2] == dArray[3]) ? dArray[2] : chinRemainderTheo((*it)->getValue(), dArray[0], dArray[1], dArray[2], dArray[3])));

                //update bitset:
                temp = ((*it)->getCapColBitset() << (*it)->getPosition() - 1) & this->_state;
                //                (*it)->setCurCapColBitset(new std::bitset<BITSET_SIZE>(temp));
                (*it)->setCurCapColBitset(temp);

            } else {// position not exist yet
                temp = ((*it)->getCapColBitset() & this->_state);
                (*it)->setPosition(0);
            }
            tempEven = temp&_evenBitset;
            tempOdd = temp&_oddBitset;

            if (((sumCapCal = temp.count()) == 0) /*&& (this->_op->getValue() != (*it)->getValue())*/) {
                _applicable.erase(it);
                continue;
            }
            this->_maxC += sumCapCal;//reduced sized should check
            this->_evenC += tempEven.count();//reduced sized should check
            this->_oddC += tempOdd.count();//reduced sized should check
            
            //for centralShieve:
            std::bitset<BITSET_SIZE> bitsetCS_maxC(temp&_cenBitset); //decl pos?? ->set()
            //std::cout<<this->get_op()->getValue()<<std::endl;
//            std::bitset<BITSET_SIZE> bitsetCS_maxC(temp&_cenBitsetVector[this->get_op()->isNull()?0:this->get_op()->getValue()]);
//            std::bitset<BITSET_SIZE> bitsetCS_maxC(temp&_cenBitsetVector[this->get_op()->isNull()||this->get_op()->getValue()<16?16:this->get_op()->getValue()]);
//            std::bitset<BITSET_SIZE> bitsetCS_maxC(temp&_cenBitsetVector[16]);
//            tempEvenBC = bitsetCS_maxC&_evenBitset;
//            tempOddBC = bitsetCS_maxC&_oddBitset;
//       
            this->_maxCC += bitsetCS_maxC.count();//reduced sized should check
//            this->_evenCC += tempEvenBC.count();//reduced sized should check
//            this->_oddCC += tempOddBC.count();//reduced sized should check

            continue;
        }

        //normal operators    
        //std::bitset<BITSET_SIZE> 
                temp = (*it)->getCapColBitset() & this->_state;
        //std::bitset<BITSET_SIZE> 
                tempEven = temp&_evenBitset;
        //std::bitset<BITSET_SIZE> 
                tempOdd = temp&_oddBitset;

        if (((sumCapCal = temp.count()) == 0) /*&& (this->_op->getValue() != (*it)->getValue())*/) {
            _applicable.erase(it);
            continue;
        }
        
//        //for centralShieve:
        std::bitset<BITSET_SIZE> bitsetCS_maxC(temp&_cenBitset); //decl pos?? ->set()
//        std::bitset<BITSET_SIZE> bitsetCS_maxC(temp&_cenBitsetVector[this->get_op()->isNull()?0:this->get_op()->getValue()]);
//          std::bitset<BITSET_SIZE> bitsetCS_maxC(temp&_cenBitsetVector[this->get_op()->isNull()||this->get_op()->getValue()<16?16:this->get_op()->getValue()]);
//          std::bitset<BITSET_SIZE> bitsetCS_maxC(temp&_cenBitsetVector[16]);
//        tempEvenBC = bitsetCS_maxC&_evenBitset;
//        tempOddBC = bitsetCS_maxC&_oddBitset;

        unsigned short int tempC = sumCapCal;
        unsigned short int tempEvenC = tempEven.count();
        unsigned short int tempOddC = tempOdd.count();
        
        unsigned short int tempCC = bitsetCS_maxC.count();
//        unsigned short int tempEvenCC = tempEvenBC.count();
//        unsigned short int tempOddCC = tempOddBC.count();

        //Similar operators skip help by flag:
        if (flag != (*it)->getValue()) {

            max = tempC;
            this->_maxC += max;
            
            maxCC = tempCC;
            this->_maxCC += maxCC;

            maxE = tempEvenC;
            this->_evenC += maxE;
            
//            maxEC = tempEvenCC;
//            this->_evenCC += maxEC;

            maxO = tempOddC;
            this->_oddC += maxO;
            
//            maxOC = tempOddC;
//            this->_oddCC += maxOC;

            flag = (*it)->getValue();

            //Find max between similar types:
        } else {

            //redefine max , and correct the value:
            if (max < tempC) {
                this->_maxC -= max;

                max = tempC;
                this->_maxC += max;
            }
            
            if (maxCC < tempCC) {
                this->_maxCC -= maxCC;

                maxCC = tempCC;
                this->_maxCC += maxCC;
            }

            if (maxE < tempEvenC) {
                this->_evenC -= maxE;

                maxE = tempEvenC;
                this->_evenC += maxE;
            }
            
//            if (maxEC < tempEvenCC) {
//                this->_evenCC -= maxEC;
//
//                maxEC = tempEvenCC;
//                this->_evenCC += maxEC;
//            }

            if (maxO < tempOddC) {
                this->_oddC -= maxO;

                maxO = tempOddC;
                this->_oddC += maxO;
            }
            
//            if (maxOC < tempOddCC) {
//                this->_oddCC -= maxOC;
//
//                maxOC = tempOddCC;
//                this->_oddCC += maxOC;
//            }
        }
    }
}

const std::set<pillai_op*, setCompareEqual>& pillai::get_applicable() const {
    return _applicable;
}

pillai_op *pillai::choose_op() {

    pillai_op* op = NULL;
    unsigned short int maxCapCov = 0;
    for (std::set<pillai_op*, setCompareEqual>::iterator it = this->_applicable.begin(); it != this->_applicable.end(); ++it) {
        if (this->op_apply_req(*it)) {
            //op = (*it);
            op = ((std::bitset<BITSET_SIZE>)((*it)->getExtBitset() & this->get_state())).count() == 0 ? (*it) : NULL;
            break;

            //Antisimm. shieve
            //            if((maxCapCov < (*it)->getCurCapColBitset()->count()) || op->isConnOp()) {
            //                op = (*it);
            //                maxCapCov = (*it)->getCurCapColBitset()->count();
            //                if(op->isConnOp()) break;
            //            }
            //            else if(maxCapCov >= (*it)->getCapColBitset()->count()) {
            //                break;
            //            }
        }
    }
    
    return op;
}

bool pillai::op_apply_req(pillai_op* op) {
    if (((op->getPosition() != 0) &&
            ((this->_chOpType == 0) || (this->_chOpType == op->getValue())) &&
                     //(((_postreqopBitset.count() == 0) || _postreqopBitset.test(op->getValue()) || _prereqopBitset.test(op->getValue()))) &&
            //((_postreqopBitset.count() == 0) || op->isConnOp()))
            (((_postreqopBitset.count() == 0) && (_prereqopBitset.count() == 0)) || op->isConnOp()))
            ) {
        return true;
    } else {//pre_operator
        return false;
    }
}

std::bitset<BITSET_SIZE>& pillai::get_evenBitset() {
    return _evenBitset;
}

std::bitset<BITSET_SIZE>& pillai::get_oddBitset() {
    return _oddBitset;
}

std::bitset<BITSET_SIZE>& pillai::get_cenBitset() {
    return _cenBitset;
}

unsigned short int& pillai::get_maxC() {
    return _maxC;
}

unsigned short int& pillai::get_maxCC() {
    return _maxCC;
}

unsigned short int& pillai::get_evenC() {
    return _evenC;
}

unsigned short int& pillai::get_evenCC() {
    return _evenCC;
}

unsigned short int& pillai::get_oddC() {
    return _oddC;
}

unsigned short int& pillai::get_oddCC() {
    return _oddCC;
}

pillai* pillai::apply_op(pillai_op *newOp) {

    pillai* npbt = new pillai(*this);
    for (unsigned short int i = newOp->getPosition(); i <= npbt->get_state().size(); i += newOp->getValue()) {
        if ((npbt->get_state())[i - 1] == 1) {
            npbt->_state.reset(i - 1);
        }
    }
    
    //setup new node:
    npbt->_parent = this;
    npbt->_op = newOp;
    npbt->_depth = ((this->_depth) + 1);
    npbt->_chOpType = 0;
    this->_chOpType = newOp->getValue();
    npbt->_usedopBitset.set(npbt->_op->getValue());

    npbt->remove_sim_ops(newOp);
    //npbt->_parent->remove_nsim_ops(newOp);
    npbt->_parent->_applicable.erase(newOp);
    npbt->_applicable.erase(newOp);

    //Is it a post operator? => test postreqopBitset feature:
    if ((_postreqopBitset.test(npbt->_op->getValue()))) {
        _postreqopBitset.reset(npbt->_op->getValue());
        _usedPOps.insert(_usedPOps.end(), newOp);
    }
        //Is it a pre operator? => test prereqopBitset feature:
    else if ((_prereqopBitset.test(npbt->_op->getValue()))) {
        _prereqopBitset.reset(npbt->_op->getValue());
    }

    //symmetry sieve:
    if (npbt->_simChainFlag && newOp != newOp->getSimOp()) {
/*if(newOp->getValue() == 7) {
    std::cout<<"REM"<<std::endl;
    this->print_sol();
        newOp->printall();
    }*/
        this->_applicable.erase(newOp->getSimOp());
        npbt->_simChainFlag = false;
/*if(newOp->getValue() == 7) {
    this->print_sol();
    }*/
    }

    return npbt;
}

void pillai::remove_sim_ops(pillai_op *op) {
    unsigned short int flag = 0;
    for (std::set<pillai_op*, setCompareEqual>::iterator it = this->_applicable.begin(); it != this->_applicable.end();) {
        if (((*it)->is_similar(*op)) && ((*it)->getPosition() != op->getPosition())) {
            
            this->_applicable.erase((it));
            it = this->_applicable.begin();
            ++flag;
        } else if (flag == op->getValue()) {
            break;
        } else {
            ++it;
        }
    }
}

void pillai::remove_nsim_ops(pillai_op *op) {
    unsigned short int flag = 0;
    for (std::set<pillai_op*, setCompareEqual>::iterator it = this->_applicable.begin(); it != this->_applicable.end();) {
        if (!(*it)->is_similar(*op)) {
            this->_applicable.erase((it));
            it = this->_applicable.begin();
        } else {
            ++it;
        }
    }
}

pillai *pillai::back_track() {

    pillai *parentN = (this->_parent);
    if (parentN != NULL) {

        this->inv_apply_op();

        //auto BackTrack:
        if (parentN->_op != NULL && this->_op->isPreOp()) {
            return parentN->back_track();
        }
        delete this;

    } else {
        
        delete this;
        //delete parentN;
        parentN = NULL;
        //parentN->_state.clear();
    }
    return parentN;
}

void pillai::inv_apply_op() {

    if (this->_op->isPostOp()) {
        _postreqopBitset.set(this->_op->getValue(), 1);
        _usedPOps.erase(this->get_op());
    } else if (this->_op->isPreOp()) {
        _prereqopBitset.set(this->_op->getValue(), 1);
        this->_op->setPosition(0);
    }
}

pillai_op* pillai::get_op() {
    return _op;
}

pillai* pillai::get_parent() {
    return _parent;
}

unsigned short int pillai::chinRemainderTheo(const unsigned short int& op_value, const unsigned short int& x_value, const unsigned short int& y_value, const unsigned short int& x_pos, const unsigned short int& y_pos) {
    for (int i = x_pos; true; i += x_value) {

        if ((((i - x_pos) % x_value) == 0) && (((i - y_pos) % y_value) == 0)) {
            return i == 0 ? op_value : i % op_value;
        }
    }
    return 0;
}

//boost::dynamic_bitset<>& pillai::get_allPrereqopBitset() {

std::bitset<BITSET_SIZE>& pillai::get_allPrereqopBitset() {
    return _allPrereqopBitset;
}

//boost::dynamic_bitset<>& pillai::get_allPostreqopBitset() {

std::bitset<BITSET_SIZE>& pillai::get_allPostreqopBitset() {
    return _allPostreqopBitset;
}

//boost::dynamic_bitset<>& pillai::get_prereqopBitset() {

std::bitset<BITSET_SIZE>& pillai::get_prereqopBitset() {
    return _prereqopBitset;
}

//boost::dynamic_bitset<>& pillai::get_postreqopBitset() {

std::bitset<BITSET_SIZE>& pillai::get_postreqopBitset() {
    return _postreqopBitset;
}

void pillai::simSieve(pillai_op* newOp) {

    for (std::set<pillai_op*, setCompareEqual>::iterator itF = _ops.begin(); itF != _ops.end() && (*itF)->getValue() == newOp->getValue() && (*itF)->getValue() != (*itF)->getPosition(); itF++) {
        unsigned short int i = 0;
        for (i = (*itF)->getPosition(); i <= this->_state.size(); i += (*itF)->getValue());
        unsigned short int pos = (this->_state.size() - (i - (*itF)->getValue()) + 1);
        if (pos != (*itF)->getPosition()) {
            //(new pillai_op( (*itF)->getValue(), pos, false, false, this->_state.size()))->printall();
            _ops.erase(new pillai_op((*itF)->getValue(), pos, false, false, this->_state.size()));
        }
    }
}

void pillai::gen_symmetry() {

    for (std::set<pillai_op*, setCompareEqual>::iterator itF = _ops.begin(); itF != _ops.end(); itF++) {
        unsigned short int i = 0;
        for (i = (*itF)->getPosition(); i <= (*itF)->getCapColBitset().size(); i += (*itF)->getValue());
        unsigned short int pos = ((*itF)->getCapColBitset().size() - (i - (*itF)->getValue()) + 1);
        if (pos != (*itF)->getPosition()) {
            (*itF)->setSimOp(*_ops.find(new pillai_op((*itF)->getValue(), pos, false, false, (*itF)->getCapColBitset().size())));
        } else {
            (*itF)->setSimOp(*itF);
        }
    }
}

pillai* pillai::orphan() {
    if (this != NULL) {
        return new pillai(this->_state, this->_applicable, this->_depth);
    }
    return NULL;
}

//void pillai::set_parent(pillai* parent_node) {
//    this->_parent = parent_node;
//}

unsigned short int pillai::get_depth() {
    return this->_depth;
}

void pillai::set_element(const unsigned short int& value, const unsigned short int& pos) {
    unsigned short int startPos = 0;

    for (unsigned short int i = this->_state.size() % (pos + 1); i < this->_state.size(); i += value) {
        if (this->_state.test(i))
            this->_state.reset(i);
    }
}

bool pillai::get_simChainFlag() {
    return _simChainFlag;
}

void pillai::set_simChainFlag(const bool flag) {
    _simChainFlag = flag;
}
