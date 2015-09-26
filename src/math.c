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

#define Complex_val(v) (* (double complex *)(v))

int complex_compare(value v1, value v2) {
  return memcmp(Data_custom_val(v1), Data_custom_val(v2), sizeof(double complex));
}

static struct custom_operations complex_custom_ops = {
  identifier:  "Posix_math.complex",
  finalize:    custom_finalize_default,
  compare:     complex_compare,
  hash:        custom_hash_default,
  serialize:   custom_serialize_default,
  deserialize: custom_deserialize_default
};

static value caml_copy_complex(double complex c) {
  CAMLparam0();
  CAMLlocal1(v);
  v = caml_alloc_custom(&complex_custom_ops, sizeof(double complex), 0, 1);
  memcpy(Data_custom_val(v), &c, sizeof(double complex));
  CAMLreturn(v);
}

CAMLprim value math_acos(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_double(acos(Double_val(x))));
}

CAMLprim value math_acosh(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_double(acosh(Double_val(x))));
}

CAMLprim value math_asin(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_double(asin(Double_val(x))));
}

CAMLprim value math_asinh(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_double(asinh(Double_val(x))));
}

CAMLprim value math_atan(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_double(atan(Double_val(x))));
}

CAMLprim value math_atan2(value x, value y) {
  CAMLparam2(x, y);
  CAMLreturn(caml_copy_double(atan2(Double_val(x), Double_val(y))));
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

CAMLprim value math_carg(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_double(carg(Complex_val(x))));
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

CAMLprim value math_cexp(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_complex(cexp(Complex_val(x))));
}

CAMLprim value math_cimag(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_double(cimag(Complex_val(x))));
}

CAMLprim value math_clog(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_complex(clog(Complex_val(x))));
}

CAMLprim value math_conj(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_complex(conj(Complex_val(x))));
}

CAMLprim value math_copysign(value x, value y) {
  CAMLparam2(x, y);
  CAMLreturn(caml_copy_double(copysign(Double_val(x), Double_val(y))));
}

CAMLprim value math_cos(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_double(conj(Double_val(x))));
}

CAMLprim value math_cosh(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_double(cosh(Double_val(x))));
}

CAMLprim value math_cpow(value x, value y) {
  CAMLparam2(x, y);
  CAMLreturn(caml_copy_complex(cpow(Complex_val(x), Complex_val(y))));
}

CAMLprim value math_cproj(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_complex(cproj(Complex_val(x))));
}

CAMLprim value math_creal(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_double(creal(Complex_val(x))));
}

CAMLprim value math_csin(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_complex(csin(Complex_val(x))));
}

CAMLprim value math_csinh(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_complex(csinh(Complex_val(x))));
}

CAMLprim value math_csqrt(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_complex(csqrt(Complex_val(x))));
}

CAMLprim value math_ctan(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_complex(ctan(Complex_val(x))));
}

CAMLprim value math_ctanh(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_complex(ctanh(Complex_val(x))));
}

CAMLprim value math_ldexp(value x, value y) {
  CAMLparam2(x, y);
  CAMLreturn(caml_copy_double(ldexp(Double_val(x), Int_val(y))));
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

CAMLprim value math_log(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_double(log(Double_val(x))));
}

CAMLprim value math_log10(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_double(log10(Double_val(x))));
}

CAMLprim value math_log1p(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_double(log1p(Double_val(x))));
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

CAMLprim value math_modf(value x, value y) {
  CAMLparam2(x, y);
  CAMLlocal1(z);
  double a, b;
  a = modf(Double_val(x), &b);
  z = caml_alloc(2, 0);
  Store_field(z, 0, caml_copy_double(a));
  Store_field(z, 1, caml_copy_double(b));
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

CAMLprim value math_sin(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_double(sin(Double_val(x))));
}

CAMLprim value math_sinh(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_double(sinh(Double_val(x))));
}

CAMLprim value math_sqrt(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_double(sqrt(Double_val(x))));
}

CAMLprim value math_tan(value x) {
  CAMLparam1(x);
  CAMLreturn(caml_copy_double(tan(Double_val(x))));
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

