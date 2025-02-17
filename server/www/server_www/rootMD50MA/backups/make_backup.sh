#!/bin/bash

MYSQL_PASSWORD=..yourpassword..
MYSQL_DB=database

cd `dirname "$0"`
pwd
mysqldump -uroot -p$MYSQL_PASSWORD $MYSQL_DB > db.sql
zip -r9 -P$MYSQL_PASSWORD backup.zip db.sql ../data/*.log
rm db.sql
date +%s > ../static/last_backup.ts
echo "DONE, password $MYSQL_PASSWORD"

