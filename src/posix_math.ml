type complex = Complex.t

external math_init : unit -> float * float * float * float * float * float *float * float * float * float * float * float * float = "math_init"
let m_e,
  m_log2e,
  m_log10e,
  m_ln2,
  m_ln10,
  m_pi,
  m_pi_2,
  m_pi_4,
  m_1_pi,
  m_2_pi,
  m_2_sqrtpi,
  m_sqrt2,
  m_sqrt1_2 = math_init ()

let acos = Pervasives.acos
external acosh : float -> float = "math_acosh"
let asin = Pervasives.asin
external asinh : float -> float = "math_asinh"
let atan = Pervasives.atan
let atan2 = Pervasives.atan2
external atanh : float -> float = "math_atanh"
external cabs : complex -> float = "math_cabs"
external cacos : complex -> complex = "math_cacos"
external cacosh : complex -> complex = "math_cacosh"
let carg = Complex.arg
external casin : complex -> complex = "math_casin"
external casinh : complex -> complex = "math_casinh"
external catan : complex -> complex = "math_catan"
external catanh : complex -> complex = "math_catanh"
external cbrt : float -> float = "math_cbrt"
external ccos : complex -> complex = "math_ccos"
external ccosh : complex -> complex = "math_ccosh"
external ceil : float -> float = "math_ceil"
let cexp = Complex.exp
let cimag x = Complex.(x.im)
let clog = Complex.log
let conj = Complex.conj
let copysign = Pervasives.copysign
let cos = Pervasives.cos
external cosh : float -> float = "math_cosh"
let cpow = Complex.pow
external cproj : complex -> complex = "math_cproj"
let creal x = Complex.(x.re)
external csin : complex -> complex = "math_csin"
external csinh : complex -> complex = "math_csinh"
let csqrt = Complex.sqrt
external ctan : complex -> complex = "math_ctan"
external ctanh : complex -> complex = "math_ctanh"
let exp = Pervasives.exp
external hypot : float -> float -> float = "math_hypot"
let ldexp = Pervasives.ldexp
external lgamma : float -> float = "math_lgamma"
external llrint : float -> int64 = "math_llrint"
external llround : float -> int64 = "math_llround"
let log = Pervasives.log
let log10 = Pervasives.log10
let log1p = Pervasives.log1p
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
let sin = Pervasives.sin
let sinh = Pervasives.sinh
let sqrt = Pervasives.sqrt
let tan = Pervasives.tan
external tanh : float -> float = "math_tanh"
external tgamma : float -> float = "math_tgamma"
external trunc : float -> float = "math_trunc"

external fexcept_init : unit -> (int * int * int * int * int * int) = "fexcept_init"
module Fexcepts = struct
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
external feclearexcept : Fexcepts.t -> (unit, [>`Error]) Result.result = "fenv_feclearexcept"
external feraiseexcept : Fexcepts.t -> (unit, [>`Error]) Result.result = "fenv_feraiseexcept"
external fetestexcept : Fexcepts.t -> (Fexcepts.t, [>`Error]) Result.result = "fenv_fetestexcept"

module Fexcept = struct
  type t
end
external fesetexceptflag : Fexcept.t -> Fexcepts.t -> (unit, [>`Error]) Result.result = "fenv_fesetexceptflag"
external fegetexceptflag : Fexcepts.t -> (Fexcept.t, [>`Error]) Result.result = "fenv_fegetexceptflag"

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

