# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohammoh <mohammoh@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/03 17:03:04 by mohammoh          #+#    #+#              #
#    Updated: 2023/08/28 16:59:45 by mohammoh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strcat.c ft_strcpy.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BSOURCES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c 

OBJECTS = $(SRC:.c=.o) 
BOBJECTS = $(BSOURCES:.c=.o)

HEAD	= ./
CC = cc
CFLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(OBJECTS): %.o: %.c
	@$(CC) $(CFLAGS) -c -I $(HEAD) $< -o $@

$(BOBJECTS): %.o: %.c
	@$(CC) $(CFLAGS) -c -I  $(HEAD) $< -o $@

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)
	@echo "libft compiled"
bonus: $(OBJECTS) $(BOBJECTS)
	@ar rcs $(NAME) $(BOBJECTS)

clean:
	@rm -f $(OBJECTS) $(BOBJECTS)

fclean: clean
	@rm -f $(NAME)
	@echo "compilation removed"

re: fclean all

.PHONY: all bonus clean fclean re