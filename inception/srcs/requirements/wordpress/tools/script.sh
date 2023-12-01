#!/bin/bash
set -e

# Attendre que la base de données soit prête
until nc -z mariadb 3306; do
  >&2 echo "MariaDB is unavailable - sleeping"
  sleep 1
done

# Utiliser wp-cli pour configurer WordPress et créer les utilisateurs
cd /var/www/html
wp core install --url="$DOMAIN_NAME" --title="$WP_TITLE" --admin_user="$WP_ADMIN_USER" --admin_password="$WP_ADMIN_PWD" --admin_email="$WP_ADMIN_EMAIL" --allow-root
wp user create "$WP_USER1" "$WP_USER1_EMAIL" --role=author --user_pass="$WP_USER1_PWD" --allow-root

# Créer le répertoire pour le socket, si nécessaire
mkdir -p /run/php

# Assurer que www-data (ou autre utilisateur PHP-FPM) peut écrire dans ce répertoire
chown www-data:www-data /run/php

# Chemin du fichier de configuration PHP-FPM
WWW_CONF="/etc/php/7.4/fpm/pool.d/www.conf"

# Configurer PHP-FPM pour utiliser un socket Unix
sed -i 's/^listen = .*/listen = \/run\/php\/php7.4-fpm.sock/' $WWW_CONF


# Exécuter php-fpm en tant que processus principal
exec /usr/sbin/php-fpm7.4


