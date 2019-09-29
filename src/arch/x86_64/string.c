/****************************************************************************
 * Eric Ekstrom
 * CPE454
 * 2019-04-11
 *
 * string functions
 ***************************************************************************/

/*void *memset(void *dst, int c, int n) {
   unsigned char *ptr;
   int i;
   for (i = 0; i < n; i++)
      ptr[i] = c;

   return dst;
}

void *memcpy(void *dest, const void *src, int n) {
   uint8_t *srcPtr = src, *destPtr = dest;
   int i;
   for (i = 0; i < n; i++)
      destPtr[i] = srcPtr[i];

   return (void *) srcPtr;
}*/

int strlen(const char *chPtr) {
   int len = 0;
   while (*chPtr++ != '\0')
      len++;

   return len;
}
