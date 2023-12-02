FROM debian:bullseye


RUN apt update -y 

RUN apt install php-fpm php-mysql -y

RUN apt install curl -y

RUN apt install netcat-openbsd -y


COPY ./tools/init_wp.sh /
COPY ./conf/wp-config.php /


CMD [ "/init_wp.sh" ]