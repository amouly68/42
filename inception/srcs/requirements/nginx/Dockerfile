

FROM debian:bullseye

RUN echo 'debconf debconf/frontend select Noninteractive' | debconf-set-selections
RUN apt-get update && apt-get install -y apt-utils && apt-get install -y nginx openssl

RUN mkdir /etc/nginx/ssl
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/nginx/ssl/mon_site.key -out /etc/nginx/ssl/mon_site.crt -subj "/C=FR/ST=Grand Est/L=Mulhouse/O=42 School/CN=localhost"

COPY ./conf/nginx.conf /etc/nginx/conf.d

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]

