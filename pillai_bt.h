/*
 * File:   pillai_bt.h
 * Author: Laszlo Kovacs
 * Desc: The proble of Pillai header.
 * Version: v001
 * OS: Linux
 *
 * Created on October 5, 2011, 9:50 AM
 */

#ifndef PILLAI_BTF_H
#define	PILLAI_BTF_H


#include <set>
#include "pillai.h"
#include "pillai_op.h"
#include "ToolBox_Math.h"
#include "pillai_op.h"
#include "set"
#include "iostream"
#include <vector>
#include "pillai.h"
#include <omp.h>
#include <valarray>
#include "pillai_cmp.h"
#include "pillaiOperatorComparator.h"
//#include <bitset>

class pillai_bt {
public:

//    pillai_bt();
//    pillai_bt(unsigned short int);
//    pillai_bt(pillai_bt*);
//    virtual ~pillai_bt();

  

//    pillai_op *getOp() const;
//    pillai_bt *getParent() const;
//    pillai *getState() const;
//    std::set<pillai_op*, setCompareEqual>* getApplicable() const;
//    unsigned short int getDepth() const;
//    unsigned short int getChOpType() const;
//    //unsigned short int getNoE() const;
//    unsigned short int getMaxC() const;
//    //    unsigned short int getZeros() const;
//
//    void setMaxC(unsigned short int maxC);
//    //    void setZeros(unsigned short int pZeros);
//    //void setNoE(unsigned short int noE);
//    void setOp(pillai_op*);
//    void setParent(pillai_bt*);
//    void setState(pillai*);
//    void setApplicable(std::set<pillai_op*, setCompareEqual>*);
//    void setDepth(unsigned short int depth);
//    void setChOpType(unsigned short int chOpType);
//    void setDone(bool);
//
//    void print() const;
//    void print_all() const;
//    void print_Solution() const;
//
//    bool isFinish();
//    bool opApplyReq(pillai_op*);
//    bool containsOp(pillai_op*);
//    void removeSimOps(pillai_op*);
//    void removeOthOps(pillai_op*);
//    //    std::set<pillai_op*>* copyApplic();
//    pillai_bt* applyOp(pillai_op*);
//    void invApplyOp();
//    pillai_bt* backTrack();
//    pillai_op* chooseOp();
//    
//    void freeMem();
//    void dectructWay();
//    void updateOpBitset();
//
//    static void print(const std::set<pillai_op*, setCompareEqual>*);
//    static void print(std::vector<unsigned short int>*);
//
//    static std::set<pillai_op*, setCompareEqual>* getOps();
//    //static std::set<unsigned short int>* getZeross();
//    static unsigned short int getCapCov();
//    static boost::dynamic_bitset<>* getZeroBitset();
//    static boost::dynamic_bitset<>* getUsedopBitset();
//    static boost::dynamic_bitset<>* getEvenBitset();
//    static boost::dynamic_bitset<>* getOddBitset();
//    static void setOddBitset(boost::dynamic_bitset<>*);
//    static void setEvenBitset(boost::dynamic_bitset<>*);
//    static void setUsedopBitset(boost::dynamic_bitset<>*);
//    static void setZeroBitset(boost::dynamic_bitset<>*);
//    static std::bitset<BITSET_SIZE>* getZeroBitset();
//    static std::bitset<BITSET_SIZE>* getUsedopBitset();
//    static std::bitset<BITSET_SIZE>* getEvenBitset();
//    static std::bitset<BITSET_SIZE>* getOddBitset();
//    static void setOddBitset(std::bitset<BITSET_SIZE>*);
//    static void setEvenBitset(std::bitset<BITSET_SIZE>*);
//    static void setUsedopBitset(std::bitset<BITSET_SIZE>*);
//    static void setZeroBitset(std::bitset<BITSET_SIZE>*);
//    static void setCapCov(unsigned short int);
//    static void addOps(pillai_op*);
//    static void setOps(std::set<pillai_op*, setCompareEqual>*);
    //static void setZeross(std::set<unsigned short int>*);
//    static void gOperators(unsigned short int, unsigned short int, std::vector<unsigned short int>*, boost::dynamic_bitset<> *, boost::dynamic_bitset<> *);
//    static void gOperators(unsigned short int, unsigned short int, std::vector<unsigned short int>*, std::bitset<BITSET_SIZE> *, std::bitset<BITSET_SIZE> *);
//    
//    static bool isDone();
//    static unsigned short int capCal(unsigned short int, std::set<pillai_op*, setCompareEqual> *);
    
    //static void bitsetInit(boost::dynamic_bitset<>*, unsigned short int, unsigned short int);

    //    static unsigned short int capCurCal(pillai_op *);

    /**
     * Pillai BTF Solver
     * @param number of covered set
     * @param number of primes
     * @param vector of primes
     * @return first found solution
     */
    static pillai* pillai_solver(unsigned short int, std::vector<unsigned short int>*, unsigned short int);
    static pillai* pillai_solver(pillai* );
    static std::vector<std::string*>* pillai_solver(unsigned short int, std::vector<unsigned short int>*, unsigned short int, unsigned short int);
    static std::vector<std::string*>* pillai_solver_p(unsigned short int, std::vector<unsigned short int>*, unsigned short int, unsigned short int);
    static void pillai_solver_with_writer(unsigned short int, std::vector<unsigned short int>*, unsigned short int, std::string, unsigned short int);
    static void pillai_writer_for_input(std::vector<std::string*>*, unsigned short int, unsigned short int, std::string);
    static void pillai_writer_for_input_p(std::vector<std::string*>*, unsigned short int, unsigned short int, std::string);
    static void pillai_writer_for_input(std::string*, unsigned short int, unsigned short int, std::string);
    static void pillai_writer_for_output(pillai*, const char *);
    static pillai* pillai_reader(const char *, const std::string&);
    static void pillai_generate(unsigned short int, unsigned short int, unsigned short int, std::string);
    static void pillai_generate_p(unsigned short int, unsigned short int, unsigned short int, std::string);
    static void pillai_solver_f(const char *);
    
    
    
//    static pillai* pillai_solverG(char*);
//    static void pillai_pnodes_generator_writer(unsigned short int, std::vector<unsigned short int>*, unsigned short int, unsigned short int, std::string);
//    static std::set<pillai*>* pillai_pnodes_generator(unsigned short int, std::vector<unsigned short int>*, unsigned short int, unsigned short int);
    
//    static pillai_bt* pillai_solverA(unsigned short int, std::vector<unsigned short int>*, unsigned short int);
//    static pillai* pillai_reader(char*, unsigned short int*, unsigned short int*, const std::string& delimiters);
    
//    static pillai_bt* pillai_solver(unsigned short int, std::vector<unsigned short int>*, unsigned short int, unsigned short int);
    
//    static void pillai_pnodes_generator_writer(unsigned short int, std::vector<unsigned short int>*, unsigned short int, unsigned short int, std::string);
//    static pillai_bt* pillai_psolver(unsigned short int, std::vector<unsigned short int> *, unsigned short int, unsigned short int);
//    static std::valarray<pillai_bt*>* pillai_psolverS(unsigned short int, std::vector<unsigned short int> *, unsigned short int, unsigned short int);
//    static pillai_bt* pillai_psolver(unsigned short int, std::vector<unsigned short int> *, unsigned short int, unsigned short int, unsigned short int);
//    static std::valarray<pillai_bt*>* pillai_psolverA(unsigned short int, std::vector<unsigned short int> *, unsigned short int, unsigned short int);
//    static std::valarray<pillai_bt*>* pillai_psolverA(unsigned short int, std::vector<unsigned short int> *, unsigned short int, unsigned short int, unsigned short int);
//    static std::valarray<pillai_bt*>* copyToVarray(std::set<pillai_bt*>*);
//    static pillai_bt* pillai_solver(pillai_bt*);
//    static pillai_bt* pillai_solver(pillai_bt*, unsigned short int);
//    static pillai_bt* pillai_solverK(unsigned short int, std::vector<unsigned short int> *, unsigned short int, unsigned short int, unsigned short int);

    //static unsigned short int* gPrimesMultiple(unsigned short int*);

//private:
    //static std::vector<pillai_op*> _solV;
    static std::set<pillai_op*, pillaiOperatorComparator> _solV;

};

#endif	/* PILLAI_BTF_H */

