#!/bin/bash
mkdir ./overlay ./overlay/work ./overlay/upper ./merged
sudo mount -t overlay overlay -o lowerdir=./share,upperdir=./overlay/upper,workdir=./overlay/work ./merged
chmod -R ugo+rw ./merged

docker-compose run --rm homework /bin/sh

sudo umount -l ./merged
sudo rm -rf ./overlay ./merged
