SOURCES="prepare.c"

TEST_FOLD="./tests/"
TEST_SOURCES = "${TEST_FOLD}stack.c"

all:
	gcc -Wall -Wextra -Werror -g -std=c11 -c ${SOURCES}
	gcc -Wall -Wextra -Werror -g -std=c11 -c ${TEST_SOURCES}
	gcc *.o -o a.out

clean:
	@find . -type f -name "*.o" -exec rm -f {} \;
	@find . -name a.out -exec rm -f {} \;

