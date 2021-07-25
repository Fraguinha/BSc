open Printf;;

let rec fib n = if n <= 1 then 1 else fib (n-2) + fib(n-1);;

let main  () =

  let f = open_in "input.txt" in
  let number = int_of_string (input_line f) in
  let answer = fib number in
  let () = printf "Fibonacci of order %d is %d\n" number answer in

  close_in f;;

main ();;
