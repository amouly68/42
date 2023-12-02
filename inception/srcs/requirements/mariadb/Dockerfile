#dockerfile
FROM debian:bullseye

RUN apt-get update -y && apt-get upgrade -y && apt-get install -y mariadb-server

COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

# Copier le script d'initialisation dans le conteneur
COPY tools/init_db.sh /usr/local/bin/init_db.sh
RUN chmod +x /usr/local/bin/init_db.sh

# COPY tools/script.sh /docker-entrypoint-initdb.d/

RUN mkdir -p /var/run/mysqld \
&& chown -R mysql:mysql /var/run/mysqld \
&& chmod 777 /var/run/mysqld

# Exposer le port 3306 pour MariaDB
EXPOSE 3306

# Commande pour démarrer MariaDB et exécuter le script d'initialisation
ENTRYPOINT ["init_db.sh"]
# CMD ["/bin/bash", "-c", "/usr/local/bin/init_db.sh && exec mysqld"]
