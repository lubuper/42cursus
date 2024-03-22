FROM debian:bullseye

EXPOSE 443

ARG	CERT_DIR
ARG	CERTIFICATE
ARG	KEY
ARG	COUNTRY
ARG	STATE
ARG	LOCALITY
ARG	ORGANIZATION
ARG	UNIT
ARG	DOMAIN_NAME

RUN	apt update

RUN	apt upgrade -y

RUN	apt update && apt install -y --no-install-recommends --no-install-suggests \
	nginx openssl

RUN	mkdir -p ${CERT_DIR} && openssl req -newkey rsa:4096 -x509 -sha256 -nodes \
	-out ${CERTIFICATE} -keyout ${KEY} \
	-subj "/C=${COUNTRY}/ST=${STATE}/L=${LOCALITY}/O=${ORGANIZATION}/OU=${UNIT}/CN=${DOMAIN_NAME}"

RUN	mkdir -p /var/run/nginx

COPY	./conf/nginx.conf /etc/nginx/

RUN	sed -i "s#{{CERTIFICATE}}#$CERTIFICATE#g" /etc/nginx/nginx.conf

RUN	sed -i "s#{{KEY}}#$KEY#g" /etc/nginx/nginx.conf

RUN	sed -i "s#{{DOMAIN_NAME}}#$DOMAIN_NAME#g" /etc/nginx/nginx.conf

RUN	chmod 755 /var/www/html

RUN	chown -R www-data:www-data /var/www/html

ENTRYPOINT	["nginx", "-g", "daemon off;"]
