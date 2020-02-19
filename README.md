# CS 4220 Computer Networks Project 1
These programs were written for CS 4220 Computer Networks at UCCS Spring 2020

## Notes
- I have colored output in the terminal to improve readability, the colors might not work on traditional powershell or CMD on windows, in which case the answer will just look a bit different but will still be in the output. 

## Compilation
- There is a make file included in this directory. To compile the files omit the extension and use the comand `make compile(fileNameNoExtension)`
- Ex. `make compile1.1` will compile 1.1.cpp in this project.
- This will make an executable in the current directory named 1.1, 1.2, or 2 depending on which one you want to run
- You can also compile all of the files at once by running `make compile-all` which will compile each program and write all their executables to the currect directory.
- When you run `make compile-all` you also need to specify the OS you are on. For linux its `make compile-all-linux` and for windows it's `make compile-all-windows`.

## Self Tests
### 1.1
- Input 1001000; output 00110010000
```
[+] Populating the final string...
[*] Populated!
[*] Populated string: 00100010000
[+] Calculating Hamming...
[+] Hamming Code: 00110010000
```

- Input 1101001100110101; output 011110110011001110101
```
[+] Populating the final string...
[*] Populated!
[*] Populated string: 001010100011001010101
[+] Calculating Hamming...
[+] Hamming Code: 011110110011001110101
```
- Input 1010101; output 11110100101
```
[+] Populating the final string...
[*] Populated!
[*] Populated string: 00100100101
[+] Calculating Hamming...
[+] Hamming Code: 11110100101
```

- Input 11111111; output 111011101111
```
[+] Populating the final string...
[*] Populated!
[*] Populated string: 001011101111
[+] Calculating Hamming...
[+] Hamming Code: 111011101111
```

### 1.2
- Input 00110010000; output 1001000
```
[+] Input bitstream: 00110010000
[*] Finding the correct bitsteam...
[+] Hamming Code Corrected: 00110010000
[*] Removing parity bits...
[+] Original bits without parity bits: 1001000
```

- Input 00110010001; output 1001000
```
[+] Input bitstream: 00110010001
[*] Finding the correct bitsteam...
[+] Hamming Code Corrected: 00110010000
[*] Removing parity bits...
[+] Original bits without parity bits: 1001000
```

- Input 011110110011001110101; output 1101001100110101
```
[+] Input bitstream: 011110110011001110101
[*] Finding the correct bitsteam...
[+] Hamming Code Corrected: 011110110011001110101
[*] Removing parity bits...
[+] Original bits without parity bits: 1101001100110101
```

- Input 11110100101; output 1010101
```
[+] Input bitstream: 11110100101
[*] Finding the correct bitsteam...
[+] Hamming Code Corrected: 11110100101
[*] Removing parity bits...
[+] Original bits without parity bits: 1010101
```

- Input 111011101111; output 11111111
```
[+] Input bitstream: 111011101111
[*] Finding the correct bitsteam...
[+] Hamming Code Corrected: 111011101111
[*] Removing parity bits...
[+] Original bits without parity bits: 11111111
```

- Input 11110000101; output 1010101
```
[+] Input bitstream: 11110000101
[*] Finding the correct bitsteam...
[+] Hamming Code Corrected: 11110100101
[*] Removing parity bits...
[+] Original bits without parity bits: 1010101
```

### 2
- Input = 10011101, generator 1001, output 10011101100.
```
[+] Input bitstream: 10011101
[+] Input CRC: 1001
[*] Finding CRC Checksum length and appending to the bitstream...
[*] XOR'ing the generator with the bit stream...
[+] Bit stream after XOR: 00000000100
[+] CRC Checksum: 100
[*] Appending Checksum to original bit stream...
[+] Final bit stream: 10011101100
```

- Input = 1101011011, generator 10011, output 11010110111110.
```
[+] Input bitstream: 1101011011
[+] Input CRC: 10011
[*] Finding CRC Checksum length and appending to the bitstream...
[*] XOR'ing the generator with the bit stream...
[+] Bit stream after XOR: 00000000001110
[+] CRC Checksum: 1110
[*] Appending Checksum to original bit stream...
[+] Final bit stream: 11010110111110
```

- Input = 10011101, generator 1001, output 10011101100.
```
[+] Input bitstream: 10011101
[+] Input CRC: 1001
[*] Finding CRC Checksum length and appending to the bitstream...
[*] XOR'ing the generator with the bit stream...
[+] Bit stream after XOR: 00000000100
[+] CRC Checksum: 100
[*] Appending Checksum to original bit stream...
[+] Final bit stream: 10011101100
```

- Input = 1101011011011100, generator 1101110111011101, output 1101011011011100110101101101110
```
[+] Input bitstream: 1101011011011100
[+] Input CRC: 1101110111011101
[*] Finding CRC Checksum length and appending to the bitstream...
[*] XOR'ing the generator with the bit stream...
[+] Bit stream after XOR: 0000000000000000110101101101110
[+] CRC Checksum: 110101101101110
[*] Appending Checksum to original bit stream...
[+] Final bit stream: 1101011011011100110101101101110
```
