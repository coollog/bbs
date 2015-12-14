/*
 * Tester.hpp
 *
 *  Created on: Nov 27, 2015
 *      Author: mike
 */

#ifndef TESTER_HPP_
#define TESTER_HPP_

#include "Blum.hpp"
#include "bbs.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;

//=============================================================================
class Tester {
private:
    // gmp non-cryptographically secure pseudorandom number generator
    gmp_randclass& gmpGen;

    // BBS generator parameters and instance
    mpz_class modulus;  // Current BBS modulus
    mpz_class seed;     // Current BBS seed
    BBS bbsGen;         // Current BBS generator

    // State variables to ensure that BBS generator is fully initialized
    bool haveMod = false;
    bool haveGen = false;

private:
    // Commands
    void doGenBI(stringstream& ss);
    void doReadBI(stringstream& ss);
    void doSrand(stringstream& ss);
    void doRand(stringstream& ss);

public:
    Tester( gmp_randclass& rnd ) : gmpGen(rnd) {
    }

    void run();
};

#endif /* TESTER_HPP_ */
