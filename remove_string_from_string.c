#include <stdio.h>
#include <string.h>

/* You wanna do it it python?
 * a = 'UNOdogDUEdogTRE'
 * b = 'dog'
 * print b
 * a = a.replace(b, '')
 * print a
 */

void removeSubstring(char *s, const char *toremove) {
  while(s = strstr(s, toremove)) {
    memmove(s, s+strlen(toremove), strlen(s)-strlen(toremove));
  }
}


int main(void) {

  char a[] = "UNOdogDUEdogTRE";
  const char *b = "dog";

  printf("String = %s\n", a);
  //printf("String len = %lu\n", sizeof(a)/sizeof(char));
  removeSubstring(a, b);
  printf("String = %s\n", a);
  //printf("String len = %lu\n", sizeof(a)/sizeof(char));
  return 0;
}
