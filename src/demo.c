#include <openssl/evp.h>
#include "demo.h"
int main()
{
  EVP_CIPHER_CTX *ctx;
  ctx = EVP_CIPHER_CTX_new();
MAIN_EXIT:
  if(ctx)
  {
    EVP_CIPHER_CTX_free(ctx);
    ctx = NULL;
  }
  return (0);
}
