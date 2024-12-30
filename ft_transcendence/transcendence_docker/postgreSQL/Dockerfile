FROM postgres:16.4

COPY initdb.sh /docker-entrypoint-initdb.d/
RUN chmod +x /docker-entrypoint-initdb.d/initdb.sh
#to check if script worked:
#docker run --name *container_name* -e POSTGRES_PASSWORD=admin -d *image_name*
#docker exec -it *container_name* bash
#psql -U admin -d transcendence_db
