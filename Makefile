CC = gcc
CFLAGS = -I include
CPPFLAGS = -Wall -Wextra

SRC = main.c \
	$(wildcard src/*.c)

OBJ = $(SRC:.c=.o)
NAME = bsq

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) -g3

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) test_runner
	$(RM) *.gc*
	$(RM) vgcore.*
	$(RM) test/*.txt

re: fclean all

units_test: re
	gcc -o test_runner test/tests.c src/*.c -I include -lcriterion --coverage

tests_run: units_test
	$(RM) test_output.txt
	./test_runner 2>&1 | sed -r "s/\x1B\[[0-9;]*[JKmsu]//g" > test_output.txt
	make fclean

coverage: tests_run
	lcov --directory . --capture --output-file coverage.info
	genhtml coverage.info --output-directory coverage_report

.PHONY: all re clean fclean units_test tests_run coverage
