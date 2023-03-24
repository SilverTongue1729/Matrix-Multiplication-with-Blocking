CXX := g++
CXXFLAGS := -std=c++20 -O2 -DLOCAL -fconcepts 

TESTS := $(wildcard test/input/*.in)
OUTPUTS := $(patsubst test/input/%.in,test/output/%.out,$(TESTS))

all: $(OUTPUTS)

test: all
    @for i in $(TESTS); do \
        echo "Running $$i..."; \
        ./src/main < $$i | diff -u $(patsubst test/input/%.in,test/output/%.out,$$i) -; \
    done

test_naive:
    @for i in $(TESTS); do \
        echo "Running $$i..."; \
        ./src/naive < $$i | diff -u $(patsubst test/input/%.in,test/output/%.out,$$i) -; \
    done

test_%:
    @for i in $(filter %,$(subst _, ,$@)); do \
        echo "Running test $$i..."; \
        ./src/main < test/input/test$$i.in | diff -u test/output/test$$i.out -; \
    done

test_naive_%:
    @for i in $(filter %,$(subst _, ,$@)); do \
        echo "Running test $$i..."; \
        ./src/naive < test/input/test$$i.in | diff -u test/output/test$$i.out -; \
    done

clean:
    rm -f src/main src/naive $(OUTPUTS)

test/input/test%.in:
    ./test/generate > $@

test/output/test%.out: test/input/test%.in
    ./src/main < $< > $@

test/compare: test/output/test%.out
    @./test/compare $< test/output/test%.out

.PHONY: all test test_naive test_% test_naive_% clean test/compare

gen_tests:
    @for i in $(shell seq 1 $(filter-out $@,$(MAKECMDGOALS))); do \
        ./test/generate > test/input/test$$i.in; \
        echo "Generating test input file test$$i.in..."; \
    done

%:
	@:
