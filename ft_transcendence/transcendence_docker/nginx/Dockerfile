FROM nginx:alpine

COPY nginx.conf /etc/nginx/nginx.conf

#COPY ./etc/certs/self_signed_cert.pem /etc/nginx/ssl/self_signed_cert.pem
#COPY ./etc/certs/self_signed_key.pem /etc/nginx/ssl/self_signed_key.pem
#COPY ./etc/certs/self_signed_cert.crt /etc/nginx/ssl/self_signed_cert.crt
#COPY ./etc/certs/self_signed_cert.crt /usr/local/share/ca-certificates/

COPY ./etc/certs/server.crt /etc/nginx/ssl/server.crt
COPY ./etc/certs/server.key /etc/nginx/ssl/server.key

EXPOSE 80 443

# Update certificates and run nginx
RUN update-ca-certificates
CMD ["nginx", "-g", "daemon off;"]
