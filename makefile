emptyLineDeletor: emptyLineDeletor.o
	g++ -o ELD emptyLineDeletor.o
emptyLineDeletor.o: emptyLineDeletor.cc
	g++ -g -c -Wall -Werror emptyLineDeletor.cc