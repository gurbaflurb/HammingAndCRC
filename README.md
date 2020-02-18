# CS 4220 Computer Networks Project 1
These programs were written for CS 4220 Computer Networks at UCCS Spring 2020

## Notes
- I wrote this on Linux and noticed some compatability issues on windows, namely that the executables genereated dont run by default. To fix this simply add `.exe` to the end of the executables and then you should be able to run them in powershell or CMD with command line arguments in the form: `1.1.exe 1010101011`.
- I have colored output in the terminal to improve readability, as noted above, the colors might not work on traditional powershell or CMD on windows, in which case the answer will just look a bit different but will still be in the output. 

## Compilation
- There is a make file included in this directory. To compile the files omit the extension and use the comand `make compile(fileNameNoExtension)`
- Ex. `make compile1.1` will compile 1.1.cpp in this project.
- This will make an executable in the current directory named 1.1, 1.2, or 2 depending on which one you want to run
- You can also compile all of the files at once by running `make compile-all` which will compile each program and write all their executables to the currect directory.

## Tests
