SOURCES=common_fn.c notation.c parser.c

TEST_FOLD="./tests/"
TEST_SOURCES = "${TEST_FOLD}stack.c"

all:
	gcc -Wall -Wextra -Werror -g -std=c11 -c ${SOURCES}
	gcc -Wall -Wextra -Werror -g -std=c11 -c ${TEST_SOURCES}
	gcc *.o -o a.out

sanitizer:
	gcc -Wall -Wextra -Werror -g -std=c11 -c ${SOURCES} -fsanitize=address
	gcc -Wall -Wextra -Werror -g -std=c11 -c ${TEST_SOURCES} -fsanitize=address
	gcc *.o -o a.out -fsanitize=address

clean:
	@find . -type f -name "*.o" -exec rm -f {} \;
	@find . -name a.out -exec rm -f {} \;

