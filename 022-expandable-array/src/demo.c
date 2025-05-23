
size_t load_file(char *filename, char **buffer) {
  size_t bytes_read;

  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("failed to open file");
    return -1;
  }

  struct stat st;
  int retval;
  retval = stat(filename, &st);
  if (retval == -1) {
    perror("stat failed");
    fclose(fp);
    return -1;
  }

  *buffer = malloc(st.st_size);
  if (buffer == NULL) {
    perror("malloc failed");
    fclose(fp);
    return -1;
  }

  bytes_read = fread(*buffer, sizeof(char), st.st_size, fp);
  if (ferror(fp)) {
    perror("fread failed");
    free(*buffer);
    fclose(fp);
    return -1;
  }

  fclose(fp);

  return bytes_read;
}

void free_file(char *buffer) {
    free(buffer);
}

typedef struct { size_t len; char *data; } slice;

void slice_inspect(slice *s) {
  printf("slice: %p\n", (void *)s);
  printf("  len: %zu\n", s->len);
  printf("  ");
  for(size_t i = 0; i < s->len; i++) {
    putc(s->data[i], stdout);
  }
  putc('\n', stdout);
}

#define GREETING "hello world!"

int main(int argc, char *argv[]) {

  char *buffer;
  size_t bytes_read;
  int retval = 0;

  size_t max_elements = 2;
  /* size_t growth_factor = 2, max_elements; */

  slice *array = NULL;

  array = calloc(max_elements, sizeof(slice));

  for(size_t j = 0; j < 16; j++) {
    if(j >= max_elements) {
      puts("going to realloc");
      max_elements *= 2;
      array = realloc(array, max_elements * sizeof(slice));
      if (array == NULL) {
        perror("realloc failed");
        exit(EXIT_FAILURE);
      }
    }
    printf("j: %zu\n", j);
    printf("max_elements: %zu\n", max_elements);

    array[j].len = strlen(GREETING);
    array[j].data = GREETING;
    slice_inspect(&array[j]);

  }

  free(array);

  exit(EXIT_SUCCESS);

  for(int i = 1; i < argc; i++) {
    bytes_read = load_file(argv[i], &buffer);
    if (bytes_read == 0) {
      continue;
    }

    size_t slice_start = 0;
    for(size_t j = 0; j < bytes_read; j++) {

      if (buffer[j] == '\n') {
        slice s = { .len = j - slice_start, .data = buffer + slice_start };
        slice_inspect(&s);
        slice_start = j + 1;
      }

      putc(buffer[j], stdout);
    }

    free_file(buffer);
  }

  return retval;
}
