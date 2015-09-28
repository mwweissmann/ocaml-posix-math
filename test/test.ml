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

let printi x =
  let open Complex in
  Printf.printf "%f + I * %f\n" x.re x.im

let _ =
  let c = Complex.( { re = 13.0;  im = 9.0; } ) in
  printi c;
  let c1 = csin c in
  printi c1;
  let d = creal c1 in
  let () = Printf.printf "%f\n" d in
  print_endline "done"
