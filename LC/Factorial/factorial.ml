open Printf;;

let rec fact n = if n <= 1 then 1 else n * fact (n-1);;

let main () =

  let number = read_int () in
  let answer = fact number in

  printf "Factorial of %d is %d\n" number answer;;

main ();;

