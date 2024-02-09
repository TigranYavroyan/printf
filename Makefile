NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRCS = ./srcs/*.c
OBJS = *.o

all: $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $@ $^

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(EXEC) $(NAME)

re: fclean all
