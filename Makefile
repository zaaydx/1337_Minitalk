# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zchbani <zchbani@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/28 21:43:15 by zchbani           #+#    #+#              #
#    Updated: 2021/12/29 23:53:42 by zchbani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = server

NAME2 = client

NAME3 = server_bonus

NAME4 = client_bonus

all :
	gcc -Wall -Wextra -Werror server.c utiles.c -o $(NAME1)
	gcc -Wall -Wextra -Werror client.c utiles.c -o $(NAME2)

bonus :
	gcc -Wall -Wextra -Werror server_bonus.c utiles_bonus.c -o $(NAME3)
	gcc -Wall -Wextra -Werror client_bonus.c utiles_bonus.c -o $(NAME4)

clean :
	@rm -rf client.o server.o client_bonus.o server_bonus.o

fclean : clean
	@rm -rf $(NAME1) $(NAME2) $(NAME3) $(NAME4)

re : fclean all
