/*
 * File:   .h
 * Author: Laszlo Kovacs
 * Desc: .
 * Version: v001
 * OS: Linux
 *
 * Created on October 5, 2011, 9:50 AM
 */

#ifndef TOOLBOX_MATH_H
#define	TOOLBOX_MATH_H

#include <vector>


namespace TB_Math {

bool isPrime(unsigned short int);
unsigned short int* gPrimes(unsigned short int);
//std::vector<unsigned short int>* gPrimesV(unsigned short int);
unsigned short int* gPrimes(unsigned short int,unsigned short int);
unsigned short int* gGraterPrimes(unsigned short int,unsigned short int);
unsigned short int* gSmallerPrimes(unsigned short int);
unsigned short int nChooseK(unsigned short int, unsigned short int);
unsigned int fakt(unsigned short int);
}  // namespace TB_Math

#endif	/*TOOLBOX_MATH_H*/
