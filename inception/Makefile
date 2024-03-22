NAME = inception
COMP = ./srcs/docker-compose.yml

all: conf up

conf:
	@echo "Copying enviroment variables..."
	@cp ../.env ./srcs/
	@echo "Copying enviroment variables [OK]\n"
	@sleep 1
	@echo "Creating volumes..."
	@mkdir -p /home/lde-sous/data/mariadb_data
	@mkdir -p /home/lde-sous/data/wordpress_data
	@echo "Creating volumes [OK]\n"
	@sleep 1
	@echo "Adding 'lde-sous.42.fr' to hosts..."
	@sudo sed -i '/^127.0.0.1/ {/lde-sous.42.fr/! s/localhost/localhost lde-sous.42.fr/}' /etc/hosts
	@echo "Adding 'lde-sous.42.fr' to hosts [OK]\n"
	@sleep 1

up:
	docker compose -p $(NAME) -f $(COMP) up --build -d

down:
	docker compose -p $(NAME) down --volumes

start:
	docker compose -p $(NAME) start

stop:
	docker compose -p $(NAME) stop

clean-images:
	docker rmi -f $$(docker images -q) || true

clean: down clean-images

fclean: clean
	@sudo rm -rf /home/lde-sous/data
	@docker system prune -a
	@rm -f ./srcs/.env

re: fclean conf up
