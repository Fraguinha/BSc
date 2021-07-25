(* Number of states *)
let (n:int) = Scanf.scanf " %d" (fun x -> x)

(* Initial state *)
let (s:int) = Scanf.scanf " %d" (fun x -> x)

(* Cardinality of F *)
let (nf:int) = Scanf.scanf " %d" (fun x -> x)

(* Final states *)
let (f:int list) =
  let rec readFinalState (lst:int list) (i:int) =
    if i = 0 then
      lst
    else
      let s = Scanf.scanf " %d" (fun x-> x) in
      let lst = lst @ [s] in
      readFinalState lst (i-1)
  in
  readFinalState [] nf

(* Number of transitions *)
let (m:int) = Scanf.scanf " %d" (fun x -> x)

(* Transitions *)
let (t:(int * char * int) list) =
  let rec readTransitions (lst:(int * char * int) list) (k:int) =
    if k = 0 then
      lst
    else
      let i  = Scanf.scanf " %d" (fun x -> x) in
      let c  = Scanf.scanf " %c" (fun x -> x) in
      let j  = Scanf.scanf " %d" (fun x -> x) in
      let transition   = (i, c, j) in
      let lst = lst @ [transition] in
      readTransitions lst (k-1)
  in
  readTransitions [] m

(* Print list *)
let rec print_list lst =
  match lst with
  | [] -> Printf.printf "\n"
  | [el] ->
    let () = Printf.printf "%d" el in
    print_list []
  | el :: tl ->
    let () = Printf.printf "%d " el in
    print_list tl

(* Print transitions *)
let rec print_transitions t =
  match t with
  | [] -> ()
  | (i, c, j) :: tl ->
    let () = Printf.printf "%d %c %d\n" i c j in
    print_transitions tl

(* Print automaton *)
let print_automaton n s nf f m t =
  let () = Printf.printf "%d\n" n in
  let () = Printf.printf "%d\n" s in
  let () = Printf.printf "%d\n" nf in
  let () = print_list f in
  let () = Printf.printf "%d\n" m in
  let () = print_transitions t in
  ()

(* Alphabet *)
let (a:char list) =
  let rec readAlphabet (alphabet:char list) (transitions:(int * char * int) list) =
    match transitions with
    | [] -> alphabet
    | (_, c, _) :: ttl ->
      let alphabet =
        if not (List.mem c alphabet) then
          alphabet @ [c]
        else
          alphabet
      in
      readAlphabet alphabet ttl
  in
  readAlphabet [] t

(* Matrix to fill *)
let matrix = Array.make_matrix (n + 1) (n + 1) (-1)
let () =
  for i = 1 to n do
    for j = 1 to n do
      if i > j then
        matrix.(i).(j) <- 0
    done
  done

(* First step *)
let () =
  for i = 1 to n do
    for j = 1 to n do
      if i > j then
        if List.mem i f && not (List.mem j f) || not (List.mem i f) && List.mem j f then
          matrix.(i).(j) <- 1
    done
  done

(* Secound step *)
let () =
  let flag = ref 1 in
  while !flag = 1 do
    let () = flag := 0 in
    for i = 1 to n do
      for j = 1 to n do
        if i > j && matrix.(i).(j) = 0 then
          for k = 0 to (List.length a) - 1 do
            let (_, _, x) = List.hd (List.filter (fun (src, c, dst) -> if src = i && c = (List.nth a k) then true else false) t) in
            let (_, _, y) = List.hd (List.filter (fun (src, c, dst) -> if src = j && c = (List.nth a k) then true else false) t) in
            if matrix.(x).(y) = 1 || matrix.(y).(x) = 1 then
              let () = flag := 1 in
              matrix.(i).(j) <- 1
          done
      done
    done
  done

(* Empty cells *)
let (empty:(int list) list) =
  let rec getEmpty n i j matrix lst =
    if i > n then
      lst
    else if j > n then
      getEmpty n (i+1) 0 matrix lst
    else if matrix.(i).(j) = 0 then
      let lst = lst @ [[i; j]] in
      getEmpty n i (j+1) matrix lst
    else
      getEmpty n i (j+1) matrix lst
  in
  getEmpty n 0 0 matrix []

(* Make Partitions *)
let (partitions:(int list) list) =
  let rec getPartitions lst partitions =
    match lst with
    | [] -> partitions
    | el :: ttl ->
      let atleastOne = List.filter (fun x -> if List.mem (List.nth el 0) x || List.mem (List.nth el 1) x then true else false) ttl in
      let newElement = [] in
      let newElement = addFromList el newElement in
      let newElement = addFromListList atleastOne newElement in
      let ttl = List.filter (fun x -> checkElement newElement x) ttl in
      let partitions = partitions @ [newElement] in
      getPartitions ttl partitions
  and checkElement newElement x =
    match x with
    | [] -> true
    | el :: tl -> if List.mem el newElement then false else checkElement newElement tl
  and addFromList lst newElement =
    match lst with
    | [] -> newElement
    | el :: ttl -> if not (List.mem el newElement) then addFromList ttl (newElement @ [el]) else addFromList ttl newElement
  and addFromListList lst newElement =
    match lst with
    | [] -> newElement
    | el :: ttl ->
      let newElement = addFromList el newElement in
      addFromListList ttl newElement
  in
  let partitions = getPartitions empty [] in
  let rec getMissing n partitions =
    if n > 0 then
      let test = List.filter (fun x -> if (List.mem n x) then true else false) partitions in
      let partitions = if test = [] then partitions @ [[n]] else partitions in
      getMissing (n - 1) partitions
    else
      partitions
  in
  getMissing n partitions

(* Minimal Automaton *)
let (number:int) = List.length partitions

let (start:int) =
  let rec getStart n partitions =
    if n >= 1 then
      if List.mem s (List.nth partitions (n - 1)) then n else getStart (n - 1) partitions
    else
      0
  in
  getStart number partitions

let (final:int list) =
  let rec getFinal n m i partitions lst =
    if n >= 1 then
      if i >= 1 then
        if List.mem i f && List.mem i (List.nth partitions (n - 1)) then
          let lst =
            if not (List.mem n lst) then
              [n] @ lst
            else lst
          in
          getFinal n m (i - 1) partitions lst
        else
          getFinal n m (i - 1) partitions lst
      else
        getFinal (n - 1) m m partitions lst
    else
      lst
  in
  getFinal number n n partitions []

let (numberFinal:int) = List.length final

let (transitions:(int * char * int) list) =
  let rec getTransitions i n a partitions lst =
    if i <= n then
      let state = List.hd (List.nth partitions (i-1)) in
      let transitions = List.filter (fun (x, _, _) -> if x = state then true else false) t in
      let lst = createTransitions i n a partitions transitions lst in
      getTransitions (i+1) n a partitions lst
    else
      lst
  and createTransitions i n a partitions transitions lst =
    match transitions with
    | [] -> lst
    | (src, c, dst) :: ttl ->
      let j = findDestination dst 1 partitions in
      let lst = lst @ [(i, c, j)] in
      createTransitions i n a partitions ttl lst
  and findDestination dst n partitions =
    match partitions with
    | [] -> 0
    | el :: ttl ->
      if (List.mem dst el) then n else findDestination dst (n + 1) ttl
  in
  getTransitions 1 number a partitions []

let (numberTransitions:int) = (List.length a) * number

(* Print Solution *)
let () = print_automaton number start numberFinal final numberTransitions transitions
