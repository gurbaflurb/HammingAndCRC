compile1.1-linux:
	@echo "Compiling 1.1.cpp into executable 1.1"
	@g++ -o 1.1 src/1.1.cpp

compile1.2-linux:
	@echo "Compiling 1.2.cpp into executable 1.2"
	@g++ -o 1.2 src/1.2.cpp

compile2-linux:
	@echo "Compiling 2.cpp into executable 2"
	@g++ -o 2 src/2.cpp

compile-all-linux:
	@echo "Compiling all programs for project 1"
	@echo "Compiling 1.1.cpp into 1.1"
	@g++ -o 1.1 src/1.1.cpp
	@echo "Compiling 1.2.cpp into 1.2"
	@g++ -o 1.2 src/1.2.cpp
	@echo "Compiling 2.cpp into  2"
	@g++ -o 2 src/2.cpp

compile1.1-windows:
	@echo "Compiling 1.1.cpp into executable 1-1.exe"
	@g++ -o 1-1.exe src/1.1.cpp

compile1.2-windows:
	@echo "Compiling 1.2.cpp into executable 1-2.exe"
	@g++ -o 1-2.exe src/1.2.cpp

compile2-windows:
	@echo "Compiling 2.cpp into executable 2.exe"
	@g++ -o 2.exe src/2.cpp

compile-all-windows:
	@echo "Compiling all programs for project 1"
	@echo "Compiling 1.1.cpp into 1-1.exe"
	@g++ -o 1-1.exe src/1.1.cpp
	@echo "Compiling 1.2.cpp into 1-2.exe"
	@g++ -o 1-2.exe src/1.2.cpp
	@echo "Compiling 2.cpp into  2.exe"
	@g++ -o 2.exe src/2.cpp

debug-1.1:
	@echo "Compiling 1.1.cpp into executable 1.1"
	@g++ -o 1.1 src/1.1.cpp -Wall

debug-1.2:
	@echo "Compiling 1.2.cpp into executable 1.2"
	@g++ -o 1.2 src/1.2.cpp -Wall

debug-2:
	@echo "Compiling 2.cpp into executable 2"
	@g++ -o 2 src/2.cpp -Wall

debug1.1-windows:
	@echo "Compiling 1.1.cpp into executable 1-1.exe"
	@g++ -o 1-1.exe src/1.1.cpp -Wall

debug-1.2-windows:
	@echo "Compiling 1.2.cpp into executable 1-2.exe"
	@g++ -o 1-2.exe src/1.2.cpp -Wall

debug-2-windows:
	@echo "Compiling 2.cpp into executable 2.exe"
	@g++ -o 2.exe src/2.cpp -Wall

clean-linux:
	@echo "Removing executables!"
	@rm 1.1
	@rm 1.2
	@rm 2

clean-windows:
	@echo "Removing executables!"
	@rm 1-1.exe
	@rm 1-2.exe
	@rm 2.exe

run-1.1:
	@echo "*********************************************"
	@echo "Running 1.1 with input 1001000"
	@./1.1 1001000
	@echo "*********************************************"
	@echo "Running 1.1 with input 1101001100110101"
	@./1.1 1101001100110101
	@echo "*********************************************"
	@echo "Running 1.1 with input 1010101"
	@./1.1 1010101
	@echo "*********************************************"
	@echo "Running 1.1 with input 11111111"
	@./1.1 11111111
	@echo "*********************************************"

run-1.2:
	@echo "*********************************************"
	@echo "Running 1.2 with input 00110010000"
	@./1.2 00110010000
	@echo "*********************************************"
	@echo "Running 1.2 with input 00110010001"
	@./1.2 00110010001
	@echo "*********************************************"
	@echo "Running 1.2 with input 011110110011001110101"
	@./1.2 011110110011001110101
	@echo "*********************************************"
	@echo "Running 1.2 with input 11110100101"
	@./1.2 11110100101
	@echo "*********************************************"
	@echo "Running 1.2 with input 111011101111"
	@./1.2 111011101111
	@echo "*********************************************"
	@echo "Running 1.2 with input 11110000101"
	@./1.2 11110000101
	@echo "*********************************************"

run-2:
	@echo "*********************************************"
	@echo "Running 2 with input 10011101 with generator 1001"
	@./2 10011101 1001
	@echo "*********************************************"
	@echo "Running 2 with input 1101011011 with generator 10011"
	@./2 1101011011 10011
	@echo "*********************************************"
	@echo "Running 2 with input 10011101 with generator 1001"
	@./2 10011101 1001
	@echo "*********************************************"
	@echo "Running 2 with input 1101011011011100 with generator 1101110111011101"
	@./2 1101011011011100 1101110111011101
	@echo "*********************************************"

run-1.1-windows:
	@echo "*********************************************"
	@echo "Running 1-1.exe with input 1001000"
	@./1-1.exe 1001000
	@echo "*********************************************"
	@echo "Running 1-1.exe with input 1101001100110101"
	@./1-1.exe 1101001100110101
	@echo "*********************************************"
	@echo "Running 1-1.exe with input 1010101"
	@./1-1.exe 1010101
	@echo "*********************************************"
	@echo "Running 1-1.exe with input 11111111"
	@./1-1.exe 11111111
	@echo "*********************************************"

run-1.2-windows:
	@echo "*********************************************"
	@echo "Running 1-2.exe with input 00110010000"
	@./1-2.exe 00110010000
	@echo "*********************************************"
	@echo "Running 1-2.exe with input 00110010001"
	@./1-2.exe 00110010001
	@echo "*********************************************"
	@echo "Running 1-2.exe with input 011110110011001110101"
	@./1-2.exe 011110110011001110101
	@echo "*********************************************"
	@echo "Running 1-2.exe with input 11110100101"
	@./1-2.exe 11110100101
	@echo "*********************************************"
	@echo "Running 1-2.exe with input 111011101111"
	@./1-2.exe 111011101111
	@echo "*********************************************"
	@echo "Running 1-2.exe with input 11110000101"
	@./1-2.exe 11110000101
	@echo "*********************************************"

run-2-windows:
	@echo "*********************************************"
	@echo "Running 2.exe with input 10011101 with generator 1001"
	@./2.exe 10011101 1001
	@echo "*********************************************"
	@echo "Running 2.exe with input 1101011011 with generator 10011"
	@./2.exe 1101011011 10011
	@echo "*********************************************"
	@echo "Running 2.exe with input 10011101 with generator 1001"
	@./2.exe 10011101 1001
	@echo "*********************************************"
	@echo "Running 2.exe with input 1101011011011100 with generator 1101110111011101"
	@./2.exe 1101011011011100 1101110111011101
	@echo "*********************************************"