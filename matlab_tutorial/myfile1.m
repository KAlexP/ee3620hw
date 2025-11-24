function f = myfile1(n) % compute the factorial of a number recursively

if(n ==1)
    f = 1;
else
    f = n * myfile1(n - 1);
end