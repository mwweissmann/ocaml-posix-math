open Posix_math

let x, y = 11.5, 12.5

let _ =
  Printf.printf "%f -> %f\n" x (rint x); (* 12.0 *)
  assert((rint 11.5) = 12.0);
  Printf.printf "%f -> %f\n" y (rint y); (* 12.0 *)
  assert((rint 12.5) = 12.0);

  print_endline "done"

let _ =
  feclearexcept Fexcepts.fe_all_except;
  fesetround Fround.fe_downward;
  Printf.printf "%f\n" (1.0 /. 0.0);
  Printf.printf "%f -> %f\n" x (rint x); (* 11.0 *)
  assert((rint 11.5) = 11.0);
  Printf.printf "%f -> %f\n" y (rint y); (* 12.0 *)
  assert((rint 12.5) = 12.0);

  print_endline "done"

