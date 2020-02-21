/*
Author: Sean Chen
Date: February 13, 2020
Written for CS 4220 at UCCS Spring 2020
2. CRC for Error Detection

Write a program in C (or C++) that can convert a bit stream of a message into a frame by using CRC. The bit stream is 
the first input parameter of the program, which will have 8 to 128 bits. The generator function is the second input 
parameter of the program, which will have 4 to 16 bits. For example, if the generator function is x^4 + x + 1, the second 
input will be 10011. The output should be the transmitted bit stream with its CRC checksum bits; see example in Figure 
3-9 in the textbook.

Some self-testing examples are:
Input = 10011101, generator 1001, output 10011101100.
Input = 1101011011, generator 10011, output 11010110111110.
Input = 10011101, generator 1001, output 10011101100.
Input = 1101011011011100, generator 1101110111011101, output 1101011011011100110101101101110 

tl;dr
________________________________________________________________________________________________
|Do CRC checksums where the first arg is the input, and the second argument is the CRC checksum|
|______________________________________________________________________________________________|
*/

// These defines just make the output to the terminal include color
#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define BLUE    "\033[34m"      /* Blue */
#define GREEN   "\033[32m"      /* Green */

// Include basic headers that will be needed for the program to function
#include <iostream>
#include <string>
#include <tuple>
#include <cstdlib>
#include <cmath>

// These print functions simply standardize the output to the screen with color
void printStage(std::string msg) {
    std::cout << GREEN << "[+] " << RESET << msg << std::endl;
}

void printStep(std::string msg) {
    std::cout << BLUE << "[*] " << RESET << msg << std::endl;
}

void printWarning(std::string warning) {
    std::cout << RED << "[!] "<< RESET << warning << std::endl;  
}

// Gets the degree of the generator
int findDegree(std::string generator) {
    return generator.length() -1;
}

// CheckInput checks the user supplied command-line arguments to ensure that there are no invalid characters.
bool checkInput(std::string checkString) {
    for(int i = 0; i < (signed)checkString.length(); i++) {
        if(checkString[i] == '1' || checkString[i] == '0') {
            continue;
        }
        else {
            return true;
        }
    }
    return false;
}

// Start of main
int main(int argc, char **argv) {
    std::cout << "****Running part 2 for Project 1****\n" << std::endl; // Output which part of the project is being run
    if (argc < 3) { // Test to make sure enough arguments are passed in otherwise print the usage and exit.
        printWarning("Not enough arguments!\n    Usage: ./2 binaryStream generator");
        exit(-1);
    }
    if(checkInput(argv[1]) && checkInput(argv[2])) { // Check the user input characters
        printWarning("Invalid input provided!");
        exit(-1);
    }
    int crcLength = 0;
    std::string tempBitStream = argv[1];
    // Output the bitstream to and the crc to the user
    printStage("Input bitstream: "+(std::string)argv[1]);
    printStage("Input CRC: "+(std::string)argv[2]);
    printStep("Finding CRC Checksum length and appending to the bitstream...");
    crcLength = findDegree((std::string)argv[2]); // Gets the degree of the generator and then appends 0's to the end of the temporary bitstream
    for(int i = 0; i < crcLength; i++) {
        tempBitStream += '0';
    }
    printStep("XOR'ing the generator with the bit stream...");
    for(int i = 0; i < (signed)tempBitStream.length()-crcLength; i++) { // Loop through the temporary bit stream and XOR the bits with the generator
        if(tempBitStream[i] == '0') { // If while looping through we land on a 0, just skip the zero since it doesn't make sense to XOR nothing
                continue;
            }
        for(int j = 0; j < crcLength+1; j++) { // Loop through the size of the generator and XOR all the bits along the way between the temporary bit stream and the generator
            if(tempBitStream[i+j] == argv[2][j]) {
                tempBitStream[i+j] = '0';
            }
            else {
                tempBitStream[i+j] = '1';
            }
        }
    }
    printStage("Bit stream after XOR: "+tempBitStream); // Output the bitstream after being XOR'd
    std::string crcCheckSum = "";
    for(int i = tempBitStream.length()-crcLength; i < (signed)tempBitStream.length(); i++) { // copy the CRC Checksum(The bits appended earlier) to the end of the original bit string.
        crcCheckSum += tempBitStream[i];
    }
    // Output the CRC Checksum information and the final bitstring with the CRC Checksum appended to it.
    printStage("CRC Checksum: "+crcCheckSum);
    printStep("Appending Checksum to original bit stream...");
    printStage("Final bit stream: "+(std::string)argv[1]+crcCheckSum);

    return 0;
}