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
    std::cout << "****Running part 2 for Project 1****\n" << std::endl;
    if (argc < 2) {
        printWarning("Not enough arguments!");
        std::cout << "    Usage: ./2 binaryStream" << std::endl;  
        exit(-1);
    }
    return 0;
}