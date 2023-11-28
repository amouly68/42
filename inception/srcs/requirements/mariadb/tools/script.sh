#!/bin/bash
# Démarrer MariaDB
service mariadb start;

# Créer la base de données
# mysql -e "CREATE DATABASE IF NOT EXISTS \`${SQL_DATABASE}\`;"
mysql -e "CREATE DATABASE IF NOT EXISTS \`wordpress\`;"

# Créer l'utilisateur et lui donner les droits
# mysql -e "CREATE USER IF NOT EXISTS \`${SQL_USER}\`@'127.0.0.1' IDENTIFIED BY '${SQL_PASSWORD}';"
# mysql -e "GRANT ALL PRIVILEGES ON \`${SQL_DATABASE}\`.* TO \`${SQL_USER}\`@'%' IDENTIFIED BY '${SQL_PASSWORD}';"
mysql -e "CREATE USER IF NOT EXISTS \`user\`@'127.0.0.1' IDENTIFIED BY 'pass';"
mysql -e "GRANT ALL PRIVILEGES ON \`wordpress\`.* TO \`user\`@'%' IDENTIFIED BY 'pass';"

# mysql -e "UPDATE mysql.user SET host='%' WHERE user='root' AND host='localhost';"
# mysql -e "FLUSH PRIVILEGES;"
# mysql -e "ALTER USER 'root'@'%' IDENTIFIED WITH mysql_native_password BY 'secret';"

# Modifier les droits de l'utilisateur root
mysql -e "ALTER USER 'root'@'127.0.0.1' IDENTIFIED WITH mysql_native_password BY '${SQL_ROOT_PASSWORD}';"
# mysql -e "ALTER USER 'root'@'127.0.0.1' IDENTIFIED BY 'root';"

# Rafraîchir les privilèges
mysql -e "FLUSH PRIVILEGES;"

# Arrêter MariaDB proprement
mariadb-admin -u root -p"${SQL_ROOT_PASSWORD}" shutdown
# mysqladmin -u root -p"root" shutdown

# Lancer MariaDB en mode "safe"
exec mysqld_safe

