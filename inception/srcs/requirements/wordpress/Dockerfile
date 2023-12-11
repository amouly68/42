
# Utilise l'image de base Debian Bullseye
FROM debian:bullseye

# Installer PHP, php-fpm, et les extensions PHP nécessaires
RUN apt-get update && apt-get install -y \
    php \
    php-fpm \
    php-mysql \
    php-curl \
    php-gd \
    php-mbstring \
    php-xml \
    php-xmlrpc \
    php-soap \
    php-intl \
    php-zip \
    netcat-openbsd \
    curl \
    sudo \
    less \
    && rm -rf /var/lib/apt/lists/*
# Créer le répertoire pour WordPress avec les bonnes permissions
RUN mkdir -p /var/www/html && chown -R www-data:www-data /var/www/html

# Télécharger WordPress et le décompresser dans le répertoire de travail
RUN curl -o latest.tar.gz https://wordpress.org/latest.tar.gz \
    && tar -xzf latest.tar.gz -C /var/www/html --strip-components=1 \
    && rm latest.tar.gz

# Installer wp-cli
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && chmod +x wp-cli.phar \
    && mv wp-cli.phar /usr/local/bin/wp

# Copier le script d'initialisation dans le conteneur et changer les permissions
COPY tools/init_wp.sh /usr/local/bin/init_wordpress.sh
RUN chmod +x /usr/local/bin/init_wordpress.sh

# Copier le fichier de configuration php-fpm (si nécessaire)
COPY conf/wp-config.php /var/www/html/wp-config.php

Exposer le port sur lequel php-fpm écoute
EXPOSE 9000

ENTRYPOINT ["init_wordpress.sh"]