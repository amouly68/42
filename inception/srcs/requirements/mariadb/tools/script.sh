#!/bin/bash
# Démarrer MariaDB
service mysql start;

# Créer la base de données
# mysql -e "CREATE DATABASE IF NOT EXISTS \`${SQL_DATABASE}\`;"
mysql -e "CREATE DATABASE IF NOT EXISTS \`wordpress\`;"

# Créer l'utilisateur et lui donner les droits
# mysql -e "CREATE USER IF NOT EXISTS \`${SQL_USER}\`@'localhost' IDENTIFIED BY '${SQL_PASSWORD}';"
# mysql -e "GRANT ALL PRIVILEGES ON \`${SQL_DATABASE}\`.* TO \`${SQL_USER}\`@'%' IDENTIFIED BY '${SQL_PASSWORD}';"
mysql -e "CREATE USER IF NOT EXISTS \`user\`@'localhost' IDENTIFIED BY 'pass';"
mysql -e "GRANT ALL PRIVILEGES ON \`wordpress\`.* TO \`user\`@'%' IDENTIFIED BY 'pass';"


# Modifier les droits de l'utilisateur root
# mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${SQL_ROOT_PASSWORD}';"
mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY 'root';"

# Rafraîchir les privilèges
mysql -e "FLUSH PRIVILEGES;"

# Arrêter MariaDB proprement
# mysqladmin -u root -p"$SQL_ROOT_PASSWORD" shutdown
mysqladmin -u root -p"root" shutdown

# Lancer MariaDB en mode "safe"
exec mysqld_safe

