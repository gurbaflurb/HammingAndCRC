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
-------------------------------------
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
    return 0;
}