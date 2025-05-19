int main() {

  char *str2;
  char *str1 = "Hello, World!";

  int arr1[] = {1, 2, 3};
  int *arr2 = arr1;
  int *arr3 = &arr1[0];

  str2 = str1;

  puts(str1);
  puts(str2);

  for(int i = 0; i < 3; i++) {
    printf("%d ", arr1[i]);
  }
  puts("");

  for(int i = 0; i < 3; i++) {
    printf("%d ", arr2[i]);
  }
  puts("");

  printf("%d \n", arr1[0]);

  for(int i = 0; i < 3; i++) {
    printf("%d ", arr3[i]);
  }
  puts("\n");

  printf("char bits      %d \n", CHAR_BIT);
  puts("");

  unsigned char xval1 = 0;
  printf("char      %zu (%u::%u)\n", sizeof(xval1) * CHAR_BIT, 0, UCHAR_MAX);
  unsigned short xval2 = 0;
  printf("short     %zu (%u::%u)\n", sizeof(xval2) * CHAR_BIT, 0, USHRT_MAX);
  unsigned int xval4 = 0;
  printf("int       %zu (%u::%u)\n", sizeof(xval4) * CHAR_BIT, 0, UINT_MAX);
  unsigned long xval3 = 0;
  printf("long      %zu (%lu::%lu)\n", sizeof(xval3) * CHAR_BIT, 0, ULONG_MAX);

  puts("");

  signed char val1 = 0;
  printf("char      %zu (%d::%d) \n", sizeof(val1) * CHAR_BIT, CHAR_MIN, CHAR_MAX);
  signed short val2 = 0;
  printf("short     %zu (%d::%d) \n", sizeof(val2) * CHAR_BIT, SHRT_MIN, SHRT_MAX);
  signed int val4 = 0;
  printf("int       %zu (%d::%d) \n", sizeof(val4) * CHAR_BIT, INT_MIN, INT_MAX);
  signed long val3 = 0;
  printf("long      %zu (%ld::%ld) \n", sizeof(val3) * CHAR_BIT, LONG_MIN, LONG_MAX);

  return 0;
}
