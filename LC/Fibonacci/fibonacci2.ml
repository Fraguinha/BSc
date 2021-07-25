open Printf;;

let rec fib n = if n <= 1 then 1 else fib (n-2) + fib(n-1);;

let main () =

  let number = int_of_string Sys.argv.(1) in
  let answer = fib number in

  printf "Fibonacci of order %d is %d\n" number answer;;

main ();;