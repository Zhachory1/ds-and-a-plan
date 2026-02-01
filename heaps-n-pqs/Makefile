CXX = g++
CXXFLAGS = -std=c++17 -Wall

all: test

test: tests.cpp MinHeap.cpp KClosest.cpp
	@echo "Compiling and running tests..."
	$(CXX) $(CXXFLAGS) -o run_tests tests.cpp
	./run_tests

run-heap: MinHeap.cpp
	@echo "Running Student MinHeap Main..."
	$(CXX) $(CXXFLAGS) -o my_heap MinHeap.cpp
	./my_heap

run-k: KClosest.cpp
	@echo "Running Student KClosest Main..."
	$(CXX) $(CXXFLAGS) -o my_k KClosest.cpp
	./my_k

clean:
	rm -f run_tests my_heap my_k