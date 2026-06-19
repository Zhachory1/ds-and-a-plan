# Makefile for TSP Homework

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

# Targets
all: tsp_solver solution

tsp_solver: tsp_solver.cpp json.hpp
	$(CXX) $(CXXFLAGS) -o tsp_solver tsp_solver.cpp

solution: solution.cpp json.hpp
	$(CXX) $(CXXFLAGS) -o solution solution.cpp

# Convenience targets
run: tsp_solver
	./tsp_solver

demo: solution
	./solution

clean:
	rm -f tsp_solver solution *.o

.PHONY: all run demo clean
