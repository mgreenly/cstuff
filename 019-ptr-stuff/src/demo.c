int main() {

  char c = 'a';
  char *p= &c;
  char **pp = &p;

  printf("&c                = %p\n", (void *)&c);
  printf("(void *)p         = %p\n", (void *)p);
  printf("(void *)pp        = %p\n", (void *)pp);
  printf("(void *)*pp       = %p\n", (void *)*pp);

  putchar(c);
  puts("");

  putchar(*p);
  puts("");

  putchar(*(*pp));
  puts("");

  *p = 'b';

  putchar(c);
  puts("");

  putchar(*p);
  puts("");

  putchar(*(*pp));
  puts("");

  *(*pp) = 'c';

  putchar(c);
  puts("");

  putchar(*p);
  puts("");

  putchar(*(*pp));
  puts("");
}
