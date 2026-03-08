CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

all: test

test: tests.cpp merge_sort.cpp merge_sort.h
	$(CXX) $(CXXFLAGS) -o run_tests tests.cpp
	./run_tests

run: merge_sort.cpp merge_sort.h
	$(CXX) $(CXXFLAGS) -o merge_sort merge_sort.cpp
	./merge_sort

clean:
	rm -f run_tests merge_sort

.PHONY: all test run clean
