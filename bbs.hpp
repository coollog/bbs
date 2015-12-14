/*
 * bbs.hpp
 *
 *  Created on: Nov 24, 2015
 *      Author: Michael J. Fischer
 */

#ifndef BBS_HPP_
#define BBS_HPP_

#include <gmpxx.h>

// Blum-Blum-Shub pseudo-random sequence generator
class BBS {
private:
    mpz_class n;        // Blum integer
    mpz_class state;    // State of BBS generator

    int lsb() const;    // Least significant bit

public:
    BBS() =default;
    BBS( mpz_class n, mpz_class seed );

    void srand( mpz_class seed );   // Seed the BBS generator
    mpz_class rand( int num );      // Return num pseudorandom bits
};

#endif /* BBS_HPP_ */
