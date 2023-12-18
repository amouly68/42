
up: clean
	docker-compose -f srcs/docker-compose.yml up -d

run: 
	docker-compose -f srcs/docker-compose.yml up -d

down: 
	docker-compose -f srcs/docker-compose.yml down

clean:
	docker container prune -f
	docker volume prune -f
	docker system prune -f


deep_clean:
	docker container rm -f nginx wordpress mariadb debian
	docker image rm nginx wordpress mariadb
	docker volume rm srcs_dbdata srcs_wordpress
	docker system prune -f
