/** 文件名: client.c */
#include <stdio.h>
#include <openssl/evp.h>
#include <openssl/x509.h>
#include <openssl/ssl.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <dlfcn.h>
#include <unistd.h>

#define CHK_ERR(err, s) if((err) == -1) { perror(s); return -1; }
#define CHK_RV(rv, s) if((rv) != 1) { printf("%s error\n", s); return -1; }
#define CHK_NULL(x, s) if((x) == NULL) { printf("%s error\n", s); return -1; }
#define CHK_SSL(err, s) if((err) == -1) { ERR_print_errors_fp(stderr);  return -1;}

int main()
{
	int rv;
	int err;
	int client_fd;
	struct sockaddr_in socketAddrClient;
	const SSL_METHOD *meth = NULL;
	SSL_CTX *ctx = NULL;
	SSL *ssl = NULL;
	char buf[4096];

	rv = SSL_library_init();
	CHK_RV(rv, "SSL_library_init");

	meth = TLSv1_2_client_method();
	ctx = SSL_CTX_new(meth);
	CHK_NULL(ctx, "SSL_CTX_new");

	client_fd = socket(AF_INET, SOCK_STREAM, 0);
	CHK_ERR(client_fd, "socket");
	memset(&socketAddrClient, 0, sizeof(socketAddrClient));
	socketAddrClient.sin_family = AF_INET;
	socketAddrClient.sin_port = htons(8443);
	socketAddrClient.sin_addr.s_addr = inet_addr("127.0.0.1");

	err = connect(client_fd, (struct sockaddr *)&socketAddrClient, sizeof(socketAddrClient));
	CHK_ERR(err, "connect");
	ssl = SSL_new(ctx);
	CHK_NULL(ssl, "SSL_new");
	rv = SSL_set_fd(ssl, client_fd);
	CHK_RV(rv, "SSL_set_fd");
	rv = SSL_connect(ssl);
	CHK_RV(rv, "SSL_connect");

	rv = SSL_write(ssl, "Hello, I am the client", strlen("Hello, I am the client"));
	CHK_SSL(rv, "SSL_write");
	rv = SSL_read(ssl, buf, sizeof(buf) - 1);
	CHK_SSL(rv, "SSL_read");
	buf[rv] = '\0';
	printf("Got %d chars :%s\n", rv, buf);

	SSL_shutdown(ssl);
	close(client_fd);
	SSL_free(ssl);
	SSL_CTX_free(ctx);

	return 0;
}
