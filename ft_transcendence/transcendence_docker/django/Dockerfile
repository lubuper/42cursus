FROM debian:bullseye

RUN apt-get update && \
    apt upgrade -y && \
    apt install -y python3-pip netcat iproute2 net-tools && \
    pip3 install django psycopg2-binary channels_redis Pillow


RUN django-admin startproject transcendence

WORKDIR /transcendence

COPY project_files/. .

#RUN pip3 install Pillow
RUN pip3 install channels daphne

#RUN python3 manage.py migrate



COPY wait_for_db.sh .
RUN chmod +x wait_for_db.sh

EXPOSE 8000 443

#CMD ["tail", "-f", "/dev/null"]

# Add this at the top to define a build argument
ARG ALLOWED_HOST

# Set the environment variable inside the Docker container
ENV ALLOWED_HOST=$ALLOWED_HOST

RUN python3 manage.py collectstatic --noinput

ENTRYPOINT ["./wait_for_db.sh"]



#If you want to test the container alone,
#don't forget to run "docker run -d -p 8000:8000 django",
#otherwise it won't work
