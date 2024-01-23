FROM debian: oldstable

RUN apt-get update && apt-get install -y --no-install-recommends nginx openssl

RUN rm -rf /var/lib/apt/lists/*

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
	-keyout /etc/nginx/ssl/nginx.key -out /etc/nginx.crt \
	-subj "/C=PT/ST=Porto/L=Porto/O=42Porto/CN=ldesous"

COPY /config/nginx.conf /etc/nginx/nginx.conf

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]

# 'nginx' is the main command, '-g' is an option to specify global directives
#  'daemon off' turns off nginx running in background - allows the container
#  to stay active as long as the process is running
