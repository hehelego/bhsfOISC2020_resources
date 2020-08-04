sol:main.o
	g++ main.o -o sol.exe
main.o:
	g++ main.cpp -Wall -Wextra -O2 -c -o main.o


force:main.o
	g++ force.o -o force.exe
force.o:
	g++ force.cpp -Wall -Wextra -O2 -c -o force.o

clean:
	rm main.o force.o sol.exe force.exe

