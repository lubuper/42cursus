# Pause execution for 10 seconds
sleep 10

# Install WordPress
wp core install --url="$WP_URL" \
    --title="$WP_TITLE" \
    --admin_user="$WP_ADMIN_USER" \
    --admin_password="$WP_ADMIN_PASSWORD" \
    --admin_email="$WP_ADMIN_EMAIL" \
    --skip-email \
    --path='/var/www/wordpress' \
    --allow-root

wp user create "$WP_USER" "$WP_EMAIL" \
    --user_pass="$WP_PASSWORD" \
    --role="$WP_ROLE" \
    --path='/var/www/wordpress' \
    --allow-root

# Start PHP FastCGI Process Manager
# PHP-FPM is responsible for handling PHP requests. 
/usr/sbin/php-fpm7.4 -F
