// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=93038
// { dg-options "-J $srcdir/gdc.dg/fileimports -MMD -MP" }
// { dg-do compile }
// { dg-final { scan-file pr93038b.deps "pr93038b.o: \[^\n\]*/pr93038b.d \[ \\\\\n\]*\[^\n\]*/fileimports/pr93038.txt\n\n\[^\n\]*/fileimports/pr93038.txt:" } }
// { dg-final { file delete pr93038b.deps } }
module pr93038b;

const VERSION = import("pr93038.txt");
