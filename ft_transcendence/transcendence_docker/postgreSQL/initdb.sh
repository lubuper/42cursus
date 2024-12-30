#!/bin/bash

# Wait for PostgreSQL to be ready
until pg_isready -U "$POSTGRES_USER"; do
  echo "Waiting for PostgreSQL to be ready..."
  sleep 1
done

# Run the SQL commands
psql -U "$POSTGRES_USER" <<EOF
CREATE DATABASE transcendence_db;

DO \$\$
BEGIN
    IF NOT EXISTS (SELECT FROM pg_roles WHERE rolname = '${POSTGRES_USER}') THEN
        CREATE USER ${POSTGRES_USER} WITH PASSWORD '${POSTGRES_PASSWORD}';
    END IF;
END \$\$;

GRANT ALL PRIVILEGES ON DATABASE transcendence_db TO ${POSTGRES_USER};
EOF