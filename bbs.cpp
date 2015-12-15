#include "bbs.hpp"

int BBS::lsb() const {
  return mpz_tstbit(state.get_mpz_t(), 0);
}

BBS::BBS(mpz_class n, mpz_class seed) : n(n), state(seed) {}

void BBS::srand(mpz_class seed) {
  state = seed;
}

mpz_class BBS::rand(int num) {
  mpz_class b;
  for (unsigned int i = 0; i < num; i ++) {
    // Next state.
    state = (state * state) % n;
    // Set the bit.
    int bi = lsb();
    if (bi) mpz_setbit(b.get_mpz_t(), i);
    else mpz_clrbit(b.get_mpz_t(), i);
  }
  return b;
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