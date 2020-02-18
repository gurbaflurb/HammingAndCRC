compile1.1:
	@echo "Compiling 1.1.cpp into executable 1.1"
	@g++ -o 1.1 src/1.1.cpp

compile1.2:
	@echo "Compiling 1.2.cpp into executable 1.2"
	@g++ -o 1.2 src/1.2.cpp

compile2:
	@echo "Compiling 2.cpp into executable 2"
	@g++ -o 2 src/2.cpp

compile-all:
	@echo "Compiling all programs for project 1"
	@echo "COmpiling 1.1.cpp into 1.1"
	@g++ -o 1.1 src/1.1.cpp
	@echo "Compiling 1.2.cpp into 1.2"
	@g++ -o 1.2 src/1.2.cpp
	@echo "Compiling 2.cpp into  2"
	@g++ -o 2 src/2.cpp

compile-debug:
	@echo "Compiling 1.1.cpp into executable 1.1"
	@g++ -o 1.1 src/1.1.cpp -Wall

clean:
	@echo "Removing executables!"
	@rm 1.1
	@rm 1.2
	@rm 2