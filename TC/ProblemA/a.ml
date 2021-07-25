(* Number of states *)
let (n:int) = Scanf.scanf " %d" (fun x -> x)

(* Cardinality of S *)
let (cardS:int) = Scanf.scanf " %d" (fun x -> x)

(* Initial states *)
let (is:(int * int) list) =
  let rec readInitialState lst (i:int) =
    if i = 0 then
      lst
    else
      let state = Scanf.scanf " %d" (fun x -> x) in
      let lst = lst@[(state, 0)] in
      readInitialState lst (i-1)
  in
  readInitialState [] cardS

(* Cardinality of F*)
let (cardF:int) = Scanf.scanf " %d" (fun x -> x)

(* Final states *)
let (fs:int list) =
  let rec readFinalState lst (i:int) =
    if i = 0 then
      lst
    else
      let s = Scanf.scanf " %d" (fun x-> x) in
      let lst = lst@[s] in
      readFinalState lst (i-1)
  in
  readFinalState [] cardF

(* Number of transitions *)
let (m:int) = Scanf.scanf " %d" (fun x -> x)

(* Transitions *)
let (t:(int * char * string * int * int * int) list) =
  let rec readTransitions lst (k:int) =
    if k = 0 then
      lst
    else
      let i  = Scanf.scanf " %d" (fun x -> x) in
      let c  = Scanf.scanf " %c" (fun x -> x) in
      let op = Scanf.scanf " %s" (fun x -> x) in
      let a  = Scanf.scanf " %c" (fun x -> x) in
      let a = if a = '_' then (-1) else (int_of_char a - 48) in
      let b  = Scanf.scanf " %c" (fun x -> x) in
      let b = if b = '_' then (-1) else (int_of_char b - 48) in
      let j  = Scanf.scanf " %d" (fun x -> x) in
      let transition   = (i, c, op, a, b, j) in
      let lst = lst@[transition] in
      readTransitions lst (k-1)
  in
  readTransitions [] m

(* Word *)
let (w:string) = Scanf.scanf " %s" (fun x -> x)

(* This function checks if any of the states is a final state *)
let rec checkState state finalState =
  match state with
  | [] -> false
  | (s, _)::tl ->
    if List.mem s finalState then
      true
    else
      checkState tl finalState

(* This function converts the variables and operation into a boolean expression *)
let operation x op a =
  match op with
  | "_" -> true
  | "<" -> x < a
  | "<=" -> x <= a
  | "=" -> x = a
  | "!=" -> x <> a
  | ">=" -> x >= a
  | ">" -> x > a
  | _ -> false

(* This function follows current state's e's *)
let rec followE state newState transitions =
  match state with
  | [] -> newState
  | (s, x)::stl ->
    let newState =
      if not (List.mem (s, x) newState) then
        newState@[(s, x)]
      else
        newState
    in
    let rec followETransitions newState transitions =
      match transitions with
      | [] -> newState
      | (i, c, op, a, b, j)::ttl ->
        let newState =
          if c = '_' && s = i then
            if b = (-1) then
              if not (List.mem (j, x) newState) then
                newState@[(j, x)]
              else
                newState
            else
            if not (List.mem (j, b) newState) then
              newState@[(j, b)]
            else
              newState
          else
            newState
        in
        followETransitions newState ttl
    in
    let newState = followETransitions newState transitions in
    followE stl newState transitions

(* This function follows all e's possible *)
let rec followAllE state lastState transitions =
  let state = followE state [] transitions in
  if state <> lastState then
    let lastState = state in
    followAllE state lastState transitions
  else
    state

(* This function follows the letter when allowed by the guard, and updates accordingly *)
let rec consumeL l state newState transitions =
  match state with
  | [] -> newState
  | (s, x)::stl ->
    let rec followLTransitions newState transitions =
      match transitions with
      | [] -> newState
      | (i, c, op, a, b, j)::ttl ->
        let newState =
          if c = l && s = i && operation x op a then
            if b = (-1) then
              newState@[(j, x)]
            else
              newState@[(j, b)]
          else newState
        in
        followLTransitions newState ttl
    in
    let newState = followLTransitions newState transitions in
    consumeL l stl newState transitions

(* This function checks if the word is recognized *)
let rec solution w state finalState transitions =
  if w = "" || state = [] then
    let state = followAllE state state transitions in
    checkState state finalState
  else
    let l = String.get w 0 in
    let state = followAllE state state transitions in
    let state = consumeL l state [] transitions in
    let w = (String.sub w 1 ((String.length w) - 1)) in
    solution w state finalState transitions

(* Get answer *)
let () =
  if solution w is fs t then
    Printf.printf "YES\n"
  else
    Printf.printf "NO\n"
