#!/bin/bash
mv sites/bot.conf /etc/apache2/sites-available/
mv www /var/data/www/icserver
a2ensite bot
service apache2 restart
mv apache_ip_block /var/data/
chown -R www-data:www-data /var/data/apache_ip_block
chmod 0777 /var/data/www/icserver/gate/pdo.php
chmod 0777 /var/data/www/icserver/gate/bot_api.php
chmod 0777 /var/data/www/icserver/gate/smarts.class.php