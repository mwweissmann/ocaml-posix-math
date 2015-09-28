#include <assert.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>
#include <time.h>
#include <math.h>
#include <complex.h>

#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h> 
#include <caml/threads.h> 
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/unixsupport.h>
#include <caml/custom.h>

#include "ocaml-posix-math-complex.h"

CAMLprim value caml_copy_complex(double complex c) {
  CAMLparam0();
  CAMLlocal1(v);
  v = caml_alloc(2, 0);
  Store_double_field(v, 0, creal(c));
  Store_double_field(v, 1, cimag(c));
  CAMLreturn(v);
}

CAMLprim value math_acosh(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_double(acosh(Double_val(x))));
}

CAMLprim value math_asinh(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_double(asinh(Double_val(x))));
}

CAMLprim value math_atanh(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_double(atanh(Double_val(x))));
}

CAMLprim value math_cabs(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_double(cabs(Complex_val(x))));
}

CAMLprim value math_cacos(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_complex(cacos(Complex_val(x))));
}

CAMLprim value math_cacosh(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_complex(cacosh(Complex_val(x))));
}

CAMLprim value math_casin(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_complex(casin(Complex_val(x))));
}

CAMLprim value math_casinh(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_complex(casinh(Complex_val(x))));
}

CAMLprim value math_catan(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_complex(catan(Complex_val(x))));
}

CAMLprim value math_catanh(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_complex(catanh(Complex_val(x))));
}

CAMLprim value math_cbrt(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_double(cbrt(Double_val(x))));
}

CAMLprim value math_ccos(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_complex(ccos(Complex_val(x))));
}

CAMLprim value math_ccosh(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_complex(ccosh(Complex_val(x))));
}

CAMLprim value math_ceil(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_double(ceil(Double_val(x))));
}

CAMLprim value math_copysign(value x, value y) {
  CAMLparam2(x, y);
  CAMLreturn(caml_copy_double(copysign(Double_val(x), Double_val(y))));
}

CAMLprim value math_cosh(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_double(cosh(Double_val(x))));
}

CAMLprim value math_cproj(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_complex(cproj(Complex_val(x))));
}

CAMLprim value math_csin(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_complex(csin(Complex_val(x))));
}

CAMLprim value math_csinh(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_complex(csinh(Complex_val(x))));
}

CAMLprim value math_ctan(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_complex(ctan(Complex_val(x))));
}

CAMLprim value math_ctanh(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_complex(ctanh(Complex_val(x))));
}

CAMLprim value math_lgamma(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_double(lgamma(Double_val(x))));
}

CAMLprim value math_llrint(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_int64(llrint(Double_val(x))));
}

CAMLprim value math_llround(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_int64(llround(Double_val(x))));
}

CAMLprim value math_log2(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_double(log2(Double_val(x))));
}

CAMLprim value math_logb(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_double(logb(Double_val(x))));
}

CAMLprim value math_lrint(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_int32(lrint(Double_val(x))));
}

CAMLprim value math_lround(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_int32(lround(Double_val(x))));
}

CAMLprim value math_modf(value x) {
  CAMLparam1(x);
  CAMLlocal1(z);
  double u, v;
  u = modf(Double_val(x), &v);
  z = caml_alloc(2, 0);
  Store_double_field(z, 0, u);
  Store_double_field(z, 1, v);
  CAMLreturn(z);
}

CAMLprim value math_nearbyint(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_double(nearbyint(Double_val(x))));
}

CAMLprim value math_nextafter(value x, value y) {
  CAMLparam2(x, y);
  CAMLreturn(caml_copy_double(nextafter(Double_val(x), Double_val(y))));
}

CAMLprim value math_nexttoward(value x, value y) {
  CAMLparam2(x, y);
  CAMLreturn(caml_copy_double(nexttoward(Double_val(x), Double_val(y))));
}

CAMLprim value math_pow(value x, value y) {
  CAMLparam2(x, y);
  CAMLreturn(caml_copy_double(pow(Double_val(x), Double_val(y))));
}

CAMLprim value math_remainder(value x, value y) {
  CAMLparam2(x, y);
  CAMLreturn(caml_copy_double(remainder(Double_val(x), Double_val(y))));
}

CAMLprim value math_remquo(value x, value y) {
  CAMLparam2(x, y);
  CAMLlocal1(z);
  double a;
  int i;
  a = remquo(Double_val(x), Double_val(y), &i);
  z = caml_alloc(2, 0);
  Store_field(z, 0, caml_copy_double(a));
  Store_field(z, 1, Val_int(i));
  CAMLreturn(z);
}

CAMLprim value math_rint(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_double(rint(Double_val(x))));
}

CAMLprim value math_round(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_double(round(Double_val(x))));
}

CAMLprim value math_scalbln(value x, value y) {
  CAMLparam2(x, y);
  CAMLreturn(caml_copy_double(scalbln(Double_val(x), Int64_val(y))));
}

CAMLprim value math_scalbn(value x, value y) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_double(scalbn(Double_val(x), Int_val(y))));
}

CAMLprim value math_signbit(value x) {
  CAMLparam1(x);
  CAMLreturn(Val_int(signbit(Double_val(x))));
}

CAMLprim value math_tanh(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_double(tanh(Double_val(x))));
}

CAMLprim value math_tgamma(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_double(tgamma(Double_val(x))));
}

CAMLprim value math_trunc(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_double(trunc(Double_val(x))));
}

