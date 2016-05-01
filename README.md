# POSIX math

This library provides access to the [POSIX math functions](http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/math.h.html), including complex numbers.
posix-math links to the standard C-library or whatever provides the POSIX math library libm on your system. Calls to the OCaml functions then are handed over to your systems math library and returned to OCaml.

```ocaml
open Posix_math

let _ =
  Printf.printf "%f\n" (acosh 47.0)
```

To avoid shadowing functions from other libraries, it is a good idea to open the module only where required.

```ocaml
let _ =
  let z = Complex.zero in
  Printf.printf "%f\n" Posix_math.(cabs z)
```

The full interface is available in the [API documentation](http://mwweissmann.github.io/ocaml-posix-math/).

The source code of time is available under the MIT license.

This library is originally written by [Markus Weissmann](http://www.mweissmann.de/)
