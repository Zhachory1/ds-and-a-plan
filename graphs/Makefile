CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -g
TARGET = test_network
SOURCES = social_network.cpp test_network.cpp
HEADERS = social_network.h
OBJECTS = $(SOURCES:.cpp=.o)

# Colors for output
GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
NC = \033[0m # No Color

.PHONY: all clean test run help

# Default target
all: $(TARGET)

# Build the test executable
$(TARGET): $(OBJECTS)
	@echo "$(YELLOW)Linking $(TARGET)...$(NC)"
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)
	@echo "$(GREEN)✓ Build successful!$(NC)"

# Compile source files
%.o: %.cpp $(HEADERS)
	@echo "$(YELLOW)Compiling $<...$(NC)"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the tests
test: $(TARGET)
	@echo "$(YELLOW)Running tests...$(NC)"
	@echo ""
	./$(TARGET)

# Quick run (build + test in one command)
run: test

# Clean build artifacts
clean:
	@echo "$(YELLOW)Cleaning build artifacts...$(NC)"
	rm -f $(OBJECTS) $(TARGET)
	@echo "$(GREEN)✓ Clean complete!$(NC)"

# Rebuild from scratch
rebuild: clean all

# Check code style (optional - requires clang-format)
format:
	@if command -v clang-format >/dev/null 2>&1; then \
		echo "$(YELLOW)Formatting code...$(NC)"; \
		clang-format -i $(SOURCES) $(HEADERS); \
		echo "$(GREEN)✓ Code formatted!$(NC)"; \
	else \
		echo "$(RED)clang-format not found. Install it to use this target.$(NC)"; \
	fi

# Help message
help:
	@echo "$(GREEN)Social Network Graph - Makefile Commands$(NC)"
	@echo ""
	@echo "  $(YELLOW)make$(NC) or $(YELLOW)make all$(NC)     - Build the project"
	@echo "  $(YELLOW)make test$(NC)            - Build and run tests"
	@echo "  $(YELLOW)make run$(NC)             - Same as 'make test'"
	@echo "  $(YELLOW)make clean$(NC)           - Remove build artifacts"
	@echo "  $(YELLOW)make rebuild$(NC)         - Clean and rebuild from scratch"
	@echo "  $(YELLOW)make format$(NC)          - Format code (requires clang-format)"
	@echo "  $(YELLOW)make help$(NC)            - Show this help message"
	@echo ""
	@echo "$(GREEN)Quick Start:$(NC)"
	@echo "  1. Implement the TODO items in social_network.cpp"
	@echo "  2. Run '$(YELLOW)make test$(NC)' to see if your implementation works"
	@echo "  3. Iterate until all tests pass!"
	@echo ""
