#!/bin/bash

PREFIX=/usr/local
build_dir=openssl
cd $build_dir
./config enable-sm2 enable-sm3 enable-sm4 --prefix="$PREFIX" && make \
	&& echo "Build OK! type: sudo make -C openssl install"
