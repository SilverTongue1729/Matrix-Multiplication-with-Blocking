CXX := g++
CXXFLAGS := -std=c++20 -O2 -DLOCAL -fconcepts 

TESTS := $(wildcard test/input/*.in)
OUTPUT_MAIN := $(patsubst test/input/%.in,test/output_main/%.out,$(TESTS))
OUTPUT_NAIVE := $(patsubst test/input/%.in,test/output_naive/%.out,$(TESTS))

all: src/main src/naive

src/main: src/main.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

src/naive: src/naive.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<
		
test/generate: test/generate.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

test: all $(patsubst test/input/%.in,test_%,$(TESTS))

test_%: all
	@echo "Running test $*..."
	@./src/main < test/input/test$*.in > output_main/test$*.out
	@./src/naive < test/input/test$*.in > output_naive/test$*.out
	@if diff -q output_main/test$*.out output_naive/test$*.out >/dev/null; \
	then \
	  echo "Test $* PASSED"; \
	else \
	  echo "Test $* FAILED"; \
	fi

clean:
	rm -f src/main src/naive test/generate output_main/* output_naive/* 

test/input/test%.in:
	./test/generate > $@

gen: test/generate
	@for i in $(shell seq 1 $(filter-out $@,$(MAKECMDGOALS))); do \
		make gen_one $$i; \
	done


.PHONY: all test test_% clean gen_one gen check

check:
	@echo "Checking for differences..."
	@if diff -q output_main output_naive >/dev/null; \
	then \
	  echo "All tests PASSED"; \
	else \
	  echo "Some tests FAILED"; \
	fi

gen_one:
	./test/generate > test/input/test$(filter-out $@,$(MAKECMDGOALS)).in
