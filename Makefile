all: RPSComp2.c
	g++ -Wall RPSComp2.c -o rps

check: 
	cpplint RPSComp2.c

clean:
	rm -f rps
