#ifndef OCAML_POSIX_MATH_COMPLEX_H
#define OCAML_POSIX_MATH_COMPLEX_H

#include <complex.h>
#include <caml/mlvalues.h>

#define Complex_val(v) ((double complex) (Double_field(v, 0) + I * Double_field(v, 0)))
CAMLextern value caml_copy_complex(double complex c);

#endif

