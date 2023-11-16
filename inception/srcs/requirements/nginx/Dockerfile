FROM debian:buster
RUN apt-get update && apt-get install -y nginx
RUN apt-get install -y openssl
# RUN rm -rf /var/www/html/*
# RUN rm -rf /etc/nginx/sites-enabled/default
#RUN openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=amouly.42.fr/UID=amouly"

COPY ./tools/index.html /var/www/
COPY ./conf/nginx.conf /etc/nginx/sites-available/

COPY ./conf/nginx.conf /etc/nginx/nginx.conf

EXPOSE 80

CMD [ "nginx", "-g", "daemon off;" ]