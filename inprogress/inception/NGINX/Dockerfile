FROM debian: oldstable

RUN apt-get update && apt-get install -y nginx && apt-get install -y openssl && rm -rf /var/lib/apt/lists/*

CMD ["nginx", "-g", "daemon off;"]

# 'nginx' is the main command, '-g' is an option to specify global directives
#  'daemon off' turns off nginx running in background - allows the container
#  to stay active as long as the process is running
