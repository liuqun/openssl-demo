#!/bin/bash

clone_from_url="https://github.com/openssl/openssl.git"
openssl_git_tag="OpenSSL_1_1_1c"
build_dir=openssl
if [ ! -d "$build_dir" ] ; then
  echo "Cloning tag $openssl_git_tag from $clone_from_url"
  git clone --depth=1 -b $openssl_git_tag $clone_from_url
fi