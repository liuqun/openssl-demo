#!/bin/bash

tarball_version="1.1.1c"
tarball_filename="openssl-$tarball_version.tar.gz"
download_from_url="https://openssl.org/source/$tarball_filename"
wget --continue $download_from_url

build_dir=openssl
if [ ! -d "$build_dir" ] ; then
  tar xf $tarball_filename
  mv "openssl-$tarball_version" "$build_dir"
fi