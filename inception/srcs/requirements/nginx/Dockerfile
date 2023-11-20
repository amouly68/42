
# Utilisez l'image Debian Buster comme base
FROM debian:buster

# Mettez à jour les packages et installez Nginx
RUN apt-get update && apt-get install -y nginx openssl

# Générez un certificat SSL/TLS auto-signé
RUN mkdir /etc/nginx/ssl
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/nginx/ssl/mon_site.key -out /etc/nginx/ssl/mon_site.crt -subj "/C=FR/ST=Grand Est/L=Mulhouse/O=42 School/CN=localhost"


# Copiez votre fichier de configuration Nginx dans le conteneur
COPY ./conf/nginx.conf /etc/nginx/conf.d
# Copiez votre fichier HTML dans le répertoire de Nginx
COPY ./tools/index.html /var/www/html

# Exposez le port 80 pour Nginx
EXPOSE 6500
EXPOSE 6556

# Commande pour démarrer Nginx en mode daemon
CMD ["nginx", "-g", "daemon off;"]

