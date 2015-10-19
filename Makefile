all: tobow split

tobow: tobow.cc
	g++ -O3 -std=c++11 -o $@ $^

split: split.cc
	g++ -O3 -std=c++11 -o $@ $^
