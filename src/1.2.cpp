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
    std::cout << "****Running part 1.2 for Project 1****\n" << std::endl; // Output which part of the project is being run
    if (argc < 2) { // Test to make sure enough arguments are passed in otherwise print the usage and exit.
        printWarning("Not enough arguments!");
        std::cout << "    Usage: ./1.2 binaryStream" << std::endl;  
        exit(-1);
    }
    if(checkInput(argv[1])) { // Check the user input characters
        printWarning("Invalid input provided!");
        exit(-1);
    }
    printStage("Input bitstream: "+(std::string)argv[1]); // output what the input bitstream is
    printStep("Finding the correct bitsteam...");
    int invalidBit = -1; // set the invalid bit to -1 so that we can check if a bit has been flipped.
    std::string finalBitStream = argv[1];
    for(int i = 0; i < (signed)finalBitStream.length(); i++) { // Loop through the final bit stream
        if(i == 0 || i == 1 || i == 3 || i== 7 || i == 15 || i == 31 || i == 63) { // if we are on any of these values, then we have made it to a parity bit that needs to be checked.
            int gap = i+1; // dynamically find the gap between bits that need to be checked, for the first one its every other bit, second we skip two bits for every two bits we read in and so on.
            int parityCount = 0;
            for(int j=i; j < (signed)finalBitStream.length(); j+=gap*2) { // loop through the rest of the bitstream starting from the parity bit we found with the outer loop
                for(int k = 0; k < gap; k++) { // loop through the bits in the bitstream that affect the parity bit.
                    if((j+k) >(signed)finalBitStream.length()) {
                        break;
                    }
                    else {
                        if (finalBitStream[j+k] == '1') { // count up the 1's that affect the parity.
                            parityCount++;
                        }
                    }
                }
            }
            if((parityCount%2) != 0) { // if the parity is wrong then we know a bit is flipped
                if(invalidBit == -1) { // Check if the invalid bit has been set already
                    invalidBit += 1 + gap; // If not then add an extra 1 to zero out the invalid bit for the rest of the bits
                }
                else {
                    invalidBit += gap; // otherwise just add the other parity bit that is wrong.
                }
            }
        }
    }
    if(invalidBit != -1) { // check if the invalid bit is set, if so then flip the located invalid bit in the sequence
        if(finalBitStream[invalidBit-1] == '1') {
            finalBitStream[invalidBit-1] = '0';
        }
        else {
            finalBitStream[invalidBit-1] = '1';
        }
    }
    printStage("Hamming Code Corrected: "+finalBitStream); // output the corrected code
    printStep("Removing parity bits...");
    std::string originalBits = "";
    for(int i = 0; i < (signed)finalBitStream.length(); i++) { // loop through the corrected code and remove the parity bits from the sequence.
        if(i == 0 || i == 1 || i == 3 || i== 7 || i == 15 || i == 31 || i == 63) {
            continue;
        }
        else {
            originalBits += finalBitStream[i];
        }
    }
    printStage("Original bits without parity bits: "+originalBits); // print the original bit stream to the user.
    return 0;
}