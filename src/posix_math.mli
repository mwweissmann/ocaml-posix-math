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

type complex

val acos : float -> float
val acosh : float -> float
val asin : float -> float
val asinh : float -> float
val atan : float -> float
val atan2 : float -> float -> float
val atanh : float -> float
val cabs : complex -> float
val cacos : complex -> complex
val cacosh : complex -> complex
val carg : complex -> float
val casin : complex -> complex
val casinh : complex -> complex
val catan : complex -> complex
val catanh : complex -> complex
val cbrt : float -> float
val ccos : complex -> complex
val ccosh : complex -> complex
val ceil : float -> float
val cexp : complex -> complex
val cimag : complex -> float
val clog : complex -> complex
val conj : complex -> complex
val copysign : float -> float -> float
val cos : float -> float
val cosh : float -> float
val cpow : complex -> complex -> complex
val cproj : complex -> complex
val creal : complex -> float
val csin : complex -> complex
val csinh : complex -> complex
val csqrt : complex -> complex
val ctan : complex -> complex
val ctanh : complex -> complex
val ldexp : float -> int -> float
val lgamma : float -> float
val llrint : float -> int64
val llround : float -> int64
val log : float -> float
val log10 : float -> float
val log1p : float -> float
val log2 : float -> float
val logb : float -> float
val lrint : float -> int32
val lround : float -> int32
val modf : float -> float * float
val nearbyint : float -> float
val nextafter : float -> float -> float
val nexttoward : float -> float -> float
val pow : float -> float -> float
val remainder : float -> float -> float
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

