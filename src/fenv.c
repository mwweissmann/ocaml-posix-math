#include <assert.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>
#include <time.h>
#include <math.h>
#include <fenv.h>

#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h> 
#include <caml/threads.h> 
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/unixsupport.h>
#include <caml/custom.h>

#include "ocaml-posix-math-fenv.h"

static struct custom_operations fexcept_custom_ops = {
  .identifier  = "Posix_math.fexcept",
  .finalize    = custom_finalize_default,
  .compare     = custom_compare_default,
  .hash        = custom_hash_default,
  .serialize   = custom_serialize_default,
  .deserialize = custom_deserialize_default
};

CAMLprim value caml_copy_fexcept(fexcept_t *e) {
  CAMLparam0();
  CAMLlocal1(v);
  v = caml_alloc_custom(&fexcept_custom_ops, sizeof(fexcept_t), 0, 1);
  memcpy(Data_custom_val(v), e, sizeof(fexcept_t));
  CAMLreturn(v);
}

static struct custom_operations fenv_custom_ops = {
  .identifier  = "Posix_math.fenv",
  .finalize    = custom_finalize_default,
  .compare     = custom_compare_default,
  .hash        = custom_hash_default,
  .serialize   = custom_serialize_default,
  .deserialize = custom_deserialize_default
};

CAMLprim value caml_copy_fenv(fenv_t *e) {
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

CAMLprim value fenv_fetestexcept(value flags) {
  CAMLparam1(flags);
  CAMLlocal1(result);
  int rc;

  rc = fetestexcept(Int_val(flags));

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
  fexcept_t *f;

  f = Fexcept_val(fex);
  cflags = Int_val(flags);
  rc = fesetexceptflag(f, cflags);

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
  fenv_t *f;
  int rc;

  f = Fenv_val(fenv);
  rc = feupdateenv(f);

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
  fenv_t *f;
  int rc;

  f = Fenv_val(fenv);
  rc = fesetenv(f);

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

