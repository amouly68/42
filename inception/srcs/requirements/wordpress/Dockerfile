# Utilise l'image de base Debian Bullseye
FROM debian:bullseye

# Installer PHP, php-fpm, extensions PHP nécessaires, et autres dépendances
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
COPY tools/script.sh /usr/local/bin/init_wordpress.sh
RUN chmod +x /usr/local/bin/init_wordpress.sh

# Créer un utilisateur non-root
# RUN useradd -m wordpress_user

# Copier le fichier de configuration php-fpm (si nécessaire)
# COPY www.conf /etc/php/7.4/fpm/pool.d/

# Exposer le port sur lequel php-fpm écoute
EXPOSE 9000

# Passer à l'utilisateur non-root et définir le script d'initialisation comme point d'entrée
# USER wordpress_user
ENTRYPOINT ["init_wordpress.sh"]

