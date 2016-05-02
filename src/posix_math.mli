(*
Copyright (c) 2015 Markus W. Weissmann <markus.weissmann@in.tum.de>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*)

(** POSIX math

  @author Markus W. Weissmann
*)

(** A comlex number as defined in the standard library *)
type complex = Complex.t

(** [acos x] calculates the arc cosine of x; in principle [cos (acos x) = x] holds but for floating point rounding errors. *)
val acos : float -> float

(** [acosh x] computes the hyperbolic cosine of x;  in principle [cosh (acosh x) = x] holds but for floating point rounding errors. *)
val acosh : float -> float

(** [asin x] computes the arc sine os x; in principle [sin (asin x) = x] holds but for floating point rounding errors. *)
val asin : float -> float

(** [asinh x] computes the inverse hyperbolic sine of x; in principle [sinh (asinh x) = x] holds but for floating point rounding errors. *)
val asinh : float -> float

(** [atan x] computes the arc tangent of x; in principle [tan (atan x) = x] holds but for floating point rounding errors. *)
val atan : float -> float

(** [atan2 x y] computes the arc tangent of [y ./ x] in radians. *)
val atan2 : float -> float -> float

(** [atanh x] computes the inverse hyperbolic tangent of x; in principle [tanh (atanh x) = x] holds but for floating point rounding errors. *)
val atanh : float -> float

(** [cabs z] returns the absolute value of the complex number [z]. *)
val cabs : complex -> float

(** [cacos z] calculates  the complex arc cosine of [z]. If [y = cacos z] then [z = ccos y] holds. *)
val cacos : complex -> complex

(** [cacosh z] calculates the complex arc hyperbolic cosine of [z]. *)
val cacosh : complex -> complex

(** [carg z] computes the radius of the number [z] in polar coordinates. In principle [tan (carg z) = cimag z ./ creal z] holds but for floating point rounding errors. *)
val carg : complex -> float

(** [casin z] computes the complex arc sine of [z]. *)
val casin : complex -> complex

(** [casinh z] computes the complex arc hyperbolic sine of z. If [y = casinh z] then [z = csinh y]. *)
val casinh : complex -> complex

(** [catan z] computes the  complex  arc  tangent  of  z. If [y = catan z] then [z = ctan z]. *)
val catan : complex -> complex

(** [catanh z] computes the complex arc hyperbolic tangent of z. If [y = catanh z] then [z = ctanh y]. *)
val catanh : complex -> complex

(** [cbrt x] computes the (real) cube root of [x]. *)
val cbrt : float -> float

(** [ccos z] computes the complex cosine of [z]. *)
val ccos : complex -> complex

(** [ccosh z] computes the complex hyperbolic cosine of [z]. *)
val ccosh : complex -> complex

(** [ceil x] computes the smallest integral value not less than [x]. *)
val ceil : float -> float

(** [cexp z] computes the complex exponent of [z], defined as e^z. *)
val cexp : complex -> complex

(** [cimag z] computes the imaginary part of [z]. *)
val cimag : complex -> float

(** [clog z] computes the complex natural (base e) logarithm of [z], with a branch cut along the negative real axis. *)
val clog : complex -> complex

(** [conj z] computes the complex conjugate of [z], by reversing the sign of its imaginary part. *)
val conj : complex -> complex

(** [copysign x y] computes a value with the magnitude of [x] and the sign of [y]. On implementations that represent a signed zero but do not treat negative zero consistently in arithmetic operations, these functions regard the sign of zero as positive. *)
val copysign : float -> float -> float

(** [cos x] computes the cosine of [x], measured in radians. *)
val cos : float -> float

(** [cosh] computes the hyperbolic cosine of [x]. *)
val cosh : float -> float

(** [cpow x y] computes the complex power function x^y, with a branch cut for the first parameter along the negative real axis. *)
val cpow : complex -> complex -> complex

(** [cproj z] computes a projection of [z] onto the Riemann sphere. *)
val cproj : complex -> complex

(** [creal z] computes the real part of [z]. *)
val creal : complex -> float

(** [csin z] computes the complex sine of [z]. *)
val csin : complex -> complex

(** [csinh z] computes the complex hyperbolic sine of [z]. *)
val csinh : complex -> complex

(** [csqrt z] computes the complex square root of [z], with a branch cut along the negative real axis. *)
val csqrt : complex -> complex

(** [ctan z] compute the complex tangent of [z]. *)
val ctan : complex -> complex

(** [ctanh z] computes the complex hyperbolic tangent of [z]. *)
val ctanh : complex -> complex

(** [exp x] computes the base-e exponential of [x]. *)
val exp : float -> float

(** [ldexp x i] computes the quantity [x .* 2 ^ exp]. *)
val ldexp : float -> int -> float

(** [lgamma x] returns the natural logarithm of the absolute value of the Gamma function. *)
val lgamma : float -> float

(** [llrint x] rounds it's argument to the nearest integer value, rounding according to the current rounding direction. *)
val llrint : float -> int64

(** [llround x] rounds it's argument to the nearest integer value, rounding halfway cases away from zero, regardless of the current rounding direction. *)
val llround : float -> int64

(** [log x] computes the natural logarithm of their argument [x]. *)
val log : float -> float

(** [log10 x] computes the base 10 logarithm of their argument [x]. *)
val log10 : float -> float

(** [log1p x] returns a value equivalent to [log (1 + x)]. *)
val log1p : float -> float

(** [log2 x] computes the base 2 logarithm of their argument [x]. *)
val log2 : float -> float

(** [logb x] extracts the exponent from the internal floating-point representation of [x] and return it as a floating-point value. *)
val logb : float -> float

(** [lrint x] rounds it's argument to the nearest integer value, rounding according to the current rounding direction. *)
val lrint : float -> int32

(** [lround x] rounds it's argument to the nearest integer value, rounding halfway cases away from zero, regardless of the current rounding direction. *)
val lround : float -> int32

(** [modf x] break the argument [x] into integral and fractional parts, each of which has the same sign as the argument. *)
val modf : float -> float * float

(** [nearbyint x] rounds it's argument to an integer value in floating-point format, using the current rounding direction and without raising the inexact floating-point exception. *)
val nearbyint : float -> float

(** [nextafter x y] computes the next representable floating-point value following x in the direction of y. *)
val nextafter : float -> float -> float
val nexttoward : float -> float -> float

(** [pow x y] computes the value of [x] raised to the power [y]. If x is negative, the application shall ensure that y is an integer value. *)
val pow : float -> float -> float

(** [remainder x y] computes the remainder of dividing [x] by [y]. The return value is [x .- n .* y], where [n] is the value [x ./ y], rounded to the nearest integer. If the absolute value of [x .- n .* y] is [0.5], [n] is chosen to be even. *)
val remainder : float -> float -> float

(** [remquo x y] *)
val remquo : float -> float -> float * int 
val rint : float -> float
val round : float -> float
val scalbln : float -> int64 -> float
val scalbn : float -> int -> float
val signbit : float -> int
val sin : float -> float
val sinh : float -> float
val sqrt : float -> float
val tan : float -> float
val tanh : float -> float
val tgamma : float -> float
val trunc : float -> float

(*
val isfinite : float -> bool
val isgreater : float -> float -> bool
val isgreaterequal : float -> float -> bool
val isinf : float -> bool
val isless : float -> float -> bool
val islessequal : float -> float -> bool
val islessgreater : float -> float -> bool
val isnan : float -> bool
val isnormal : float -> bool
val isunordered : float -> bool
val nan : string -> float

*)

module Fexcepts : sig
  type t
  val fe_all_except : t
  val fe_divbyzero : t
  val fe_inexact : t
  val fe_invalid : t
  val fe_overflow : t
  val fe_underflow : t

  val union : t -> t -> t
end
val feclearexcept : Fexcepts.t -> (unit, [>`Error]) Result.result
val feraiseexcept : Fexcepts.t -> (unit, [>`Error]) Result.result
val fetestexcept : Fexcepts.t -> (Fexcepts.t, [>`Error]) Result.result

module Fexcept : sig
  type t
end
val fesetexceptflag : Fexcept.t -> Fexcepts.t -> (unit, [>`Error]) Result.result
val fegetexceptflag : Fexcepts.t -> (Fexcept.t, [>`Error]) Result.result

module Fenv : sig
  type t
end
val fegetenv : unit -> (Fenv.t, [>`Error]) Result.result
val fesetenv : Fenv.t -> (unit, [>`Error]) Result.result
val feupdateenv : Fenv.t -> (unit, [>`Error]) Result.result
val feholdexcept : unit -> (Fenv.t, [>`Error]) Result.result

module Fround : sig
  type t
  val fe_tonearest : t
  val fe_upward : t
  val fe_downward : t
  val fe_towardzero : t
end
val fesetround : Fround.t -> (unit, [>`Error]) Result.result
val fegetround : unit -> (Fround.t, [>`Error]) Result.result

