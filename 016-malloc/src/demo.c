
int main(int argc, char *argv[]) {

  struct stat st;
  char *buffer;
  size_t bytes_read;
  int retval = 0;

  for(int i = 1; i < argc; i++) {
    FILE *fp = fopen(argv[i], "r");
    if (fp == NULL) {
      perror("failed to open file");
      continue;
    }

    retval = stat(argv[i], &st);
    if (retval == -1) {
      perror("stat failed");
      fclose(fp);
      continue;
    }

    buffer = malloc(st.st_size);
    bytes_read = fread(buffer, sizeof(char), st.st_size, fp);
    if (ferror(fp)) {
      perror("fread failed");
      free(buffer);
      fclose(fp);
      continue;
    }

    for(unsigned int j = 0; j < bytes_read; j++) {
      putc(buffer[j], stdout);
    }

    free(buffer);
    fclose(fp);
  }

  return retval;
}
