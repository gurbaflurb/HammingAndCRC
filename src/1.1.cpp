/*
Author: Sean Chen
Date: February 13, 2020
Written for CS 4220 at UCCS Spring 2020

1.1 Write a program in C (or C++) that can convert a bit stream of a message into a frame by using Hamming coding. The bit 
stream is the input parameter of the program. For example, given an input parameter as 1001000, the correct output of the 
frame is 00110010000. Input bit stream will have 1 to 64 bits.

Some self-testing examples are:
Input 1001000; output 00110010000
Input 1101001100110101; output 011110110011001110101
Input 1010101; output 11110100101
Input 11111111; output 111011101111 

tl;dr
______________________________________
|Is actually just regular hamming ECC|
--------------------------------------
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

class bitstream {
    private:
        std::string bits;

    public:
        bitstream(char *argv) {
            bits = argv;
        }
        std::string getBits() {
            return bits;
        }
        void setBits(std::string newBits) {
            bits = newBits;
        }
        int getLength() {
            return bits.length();
        }
        int *getPartity() {
            int *ptr = (int *)malloc(sizeof(int)*7);
            int len = getLength();
            for(int i = 0; i < 7; i++) {
                if((std::pow(2, i) <= len)) {
                    ptr[i] = std::pow(2, i);
                }
            }
            return ptr;
        }
};

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
    std::cout << "****Running part 1.1 for Project 1****\n" << std::endl;
    if (argc < 2) {
        printWarning("Not enough arguments!");
        std::cout << "    Usage: ./1.1 binaryStream" << std::endl;  
        exit(-1);
    }
    bitstream input(argv[1]); // Create a bitstream for the inputed argument
    int *ptr = input.getPartity(); // Get which bits should be in parity
    std::string finalBitStream = "";

    // Create final output string
    printStage("Populating the final string...");
    int end = input.getLength();
    int offset = 0;
    for(int i = 0; i < end; i++) {
        if(i == 0 || i == 1 || i == 3 || i== 7 || i == 15 || i == 31 || i == 63) {
            finalBitStream += '0';
            offset++;
            end++;
        }
        else {
            finalBitStream += argv[1][i-offset];
        }
    }
    printStep("Populated!");
    printStep("Populated string: " + finalBitStream);
    printStage("Calculating Hamming...");

    // Calculate what the parity bits should be
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
                finalBitStream[i] = '1';
            }
        }
    }
    printStage("Hamming Code: "+finalBitStream);
    
    free(ptr); //Free memory on the heap
    
    /*
    - Read in parity bit
    - calculate what the parity bit should be
    - Input the parity bit into the stream
    */

    return 0;
}