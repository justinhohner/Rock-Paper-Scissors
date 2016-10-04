all: Rps.cpp
	g++ -Wall Rps.cpp -o rps

check: 
	cpplint Rps.cpp

clean:
	rm -f rps
