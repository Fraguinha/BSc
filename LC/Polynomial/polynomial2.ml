let rec print_list l =

  match l with
  | [] -> Printf.printf "\n"
  | h::t -> Printf.printf "%.2f " h; print_list t

let rec read_polynomial n acc = 

  if n >= 0 then read_polynomial (n-1) (read_float()::acc) else acc

let rec horner li x acc =

  match li with
  | [] -> acc
  | el::li -> horner li x (x *. acc  +. el)

let () =

  let n = read_int () in
  let poly = read_polynomial n [] in
  let ans = horner poly 5. 0. in 

  print_endline (string_of_float(ans))