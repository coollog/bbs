/*
 * Tester.cpp
 *
 *  Created on: Nov 27, 2015
 *      Author: mike
 */

// Command processor for BBS pseudorandom sequence generator
#include "Tester.hpp"

//-----------------------------------------------------------------------------
void Tester::run() {
    cout << "Commands are:\t\n"
            "  genBI size:\tGenerates a random size-bit Blum integer.\n"
            "  readBI file:\tReads a Blum integer from file.\n"
            "  srand [seed]:\tCreates and seeds a BBS generator.\n"
            "  \t\tUses time(nullptr) if seed is omitted.\n"
            "  rand num:\tGenerates num bits using current BBS generator.\n"
            "  quit\t\tExit program." << endl;

    while (!cin.eof()) {
        cout << "> ";           // prompt
        string line;
        getline(cin, line);
        if (!cin.good())
            break;
        stringstream ss(line);

        string cmd;
        ss >> cmd;
        if (cmd == "genBI")
            doGenBI(ss);
        else if (cmd == "readBI")
            doReadBI(ss);
        else if (cmd == "srand")
            doSrand(ss);
        else if (cmd == "rand")
            doRand(ss);
        else if (cmd == "quit")
            break;
        else
            cout << "Unknown command \"" << cmd << "\"" << endl;
    }
}

//-----------------------------------------------------------------------------
void Tester::doGenBI(stringstream& ss) {
    mp_bitcnt_t size;
    ss >> size;
    if (ss.fail()) {
        cout << "genBi requires size argument" << endl;
        return;
    }
    if (size < 6) {
        cout << "size must be >= 6" << endl;
        return;
    }
    Blum bl(gmpGen);
    modulus = bl.randBlumInt(size);
    if (modulus == -1)
        return;
    cout << "Modulus: " << hex << showbase << modulus << endl;
    haveMod = true;
}

//-----------------------------------------------------------------------------
void Tester::doReadBI(stringstream& ss) {
    string fileName;
    ss >> fileName;
    if (ss.fail()) {
        cout << "readBI requires file name argument" << endl;
        return;
    }
    ifstream cin(fileName);
    if (!cin) {
        cout << "readBI: Can't open file \"" << fileName << "\" for reading"
                << endl;
        return;
    }

    // Read modulus in prefix-specified base
    cin >> setbase(0) >> modulus;
    if (cin.fail()) {
        cout << "readBI: Can't read modulus from file \"" << fileName << "\""
                << endl;
        return;
    }
    cout << "Modulus: " << hex << showbase << modulus << endl;
    haveMod = true;
}

//-----------------------------------------------------------------------------
void Tester::doSrand(stringstream& ss) {

    if (!haveMod) {
        cout << "srand: Must set modulus for BBS generator first" << endl;
        return;
    }
    mpz_class seed;
    ss >> setbase(0) >> seed;
    if (ss.fail()) {
        seed = time(nullptr);
        cout << "Using time for seed" << endl;
    }
    cout << "Seed: " << dec << seed << endl;
    bbsGen = BBS(modulus, seed);
    haveGen = true;

}

//-----------------------------------------------------------------------------
void Tester::doRand(stringstream& ss) {

    if (!haveGen) {
        cout << "rand: Must use srand before using rand" << endl;
        return;
    }

    int numBits;
    ss >> numBits;
    if (ss.fail()) {
        cout << "rand requires number of bits argument" << endl;
        return;
    }
    cout << dec << numBits << " random bits from BBS: " << hex << showbase
            << bbsGen.rand(numBits) << endl;
}

