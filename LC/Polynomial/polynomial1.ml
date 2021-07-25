let rec print_list l =

  match l with
  | [] -> Printf.printf "\n"
  | h::t -> Printf.printf "%.2f " h; print_list t

let rec read_polynomial n acc = 

  if n >= 0 then read_polynomial (n-1) (read_float()::acc) else acc

let () = 

  let n = read_int () in
  let poly = read_polynomial n [] in print_list poly

let rec pretty_print l n =

  match l with
  | [] -> Printf.printf "\n"
  | [e] -> if e = 0. then Printf.printf "" else Printf.printf "%.2f " e; pretty_print [] (n-1)
  | h::t -> if h = 0. then Printf.printf "" 
    else 
    if n = 1 then Printf.printf "%.2fx " h
    else
      Printf.printf "%.2fx^%d + " h n; pretty_print t (n-1)

let () =

  let n = read_int () in
  let poly = read_polynomial n [] in pretty_print poly n
