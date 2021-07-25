let rec comb n k memo =

  let m = memo.(n).(k) in

  if m <> -1

  then m

  else

    let ans = if (n = k || k = 0) then 1 else comb (n - 1) (k - 1) memo + comb (n - 1) k memo in
    let () = memo.(n).(k) <- ans in

    ans

let () =

  let (n, k) = Scanf.scanf "%d %d" (fun x y -> x, y) in

  let memo = Array.make_matrix (n + 1) (k + 1) (-1) in

  let answer = (comb n k memo * comb n (k - 1) memo) / n in

  print_endline (string_of_int (answer))
