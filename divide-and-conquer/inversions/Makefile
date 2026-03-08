CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

all: test

test: tests.cpp inversions.cpp inversions.h
	$(CXX) $(CXXFLAGS) -o run_tests tests.cpp
	./run_tests

run: inversions.cpp inversions.h
	$(CXX) $(CXXFLAGS) -o inversions_demo inversions.cpp
	./inversions_demo

clean:
	rm -f run_tests inversions_demo

.PHONY: all test run clean
