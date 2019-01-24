参考：https://blog.csdn.net/oj847935591/article/details/79362542
作者：Brown_IT小白
来源：CSDN

# 制作serverKey.pem和serverCert.cer
```
openssl req -newkey rsa:2048 -nodes -keyout serverKey.pem \
    -x509 -days 365 -out serverCert.cer \
    -subj "/C=CN/ST=GD/L=GZ/O=abc/OU=defg/CN=hijk/emailAddress=132456.com"
```

# CentOS环境编译前需要安装开发工具
```
sudo yum groupinstall "Development Tools"
sudo yum install cmake3 openssl-devel
```

# 编译步骤
```
cmake3 .
make
```
