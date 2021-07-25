let list = [1; 2; 3; 4; 5]

let rec print_list l =

  match l with
  | [] -> Printf.printf "\n"
  | h::t -> Printf.printf "%d " h; print_list t

let () = print_list list

let rec list_length l =

  match l with
  |  [] -> 0
  | h::t -> 1 + list_length t

let rec list_length_tr l acc =

  match l with
  | [] -> acc
  | h::t -> list_length_tr t (acc + 1)

let () = Printf.printf "length: %d\n" (list_length list)
let () = Printf.printf "length: %d\n" (list_length_tr list 0)

let rec read_list_tr n acc = 
  if n >= 0 then read_list_tr (n-1) (read_int()::acc) else acc

let () = 

  let newList = read_list_tr 5 [] in print_list newList
