CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

all: test

test: tests.cpp quick_sort.cpp quick_sort.h
	$(CXX) $(CXXFLAGS) -o run_tests tests.cpp
	./run_tests

run: quick_sort.cpp quick_sort.h
	$(CXX) $(CXXFLAGS) -o quick_sort quick_sort.cpp
	./quick_sort

clean:
	rm -f run_tests quick_sort

.PHONY: all test run clean
