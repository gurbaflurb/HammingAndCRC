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