/* { dg-require-effective-target arm_v8_1m_mve_ok } */
/* { dg-skip-if "Incompatible float ABI" { *-*-* } { "-mfloat-abi=soft" } {""} } */
/* { dg-additional-options "-march=armv8.1-m.main+mve -mfloat-abi=hard -mthumb --save-temps" } */

#include "arm_mve.h"

int8x16_t value1;
int16x8_t value2;
int32x4_t value3;
int64x2_t value4;

int8x16_t
foo8 (void)
{
  int8x16_t b = value1;
  return b;
}

/* { dg-final { scan-assembler "vmov\\tq\[0-7\], q\[0-7\]"  }  } */
/* { dg-final { scan-assembler "vstrb.*" }  } */
/* { dg-final { scan-assembler "vldrb.8*" }  } */

int16x8_t
foo16 (void)
{
  int16x8_t b = value2;
  return b;
}

/* { dg-final { scan-assembler "vmov\\tq\[0-7\], q\[0-7\]"  }  } */
/* { dg-final { scan-assembler "vstrb.*" }  } */
/* { dg-final { scan-assembler "vldrb.8*" }  } */

int32x4_t
foo32 (void)
{
  int32x4_t b = value3;
  return b;
}

/* { dg-final { scan-assembler "vmov\\tq\[0-7\], q\[0-7\]"  }  } */
/* { dg-final { scan-assembler "vstrb.*" }  } */
/* { dg-final { scan-assembler "vldrb.8" }  } */

int64x2_t
foo64 (void)
{
  int64x2_t b = value4;
  return b;
}

/* { dg-final { scan-assembler "vmov\\tq\[0-7\], q\[0-7\]"  }  } */
/* { dg-final { scan-assembler "vstrb.*" }  } */
/* { dg-final { scan-assembler "vldrb.8" }  } */
