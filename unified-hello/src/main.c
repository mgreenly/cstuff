#define  _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <yaml.h>

#include "demo.h"
#include "foo.c"

#if defined(test)
  #include "unity.c"
  #include "test.c"
#else
  #include "demo.c"
#endif
