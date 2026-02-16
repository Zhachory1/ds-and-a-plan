# Makefile for Graph Search Homework

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

# Targets
all: student_solutions test_homework solution

student_solutions: student_solutions.cpp Graph.h student_solutions.h
	$(CXX) $(CXXFLAGS) -o student_solutions student_solutions.cpp

test_homework: homework_test.cpp student_solutions.h Graph.h
	$(CXX) $(CXXFLAGS) -c student_solutions.cpp -o student_solutions_for_test.o
	$(CXX) $(CXXFLAGS) homework_test.cpp student_solutions_for_test.o -o test_homework

solution: solution.cpp Graph.h
	$(CXX) $(CXXFLAGS) -o solution solution.cpp

# Convenience targets
test: test_homework
	./test_homework

run: student_solutions
	./student_solutions

demo: solution
	./solution

clean:
	rm -f student_solutions test_homework solution *.o

.PHONY: all test run demo clean
