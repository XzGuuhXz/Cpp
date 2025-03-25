all:
	clear
	g++ -g -Wall tree.cpp -o tree

compile:
	g++ -g -Wall tree.cpp -o tree

debug:
	ddd tree

clear:
	clear
