
# 下载GmSSL
网址：https://github.com/guanzhi/GmSSL
如果通过源码包方式下载需要手动解压缩
如果通过git方式下载可以按标签找出特定版本

# GmSSL编译步骤
```
cd GmSSL-master
./config
make
sudo make install
```

# 安装之后的环境配置
默认会安装到/usr/local/bin和/usr/local/lib64目录，
需要注意运行gmssl工具前，还需要手动配置环境变量LD_LIBRARY_PATH=/usr/local/lib64
```
export LD_LIBRARY_PATH=/usr/local/lib64
GmSSL> version
GmSSL 2.0 - OpenSSL 1.1.0d  26 Jan 2017
GmSSL> quit
```

# 制作SM2椭圆曲线密钥文件和X509格式的证书

```
# 设置环境变量
export LD_LIBRARY_PATH=/usr/local/lib64

# 椭圆曲线签名密钥skey
gmssl sm2 -genkey -out ca.skey.pem

# 创建CA根证书
gmssl req -new -nodes -x509 -days 3650 \
    -key ca.skey.pem -out ca.cert.pem \
    -subj "/C=CN/ST=GD/L=GZ/O=abc/OU=defg/CN=CA/emailAddress=CA@132456.com"

# 创建用户密钥和用户证书

# 通讯测试
gmssl s_server -accept 4433 -key serverKey.pem -cert serverCert.cer 
gmssl s_client -connect 127.0.0.1:4433 -key clientKey.pem -cert clientCert.cer
```

# 参考文档：
* https://github.com/guanzhi/GmSSL/tree/master#quick-start
