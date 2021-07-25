open Printf;;

let rec fib n = if n <= 1 then 1 else fib (n-2) + fib(n-1);;

let main () = 

  let number = read_int () in
  let answer = fib number in

  printf "Fibonacci of order %d is %d\n" number answer;;

main ();;