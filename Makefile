#UNAME = $(shell uname -s)
#CHECK_FLAGS = -lcheck -lm -lpthread
ifeq ($(shell uname -s),Darwin)
    CHECK_FLAGS = -lcheck -lm -lpthread
endif
ifeq ($(shell uname -s),Linux)
    CHECK_FLAGS = -lcheck -lpthread -lrt -lm -lsubunit
endif

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -std=c11 -lm
GCOV_FLAGS = -fPIC -fprofile-arcs -ftest-coverage

LIB_OUT = libcalc_backend.a
LIB_NAME = libcalc_backend.a
INCL_LIB = -L.

SOURCE_DIR = .
LIB_SRC := $(wildcard $(SOURCE_DIR)/*.c)
LIB_OBJS := $(LIB_SRC:$(SOURCE_DIR)/%.c=%.o)

TEST_DIR = ./tests
TEST_SRC := $(wildcard $(TEST_DIR)/*.c)
TEST_OBJS := $(TEST_SRC:$(TEST_DIR)/%.c=%.o)

TEST_EXEC = $(TEST_OBJS:%.o=%.out)

# S21_DECIMAL = libcalc_backend.a

BIN = bin

.PHONY: all


all: $(TEST_OBJS) $(LIB_OBJS) libcalc_backend.a

$(LIB_OBJS): %.o : $(SOURCE_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ 

$(TEST_OBJS): %.o : $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ 

$(TEST_EXEC): %.out: %.o $(TEST_OBJS)
	@if [ ! -d $(BIN) ] ; then mkdir bin; fi
	$(CC) $< $(INCL_LIB) $(LIB_NAME) -o ./bin/$@ $(CHECK_FLAGS)

.PHONY: libcalc_backend.a
libcalc_backend.a: $(LIB_OBJS) 
	@ar rs $(LIB_OUT) $(LIB_OBJS)
	@ranlib $(LIB_OUT)

.PHONY: test
test: libcalc_backend.a build

build: $(TEST_EXEC)
	@for test in $^; do \
		./bin/$${test}; \
		echo; \
	done

.PHONY: gcov_report
gcov_report: clean
	$(MAKE) -f gcov.mk

.PHONY: sanitizer
sanitizer: clean_all
	$(MAKE) -f sanit.mk

.PHONY: valgrind
valgrind: libcalc_backend.a $(TEST_EXEC)
	@if [ ! -d $(BIN) ] ; then mkdir bin; fi
	@for test in ./bin/$^; do \
    valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/$${test} \
		2> ./bin/$${test}.txt; \
		echo; \
	done

.PHONY: clean
clean:
	@find . -name "*.o" -exec rm -f {} \;
	@find . -name "*.out" -exec rm -f {} \;
	@find . -name "*.gcov" -exec rm -f {} \;
	@find . -name "*.gcda" -exec rm -f {} \;
	@find . -name "*.gcno" -exec rm -f {} \;
	@find . -name "*.txt" -exec rm -f {} \;
	@rm -rf OUT
	@rm -f cover.info
	@rm -rf gcov
	@rm -rf bin
	@echo "Cleaning..."
	@echo "Operation complete :)"

.PHONY: clean_lib
clean_lib:
	@find . -name "*.a" -exec rm -f {} \;

.PHONY: clean_all
clean_all: clean_lib clean

.PHONY: style
style:
	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h tests/*.c 

