/*
 * show-bytes-more.c
 */

 #include <stdio.h>
 
 typedef unsigned char* byte_pointer;
 
 void show_bytes(byte_pointer start, size_t len) {
   size_t i;
   for (i = 0; i < len; i++) {
     printf(" %.2x", start[i]);
   }
   printf("\n");
 }
 
 void show_int(int x) {
   show_bytes((byte_pointer) &x, sizeof(int));
 }
 
 void show_float(float x) {
   show_bytes((byte_pointer) &x, sizeof(float));
 }
 
 void show_pointer(void* x) {
   show_bytes((byte_pointer) &x, sizeof(void*));
 }
 
 //=============
 // 2.57 changes
 //=============
 void show_short(short x) {
   show_bytes((byte_pointer) &x, sizeof(short));
 }
 
 void show_long(long x) {
   show_bytes((byte_pointer) &x, sizeof(long));
 }
 
 void show_double(double x) {
   show_bytes((byte_pointer) &x, sizeof(double));
 }

 // i add for testing unsigned
 void show_unsigned(unsigned x){
   show_bytes((byte_pointer)&x,sizeof(unsigned));
 }
 //==================
 // 2.57 changes end
 //==================
 
 void test_show_bytes(int val) {
   int ival = val;
   float fval = (float) ival;
   int* pval = &ival;
 
   show_int(ival);
   show_float(fval);
   show_pointer(pval);
 
   //=============
   // 2.57 changes
   //=============
   short sval = (short) ival;
   long lval = (long) ival;
   double dval = (double) ival;
   unsigned uval=(unsigned)ival;// i add for testing unsigned
 
   show_short(sval);
   show_long(lval);
   show_double(dval);
   show_unsigned(uval); // i add for testing unsigned
   //==================
   // 2.57 changes end
   //==================

   // test unsigned negative
   unsigned a=100;
   unsigned b=-a;
   unsigned c=a+b;
   show_bytes((byte_pointer)&a,sizeof(unsigned));
   show_bytes((byte_pointer)&b,sizeof(unsigned));
   show_bytes((byte_pointer)&c,sizeof(unsigned));
 }
 
 int main(int argc, char* argv[]) {
   int test_num = 328;//try -328 :)
 
   test_show_bytes(test_num);
   return 0;
 }