let fib n =

  let temp = ref 0 in
  let resa = ref 1 in
  let resb = ref 1 in

  for v = 1 to (n-1) do

    temp:= !resa;
    resa:= !resb;
    resb:= !temp + !resa

  done;

  !resb;;

let () = Printf.printf "%d\n" (fib 6);;