open Posix_math

let _ =
  let x, y = 11.5, 12.5 in
  Printf.printf "%f -> %f\n" x (rint x);
  Printf.printf "%f -> %f\n" y (rint y);

  print_endline "done"

