#!/bin/bash
set -e

# Attend que MariaDB soit prête
function wait_for_mariadb() {
    while ! mysqladmin ping -h localhost --silent --user=root --password=""; do
        sleep 1
        echo "En attente de la base de données MariaDB..."
    done
}

# Initialisation de la base de données
function initialize_db() {
    # Définit des valeurs par défaut si les variables d'environnement ne sont pas définies
    MYSQL_DATABASE=${MYSQL_DATABASE:-default_db}
    MYSQL_USER=${MYSQL_USER:-user}
    MYSQL_PASSWORD=${MYSQL_PASSWORD:-password}
    MYSQL_ROOT_PASSWORD=${MYSQL_ROOT_PASSWORD:-rootpassword}

    # Commandes SQL pour initialiser la base de données et les utilisateurs
    mysql --user=root --password="" -e "CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE;"
    mysql --user=root --password="" -e "CREATE USER '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';"
    mysql --user=root --password="" -e "GRANT ALL ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%';"
    mysql --user=root --password="" -e "FLUSH PRIVILEGES;"
    mysql --user=root --password="" -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';"
}

# Démarre le serveur MariaDB en arrière-plan
mysqld_safe &

# Attente de la disponibilité de MariaDB
wait_for_mariadb

# Exécution des opérations d'initialisation
initialize_db

# Arrête le serveur MariaDB pour le redémarrer proprement
mysqladmin --user=root --password="$MYSQL_ROOT_PASSWORD" shutdown

# Lance le serveur MariaDB comme processus principal (PID 1)
exec mysqld
