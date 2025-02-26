/* { dg-require-effective-target arm_v8_1m_mve_ok } */
/* { dg-add-options arm_v8_1m_mve } */
/* { dg-additional-options "-O0" } */

#include "arm_mve.h"

void
foo ()
{
  int8x16_t a, aa;
  int16x8_t b, bb;
  int32x4_t c, cc;
  int64x2_t d, dd;
  uint8x16_t ua, uaa;
  uint16x8_t ub, ubb;
  uint32x4_t uc, ucc;
  uint64x2_t ud, udd;
  a = vuninitializedq (aa);
  b = vuninitializedq (bb);
  c = vuninitializedq (cc);
  d = vuninitializedq (dd);
  ua = vuninitializedq (uaa);
  ub = vuninitializedq (ubb);
  uc = vuninitializedq (ucc);
  ud = vuninitializedq (udd);
}

/* { dg-final { scan-assembler-times "vstrb.8" 24 } } */
