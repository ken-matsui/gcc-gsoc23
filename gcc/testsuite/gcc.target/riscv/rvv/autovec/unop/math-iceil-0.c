/* { dg-do compile } */
/* { dg-options "-march=rv64gcv -mabi=lp64d -O3 -ftree-vectorize -fno-vect-cost-model -ffast-math -fno-schedule-insns -fno-schedule-insns2" } */
/* { dg-final { check-function-bodies "**" "" } } */

#include "test-math.h"

/*
** test_float_int___builtin_iceilf:
**   frrm\s+[atx][0-9]+
**   ...
**   fsrmi\s+3
**   ...
**   vsetvli\s+[atx][0-9]+,\s*zero,\s*e32,\s*m1,\s*ta,\s*ma
**   vfcvt\.x\.f\.v\s+v[0-9]+,\s*v[0-9]+
**   ...
**   fsrm\s+[atx][0-9]+
**   ret
*/
TEST_UNARY_CALL_CVT (float, int, __builtin_iceilf)
