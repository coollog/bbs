#include "bbs.hpp"

int BBS::lsb() const {
  mpz_class two = 2;
  return state % two;
}

BBS::BBS(mpz_class n, mpz_class seed) : n(n), state(seed) {}

void BBS::srand(mpz_class seed) {

}

mpz_class BBS::rand(int num) {

}

// // Blum-Blum-Shub pseudo-random sequence generator
// class BBS {
// private:
//     mpz_class n;        // Blum integer
//     mpz_class state;    // State of BBS generator

//     int lsb() const;    // Least significant bit

// public:
//     BBS() =default;
//     BBS( mpz_class n, mpz_class seed );

//     void srand( mpz_class seed );   // Seed the BBS generator
//     mpz_class rand( int num );      // Return num pseudorandom bits
// };