#!/bin/bash

BACKEND_IP=..address..
FOLDER=..mainfloader..

cd `dirname "$0"`
pwd
NAME=backup_`date +%d.%m.%y`.zip
wget --no-check-certificate https://$BACKEND_IP/$FOLDER/backups/backup.zip -O $NAME
echo DONE
