NAME = myCompiler

CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = exec/main.c \
		exec/Lexer/src/get_next_line.c \
		exec/Lexer/src/get_next_line_utils.c \
		exec/Lexer/src/lst.c \
		exec/Lexer/src/parser.c \
		exec/temp/src/tmp.c \
		exec/Compiler/src/compiler.c \
		exec/Compiler/src/replace.c \
		exec/Compiler/src/trad.c \
		exec/Compiler/src/my_split.c

OBJS = $(SRCS:.c=.o)

HEADER = exec/Lexer/include/get_next_line.h \
			exec/Lexer/include/lexer.h.h \
			exec/temp/include/temp.h \
			exec/compiler/include/compiler.h \
			exec/main.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: src/push_swap/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $@ -o $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re