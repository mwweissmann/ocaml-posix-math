#ifndef POSIX_MATH_H
#define POSIX_MATH_H

#include <complex.h>
#include <fenv.h>
#include <caml/mlvalues.h>

#define Complex_val(v) ((double complex) (Double_field(v, 0) + I * Double_field(v, 0)))
CAMLextern value caml_copy_complex(double complex c);

#define Fexcept_val(v) (* (fexcept_t *)(v))
CAMLextern value caml_copy_fexcept(fexcept_t *e);

#define Fenv_val(v) (* (fenv_t *)(v))
CAMLextern value caml_copy_fenv(fenv_t *e);

#endif

