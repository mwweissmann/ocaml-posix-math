#ifndef OCAML_POSIX_MATH_FENV_H
#define OCAML_POSIX_MATH_FENV_H

#include <fenv.h>
#include <caml/mlvalues.h>

#define Fexcept_val(v) ((fexcept_t *)(Data_custom_val(v)))
CAMLextern value caml_copy_fexcept(fexcept_t *e);

#define Fenv_val(v) ((fenv_t *)(Data_custom_val(v)))
CAMLextern value caml_copy_fenv(fenv_t *e);

#endif

