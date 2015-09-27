#include <assert.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>
#include <time.h>
#include <math.h>
#include <complex.h>
#include <fenv.h>

#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h> 
#include <caml/threads.h> 
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/unixsupport.h>
#include <caml/custom.h>

#define Complex_val(v) ((double complex) (Double_val(Field(v, 0)) + I * Double_val(Field(v, 0))))

static value caml_copy_complex(double complex c) {
  CAMLparam0();
  CAMLlocal1(v);
  v = caml_alloc(2, 0);
  Store_field(v, 0, caml_copy_double(creal(c)));
  Store_field(v, 1, caml_copy_double(cimag(c)));
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

#define Fexcept_val(v) (* (fexcept_t *)(v))

static struct custom_operations fexcept_custom_ops = {
  .identifier  = "Posix_math.fexcept",
  .finalize    = custom_finalize_default,
  .compare     = custom_compare_default,
  .hash        = custom_hash_default,
  .serialize   = custom_serialize_default,
  .deserialize = custom_deserialize_default
};

static value caml_copy_fexcept(fexcept_t *e) {
  CAMLparam0();
  CAMLlocal1(v);
  v = caml_alloc_custom(&fexcept_custom_ops, sizeof(fexcept_t), 0, 1);
  memcpy(Data_custom_val(v), e, sizeof(fexcept_t));
  CAMLreturn(v);
}

#define Fenv_val(v) (* (fenv_t *)(v))

static struct custom_operations fenv_custom_ops = {
  .identifier  = "Posix_math.fenv",
  .finalize    = custom_finalize_default,
  .compare     = custom_compare_default,
  .hash        = custom_hash_default,
  .serialize   = custom_serialize_default,
  .deserialize = custom_deserialize_default
};

static value caml_copy_fenv(fenv_t *e) {
  CAMLparam0();
  CAMLlocal1(v);
  v = caml_alloc_custom(&fenv_custom_ops, sizeof(fenv_t), 0, 1);
  memcpy(Data_custom_val(v), e, sizeof(fenv_t));
  CAMLreturn(v);
}

static value error;

CAMLprim value fexcept_init(value unit) {
  CAMLparam1(unit);
  CAMLlocal1(flags);

  error = caml_hash_variant("Error");

  flags = caml_alloc(6, 0);

  Store_field(flags, 0, Val_int(FE_ALL_EXCEPT));
  Store_field(flags, 1, Val_int(FE_DIVBYZERO));
  Store_field(flags, 2, Val_int(FE_INEXACT));
  Store_field(flags, 3, Val_int(FE_INVALID));
  Store_field(flags, 4, Val_int(FE_OVERFLOW));
  Store_field(flags, 5, Val_int(FE_UNDERFLOW));

  CAMLreturn(flags);
}

CAMLprim value fenv_feclearexcept(value flags) {
  CAMLparam1(flags);
  CAMLlocal1(result);
  int rc;

  rc = feclearexcept(Int_val(flags));

  if (0 != rc) {
    goto ERROR;
  }

  result = caml_alloc(1, 0); // Result.Ok
  Store_field(result, 0, Val_unit);
  goto END;

ERROR:
  result = caml_alloc(1, 1); // Result.Error
  Store_field(result, 0, error); // `Error

END:
  CAMLreturn(result);
}


CAMLprim value fenv_feraiseexcept(value flags) {
  CAMLparam1(flags);
  CAMLlocal1(result);
  int rc;
  rc = feraiseexcept(Int_val(flags));
  CAMLreturn(Val_unit);
}

CAMLprim value fenv_fetestexcept(value flags) {
  CAMLparam1(flags);
  CAMLreturn(Val_unit);
}

CAMLprim value fenv_fegetexceptflag(value flags) {
  CAMLparam1(flags);
  CAMLlocal1(result);
  fexcept_t f;
  int rc, cflags;

  cflags = Int_val(flags);
  rc = fegetexceptflag(&f, cflags);

  if (0 != rc) {
    goto ERROR;
  }

  result = caml_alloc(1, 0); // Result.Ok
  Store_field(result, 0, caml_copy_fexcept(&f));
  goto END;

ERROR:
  result = caml_alloc(1, 1); // Result.Error
  Store_field(result, 0, error); // `Error

END:
  CAMLreturn(result);
}

CAMLprim value fenv_fesetexceptflag(value fex, value flags) {
  CAMLparam1(flags);
  CAMLlocal1(result);
  int rc, cflags;
  fexcept_t f;

  f = Fexcept_val(fex);
  cflags = Int_val(flags);
  rc = fesetexceptflag(&f, cflags);

  if (0 != rc) {
    goto ERROR;
  }

  result = caml_alloc(1, 0); // Result.Ok
  Store_field(result, 0, Val_unit);
  goto END;

ERROR:
  result = caml_alloc(1, 1); // Result.Error
  Store_field(result, 0, error); // `Error

END:
  CAMLreturn(result);
}

CAMLprim value fround_init(value unit) {
  CAMLparam1(unit);
  CAMLlocal1(flags);

  flags = caml_alloc(4, 0);
  Store_field(flags, 0, Val_int(FE_TONEAREST));
  Store_field(flags, 1, Val_int(FE_UPWARD));
  Store_field(flags, 2, Val_int(FE_DOWNWARD));
  Store_field(flags, 3, Val_int(FE_TOWARDZERO));

  CAMLreturn(flags);
}

CAMLprim value fenv_fesetround(value flags) {
  CAMLparam1(flags);
  CAMLlocal1(result);
  int rc;

  rc = fesetround(Int_val(flags));
  if (0 != rc) {
    goto ERROR;
  }

  result = caml_alloc(1, 0); // Result.Ok
  Store_field(result, 0, Val_unit);
  goto END;

ERROR:
  result = caml_alloc(1, 1); // Result.Error
  Store_field(result, 0, error); // `Error

END:
  CAMLreturn(result);
}

CAMLprim value fenv_fegetround(value unit) {
  CAMLparam1(unit);
  CAMLlocal1(result);
  int rc;
  rc = fegetround();

  if (0 > rc) {
    goto ERROR;
  }

  result = caml_alloc(1, 0); // Result.Ok
  Store_field(result, 0, Val_int(rc));
  goto END;

ERROR:
  result = caml_alloc(1, 1); // Result.Error
  Store_field(result, 0, error); // `Error

END:
  CAMLreturn(result);
}


CAMLprim value fenv_fegetenv(value unit) {
  CAMLparam1(unit);
  CAMLlocal1(result);
  fenv_t f;
  int rc;

  rc = fegetenv(&f);

  if (0 != rc) {
    goto ERROR;
  }

  result = caml_alloc(1, 0); // Result.Ok
  Store_field(result, 0, caml_copy_fenv(&f));
  goto END;

ERROR:
  result = caml_alloc(1, 1); // Result.Error
  Store_field(result, 0, error); // `Error

END:
  CAMLreturn(result);
}

CAMLprim value fenv_feholdexcept(value unit) {
  CAMLparam1(unit);
  CAMLlocal1(result);
  fenv_t f;
  int rc;

  rc = feholdexcept(&f);

  if (0 != rc) {
    goto ERROR;
  }

  result = caml_alloc(1, 0); // Result.Ok
  Store_field(result, 0, caml_copy_fenv(&f));
  goto END;

ERROR:
  result = caml_alloc(1, 1); // Result.Error
  Store_field(result, 0, error); // `Error

END:
  CAMLreturn(result);
}

CAMLprim value fenv_feupdateenv(value fenv) {
  CAMLparam1(fenv);
  CAMLlocal1(result);
  fenv_t f;
  int rc;

  f = Fenv_val(fenv);
  rc = feupdateenv(&f);

  if (0 != rc) {
    goto ERROR;
  }

  result = caml_alloc(1, 0); // Result.Ok
  Store_field(result, 0, Val_unit);
  goto END;

ERROR:
  result = caml_alloc(1, 1); // Result.Error
  Store_field(result, 0, error); // `Error

END:
  CAMLreturn(result);
}

CAMLprim value fenv_fesetenv(value fenv) {
  CAMLparam1(fenv);
  CAMLlocal1(result);
  fenv_t f;
  int rc;

  f = Fenv_val(fenv);
  rc = fesetenv(&f);

  if (0 != rc) {
    goto ERROR;
  }

  result = caml_alloc(1, 0); // Result.Ok
  Store_field(result, 0, Val_unit);
  goto END;

ERROR:
  result = caml_alloc(1, 1); // Result.Error
  Store_field(result, 0, error); // `Error

END:
  CAMLreturn(result);
}

// TODO end

