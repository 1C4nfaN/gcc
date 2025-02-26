/* PR ipa/81214.  */
/* { dg-do run } */
/* { dg-require-ifunc "" } */
/* { dg-additional-sources "pr81213-2.c" } */

int bar();

__attribute__((target_clones("avx","arch=slm","arch=core-avx2","default")))
static int
foo ()
{
  return -2;
}

int main()
{
  return foo() + bar();
}

/* { dg-final { scan-assembler "\t.globl\tfoo" } } */
/* { dg-final { scan-assembler "foo.resolver:" } } */
/* { dg-final { scan-assembler "foo\\, @gnu_indirect_function" } } */
