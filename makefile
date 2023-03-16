build:
	g++ -g -Wall -std=c++20 main.cpp -o program.exe

test:
	g++ -Wall -std=c++20 tests.cpp -o tests.exe

run:
	./program.exe

runtest:
	./tests.exe

clean:
	rm -f program.exe
	rm -f tests.exe

valgrind:
	valgrind --tool=memcheck --leak-check=yes ./program.exe
br:
	clear
	g++ -g -Wall -std=c++20 main.cpp -o program.exe
	./program.exe
	rm -f program.exe