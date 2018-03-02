CC = gcc
FLAGS = -Wall -Wextra -Werror
FLAGS =
NAME = libftprintf.a
SRC =	srcs/ft_printf.c\
		srcs/extract_specifier.c\
		srcs/conv.c\
		srcs/c_conv.c\
		srcs/s_conv.c\
		srcs/d_conv.c\
		srcs/oux_conv.c\
		srcs/bin_conv.c\
		srcs/undefined_conv.c\
		srcs/ft_atoi.c\
		srcs/ft_atoi_tools.c\
		srcs/tools.c\
		srcs/str_tools.c\
		srcs/write.c\
		srcs/number.c\
		srcs/verif_buff_space.c\
		srcs/utf_32_to_8.c\

OBJ = $(SRC:.c=.o)
INCLUDE = ./includes/


all: $(NAME)

$(NAME): $(OBJ)
	ar -r $(NAME) $^

%.o: %.c
	$(CC) -o $@ -c $< -I $(INCLUDE) $(FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
