
#include "pillai.h"

/*
 * File:   pillaip.cpp
 * Author: addy
 *
 * Created on October 5, 2011, 9:50 AM
 */

#include <limits>

#include "pillai_bt.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
//#include <boost/progress.hpp>
//#include <boost/timer.hpp>
//#include <boost/date_time/posix_time/posix_time.hpp>
//#include "boost_1_55_0/boost/date_time/posix_time/posix_time.hpp"
//#include "boost/date_time/posix_time/posix_time.hpp"
//#include "boost_1_55_0/include/boost/date_time/posix_time/posix_time.hpp"





/**
 * Pillai Solver:
 * Default the one thread pc search.
 */
pillai* pillai_bt::pillai_solver(unsigned short int n, std::vector<unsigned short int> *primesV, unsigned short int d) {

    pillai* sol = pillai::init_pillai(n, primesV, d);
    //sol->print_all();
    pillai_op* chdOp = NULL;
    
//    simmetry sieve:
    //sol->simSieve(sol->choose_op());
    
    std::bitset<BITSET_SIZE> tempZeroEven(n);
    std::bitset<BITSET_SIZE> tempZeroOdd(n);
    std::bitset<BITSET_SIZE> tempZeroCen(n);
//    std::bitset<BITSET_SIZE> tempZeroEvenC(n);
//    std::bitset<BITSET_SIZE> tempZeroOddC(n);

//    boost::posix_time::ptime start, finish, start_apply, finish_apply, start_bt, finish_bt;
//    boost::posix_time::time_duration diff, diff_apply, diff_bt;
    unsigned long int countLoop = 0, countLoop_apply = 0, countLoop_bt = 0;

    while (true) {
        
        if (sol->is_null()) {
            break;
        } else if (sol->is_finish()) {
            //sol->print_sol();
            break;
        } else { 
            sol->update_op_bitset();
        }
        tempZeroEven = sol->get_state()&pillai::get_evenBitset();
        tempZeroOdd = sol->get_state()&pillai::get_oddBitset();
        tempZeroCen = sol->get_state()&pillai::get_cenBitset();
//        tempZeroEvenC = tempZeroCen&pillai::get_evenBitset();
//        tempZeroOddC = tempZeroCen&pillai::get_oddBitset();
        
//        start = boost::posix_time::microsec_clock::local_time();
       if (!sol->get_applicable().empty() &&       
                (sol->get_maxC() >= sol->get_state().count()) &&        
                (sol->get_evenC() >= tempZeroEven.count()) &&
                (sol->get_oddC() >= tempZeroOdd.count()) &&
                (sol->get_maxCC() >= tempZeroCen.count()) &&
//                (sol->get_evenCC() >= tempZeroEvenC.count()) &&
//                (sol->get_oddCC() >= tempZeroOddC.count()) &&
//                (chdOp != NULL) ) {
                ((chdOp = sol->choose_op()) != NULL) ) {

//            start_apply = boost::posix_time::microsec_clock::local_time();
            sol = sol->apply_op(chdOp);
//            sol->print_all();

//            finish_apply = boost::posix_time::microsec_clock::local_time();
//            diff_apply += finish_apply - start_apply;
            countLoop_apply++;

        } else {
//           if(sol->get_maxCC() < tempZeroCen.count() && sol->get_maxC() >= sol->get_state().count()) {
//               std::cout<<"cc: "<<sol->get_maxCC()<<std::endl;
//               std::cout<<"cent: "<<tempZeroCen.count()<<std::endl;
//               std::cout<<tempZeroCen<<std::endl;
//               std::cout<<"c: "<<sol->get_maxC()<<std::endl;
//               std::cout<<"state: "<<sol->get_state().count()<<std::endl;
//               std::cout<<sol->get_state()<<"\n"<<std::endl;
//           }
//           std::cout<<"BT"<<std::endl;
//            start_bt = boost::posix_time::microsec_clock::local_time();
            sol = sol->back_track();
//            sol->print_all();
//            std::cout<<"-BT-"<<std::endl;

//            finish_bt = boost::posix_time::microsec_clock::local_time();
//            diff_bt += finish_bt - start_bt;
            countLoop_bt++;
        }
        
//        finish = boost::posix_time::microsec_clock::local_time();
//        diff += finish - start;
        countLoop++;
    }
    
//    std::cout << "Average node computing time: " << diff.total_microseconds() / ((countLoop==0)?1:countLoop) << " microsec." << std::endl;
//    std::cout << "Average node apply computing time: " << diff_apply.total_microseconds() / ((countLoop_apply==0)?1:countLoop_apply) << " microsec." << std::endl;
//    std::cout << "Average node backtrack computing time: " << diff_bt.total_microseconds() / ((countLoop_bt==0)?1:countLoop_bt) << " microsec." << std::endl;
    
    std::cout << "Average node computing: " << countLoop << " piece" << std::endl;
    std::cout << "Average node apply computing time: " << countLoop_apply << " piece." << std::endl;
    std::cout << "Average node backtrack computing time: " << countLoop_bt << " piece." << std::endl;

    if (!sol->is_null()) {
        sol->print_sol();
    } else {
        std::cout << "Nem Talaltam Megoldast!" << std::endl;
    }

    return sol;
}

pillai* pillai_bt::pillai_solver(pillai* pillai_state_node) {

    pillai* sol = new pillai(*pillai_state_node);
    pillai_op* chdOp = NULL;

    //simmetry sieve:
    //sol->simSieve(sol->choose_op());
    
    std::bitset<BITSET_SIZE> tempZeroEven(pillai_state_node->get_state().size());
    std::bitset<BITSET_SIZE> tempZeroOdd(pillai_state_node->get_state().size());
    std::bitset<BITSET_SIZE> tempZeroCen(pillai_state_node->get_state().size());

//    boost::posix_time::ptime start, finish, start_apply, finish_apply, start_bt, finish_bt;
//    boost::posix_time::time_duration diff, diff_apply, diff_bt;
    unsigned long int countLoop = 0, countLoop_apply = 0, countLoop_bt = 0;

    while (true) {
        
        if (sol->is_null()) {
            //std::cout<<"NULL"<<std::endl;
            break;
        } else if (sol->is_finish()) {
            //sol->print_sol();
            break;
        } else { 
            sol->update_op_bitset();
        }
        
        tempZeroEven = sol->get_state()&pillai::get_evenBitset();
        tempZeroOdd = sol->get_state()&pillai::get_oddBitset();
        tempZeroCen = sol->get_state()&pillai::get_cenBitset();
           
//        start = boost::posix_time::microsec_clock::local_time();
//        std::cout<<!sol->get_applicable().empty()<<std::endl;
//        std::cout<<sol->get_maxC()<<" "<<sol->get_state().count()<<std::endl;
//        std::cout<<sol->get_evenC()<<" "<<tempZeroEven.count()<<std::endl;
//        std::cout<<sol->get_oddC()<<" "<<tempZeroOdd.count()<<std::endl;
//        std::cout<<sol->get_maxCC()<<" "<<tempZeroCen.count()<<std::endl; 
//        std::cout<<((chdOp = sol->choose_op()) != NULL)<<std::endl;
                
       if (!sol->get_applicable().empty() &&       
                (sol->get_maxC() >= sol->get_state().count()) &&        
                (sol->get_evenC() >= tempZeroEven.count()) &&
                (sol->get_oddC() >= tempZeroOdd.count()) &&
                (sol->get_maxCC() >= tempZeroCen.count()) &&
//                (chdOp != NULL) ) {
                ((chdOp = sol->choose_op()) != NULL) ) {
           
//            start_apply = boost::posix_time::microsec_clock::local_time();

            sol = sol->apply_op(chdOp);

//            finish_apply = boost::posix_time::microsec_clock::local_time();
//            diff_apply += finish_apply - start_apply;
            countLoop_apply++;

        } else {
           //std::cout<<"BT"<<std::endl;

//            start_bt = boost::posix_time::microsec_clock::local_time();
            sol = sol->back_track();

//            finish_bt = boost::posix_time::microsec_clock::local_time();
//            diff_bt += finish_bt - start_bt;
            countLoop_bt++;
        }
        
//        finish = boost::posix_time::microsec_clock::local_time();
//        diff += finish - start;
        countLoop++;
    }
    
//    std::cout << "Average node computing time: " << diff.total_microseconds() / ((countLoop==0)?1:countLoop) << " microsec." << std::endl;
//    std::cout << "Average node apply computing time: " << diff_apply.total_microseconds() / ((countLoop_apply==0)?1:countLoop_apply) << " microsec." << std::endl;
//    std::cout << "Average node backtrack computing time: " << diff_bt.total_microseconds() / ((countLoop_bt==0)?1:countLoop_bt) << " microsec." << std::endl;
    
    std::cout << "Average node computing: " << countLoop << " piece" << std::endl;
    std::cout << "Average node apply computing time: " << countLoop_apply << " piece." << std::endl;
    std::cout << "Average node backtrack computing time: " << countLoop_bt << " piece." << std::endl;

    if (!sol->is_null()) {
        sol->print_sol();
    } else {
        std::cout << "Nem Talaltam Megoldast!" << std::endl;
    }

    return sol;
}

std::vector<std::string*>* pillai_bt::pillai_solver(unsigned short int n, std::vector<unsigned short int> *primesV, unsigned short int d,  unsigned short int gDepth=0) {

    std::vector<std::string*>* nodes = new std::vector<std::string*>();
    std::stringstream state_str;
    state_str.clear();
    
    pillai *sol_BUP, *sol = pillai::init_pillai(n, primesV, d);
    pillai_op* chdOp = NULL;
    
//    for (std::set<pillai_op*, setCompareEqual>::iterator fit, it = sol->get_applicable().begin(); it != sol->get_applicable().end(); it++) {
//        (*it)->printall();
//    }
    
    if(gDepth == 0 || gDepth < sol->get_allPostreqopBitset().count()+sol->get_allPrereqopBitset().count() ) {
        gDepth = sol->get_allPostreqopBitset().count()+sol->get_allPrereqopBitset().count();
    }
    //std::cout<<gDepth<<std::endl;
    //simmetry sieve:
    //sol->simSieve(sol->choose_op());
    
    std::bitset<BITSET_SIZE> tempZeroEven(n);
    std::bitset<BITSET_SIZE> tempZeroOdd(n);
    std::bitset<BITSET_SIZE> tempZeroCen(n);

//    boost::posix_time::ptime start, finish, start_apply, finish_apply, start_bt, finish_bt;
//    boost::posix_time::time_duration diff, diff_apply, diff_bt;
    unsigned long int countLoop = 0, countLoop_apply = 0, countLoop_bt = 0;

    std::string *str;
    while (true) {
        
        if (sol->is_null()) {
            break;
        } else if (sol->is_finish()) {
//            state_str<< n << "\n" << d << "\n" << sol->statePrintToString()<<std::endl;
            str = new std::string(state_str.str());
            nodes->insert(nodes->end(), str);
            state_str.str( "" );
            break;
        } else { 
            sol->update_op_bitset();
        }
        
        tempZeroEven = sol->get_state()&pillai::get_evenBitset();
        tempZeroOdd = sol->get_state()&pillai::get_oddBitset();
        tempZeroCen = sol->get_state()&pillai::get_cenBitset();
        
//        if (sol->get_depth() == gDepth) {
//            
//            state_str<< n << "\n" << d << "\n" << sol->statePrintToString()<<"\n"<<sol->get_simChainFlag()<<"\n";
//            str = new std::string(state_str.str());
//            nodes->insert(nodes->end(), str);
//            state_str.str( "" );
//            //std::cout<<"BT2"<<std::endl;
//            sol = sol->back_track();
//            continue;
//        }
        
//        start = boost::posix_time::microsec_clock::local_time();
       if (!sol->get_applicable().empty() &&       
                (sol->get_maxC() >= sol->get_state().count()) &&        
                (sol->get_evenC() >= tempZeroEven.count()) &&
                (sol->get_oddC() >= tempZeroOdd.count()) &&
                (sol->get_maxCC() >= tempZeroCen.count()) &&
//                (chdOp != NULL) ) {
                ((chdOp = sol->choose_op()) != NULL) ) {
           
           if (sol->get_depth() == gDepth) {
            
                state_str<< n << "\n" << d << "\n" << sol->statePrintToString()<<"\n"<<sol->get_simChainFlag()<<"\n";
                str = new std::string(state_str.str());
                nodes->insert(nodes->end(), str);
                state_str.str( "" );
                //std::cout<<"BT2"<<std::endl;
                //sol_BUP = sol;
                sol = sol->back_track();
                //sol_BUP->~pillai();
                continue;
           }
           
//            start_apply = boost::posix_time::microsec_clock::local_time();
//chdOp->print();    std::cout<<std::endl;        
            sol = sol->apply_op(chdOp);

//            finish_apply = boost::posix_time::microsec_clock::local_time();
//            diff_apply += finish_apply - start_apply;
            countLoop_apply++;

        } else {
           //std::cout<<"BT1"<<std::endl;
//            start_bt = boost::posix_time::microsec_clock::local_time();
            //sol_BUP = new pillai(*sol);
            sol = sol->back_track();
           //sol_BUP->~pillai();

//            finish_bt = boost::posix_time::microsec_clock::local_time();
//            diff_bt += finish_bt - start_bt;
            countLoop_bt++;
        }
        
//        finish = boost::posix_time::microsec_clock::local_time();
//        diff += finish - start;
        countLoop++;
    }
    
//    std::cout << "Average node computing time: " << diff.total_microseconds() / ((countLoop==0)?1:countLoop) << " microsec." << std::endl;
////    std::cout << "Average node apply computing time: " << diff_apply.total_microseconds() / ((countLoop_apply==0)?1:countLoop_apply) << " microsec." << std::endl;
//    std::cout << "Average node backtrack computing time: " << diff_bt.total_microseconds() / ((countLoop_bt==0)?1:countLoop_bt) << " microsec." << std::endl;
    
    std::cout << "Average node computing: " << countLoop << " piece" << std::endl;
    std::cout << "Average node apply computing time: " << countLoop_apply << " piece." << std::endl;
    std::cout << "Average node backtrack computing time: " << countLoop_bt << " piece." << std::endl;

    if (sol->is_null()) {
        std::cout << "A Pillai node generator futasa befejezodott!" << std::endl;
    }

    return nodes;
}

std::vector<std::string*>* pillai_bt::pillai_solver_p(unsigned short int n, std::vector<unsigned short int> *primesV, unsigned short int d,  unsigned short int gDepth=0) {

    std::vector<std::string*>* nodes = new std::vector<std::string*>();
    std::stringstream state_str;
    state_str.clear();
    
    pillai *sol_BUP, *sol = pillai::init_pillai(n, primesV, d);
    pillai_op* chdOp = NULL;
    
    if(gDepth == 0 || gDepth < sol->get_allPostreqopBitset().count()+sol->get_allPrereqopBitset().count() ) {
        gDepth = sol->get_allPostreqopBitset().count()+sol->get_allPrereqopBitset().count();
    }

    //simmetry sieve:
    //sol->simSieve(sol->choose_op());
    
    std::bitset<BITSET_SIZE> tempZeroEven(n);
    std::bitset<BITSET_SIZE> tempZeroOdd(n);
    std::bitset<BITSET_SIZE> tempZeroCen(n);

//    boost::posix_time::ptime start, finish, start_apply, finish_apply, start_bt, finish_bt;
//    boost::posix_time::time_duration diff, diff_apply, diff_bt;
    unsigned long int countLoop = 0, countLoop_apply = 0, countLoop_bt = 0;

    std::string *str;
    while (true) {
        
        if (sol->is_null()) {
            break;
        } else if (sol->is_finish()) {
            str = new std::string(state_str.str());
            nodes->insert(nodes->end(), str);
            state_str.str( "" );
            break;
        } else { 
            sol->update_op_bitset();
        }
        
        tempZeroEven = sol->get_state()&pillai::get_evenBitset();
        tempZeroOdd = sol->get_state()&pillai::get_oddBitset();
        tempZeroCen = sol->get_state()&pillai::get_cenBitset();
        
        
//        start = boost::posix_time::microsec_clock::local_time();
       if (!sol->get_applicable().empty() &&       
                (sol->get_maxC() >= sol->get_state().count()) &&        
                (sol->get_evenC() >= tempZeroEven.count()) &&
                (sol->get_oddC() >= tempZeroOdd.count()) &&
                (sol->get_maxCC() >= tempZeroCen.count()) &&
//                (chdOp != NULL) ) {
                ((chdOp = sol->choose_op()) != NULL) ) {
           
           if (sol->get_depth() == gDepth) {
            
                state_str<< n << "\n" << d << "\n" << sol->statePrintToString()<<"\n"<<sol->get_simChainFlag()<<"\n";
                str = new std::string(state_str.str());
                nodes->insert(nodes->end(), str);
                state_str.str( "" );
                //std::cout<<"BT2"<<std::endl;
                //sol_BUP = sol;
                sol = sol->back_track();
                //sol_BUP->~pillai();
                continue;
           }
           
//            start_apply = boost::posix_time::microsec_clock::local_time();      
            sol = sol->apply_op(chdOp);

//            finish_apply = boost::posix_time::microsec_clock::local_time();
//            diff_apply += finish_apply - start_apply;
            countLoop_apply++;

        } else {
//            start_bt = boost::posix_time::microsec_clock::local_time();
            sol = sol->back_track();
           //sol_BUP->~pillai();

//            finish_bt = boost::posix_time::microsec_clock::local_time();
//            diff_bt += finish_bt - start_bt;
            countLoop_bt++;
        }
        
//        finish = boost::posix_time::microsec_clock::local_time();
//        diff += finish - start;
        countLoop++;
    }
    
//    std::cout << "Average node computing time: " << diff.total_microseconds() / ((countLoop==0)?1:countLoop) << " microsec." << std::endl;
////    std::cout << "Average node apply computing time: " << diff_apply.total_microseconds() / ((countLoop_apply==0)?1:countLoop_apply) << " microsec." << std::endl;
//    std::cout << "Average node backtrack computing time: " << diff_bt.total_microseconds() / ((countLoop_bt==0)?1:countLoop_bt) << " microsec." << std::endl;
    
    std::cout << "Average node computing: " << countLoop << " piece" << std::endl;
    std::cout << "Average node apply computing time: " << countLoop_apply << " piece." << std::endl;
    std::cout << "Average node backtrack computing time: " << countLoop_bt << " piece." << std::endl;

    if (sol->is_null()) {
        std::cout << "A Pillai node generator futasa befejezodott!" << std::endl;
    }

    return nodes;
}

void pillai_bt::pillai_solver_with_writer(unsigned short int n, std::vector<unsigned short int> *primesV, unsigned short int d, std::string save_path, unsigned short int gDepth=0) {

    std::vector<std::string*>* nodes = new std::vector<std::string*>();
    std::stringstream state_str;
    state_str.clear();
    
    pillai* sol = pillai::init_pillai(n, primesV, d);
    pillai_op* chdOp = NULL;
    
//    for (std::set<pillai_op*, setCompareEqual>::iterator fit, it = sol->get_applicable().begin(); it != sol->get_applicable().end(); it++) {
//        (*it)->printall();
//    }
    
    if(gDepth == 0 || gDepth < sol->get_allPostreqopBitset().count()+sol->get_allPrereqopBitset().count() ) {
        gDepth = sol->get_allPostreqopBitset().count()+sol->get_allPrereqopBitset().count();
    }
    //std::cout<<gDepth<<std::endl;
    //simmetry sieve:
    //sol->simSieve(sol->choose_op());
    
    std::bitset<BITSET_SIZE> tempZeroEven(n);
    std::bitset<BITSET_SIZE> tempZeroOdd(n);
    std::bitset<BITSET_SIZE> tempZeroCen(n);

//    boost::posix_time::ptime start, finish, start_apply, finish_apply, start_bt, finish_bt;
//    boost::posix_time::time_duration diff, diff_apply, diff_bt;
    unsigned long int countLoop = 0, countLoop_apply = 0, countLoop_bt = 0;

    std::string *str;
    while (true) {
        
        if (sol->is_null()) {
            break;
        } else if (sol->is_finish()) {
//            state_str<< n << "\n" << d << "\n" << sol->statePrintToString()<<std::endl;
            str = new std::string(state_str.str());
            //nodes->insert(nodes->end(), str);
            pillai_bt::pillai_writer_for_input(str, n, d, save_path);
            state_str.str( "" );
            break;
        } else { 
            sol->update_op_bitset();
        }
        
        tempZeroEven = sol->get_state()&pillai::get_evenBitset();
        tempZeroOdd = sol->get_state()&pillai::get_oddBitset();
        tempZeroCen = sol->get_state()&pillai::get_cenBitset();
        
//        if (sol->get_depth() == gDepth) {
//            
//            state_str<< n << "\n" << d << "\n" << sol->statePrintToString()<<"\n"<<sol->get_simChainFlag()<<"\n";
//            str = new std::string(state_str.str());
//            nodes->insert(nodes->end(), str);
//            state_str.str( "" );
//            //std::cout<<"BT2"<<std::endl;
//            sol = sol->back_track();
//            continue;
//        }
        
//        start = boost::posix_time::microsec_clock::local_time();
       if (!sol->get_applicable().empty() &&       
                (sol->get_maxC() >= sol->get_state().count()) &&        
                (sol->get_evenC() >= tempZeroEven.count()) &&
                (sol->get_oddC() >= tempZeroOdd.count()) &&
                (sol->get_maxCC() >= tempZeroCen.count()) &&
//                (chdOp != NULL) ) {
                ((chdOp = sol->choose_op()) != NULL) ) {
           
           if (sol->get_depth() == gDepth) {
            
                state_str<< n << "\n" << d << "\n" << sol->statePrintToString()<<"\n"<<sol->get_simChainFlag()<<"\n";
                str = new std::string(state_str.str());
                //nodes->insert(nodes->end(), str);
                pillai_bt::pillai_writer_for_input(str, n, d, save_path);
                state_str.str( "" );
                //std::cout<<"BT2"<<std::endl;
                sol = sol->back_track();
                continue;
           }
           
//            start_apply = boost::posix_time::microsec_clock::local_time();
//chdOp->print();    std::cout<<std::endl;        
            sol = sol->apply_op(chdOp);

//            finish_apply = boost::posix_time::microsec_clock::local_time();
//            diff_apply += finish_apply - start_apply;
            countLoop_apply++;

        } else {
           //std::cout<<"BT1"<<std::endl;
//            start_bt = boost::posix_time::microsec_clock::local_time();
            sol = sol->back_track();

//            finish_bt = boost::posix_time::microsec_clock::local_time();
//            diff_bt += finish_bt - start_bt;
            countLoop_bt++;
        }
        
//        finish = boost::posix_time::microsec_clock::local_time();
//        diff += finish - start;
        countLoop++;
    }
    
//    std::cout << "Average node computing time: " << diff.total_microseconds() / ((countLoop==0)?1:countLoop) << " microsec." << std::endl;
////    std::cout << "Average node apply computing time: " << diff_apply.total_microseconds() / ((countLoop_apply==0)?1:countLoop_apply) << " microsec." << std::endl;
//    std::cout << "Average node backtrack computing time: " << diff_bt.total_microseconds() / ((countLoop_bt==0)?1:countLoop_bt) << " microsec." << std::endl;
    
    std::cout << "Average node computing: " << countLoop << " piece" << std::endl;
    std::cout << "Average node apply computing time: " << countLoop_apply << " piece." << std::endl;
    std::cout << "Average node backtrack computing time: " << countLoop_bt << " piece." << std::endl;

    if (sol->is_null()) {
        std::cout << "A Pillai node generator futasa befejezodott!" << std::endl;
    }

    //return nodes;
}

void pillai_bt::pillai_writer_for_input(std::vector<std::string*>* nodes, unsigned short int n, unsigned short int d, std::string save_path) {
    
    //Create folder structure:
    //create folder name
    std::stringstream n_strb, d_strd, count_string;
    n_strb << n;                                                                
    d_strd << d;                                                                
    std::string folderName, fileName, inFolderName;
    folderName = save_path + n_strb.str() + "_" + d_strd.str();
    inFolderName = folderName;
    
    // Create 'main case' directory
    if(access(folderName.c_str(), 0 ) != 0) {
       
        int creationFlag = -1; 
        #if defined _WIN64 || defined _WIN32 
            creationFlag = mkdir(folderName.c_str());
        #else
            creationFlag = mkdir(folderName.c_str(),0777);
        #endif

        if(creationFlag==-1) {
        //if(mkdir(folderName.c_str())==-1) {
//    struct stat sb;
//    if(stat(folderName.c_str(), &sb ) != 0) {
//        if(mkdir(folderName.c_str(),0777)==-1 && errno != EEXIST) {
            std::cerr<<"Error :  "<<strerror(errno)<<std::endl;
        }
    }
                     
    // Create 'in' directory
    if(access(inFolderName.append("/in/").c_str(), 0 ) == 0) {
//    if(stat(inFolderName.append("/in/").c_str(), &sb ) != 0) {
        if(system(((std::string)("exec rm -r " + inFolderName + "*")).c_str())==-1) {
            std::cerr<<"Error :  "<<strerror(errno)<<std::endl;
        }
    //} else if(mkdir(inFolderName.c_str())==-1) {
    } else {
        
        int creationFlag = -1; 
        #if defined _WIN64 || defined _WIN32 
            creationFlag = mkdir(folderName.c_str());
        #else
            creationFlag = mkdir(folderName.c_str(),0777);
        #endif

        if(creationFlag==-1) {
            std::cerr<<"Error :  "<<strerror(errno)<<std::endl;
        }
    }
    
    std::ofstream outputFile;
    unsigned short int count = 1;
    for (std::vector<std::string*>::iterator it = nodes->begin(); it != nodes->end(); it++) {
        count_string.str("");
        count_string << count; 
        fileName = folderName + "/in/" + n_strb.str() + "_" + d_strd.str() + "_" + count_string.str() + ".txt"; 
        
        outputFile.open(fileName.c_str(), std::ios::out);
        count++;
        if (outputFile.is_open()) {
            //write states:
            outputFile << *(*it) << std::endl;

            //closeing:
            outputFile.close();
        }
        else {
            std::cout << "Unable to open file";
        }
    }
}

void pillai_bt::pillai_writer_for_input_p(std::vector<std::string*>* nodes, unsigned short int n, unsigned short int d, std::string save_path) {
    
    //Create folder structure:
    //create folder name
    std::stringstream n_strb, d_strd, count_string;
    n_strb << n;                                                                
    d_strd << d;                                                                
    std::string folderName, fileName, inFolderName;
    folderName = save_path + n_strb.str() + "_" + d_strd.str();
    inFolderName = folderName;
    
    // Create 'main case' directory
    if(access(folderName.c_str(), 0 ) != 0) {
        
        int creationFlag = -1; 
        #if defined _WIN64 || defined _WIN32 
            creationFlag = mkdir(folderName.c_str());
        #else
            creationFlag = mkdir(folderName.c_str(),0777);
        #endif

        if(creationFlag==-1) {
        //if(mkdir(folderName.c_str())==-1) {
            std::cerr<<"Error :  "<<strerror(errno)<<std::endl;
        }
    }
                     
    // Create 'in' directory
    if(access(inFolderName.append("/in/").c_str(), 0 ) == 0) {
        if(system(((std::string)("exec rm -r " + inFolderName + "*")).c_str())==-1) {
            std::cerr<<"Error :  "<<strerror(errno)<<std::endl;
        }
    } else {
        
        int creationFlag = -1; 
        #if defined _WIN64 || defined _WIN32 
            creationFlag = mkdir(folderName.c_str());
        #else
            creationFlag = mkdir(folderName.c_str(),0777);
        #endif

        if(creationFlag==-1) {
        //if(mkdir(inFolderName.c_str())==-1) {
            std::cerr<<"Error :  "<<strerror(errno)<<std::endl;
        }
    }
    
    std::ofstream outputFile;
    unsigned short int count = 1;
    
    #pragma omp parallel for /*num_threads(omp_get_max_threads())*/ shared(nodes,count,count_string) private(outputFile,fileName)
    for (std::vector<std::string*>::iterator it = nodes->begin(); it < nodes->end(); it++) {
        //printf("%d threads are used to running(num).\n", omp_get_num_threads());
        count_string.str("");
        count_string << count; 
        fileName = folderName + "/in/" + n_strb.str() + "_" + d_strd.str() + "_" + count_string.str() + ".txt"; 
        
        outputFile.open(fileName.c_str(), std::ios::out);
        count++;
        if (outputFile.is_open()) {
            //write states:
            outputFile << *(*it) << std::endl;

            //closeing:
            outputFile.close();
        }
        else {
            std::cout << "Unable to open file";
        }
    }
}

void pillai_bt::pillai_writer_for_input(std::string* node, unsigned short int n, unsigned short int d, std::string save_path) {
    
    //Create folder structure:
    //create folder name
    std::stringstream n_strb, d_strd, count_string;
    n_strb << n;                                                                
    d_strd << d;                                                                
    std::string folderName, fileName, inFolderName;
    folderName = save_path + n_strb.str() + "_" + d_strd.str();
    inFolderName = folderName;
    
    // Create 'main case' directory
    if(access(folderName.c_str(), 0 ) != 0) {
        
        int creationFlag = -1; 
        #if defined _WIN64 || defined _WIN32 
            creationFlag = mkdir(folderName.c_str());
        #else
            creationFlag = mkdir(folderName.c_str(),0777);
        #endif

        if(creationFlag==-1) {
        //if(mkdir(folderName.c_str())==-1) {
            std::cerr<<"Error :  "<<strerror(errno)<<std::endl;
        }
    }
                     
    // Create 'in' directory
    if(access(inFolderName.append("/in/").c_str(), 0 ) == 0) {
        if(system(((std::string)("exec rm -r " + inFolderName + "*")).c_str())==-1) {
            std::cerr<<"Error :  "<<strerror(errno)<<std::endl;
        }
    } else {
        
        int creationFlag = -1; 
        #if defined _WIN64 || defined _WIN32 
            creationFlag = mkdir(folderName.c_str());
        #else
            creationFlag = mkdir(folderName.c_str(),0777);
        #endif

        if(creationFlag==-1) {
        //if(mkdir(inFolderName.c_str())==-1) {
            std::cerr<<"Error :  "<<strerror(errno)<<std::endl;
        }
    }
    
    std::ofstream outputFile;
    unsigned short int count = 1;
    //for (std::vector<std::string*>::iterator it = nodes->begin(); it != nodes->end(); it++) {
        count_string.str("");
        count_string << count; 
        fileName = folderName + "/in/" + n_strb.str() + "_" + d_strd.str() + "_" + count_string.str() + ".txt"; 
        
        outputFile.open(fileName.c_str(), std::ios::out);
        count++;
        if (outputFile.is_open()) {
            //write states:
            outputFile << *(node) << std::endl;

            //closeing:
            outputFile.close();
        }
        else {
            std::cout << "Unable to open file";
        }
    //}
}

void pillai_bt::pillai_writer_for_output(pillai* node, const char * inputFile) {
    
    size_t pos;
    std::string str_outputFile(inputFile), str_tail(str_outputFile.substr(pos = (str_outputFile.find("in")+2), str_outputFile.length()));
    str_outputFile.replace(pos-2, str_outputFile.length(), std::string("out" + str_tail));

    std::ofstream outputFile;
        
    outputFile.open(str_outputFile.c_str(), std::ios::out);
    if (outputFile.is_open()) {
        //write states:
        
        if(!node->is_null()) {
                outputFile << node->print_sol_toString() << std::endl;
        }

        //closeing:
        outputFile.close();
    }
    else {
        std::cout << "Unable to open file";
    }
    
}

pillai* pillai_bt::pillai_reader(const char *file_path, const std::string& delimiters = " ") {
    
    std::fstream file;
    std::string line;
    pillai* sol = NULL;
    
    //Create 'out' directory:
    std::string outFolderName = file_path;
    outFolderName = outFolderName.substr(0, outFolderName.length()-(outFolderName.length()-outFolderName.find("/in")));
    if(access(outFolderName.append("/out/").c_str(), 0 )!= 0) {
//    struct stat sb;
//    if(stat(outFolderName.append("/out/").c_str(), &sb ) != 0) {
        int creationFlag = -1; 
        #if defined _WIN64 || defined _WIN32 
            creationFlag = mkdir(outFolderName.c_str());
        #else
            creationFlag = mkdir(outFolderName.c_str(),0777);
        #endif

        if(creationFlag==-1) {
        //if(mkdir(outFolderName.c_str())==-1) {
            std::cerr<<"Error :  "<<strerror(errno)<<std::endl;
        }
    }
   
    //File Opening
    file.open(file_path);
    if (file.is_open()) {
        unsigned short int count = 0, lineNumber = 0, nd[2];
        while ( file.good() ) {
            std::getline(file,line);
 
            // Read n and d
            if(lineNumber < 2) {
                std::istringstream(line) >> nd[lineNumber];
                lineNumber++;
            }
            
            // Read state
            else if (lineNumber == 2){
        
               int n = nd[0];
               int d = nd[1];
               if(sol == NULL)
                    sol = pillai::init_pillai(n, new std::vector<unsigned short int> (), d); //sol->print_all();

                std::string::size_type firstPos = line.find_first_not_of(delimiters, 0);    //find first valuable character
                std::string::size_type tokenPos = line.find_first_of(delimiters, firstPos); //find first token

                //Tokenizing
                int value = 0, prev = 0;
                while (std::string::npos != tokenPos || std::string::npos != firstPos) {
                    
                    std::istringstream(line.substr(firstPos, tokenPos - firstPos)) >> value;

                    //
                    if(value != 0) {
                        //refresh state
//                        sol->set_element(value, count);
                        sol->get_state().reset(count);
                        sol->get_postreqopBitset().reset(value);
                        sol->get_prereqopBitset().reset(value);

                        //refresh applicable operator set
//(new pillai_op(value, count, false, false, sol->get_state().size()))->print(); std::cout<<std::endl;

                            //std::cout<<count<<std::endl;
                            //std::cout<<count%value<<std::endl;
                            sol->remove_sim_ops(new pillai_op(value, -1, false, false, sol->get_state().size()));
                            //if(value > count) 
                                //_solV.push_back(new pillai_op(value, count<value?count+1:count%value+1, false, false, sol->get_state().size()));
                                _solV.insert(new pillai_op(value, count<value?count+1:count%value+1, false, false, sol->get_state().size()));
                            

                        //refresh postreqOpBitsets
                        if(pillai::get_allPostreqopBitset().test(value)) {
                            pillai::get_allPostreqopBitset().reset(value);
                        }

                        //refresh preqreqOpBitsets
                        if(pillai::get_allPrereqopBitset().test(value)) {
                            pillai::get_allPrereqopBitset().reset(value);
                        }
                    }
                    
                    count++,   
                    firstPos = line.find_first_not_of(delimiters, tokenPos);    //give back (tokenPos - firstPos) piece character from firstPos
                    tokenPos = line.find_first_of(delimiters, firstPos);
                }
                lineNumber++;
            }
            else {
                bool b;
                std::istringstream(line) >> b;
                sol->set_simChainFlag(b);
                lineNumber++;
            }
            
        }
        file.close();  
    }
    else  {
        std::cout << "Unable to open the input file.";
    }  

    return sol;                                                                 //run solver//check finish not successful state
}

void pillai_bt::pillai_generate(unsigned short int n, unsigned short int d, unsigned short int gDepth, std::string path) {
    std::vector<unsigned short int>* primesV = new std::vector<unsigned short int> ();
    pillai_bt::pillai_writer_for_input(pillai_bt::pillai_solver(n, primesV, d, gDepth), n, d, path);
    //pillai_bt::pillai_writer_for_input_p(pillai_bt::pillai_solver(n, primesV, d, gDepth), n, d, path);
    //pillai_bt::pillai_writer_for_input(pillai_bt::pillai_solver_p(n, primesV, d, gDepth), n, d, path);
}

void pillai_bt::pillai_generate_p(unsigned short int n, unsigned short int d, unsigned short int gDepth, std::string path) {
    std::vector<unsigned short int>* primesV = new std::vector<unsigned short int> ();
//    pillai_bt::pillai_writer_for_input_p(pillai_bt::pillai_solver_p(n, primesV, d, gDepth), n, d, path);
    
    std::vector<std::string*>* nodes = new std::vector<std::string*>();
    std::stringstream state_str;
    state_str.clear();
    
    pillai *sol_BUP, *sol = pillai::init_pillai(n, primesV, d);
    pillai_op* chdOp = NULL;
    
    if(gDepth == 0 || gDepth < sol->get_allPostreqopBitset().count()+sol->get_allPrereqopBitset().count() ) {
        gDepth = sol->get_allPostreqopBitset().count()+sol->get_allPrereqopBitset().count();
    }

    //simmetry sieve:
    //sol->simSieve(sol->choose_op());
    
    std::bitset<BITSET_SIZE> tempZeroEven(n);
    std::bitset<BITSET_SIZE> tempZeroOdd(n);
    std::bitset<BITSET_SIZE> tempZeroCen(n);

//    boost::posix_time::ptime start, finish, start_apply, finish_apply, start_bt, finish_bt;
//    boost::posix_time::time_duration diff, diff_apply, diff_bt;
    unsigned long int countLoop = 0, countLoop_apply = 0, countLoop_bt = 0;

    std::string *str;
    while (true) {
        
        if (sol->is_null()) {
            break;
        } else if (sol->is_finish()) {
            str = new std::string(state_str.str());
            nodes->insert(nodes->end(), str);
            state_str.str( "" );
            break;
        } else { 
            sol->update_op_bitset();
        }
        
        tempZeroEven = sol->get_state()&pillai::get_evenBitset();
        tempZeroOdd = sol->get_state()&pillai::get_oddBitset();
        tempZeroCen = sol->get_state()&pillai::get_cenBitset();
        
        
//        start = boost::posix_time::microsec_clock::local_time();
       if (!sol->get_applicable().empty() &&       
                (sol->get_maxC() >= sol->get_state().count()) &&        
                (sol->get_evenC() >= tempZeroEven.count()) &&
                (sol->get_oddC() >= tempZeroOdd.count()) &&
                (sol->get_maxCC() >= tempZeroCen.count()) &&
//                (chdOp != NULL) ) {
                ((chdOp = sol->choose_op()) != NULL) ) {
           
           if (sol->get_depth() == gDepth) {
              
               //std::cout<<"TEST:"<<std::endl;
            //  for(int i = 1; i<10000000; i++)   { 
            
                state_str<< n << "\n" << d << "\n" << sol->statePrintToString()<<"\n"<<sol->get_simChainFlag()<<"\n";
                str = new std::string(state_str.str());
                nodes->insert(nodes->end(), str);
                state_str.str( "" );
                //std::cout<<"BT2"<<std::endl;
                //sol_BUP = sol;
                sol = sol->back_track();
                //sol_BUP->~pillai();
//                sol = sol->apply_op(chdOp);
                
             //}
              //break;
                continue;
           }
           
//            start_apply = boost::posix_time::microsec_clock::local_time();      
            sol = sol->apply_op(chdOp);

//            finish_apply = boost::posix_time::microsec_clock::local_time();
//            diff_apply += finish_apply - start_apply;
            countLoop_apply++;

        } else {
//            start_bt = boost::posix_time::microsec_clock::local_time();
            sol = sol->back_track();
           //sol_BUP->~pillai();

//            finish_bt = boost::posix_time::microsec_clock::local_time();
//            diff_bt += finish_bt - start_bt;
            countLoop_bt++;
        }
        
//        finish = boost::posix_time::microsec_clock::local_time();
//        diff += finish - start;
        countLoop++;
    }
}

void pillai_bt::pillai_solver_f(const char * file) {
    pillai_writer_for_output(pillai_solver(pillai_bt::pillai_reader(file, " ")), file);
}

