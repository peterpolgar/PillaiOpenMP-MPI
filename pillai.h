/*
 * pillaiai.h
 *
 *  Created on: Nov 5, 2011
 *      Author: addy
 */

#ifndef PILLAI_H_
#define PILLAI_H_

#include <vector>
#include <string>
#include "bitset_size.h"
#include <set>

#include "pillai_cmp.h"
#include "pillai_op.h"

class pillai {
public:
    pillai();
    pillai(const unsigned short int&);
    pillai(const std::bitset<BITSET_SIZE> &);
    pillai(const pillai&);
    pillai(const pillai&, const std::set<pillai_op*, setCompareEqual>&);
    pillai(const std::bitset<BITSET_SIZE>&, const std::set<pillai_op*, setCompareEqual>&, unsigned short int&);
    virtual ~pillai();
    
    std::bitset<BITSET_SIZE>& get_state();
    const std::set<pillai_op*, setCompareEqual>& get_applicable() const;
    pillai_op* get_op();
    unsigned short int get_depth();
    bool get_simChainFlag();

    void set_simChainFlag(const bool);
    void set_state(const std::bitset<BITSET_SIZE> & );
    void set_element(const unsigned short int&, const unsigned short int&);
    
    bool operator==(const pillai&) const;
    bool operator!=(const pillai&) const;
    
    const bool isEmpty() const;
    void print() const;
    std::string print_toString();
    void print_all() const;
    std::string print_all_toString();
    void print_sol();
    std::string print_sol_toString();
    std::string statePrintToString();
    const bool is_null() const;
    const bool is_finish() const;
    void update_op_bitset();
    
    unsigned short int& get_maxC();
    unsigned short int& get_evenC();
    unsigned short int& get_oddC();
    unsigned short int& get_maxCC();
    unsigned short int& get_evenCC();
    unsigned short int& get_oddCC();
    
    pillai_op *choose_op();
    bool op_apply_req(pillai_op*);
    pillai* apply_op(pillai_op *);
    void remove_sim_ops(pillai_op *op);
    void remove_nsim_ops(pillai_op *op);
    pillai *back_track();
    void inv_apply_op();
    pillai* get_parent();
    void simSieve(pillai_op*);
    pillai* orphan();
    
    static pillai* init_pillai(const unsigned short int&, std::vector<unsigned short int>*, const unsigned short int&);
    static void bitset_init_set(std::bitset<BITSET_SIZE>&, const unsigned short int&, const unsigned short int&, const unsigned short int&);
    static void gen_operators(const unsigned short int&, const unsigned short int&, std::vector<unsigned short int>*, std::bitset<BITSET_SIZE>&, std::bitset<BITSET_SIZE>&);
    static void gen_symmetry();
    static void add_ops(pillai_op* op);
    static unsigned short int cap_cal(const unsigned short int&, const std::set<pillai_op*, setCompareEqual>&);
    static std::bitset<BITSET_SIZE>& get_zeroBitset();
    static std::bitset<BITSET_SIZE>& get_evenBitset();
    static std::bitset<BITSET_SIZE>& get_oddBitset();
    static std::bitset<BITSET_SIZE>& get_cenBitset();
    static unsigned short int chinRemainderTheo(const unsigned short int& ,const unsigned short int&, const unsigned short int&, const unsigned short int&, const unsigned short int&);
    static std::bitset<BITSET_SIZE>& get_allPrereqopBitset();
    static std::bitset<BITSET_SIZE>& get_allPostreqopBitset();
    static std::bitset<BITSET_SIZE>& get_prereqopBitset();
    static std::bitset<BITSET_SIZE>& get_postreqopBitset();
    

private:
    std::bitset<BITSET_SIZE> _state;
    pillai *_parent;
    pillai_op *_op;
    std::set<pillai_op *, setCompareEqual> _applicable;
    unsigned short int _chOpType;
    unsigned short int _depth;
    unsigned short int _maxC;
    unsigned short int _maxCC;
    unsigned short int _evenC;
    unsigned short int _oddC;
    unsigned short int _evenCC;
    unsigned short int _oddCC;
    bool _simChainFlag;
    std::bitset<BITSET_SIZE> _usedopBitset;
    
    static std::bitset<BITSET_SIZE> _prereqopBitset;
    static std::bitset<BITSET_SIZE> _postreqopBitset;
    static std::bitset<BITSET_SIZE> _allPrereqopBitset;
    static std::bitset<BITSET_SIZE> _allPostreqopBitset;
    
    static std::set<pillai_op*, setCompareEqual> _ops;
    static std::set<pillai_op*, setCompareEqual> _usedPOps;
    static std::bitset<BITSET_SIZE> _evenBitset;
    static std::bitset<BITSET_SIZE> _oddBitset;
    static std::bitset<BITSET_SIZE> _cenBitset;
    static std::vector<std::bitset<BITSET_SIZE> > _cenBitsetVector;
    static bool _done;
    static unsigned short int _capCov;
};

#endif /* PILLAI_H_ */
