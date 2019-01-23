# 制作serverKey.pem和serverCert.cer
```
openssl req -newkey rsa:2048 -nodes -keyout serverKey.pem \
    -x509 -days 365 -out serverCert.cer \
    -subj "/C=CN/ST=GD/L=GZ/O=abc/OU=defg/CN=server/emailAddress=server@132456.com"
```

# 验证
```
在第一个终端窗口运行
openssl s_server -accept 4430 -key serverKey.pem -cert serverCert.cer

在第二个终端窗口制作clientKey.pem和clientCert.cer，然后运行openssl s_client
openssl req -newkey rsa:2048 -nodes -keyout clientKey.pem \
    -x509 -days 365 -out clientCert.cer \
    -subj "/C=CN/ST=GD/L=GZ/O=abc/OU=defg/CN=client/emailAddress=client@132456.com"
openssl s_client -connect 127.0.0.1:4430 -key clientKey.pem -cert clientCert.cer 
```
