CC = cc 

PRINTF = printf

CFLAGS = -Wall -Wextra -Werror -I$(PRINTF)/headers -L$(PRINTF) -lftprintf

SERVER = server

CLIENT = client

GREEN = \033[32m
YELLOW = \033[33m
RESET = \033[0m

run_server: all
	@echo "$(YELLOW)     _______. _______ .______     ____    ____  _______ .______$(RESET)"
	@echo "$(YELLOW)    /       ||   ____||   _  \    \   \  /   / |   ____||   _  \ $(RESET)"
	@echo "$(YELLOW)   |   (----\`|  |__   |  |_)  |    \   \/   /  |  |__   |  |_)  |$(RESET)"
	@echo "$(YELLOW)    \   \    |   __|  |      /      \      /   |   __|  |      /$(RESET)"
	@echo "$(YELLOW).----)   |   |  |____ |  |\  \----.  \    /    |  |____ |  |\  \----.$(RESET)"
	@echo "$(YELLOW)|_______/    |_______|| _| \`._____|   \__/     |_______|| _| \`._____|$(RESET)"
	@echo ""
	@echo "$(YELLOW)Server is running... 🚀$(RESET)"
	@echo "$(GREEN)Welcome to dbatista server!!!$(RESET)";
	@./$(SERVER)                                                    

all:
	@make -s -C $(PRINTF)
	@$(CC) $(CFLAGS) server.c -L$(PRINTF) -lftprintf -o $(SERVER)
	@$(CC) $(CFLAGS) client.c -L$(PRINTF) -lftprintf -o $(CLIENT)

clean: 
	@make clean -s -C $(PRINTF)

fclean: clean
	@make fclean -s -C $(PRINTF)
	@rm $(SERVER) $(CLIENT)

	                
	@echo "$(YELLOW)     #########################################  $(RESET)"              
	@echo "$(YELLOW)    #####.................................##### $(RESET)"              
	@echo "$(YELLOW)   +#######.                           .#######+$(RESET)"               
	@echo "$(YELLOW)   +##-.+####-.                     ..#####..##+$(RESET)"               
	@echo "$(YELLOW)   +##-  .+####+.                 .+####+.  .##+$(RESET)"               
	@echo "$(YELLOW)   +##-    .+####+.             .-####+..   .##+$(RESET)"               
	@echo "$(YELLOW)   +##-      .+####+.        ..+####+.      .##+$(RESET)"               
	@echo "$(YELLOW)   +##-        .-####+..   ..+####-.        .##+$(RESET)"               
	@echo "$(YELLOW)   +##-         .+######...######+..        .##+$(RESET)"               
	@echo "$(YELLOW)   +##-      ..####++#########++####.       .##+$(RESET)"               
	@echo "$(YELLOW)   +##-    ..####-.  .-#####-.  .-####..    .##+$(RESET)"               
	@echo "$(YELLOW)   +##-  ..####-.                 ..####..  .##+$(RESET)"               
	@echo "$(YELLOW)   +##-..####.                       .####...##+$(RESET)"               
	@echo "$(YELLOW)   +##+####.                           .####+##+$(RESET)"               
	@echo "$(YELLOW)    #####.................................##### $(RESET)"              
	@echo "$(YELLOW)     #########################################  $(RESET)"              
             

	@echo "$(YELLOW) _______  __  .__   __.  __       _______. __    __  $(RESET)" 
	@echo "$(YELLOW)|   ____||  | |  \ |  | |  |     /       ||  |  |  | $(RESET)" 
	@echo "$(YELLOW)|  |__   |  | |   \|  | |  |    |   -----'|  |__|  |  $(RESET)" 
	@echo "$(YELLOW)|   __|  |  | |  . '  | |  |     \   \    |   __   | $(RESET)" 
	@echo "$(YELLOW)|  |     |  | |  |\   | |  | .----'   |   |  |  |  |  $(RESET)" 
	@echo "$(YELLOW)|__|     |__| |__| \__| |__| |_______/    |__|  |__| $(RESET)" 
                                                     



                                                                    
re: fclean all

.PHONY:	all clean fclean