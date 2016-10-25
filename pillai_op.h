/*
 * pillaiop.h
 *
 *  Created on: Oct 31, 2011
 *      Author: Laszlo Kovacs
 */

#ifndef PILLAI_OP_H_
#define PILLAI_OP_H_



#include <bitset>
#include <limits>
#include <limits.h>
#include <vector>
//#include <boost/dynamic_bitset.hpp>
#include "bitset_size.h"

//#define	BITSET_SIZE 25

class pillai_op {
public:
    pillai_op();
    pillai_op(unsigned short int, unsigned short int, bool, bool, unsigned short int);
    pillai_op(unsigned short int, unsigned short int, bool, bool, unsigned short int, std::bitset<BITSET_SIZE>);
    pillai_op(unsigned short int, unsigned short int, bool, bool, unsigned short int, std::vector<unsigned short int>, std::vector<unsigned short int>);
    pillai_op(unsigned short int, unsigned short int, bool, bool, unsigned short int, std::vector<unsigned short int>, std::vector<unsigned short int>, unsigned short int, unsigned short int);
    pillai_op(unsigned short int, unsigned short int, bool, bool, unsigned short int, std::vector<unsigned short int>, std::vector<unsigned short int>, unsigned short int, unsigned short int, std::bitset<BITSET_SIZE>);
//    pillai_op(unsigned short int, unsigned short int, bool, bool, boost::dynamic_bitset<>, unsigned short int, std::vector<unsigned short int>*, std::vector<unsigned short int>*, unsigned short int, unsigned short int);
    pillai_op(unsigned short int, unsigned short int, bool, bool, std::bitset<BITSET_SIZE>, unsigned short int, std::vector<unsigned short int>, std::vector<unsigned short int>, unsigned short int, unsigned short int);
    pillai_op(unsigned short int, unsigned short int, bool, bool, std::bitset<BITSET_SIZE>, unsigned short int, std::vector<unsigned short int>, std::vector<unsigned short int>, unsigned short int, unsigned short int, std::bitset<BITSET_SIZE>);
    pillai_op(pillai_op*);
    pillai_op(pillai_op*, unsigned short int);
    pillai_op(pillai_op*, unsigned short int, std::vector<unsigned short int>, std::vector<unsigned short int>);
    virtual ~pillai_op();

    unsigned short int getPosition() const;
    unsigned short int getValue() const;
    std::bitset<BITSET_SIZE>& getPostReqBitset();
    std::bitset<BITSET_SIZE>& getCapColBitset();
    std::bitset<BITSET_SIZE>& getCurCapColBitset();
    std::bitset<BITSET_SIZE>& getExtBitset();
    pillai_op* getSimOp() const;
    std::vector<unsigned short int>& getPostreq();
    std::vector<unsigned short int>& getPrereq();
    std::vector<pillai_op*>& getPrereqP();
    std::vector<pillai_op*>& getPostreqP();
    void setPostreqP(std::vector<pillai_op*>);
    void setPrereqP(std::vector<pillai_op*>);
    void setPostreq(std::vector<unsigned short int>);
    void setPrereq(std::vector<unsigned short int>);
    void setCapColBitset(std::bitset<BITSET_SIZE> );
    void setCurCapColBitset(std::bitset<BITSET_SIZE> ); 
    void setCurCapColBitset(unsigned short int, bool ); //void setPostReqBitset(std::bitset<BITSET_SIZE>);void setCapColBitset(unsigned short int, bool );void setPostReqBitset(unsigned short int, bool );
    void setPosition(unsigned short int);
    void setValue(unsigned short int);
    void setPreOp(bool);
    void setPostOp(bool);
    void setSimOp(pillai_op*);
    bool is_similar(const pillai_op&) const;
    bool operator==(const pillai_op&) const;
    bool operator!=(const pillai_op&) const;
    bool operator<(const pillai_op&) const;
    bool isNull() const;
    bool isConnOp() const;
    bool isPreOp() const;
    bool isPostOp() const;
//    static boost::dynamic_bitset<>& get_allPrereqopBitset();
//    static boost::dynamic_bitset<>& get_allPostreqopBitset();

    void print() const;
    void printall() const;
    std::string print_toString();
    std::string printall_toString();

private:
    unsigned short int value;
    unsigned short int position;
    bool preOp;
    bool postOp;
    pillai_op *simOp;
    std::bitset<BITSET_SIZE> postReqBitset;
    std::bitset<BITSET_SIZE> capColBitset;
    std::bitset<BITSET_SIZE> curCapColBitset;
    std::bitset<BITSET_SIZE> extBitset;
//    boost::dynamic_bitset<> *postReqBitset;
//    boost::dynamic_bitset<> *capColBitset;
//    boost::dynamic_bitset<> *curCapColBitset;
    std::vector<unsigned short int> prereq;
    std::vector<unsigned short int> postreq;
    std::vector<pillai_op*> prereqP;
    std::vector<pillai_op*> postreqP;
    
//    static boost::dynamic_bitset<> _allPrereqopBitset;
//    static boost::dynamic_bitset<> _allPostreqopBitset;
};

#endif /* PILLAIAI_OP_H_ */
