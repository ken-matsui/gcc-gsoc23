/* { dg-require-effective-target vect_int } */
/* { dg-require-effective-target vect_shift } */

#include <stdarg.h>
#include "tree-vect.h"

#define N 256

__attribute__ ((noinline)) void
foo (long long *arr)
{
  for (int i = 0; i < N; i++)
    arr[i] *= 123;
}

int
main (void)
{
  check_vect ();
  long long data[N];
  int i;

  for (i = 0; i < N; i++)
    {
      data[i] = i;
      __asm__ volatile ("");
    }

  foo (data);
#pragma GCC novector
  for (i = 0; i < N; i++)
    {
      if (data[i] / 123 != i)
      __builtin_abort ();
      __asm__ volatile ("");
    }

  return 0;
}

/* { dg-final { scan-tree-dump {vect_recog_mult_pattern: detected:[^\n]* \* 123} "vect" { target aarch64*-*-* xfail aarch64_sve } } } */
/* { dg-final { scan-tree-dump-times "vectorized 1 loops" 1 "vect"  { target aarch64*-*-* } } } */
