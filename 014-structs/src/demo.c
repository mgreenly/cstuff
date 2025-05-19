
struct S {
  int x;
  int y;
};

int main() {

  struct S s1;
  struct S *s2;

  s1.x = 1;
  s1.y = 2;

  printf("%d, %d\n", s1.x, s1.y);

  s2 = &s1;

  printf("%d, %d\n", s2->x, s2->y);

  struct S s3[] = {
    { 1, 2 },
    { 3, 4 },
    { 3, 4 },
    { 3, 4 },
    { 3, 4 },
  };

  for(int i=0; i < 2; i++) {
    printf("%d, %d\n", s3[i].x, s3[i].y);
  }

  puts("-------------------");
  printf("%u\n", &s3[0]);
  printf("%u\n", &s3[1]);
  printf("%u\n", &s3[2]);
  printf("%u\n", (int)&s3[1] - (int)&s3[0]);
  printf("%u\n", sizeof(struct S));
  puts("-------------------");
  printf("%u\n", (int)&s3[0]);
  printf("%u\n", (int)&s3[0] + 8);
  printf("%u\n", (int)&s3[0] + (2 * 8));
  puts("-------------------");
  printf("%u\n", &s3[0]);
  printf("%u\n", &s3[0] + 1);
  printf("%u\n", &s3[0] + 2);
  puts("-------------------");

  for(struct S *p=&s3[0]; p < &s3[2]; p += sizeof(struct S)) {
    printf("%d, %d\n", p->x, p->y);
  }

  struct S s4 = { 5, 6};
  printf("%d, %d\n", s4.x, s4.y);


  return 0;
}
