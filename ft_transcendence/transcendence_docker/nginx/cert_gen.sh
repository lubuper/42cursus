#!/bin/bash

# Get the machine's IP address (assumes eth0 is the network interface)
HOST_IP=$(hostname -I | awk '{print $1}')
#HOST_IP="10.11.12.6"  # Uncomment and use this line if you want to hardcode the IP
echo "Host IP: $HOST_IP"

# If you prefer to use a custom domain name instead of IP, you can define it manually
DOMAIN_NAME="local.ftranscendence.local"  # You can change this

# Path where you want to store the certificates
CERT_DIR="./nginx/etc/certs"
CERT_FILE="$CERT_DIR/self_signed_cert.crt"
KEY_FILE="$CERT_DIR/self_signed_key.key"

# Create the certs directory if it doesn't exist
mkdir -p $CERT_DIR

openssl genrsa -out ./nginx/etc/certs/ca.key 2048
openssl req -x509 -new -nodes -key ./nginx/etc/certs/ca.key -sha256 -days 365 -out ./nginx/etc/certs/ca.crt \
  -subj "/C=PT/ST=Porto/L=Porto/O=42Porto/OU=IT/CN=MyCustomCA"

openssl genrsa -out ./nginx/etc/certs/server.key 2048
openssl req -new -key ./nginx/etc/certs/server.key -out ./nginx/etc/certs/server.csr \
  -subj "/C=PT/ST=Porto/L=Porto/O=42Porto/OU=IT/CN=$HOST_IP"

echo "subjectAltName=IP:$HOST_IP" > ./nginx/etc/certs/extfile.cnf

openssl x509 -req -in ./nginx/etc/certs/server.csr -CA ./nginx/etc/certs/ca.crt -CAkey ./nginx/etc/certs/ca.key -CAcreateserial \
  -out ./nginx/etc/certs/server.crt -days 365 -sha256 -extfile ./nginx/etc/certs/extfile.cnf

rm ./nginx/etc/certs/extfile.cnf

#openssl req -x509 -nodes -newkey rsa:2048 -keyout $KEY_FILE -out $CERT_FILE -days 365 -config $CERT_DIR/openssl.cnf

#if [ -f "$CERT_FILE" ] && [ -f "$KEY_FILE" ]; then
#    echo "Self-signed certificate generated for IP: $HOST_IP"
#else
#    echo "Error: Certificate generation failed."
#    exit 1
#fi

#sudo cp $CERT_FILE /usr/local/share/ca-certificates/
#sudo update-ca-certificates --verbose

#openssl x509 -in ./nginx/etc/certs/self_signed_cert.pem -out ./nginx/etc/certs/self_signed_cert.crt

# Generate the self-signed certificate using the dynamically generated config file
#openssl req -x509 -nodes -newkey rsa:2048 -keyout $KEY_FILE -out $CERT_FILE -days 365 -config $CERT_DIR/openssl.cnf

#if [ -f "$CERT_FILE" ] && [ -f "$KEY_FILE" ]; then
#    echo "Self-signed certificate generated for IP: $HOST_IP"
#else
#    echo "Error: Certificate generation failed."
#    exit 1
#fi

# Path to the .env file
ENV_FILE=".env"

# Update or add the ALLOWED_HOST variable in the .env file
if [[ -n "$HOST_IP" ]]; then
    if grep -q "ALLOWED_HOST=" "$ENV_FILE"; then
        # Update the existing ALLOWED_HOST entry
        sed -i "s/^ALLOWED_HOST=.*/ALLOWED_HOST=$HOST_IP/" "$ENV_FILE"
        echo "Updated ALLOWED_HOST in $ENV_FILE to: $HOST_IP"
    else
        # Add ALLOWED_HOST entry if it doesn't exist
        echo "ALLOWED_HOST=$HOST_IP" >> "$ENV_FILE"
        echo "Added ALLOWED_HOST to $ENV_FILE: $HOST_IP"
    fi
else
    echo "Failed to determine the host IP. Please check your network configuration."
    exit 1
fi

