function f = fact(n) % compute the factorial of a number recursively

if(n == 1)
    f = 1; % base case for factorial
else
    f = n * fact(n - 1); % recursive case

end