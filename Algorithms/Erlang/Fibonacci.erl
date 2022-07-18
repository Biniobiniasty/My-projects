-module(fibonacci).
-export([main/1]).

main(X) ->
        fibonacci_show(0, X).

fibonacci_show(Y, X) ->
        if is_integer(X) == false orelse X < 0 -> io:fwrite("Bad input\n");
            X > Y -> io:fwrite("Fibonacci[~w] = ~w~n", [Y, fibonacci(Y)]),
                    fibonacci_show(Y+1, X);
           X == Y -> io:fwrite("Fibonacci[~w] = ~w~n", [Y, fibonacci(Y)])
        end.
           

fibonacci_loop(X, Y, Param1, Param2) ->
        Sum = Param1 + Param2,
        if X == Y -> Sum;
           X =/=Y -> fibonacci_loop(X+1, Y, Param2, Sum)
        end.

fibonacci(X) ->
        if X == 0 -> 0;
           X == 1 orelse X == 2 -> 1;
           X > 1 -> fibonacci_loop(3, X, 1, 1)
        end.
