/* { dg-do compile } */
/* { dg-options "-O2 -march=rv64gc_zknh -mabi=lp64" } */
/* { dg-skip-if "" { *-*-* } { "-g" "-flto"} } */

#include <stdint-gcc.h>

uint64_t foo1(uint64_t rs1)
{
    return __builtin_riscv_sha512sig0(rs1);
}

uint64_t foo2(uint64_t rs1)
{
    return __builtin_riscv_sha512sig1(rs1);
}

uint64_t foo3(uint64_t rs1)
{
    return __builtin_riscv_sha512sum0(rs1);
}

uint64_t foo4(uint64_t rs1)
{
    return __builtin_riscv_sha512sum1(rs1);
}


/* { dg-final { scan-assembler-times "sha512sig0" 1 } } */
/* { dg-final { scan-assembler-times "sha512sig1" 1 } } */
/* { dg-final { scan-assembler-times "sha512sum0" 1 } } */
/* { dg-final { scan-assembler-times "sha512sum1" 1 } } */
