# docusaurus

Concord pay documentation

## deploy

```
git clone --branch <branchname> https://git.mustpay.tech/concordpay/docusaurus.git

docker-compose up -d

http://localhost:3000/docs/docs/ru/dispatcher
```

## commit

```
docker exec -it docusaurus_docusaurus_1  /bin/bash
/app/website# yarn build
# rm -r /app/website/ready/* 
# cp -r /app/website/build/* /app/website/ready/
# exit

git commit
```


##without docker
```
# yarn install
# yarn start
# yarn build
```