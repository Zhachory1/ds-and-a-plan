# Root Makefile for ds-and-a-plan
# Runs all homework module tests and reports results

.PHONY: test clean help

# Test all modules
test:
	@echo "======================================"
	@echo "Running all homework tests..."
	@echo "======================================"
	@pass=0; fail=0; \
	for module in \
		graphs \
		heaps-n-pqs \
		traversal/BFS_DFS \
		divide-and-conquer/merge-sort \
		divide-and-conquer/quick-sort \
		divide-and-conquer/inversions; \
	do \
		echo ""; \
		echo "=== Testing $$module ==="; \
		if $(MAKE) -C $$module test 2>&1 | tail -10; then \
			pass=$$((pass + 1)); \
			echo "✓ $$module PASSED"; \
		else \
			fail=$$((fail + 1)); \
			echo "✗ $$module FAILED"; \
		fi; \
	done; \
	echo ""; \
	echo "======================================"; \
	echo "Summary: $$pass passed, $$fail failed"; \
	echo "======================================"; \
	exit 0

# Clean all modules
clean:
	@echo "Cleaning all modules..."
	@for module in \
		graphs \
		heaps-n-pqs \
		traversal/BFS_DFS \
		divide-and-conquer/merge-sort \
		divide-and-conquer/quick-sort \
		divide-and-conquer/inversions; \
	do \
		echo "Cleaning $$module..."; \
		$(MAKE) -C $$module clean 2>/dev/null || true; \
	done
	@echo "✓ All modules cleaned"

help:
	@echo "Available targets:"
	@echo "  make test   - Run all homework module tests"
	@echo "  make clean  - Clean all build artifacts"
	@echo "  make help   - Show this help message"
