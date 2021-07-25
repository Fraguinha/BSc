let rec matrixIsFull n matrix i j =

  if i = n then

    true

  else if j = n then

    matrixIsFull n matrix (i+1) 0

  else if matrix.(i).(j) = 0 then

    false

  else matrixIsFull n matrix i (j+1)


let validPosition n i j =

  i >= 0 && i < n && j >= 0 && j < n


let positionAvailable n matrix i j = 

  validPosition n i j && matrix.(i).(j) = 0


let numberPossibleJumps n matrix i j =

  let deltaX = [|1; 1; 2; 2; -1; -1; -2; -2|] in
  let deltaY = [|2; -2; 1; -1; 2; -2; 1; -1|] in

  let num = ref 0 in

  let () =

    if (positionAvailable n matrix i j = false) then

      num := 10

    else

      for a = 0 to 7 do

        if (positionAvailable n matrix (i + deltaX.(a)) (j + deltaY.(a))) then

          num := !num + 1

      done

  in

  !num


let sortJumps n matrix i j deltaX deltaY =

  let min = ref 0 in
  let temp = ref 0 in

  for a = 0 to 7 do

    min := numberPossibleJumps n matrix (i + deltaX.(a)) (j + deltaY.(a));

    for b = (a + 1) to 7 do

      temp := numberPossibleJumps n matrix (i + deltaX.(b)) (j + deltaY.(b));

      if (temp < min) then

        let () = 

          min := !temp;

          temp := deltaX.(a);
          deltaX.(a) <- deltaX.(b);
          deltaX.(b) <- !temp;

          temp := deltaY.(a);
          deltaY.(a) <- deltaY.(b);
          deltaY.(b) <- !temp; 

        in ()

    done

  done


let rec backtrack n matrix i j =

  let rec _for n matrix i j deltaX deltaY ans count = 

    if count < 8 && ans = false then

      if backtrack n matrix (i + deltaX.(count)) (j + deltaY.(count)) then

        true

      else 

        _for n matrix i j deltaX deltaY ans (count+1)

    else

      ans

  in

  if positionAvailable n matrix i j then

    let deltaX = [|1; 1; 2; 2; -1; -1; -2; -2|] in
    let deltaY = [|2; -2; 1; -1; 2; -2; 1; -1|] in

    let () = sortJumps n matrix i j deltaX deltaY in

    let () = matrix.(i).(j) <- 1 in

    if matrixIsFull n matrix 0 0 then

      true

    else

      let ans = _for n matrix i j deltaX deltaY false 0 in

      let () = 

        matrix.(i).(j) <- 0

      in

      ans

  else

    false


let () = 

  (* Reading input *)

  let n = Scanf.scanf " %d" (fun x -> x) in 

  let matrix = Array.make_matrix n n 0 in 

  let (i, j) = Scanf.scanf " %d %d" (fun x y -> x, y) in

  let k = Scanf.scanf " %d" (fun x -> x) in 

  let x = ref 0 in
  let y = ref 0 in

  let () =

    for a = 1 to k do

      x := Scanf.scanf " %d" (fun x -> x);
      y := Scanf.scanf " %d" (fun x -> x);
      matrix.(!x).(!y) <- -1

    done

  in

  (* --- *)

  if(backtrack n matrix i j) then

    Printf.printf "YES\n"

  else

    Printf.printf "NO\n"