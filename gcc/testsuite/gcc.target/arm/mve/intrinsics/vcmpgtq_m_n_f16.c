/* { dg-require-effective-target arm_v8_1m_mve_fp_ok } */
/* { dg-add-options arm_v8_1m_mve_fp } */
/* { dg-additional-options "-O2" } */

#include "arm_mve.h"

mve_pred16_t
foo (float16x8_t a, float16_t b, mve_pred16_t p)
{
  return vcmpgtq_m_n_f16 (a, b, p);
}

/* { dg-final { scan-assembler "vpst" } } */
/* { dg-final { scan-assembler "vcmpt.f16"  }  } */

mve_pred16_t
foo1 (float16x8_t a, float16_t b, mve_pred16_t p)
{
  return vcmpgtq_m_n (a, b, p);
}

/* { dg-final { scan-assembler "vpst" } } */
