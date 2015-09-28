#ifndef POSIX_MATH_H
#define POSIX_MATH_H

#include <complex.h>
#include <caml/mlvalues.h>

#define Complex_val(v) ((double complex) (Double_field(v, 0) + I * Double_field(v, 0)))
CAMLextern value caml_copy_complex(double complex c);

#endif
