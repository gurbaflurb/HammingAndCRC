/*
Author: Sean Chen
Date: February 13, 2020
Written for CS 4220 at UCCS Spring 2020

1.2 Write a program in C (or C++) that can correct a single-bit error of a frame by using Hamming coding and output
the packet (raw data). The incoming frame is the input parameter of the program. The output is the bit stream of a packet. 
For example, given an input parameter as 00110010001 (the correct frame should actually be 00110010000), the output bit 
stream is 1001000. Input frame will have 3 to 71 bits.

Some self-testing examples are:
Input 00110010000; output 1001000
Input 00110010001; output 1001000
Input 011110110011001110101; output 1101001100110101
Input 11110100101; output 1010101
Input 111011101111; output 11111111
Input 11110000101; output 1010101

tl;dr
_____________________________________
|Use hamming to correct a single bit|
|___________________________________|
*/
#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define BLUE    "\033[34m"      /* Blue */
#define GREEN   "\033[32m"      /* Green */

#include <iostream>
#include <string>
#include <tuple>
#include <cstdlib>
#include <cmath>

void printStage(std::string msg) {
    std::cout << GREEN << "[+] " << RESET << msg << std::endl;
}

void printStep(std::string msg) {
    std::cout << BLUE << "[*] " << RESET << msg << std::endl;
}

void printWarning(std::string warning) {
    std::cout << RED << "[!] "<< RESET << warning << std::endl;  
}

int main(int argc, char **argv) {
    std::cout << "****Running part 1.2 for Project 1****\n" << std::endl;
    if (argc < 2) {
        printWarning("Not enough arguments!");
        std::cout << "    Usage: ./1.2 binaryStream" << std::endl;  
        exit(-1);
    }
    printStage("Inputted bitstream: "+(std::string)argv[1]);
    printStep("Finding the correct bitsteam");
    int invalidBit = -1;
    std::string finalBitStream = argv[1];
    for(int i = 0; i < (signed)finalBitStream.length(); i++) {
        if(i == 0 || i == 1 || i == 3 || i== 7 || i == 15 || i == 31 || i == 63) {
            int gap = i+1;
            int parityCount = 0;
            for(int j=i; j < (signed)finalBitStream.length(); j+=gap*2) {
                for(int k = 0; k < gap; k++) {
                    if((j+k) >(signed)finalBitStream.length()) {
                        break;
                    }
                    else {
                        if (finalBitStream[j+k] == '1') {
                            parityCount++;
                        }
                    }
                }
            }
            if(parityCount%2) {
                if(finalBitStream[i] != '1') {
                    if(invalidBit == -1) {
                        invalidBit += 1 + i;
                    }
                    else {
                        invalidBit += i;
                    }
                }
            }
            else {
                if (finalBitStream[i] != '0') {
                    if(invalidBit == -1) {
                        invalidBit += -1 + i;
                    }
                    else {
                        invalidBit += i;
                    }
                }
            }
        }
    }
    if(invalidBit != -1) {
        if(finalBitStream[invalidBit] == '1') {
            finalBitStream[invalidBit] = '0';
        }
        else {
            finalBitStream[invalidBit] = '1';
        }
    }
    printStage("Hamming Code Corrected: "+finalBitStream);
    printStep("Removing parity bits...");
    std::string originalBits = "";
    for(int i = 0; i < (signed)finalBitStream.length(); i++) {
        if(i == 0 || i == 1 || i == 3 || i== 7 || i == 15 || i == 31 || i == 63) {
            continue;
        }
        else {
            originalBits += finalBitStream[i];
        }
    }
    printStage("Original bits without parity bits: "+originalBits);
    return 0;
}