type complex

external acos : float -> float = "math_acos"
external acosh : float -> float = "math_acosh"
external asin : float -> float = "math_asin"
external asinh : float -> float = "math_asinh"
external atan : float -> float = "math_atan"
external atan2 : float -> float -> float = "math_atan2"
external atanh : float -> float = "math_atanh"
external cabs : complex -> float = "math_cabs"
external cacos : complex -> complex = "math_cacos"
external cacosh : complex -> complex = "math_cacosh"
external carg : complex -> float = "math_carg"
external casin : complex -> complex = "math_casin"
external casinh : complex -> complex = "math_casinh"
external catan : complex -> complex = "math_catan"
external catanh : complex -> complex = "math_catanh"
external cbrt : float -> float = "math_cbrt"
external ccos : complex -> complex = "math_ccos"
external ccosh : complex -> complex = "math_ccosh"
external ceil : float -> float = "math_ceil"
external cexp : complex -> complex = "math_cexp"
external cimag : complex -> float = "math_cimag"
external clog : complex -> complex = "math_clog"
external conj : complex -> complex = "math_conj"
external copysign : float -> float -> float = "math_copysign"
external cos : float -> float = "math_cos"
external cosh : float -> float = "math_cosh"
external cpow : complex -> complex -> complex = "math_cpow"
external cproj : complex -> complex = "math_cproj"
external creal : complex -> float = "math_creal"
external csin : complex -> complex = "math_csin"
external csinh : complex -> complex = "math_csinh"
external csqrt : complex -> complex = "math_csqrt"
external ctan : complex -> complex = "math_ctan"
external ctanh : complex -> complex = "math_ctanh"
external ldexp : float -> int -> float = "math_ldexp"
external lgamma : float -> float = "math_lgamma"
external llrint : float -> int64 = "math_llrint"
external llround : float -> int64 = "math_llround"
external log : float -> float = "math_log"
external log10 : float -> float = "math_log10"
external log1p : float -> float = "math_log1p"
external log2 : float -> float = "math_log2"
external logb : float -> float = "math_logb"
external lrint : float -> int32 = "math_lrint"
external lround : float -> int32 = "math_lround"
external modf : float -> float * float = "math_modf"
external nearbyint : float -> float = "math_nearbyint"
external nextafter : float -> float -> float = "math_nextafter"
external nexttoward : float -> float -> float = "math_nexttoward"
external pow : float -> float -> float = "math_pow"
external remainder : float -> float -> float = "math_remainder"
external remquo : float -> float -> float * int = "math_remquo"

external rint : float -> float = "math_rint"
external round : float -> float = "math_round"
external scalbln : float -> int64 -> float = "math_scalbln"
external scalbn : float -> int -> float = "math_scalbn"
external signbit : float -> int = "math_signbit"
external sin : float -> float = "math_sin"
external sinh : float -> float = "math_sinh"
external sqrt : float -> float = "math_sqrt"
external tan : float -> float = "math_tan"
external tanh : float -> float = "math_tanh"
external tgamma : float -> float = "math_tgamma"
external trunc : float -> float = "math_trunc"

external fexcept_init : unit -> (int * int * int * int * int * int) = "fexcept_init"
module Fexcept = struct
  type t = int

  let (
    fe_all_except,
    fe_divbyzero,
    fe_inexact,
    fe_invalid,
    fe_overflow,
    fe_underflow
  ) = fexcept_init ()

  let union a b = a lor b
end
external feclearexcept : Fexcept.t -> unit = "fenv_feclearexcept"
external fegetexceptflag : Fexcept.t -> Fexcept.t = "fenv_fegetexceptflag"
external feraiseexcept : Fexcept.t -> unit = "fenv_feraiseexcept"
external fetestexcept : Fexcept.t -> Fexcept.t = "fenv_fetestexcept"
external fesetexceptflag : Fexcept.t -> unit = "fenv_fesetexceptflag"

external fround_init : unit -> int * int * int * int = "fround_init"
module Fround = struct
  type t = int
  let (
    fe_tonearest,
    fe_upward,
    fe_downward,
    fe_towardzero
  ) = fround_init ()
end
external fesetround : Fround.t -> (unit, [>`Error]) Result.result = "fenv_fesetround"
external fegetround : unit -> (Fround.t, [>`Error]) Result.result = "fenv_fegetround"

module Fenv = struct
  type t
end
external fegetenv : unit -> (Fenv.t, [>`Error]) Result.result = "fenv_fegetenv"
external fesetenv : Fenv.t -> (unit, [>`Error]) Result.result = "fenv_fesetenv"
external feupdateenv : Fenv.t -> (unit, [>`Error]) Result.result = "fenv_feupdateenv"
external feholdexcept : unit -> (Fenv.t, [>`Error]) Result.result = "fenv_feholdexcept"

