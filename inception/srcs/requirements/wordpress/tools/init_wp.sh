#!/bin/bash
set -e

# Créer le répertoire pour le socket, si nécessaire
mkdir -p /run/php

# Assurer que www-data (ou autre utilisateur PHP-FPM) peut écrire dans ce répertoire
chown www-data:www-data /run/php

# Chemin du fichier de configuration PHP-FPM
WWW_CONF="/etc/php/7.4/fpm/pool.d/www.conf"

# # Configurer PHP-FPM pour utiliser un socket Unix
# sed -i 's/^listen = .*/listen = \/run\/php\/php7.4-fpm.sock/' $WWW_CONF

# Configurer PHP-FPM pour utiliser le port TCP 9000
sed -i 's/^listen = .*/listen = 9000/' $WWW_CONF

# Utiliser wp-cli pour configurer WordPress et créer les utilisateurs
cd /var/www/html

sed -i -r "s/dbname/$MYSQL_DATABASE/1"   wp-config.php
sed -i -r "s/dbuser/$MYSQL_USER/1"  wp-config.php
sed -i -r "s/dbpwd/$MYSQL_PASSWORD/1"    wp-config.php
sed -i -r "s/dbhost/$WP_DB_HOST/1"    wp-config.php

if ! wp core is-installed --allow-root; then
    wp core install --url="$DOMAIN_NAME" --title="$WP_TITLE" --admin_user="$WP_ADMIN_USER" --admin_password="$WP_ADMIN_PWD" --admin_email="$WP_ADMIN_EMAIL" --allow-root
fi

# Vérifier si l'utilisateur existe déjà
if ! wp user get "$WP_USER1" --allow-root; then
    wp user create "$WP_USER1" "$WP_USER1_EMAIL" --role=author --user_pass="$WP_USER1_PWD" --allow-root
fi

if ! wp theme is-installed twentysixteen --allow-root; then
    wp theme install twentytwentythree --activate --allow-root
fi



# wp core install --url="$DOMAIN_NAME" --title="$WP_TITLE" --admin_user="$WP_ADMIN_USER" --admin_password="$WP_ADMIN_PWD" --admin_email="$WP_ADMIN_EMAIL" --allow-root
# wp user create "$WP_USER1" "$WP_USER1_EMAIL" --role=author --user_pass="$WP_USER1_PWD" --allow-root
# wp theme install twentysixteen --activate

# Exécuter php-fpm en tant que processus principal
exec /usr/sbin/php-fpm7.4 -F


