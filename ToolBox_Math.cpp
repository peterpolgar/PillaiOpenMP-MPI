/*
 * ToolBox_Math.cpp
 *
 *  Created on: Nov 8, 2011
 *      Author: addy
 */

#include "ToolBox_Math.h"
#include <iostream>

/**
 * Test a number. If the number is a prime give true answer.
 * @param n - the number.
 * @return - boolean value {true|false}
 */
bool TB_Math::isPrime(unsigned short int n) {

    for (unsigned short int i = n - 1; i > 1; i--) {
        if ((n % i) == 0) {
            return false;
        }
    }
    return true;
}

unsigned short int* TB_Math::gPrimes(unsigned short int n) {

    unsigned short int *cv = new unsigned short int[n];
    for (unsigned short int i = 2, p = 0; p < n; i++) {
        if (isPrime(i)) {
            cv[p] = i;
            p++;
        }
    }
    return cv;
}

//std::vector<unsigned short int>* TB_Math::gPrimesV(unsigned short int n) {
//
//    std::vector<unsigned short int>* cv = new std::vector<unsigned short int>(n);
//    for (unsigned short int i = 2, p = 0; p < n; i++) {
//        if (isPrime(i)) {
//            //cv->assign(cv->begin(),i);
//            p++;
//        }
//    }
//    return cv;
//}

unsigned short int* TB_Math::gSmallerPrimes(unsigned short int d) {

    unsigned short int* cv = new unsigned short int[d + 1];
    cv[0] = 0;
    for (unsigned short int i = 2; i < d; i++) {
        if (isPrime(i)) {
            cv[0]++;
            cv[cv[0]] = i;
        }
    }
    return cv;
}

unsigned short int* TB_Math::gGraterPrimes(unsigned short int d, unsigned short int m) {

    unsigned short int*cv = new unsigned short int[m];
    unsigned short int flag = 1;
    for (unsigned short int i = d + 1, p = 0; p < m; i++) {
        if (isPrime(i)) {
            cv[p] = i;
            p++;
        }
    }
    return cv;
}

unsigned short int* TB_Math::gPrimes(unsigned short int n, unsigned short int m) {

    unsigned short int*cv = new unsigned short int[m];
    unsigned short int flag = 1;
    for (unsigned short int i = 1, p = 0; p < m; i++) {
        if (isPrime(i) && (flag >= n)) {
            cv[p] = i;
            p++;
        } else if (isPrime(i)) {
            flag++;
        }
    }
    return cv;
}

unsigned short int TB_Math::nChooseK(unsigned short int n, unsigned short int k) {
    return (fakt(n) / (fakt(k) * fakt(n - k)));
}

unsigned int TB_Math::fakt(unsigned short int n) {
    unsigned int prod = 1;
    for (unsigned short int i = 1; i <= n; ++i) {
        prod *= i;
    }
    return prod;
}
