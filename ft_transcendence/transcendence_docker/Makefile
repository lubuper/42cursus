NAME = ft_transcendence
COMP = docker-compose.yml

GREEN = \033[0;32m
GREY = \033[1;30m
YELLOW = \033[1;33m
RED = \033[0;31m
PURPLE = \033[0;35m
RESET = \033[0m

all: up start

up:
	@echo "${YELLOW}Generating https certificates...${RESET}"
	@chmod +x nginx/cert_gen.sh
	@./nginx/cert_gen.sh
	@echo "Certificates generated [${GREEN}OK${RESET}]"
	@echo "${YELLOW}Building containers...${RESET}"
	@docker-compose down
	@docker-compose build --build-arg ALLOWED_HOST=$(grep ALLOWED_HOST .env | cut -d '=' -f2)
	@docker-compose -p $(NAME) -f $(COMP) up --build || true
	@echo "Containers build [${GREEN}OK${RESET}]"

down:
	@echo "${RED}Stopping containers...${RESET}"
	@docker-compose -p $(NAME) down --volumes
	@echo "Containers stopped [${GREEN}OK${RESET}]"

start:
	@echo "${YELLOW}Starting containers...${RESET}"
	@docker-compose -p $(NAME) start
	@echo "Containers started [${GREEN}OK${RESET}]"

stop:
	@echo "${RED}Stopping containers...${RESET}"
	@docker-compose -p $(NAME) stop
	@echo "Containers stopped [${GREEN}OK${RESET}]"

fclean: down
	@echo "${YELLOW}Removing certificates...${RESET}"
	@rm -rf nginx/etc
	@rm -rf etc
	@echo "Certificates removed [${GREEN}OK${RESET}]"
	@echo "${PURPLE}Pruning system...${RESET}"
	@docker system prune -a --volumes
	@echo "System pruned [${GREEN}OK${RESET}]"

re: fclean up

.PHONY: up down start stop fclean

.SILENT:
