# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohammoh <mohammoh@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/29 15:06:47 by mohammoh          #+#    #+#              #
#    Updated: 2023/08/29 17:06:57 by mohammoh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server

CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

LIBFT = ./libft/libft.a

HEAD = ./

SRC_C = src/client.c
OBJ_C = $(SRC_C:%.c=%.o)

SRC_S = src/server.c
OBJ_S = $(SRC_S:%.c=%.o)

CLIENT_B = client_bonus
SERVER_B = server_bonus

B_C = src_b/client_b.c
B_OBJ_C = $(B_C:%.c=%.o)

B_S = src_b/server_b.c
B_OBJ_S = $(B_S:%.c=%.o)

all: $(SERVER) $(CLIENT)

$(LIBFT):
	@$(MAKE) -C ./libft
	
$(OBJ_C): %.o: %.c
	@$(CC) $(CFLAGS) -c -I $(HEAD) $< -o $@
	@echo "client file compiled"

$(OBJ_S): %.o: %.c
	@$(CC) $(CFLAGS) -c -I  $(HEAD) $< -o $@
	@echo "server file compiled"
	
$(B_OBJ_C): %.o: %.c
	@$(CC) $(CFLAGS) -c -I $(HEAD) $< -o $@
	@echo "client_bonus file compiled"
	
$(B_OBJ_S): %.o: %.c
	@$(CC) $(CFLAGS) -c -I  $(HEAD) $< -o $@
	@echo "server_bonus file compiled"

$(SERVER): $(OBJ_S) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ_S) $(LIBFT) -o server

$(CLIENT): $(OBJ_C) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ_C) $(LIBFT) -o client


$(SERVER_B): $(B_OBJ_S) $(LIBFT)
	@$(CC) $(CFLAGS) $(B_OBJ_S) $(LIBFT) -o server_bonus

$(CLIENT_B): $(B_OBJ_C) $(LIBFT)
	@$(CC) $(CFLAGS) $(B_OBJ_C) $(LIBFT) -o client_bonus

bonus: $(SERVER_B) $(CLIENT_B)

clean:
	@$(MAKE) clean -C ./libft
	@$(RM) $(OBJ_S) $(OBJ_C)
	@$(RM) $(B_OBJ_S) $(B_OBJ_C)
	@echo "all object files removed"

fclean: clean
	@$(MAKE) fclean -C ./libft
	@$(RM) $(SERVER) $(CLIENT)
	@$(RM) $(SERVER_B) $(CLIENT_B)

re: fclean all