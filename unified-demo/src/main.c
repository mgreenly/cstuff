#define  _POSIX_C_SOURCE 200809L

#define DEMO_VERSION_MAJOR 0
#define DEMO_VERSION_MINOR 1
#define DEMO_VERSION_PATCH 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <yaml.h>

#include "foo.c"
#include "bar.c"
#include "baz.c"

#if defined(test)
  #include "test/unity.c"
  #include "test/test.c"
#else
  #include "demo.c"
#endif
