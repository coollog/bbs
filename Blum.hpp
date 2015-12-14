/*
 * Blum.hpp
 *
 *  Created on: Nov 25, 2015
 *      Author: Michael J. Fischer
 */

#ifndef BLUM_HPP_
#define BLUM_HPP_

#include <gmpxx.h>

class Blum {
private:
    gmp_randclass& rng;

public:
    Blum( gmp_randclass& r );

    // Returns a random Blum prime of s bits or less
    mpz_class randBlumPrime( mp_bitcnt_t s );

    // Returns a random Blum integer of s bits or less
    mpz_class randBlumInt( mp_bitcnt_t s );
};

#endif /* BLUM_HPP_ */
