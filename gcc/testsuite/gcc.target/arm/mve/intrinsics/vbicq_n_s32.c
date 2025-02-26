/* { dg-require-effective-target arm_v8_1m_mve_ok } */
/* { dg-add-options arm_v8_1m_mve } */
/* { dg-additional-options "-O2" } */

#include "arm_mve.h"

int32x4_t
foo (int32x4_t a)
{
  return vbicq_n_s32 (a, 1);
}

/* { dg-final { scan-assembler "vbic.i32"  }  } */
