#!/bin/sh

while ! nc -z transcendence_db 5432; do
  echo "Waiting for database to be ready..."
  sleep 2
done

echo "Database is up"

# Run database migrations
python3 manage.py makemigrations
python3 manage.py migrate

# Create Django superuser
python3 manage.py shell << END
from django.contrib.auth import get_user_model
User = get_user_model()
username = os.getenv('DJANGO_SUPERUSER_USERNAME', 'admin')  # Default to 'admin' if not set
password = os.getenv('DJANGO_SUPERUSER_PASSWORD', 'admin')  # Default to 'admin' if not set
email = ''
if not User.objects.filter(username=username).exists():
    User.objects.create_superuser(username=username, email=email, password=password)
    print('Superuser created')
else:
    print('Superuser already exists')
END

#daphne -u /tmp/daphne.sock transcendence.asgi:application &

exec "$@"
