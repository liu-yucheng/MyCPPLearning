/* Ref: http://www.cplusplus.com/doc/tutorial/files/
 * A program that shows the usage of C++ file input and output */

/* Copyright 2022 Yucheng Liu. GNU GPL3 license.
 * GNU GPL3 license copy: https://www.gnu.org/licenses/gpl-3.0.txt */

#include <sys/stat.h>

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv) {
    // Use mkdir to create directories
    mkdir("./input", 0775);
    mkdir("./output", 0775);
    mkdir("./cache", 0755);

    // Use ofstream (output file stream) to write a text file
    string out1TxtName = "./output/out1.txt";
    ofstream out1Txt;
    out1Txt.open(out1TxtName.c_str());
    // See if the file is open
    if (!out1Txt.is_open()) {
        cout << "main: out1Txt (" << out1TxtName << ") is not open" << endl;
        cout << "main: program exiting" << endl;
        return EXIT_FAILURE;
    }
    cout << "main: writing out1Txt (" << out1TxtName << ")" << endl;
    // Write text into the file
    out1Txt << "Content written into out1.txt\n";
    out1Txt.flush();
    out1Txt.close();

    // Use ifstream (input file stream) to read a text file
    string in2TxtName = "./input/in2.txt";
    ifstream in2Txt;
    in2Txt.open(in2TxtName.c_str());
    if (!in2Txt.is_open()) {
        cout << "main: in2Txt (" << in2TxtName << ") is not open" << endl;
        cout << "main: program exiting" << endl;
        return EXIT_FAILURE;
    }
    cout << "main: reading in2Txt (" << in2TxtName << ")" << endl;
    cout << "====_ " << in2TxtName << " _====" << endl;
    // Read text from the file
    string line;
    while (getline(in2Txt, line)) {
        cout << line << "\n";
    }
    cout.flush();
    cout << "====^ " << in2TxtName << " ^====" << endl;
    in2Txt.close();

    // Use fstream to write a binary file
    string block3BinName = "./cache/block3.bin";
    fstream block3Bin;
    // clang-format off
    block3Bin.open(
        block3BinName,
        ios::in | ios::out | ios::binary | ios::trunc
    );
    // clang-format on
    if (!block3Bin.is_open()) {
        cout << "main: block3Bin (" << block3BinName << ") is not open" << endl;
        cout << "main: program exiting" << endl;
        return EXIT_FAILURE;
    }
    cout << "main: writing block3Bin (" << block3BinName << ")" << endl;
    // Write hex pattern into the file
    char pattern[3] = {'\x95', '\x59', '\x55'};
    for (int iter = 0; iter < 42; iter += 1) {
        block3Bin.write(pattern, 3);
    }

    // Use tellg and seekg to measure the size of a file
    block3Bin.seekg(0, ios::beg);
    streampos start = block3Bin.tellg();
    block3Bin.seekg(0, ios::end);
    streampos end = block3Bin.tellg();
    streampos sizeB = end - start;
    cout << "main: size of block3Bin (" << block3BinName << "): " << sizeB
         << "B" << endl;

    // Use fstream to read a binary file
    cout << "main: reading block3Bin (" << block3BinName << ")" << endl;
    cout << "====_ " << block3BinName << " (hex str) _====" << endl;
    // Read binary data from the file
    unsigned char byte[1];
    char hex[3];
    line = "";
    block3Bin.seekg(0, ios::beg);
    while (true) {
        block3Bin.read((char *)byte, 1);
        if (block3Bin.eof()) {
            break;
        }
        sprintf(hex, "%x", byte[0]);
        line += hex[0];
        line += hex[1];
        if (line.length() >= 79) {
            cout << line << "\n";
            line = "";
        }
    }
    cout << line << endl;
    cout << "====^ " << block3BinName << " (hex str) ^====" << endl;
    block3Bin.close();

    cout << "main: cheers!" << endl;
    return EXIT_SUCCESS;
}
