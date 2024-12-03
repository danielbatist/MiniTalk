CC = cc 

PRINTF = printf

CFLAGS = -Wall -Wextra -Werror -I$(PRINTF)/headers -L$(PRINTF) -lftprintf

SERVER = server

CLIENT = client

all:
	@make -s -C $(PRINTF)
	@$(CC) $(CFLAGS) server.c -L$(PRINTF) -lftprintf -o $(SERVER)
	@$(CC) $(CFLAGS) client.c -L$(PRINTF) -lftprintf -o $(CLIENT)
	@echo "All ready!"
clean: 
	make clean -s -C $(PRINTF)

fclean: clean
	@make fclean -s -C $(PRINTF)
	@rm $(SERVER) $(CLIENT)
	@echo "Finish!"

re: fclean all

.PHONY:	all clean fclean
