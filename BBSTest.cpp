/*
 * BBSTest.cpp
 *
 *  Created on: Nov 26, 2015
 *      Author: mike
 */

// Reads and processes a sequence of subcommands lines from standard input.
// Commands:
// genBI size:   Generates. stores, and prints a Blum integer.
// readBI file:  Reads and prints a Blum integer from specified file.
// srand [seed]: Creates and seeds a BBS generator. Uses time(nullptr) if
//               argument is omitted.
// rand num:     Generates num random bits using current BBS generator.

#include "Tester.hpp"

//=============================================================================
int main(int argc, char* argv[]) {
    // Check arguments
    if (argc > 2 || (argc > 1 && string(argv[1]) == "-h") ) {
        string progname = argv[0];
        size_t pos = progname.find_last_of("/");
        if (pos != string::npos) {
            progname = progname.substr(pos + 1);
        }
        cout << "usage: " << progname << " [seed]" << endl;
        return 0;
    }

    cout << "Welcome to BBS tester" << endl;

    mpz_class mySeed;
    if (argc == 2) {  // seed argument present
        mySeed = strtol(argv[1], nullptr, 0);
    } else {
        mySeed = time(nullptr);   // default for missing seed
        cout << "GMP seed argument omitted; using current time (insecure)" << endl;
    }
    cout << "gmp seed = " << mySeed << "\n" << endl;

    // Set up gmp (non-cryptographic) PRNG
    gmp_randclass rnd( gmp_randinit_default);
    rnd.seed(mySeed);

    // Run tester
    Tester test(rnd);
    test.run();

    cout << "Goodbye!" << endl;
}

