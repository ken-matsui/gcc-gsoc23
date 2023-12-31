/* PR c/102989 */
/* { dg-do run { target bitint } } */
/* { dg-options "-std=gnu2x" } */
/* { dg-skip-if "" { ! run_expensive_tests }  { "*" } { "-O0" "-O2" } } */
/* { dg-skip-if "" { ! run_expensive_tests } { "-flto" } { "" } } */

#include "../../c-c++-common/torture/builtin-arith-overflow-1.h"

#define U(s, op) op
TESTS (_BitInt(19), (-262143wb - 1), 262143wb)

#undef T
#define T(n, t1, t2, tr, v1, v2, vr, b, o) t##n##b ();

int
main ()
{
  TESTS (_BitInt(19), (-262143wb - 1), 262143wb)
  return 0;
}
